#include "widget.h"
#include "ui_widget.h"
#include <QVector>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "stdio.h"
#include "stdlib.h"
#include "cstring"

#define Start 0x06
#define Stop 0x07
double RPMMin=0,RPMMax=0,Flag=0,RPm=0,CurrentAct=0;
double siz=0;


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);
    ttl = new QSerialPort(this);
    serialBuffer = "";
    parsed_data = "";

    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        QString pname = serialPortInfo.portName();
        ui->comboBox->addItem(pname);
    }
    setupPlot();
}

Widget::~Widget()
{
   if(ttl->isOpen()){
       ttl->close();
       QObject::disconnect(ttl, SIGNAL(readyRead()), this, SLOT(readSerial()));
   }

    delete ui;
}

void Widget::setupPlot(){

    ui->customPlot->addGraph(ui->customPlot->xAxis, ui->customPlot->yAxis);
    ui->customPlot->addGraph(ui->customPlot->xAxis, ui->customPlot->yAxis2);
    ui->customPlot->graph(0)->setData(x, RpmGraph);
    ui->customPlot->graph(1)->setData(y, CurrentGraph);
    ui->customPlot->graph(1)->setPen(QPen(Qt::red));
    ui->customPlot->graph(0)->setName("RPM");
    ui->customPlot->graph(1)->setName("Corriente");
    ui->customPlot->plotLayout()->insertRow(0);
    ui->customPlot->plotLayout()->addElement(0, 0, new QCPTextElement(ui->customPlot, "Velocidad - Motor DC", QFont("sans", 12, QFont::Bold)));

    ui->customPlot->legend->setVisible(true);
    QFont legendFont = font();  // start out with MainWindow's font..
    legendFont.setPointSize(9); // and make a bit smaller for legend
    ui->customPlot->legend->setFont(legendFont);
    ui->customPlot->legend->setBrush(QBrush(QColor(255,255,255,230)));

    ui->customPlot->xAxis->setLabel("Time Relative");
    ui->customPlot->yAxis->setLabel("RPM.");
    ui->customPlot->xAxis->setRange(0, 1000);
    ui->customPlot->yAxis->setRange(0, 10000);
    ui->customPlot->yAxis2->setLabel("mA");
    ui->customPlot->yAxis2->setRange(0, 1000);
    ui->customPlot->yAxis2->setVisible(true);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    ui->customPlot->replot();
}

void Widget::makeplot(){

    siz++;
    /*if(siz>254){
     * double i=0;
        for(i=0;i<253;i++){
            RpmGraph.operator[](i) = RpmGraph.operator[](i+1);

        }
        RpmGraph.operator[](253)=RPm;
    }

    else{*/
    CurrentGraph.append(CurrentAct);
    RpmGraph.append(RPm);
    x.append(siz);
    y.append(siz);
    ui->customPlot->graph(0)->setData(x, RpmGraph);
    ui->customPlot->graph(1)->setData(y,CurrentGraph);
    ui->customPlot->replot();
    ui->customPlot->rescaleAxes();
    ui->customPlot->update();
}


void Widget::Send(int cmd,uint16_t Info,uint8_t Tam){
    //Protocolo
    uint8_t Count,Parity=0;;
    QByteArray data;
    data.clear();
    data.append(Start);
    data.append(Tam);
    data.append(cmd);
    //if(Info2==0){
    if(Tam<2){
        data.append(Info);
    }
    else {
        data.append(0x00FF & (Info >> 8));
        data.append(0x00FF & Info);
    }
    for(Count=0;Count<data.length();Count++){
        Parity^=data.at(Count);
    }

    data.append(Parity);
    data.append(Stop);
    ttl->write(data,data.length());
}
void Widget::readSerial()
{
    int Size,Aux,Parity=0,Check,Temp1,Temp2=0;
    double Data;
    QByteArray buffer ;
    serialData.clear();
    buffer.clear();
    buffer= ttl->readAll();
    serialData.append(buffer);
    ui->label_12->setText("Recibiendo datos");
    if(serialData.at(0)==Start && serialData.at(serialData.at(1)+4)==Stop){
        Size=serialData.at(1);
        for(Aux=3;Aux<=Size+3;Aux++){
            if(serialData.at(Aux)<0){
                serialData[Aux]=serialData.at(Aux)+256;
            }
        }
        //9653
        if(Size==1){
            Temp1=(serialData.at(3));
        }
        else{
            Temp1=serialData.at(3)<< 8;
            Temp2=serialData.at(4);
        }
        if(Temp1<0){
            Temp1+=256;
        }
        if(Temp2<0){
            Temp2+=256;
        }
        Data=Temp1|Temp2;
        for(Aux =0;Aux<Size+3;Aux++){
            Parity^=serialData.at(Aux);
        }
        Check=serialData.at(Size+3);
        if(Parity==Check || Parity==Check+256){
            processSerial(Data,serialData.at(2));
            serialData.clear();
        }
        else{
            qDebug()<< "Se recibió información con errores";
            serialData.clear();
        }
    }
}

void Widget::processSerial(double data,int cmd){
    QString Aux,Datos;
    double Rpm=0;
    Datos=QString::number(data);
    qDebug()<< Datos;
    if(cmd==1){
        Rpm=data;
        if(Flag==0){
            RPMMin=Rpm;
            Flag++;
        }
        else{
            if(RPMMin>Rpm){
                RPMMin=Rpm;
            }
            if(RPMMax<Rpm){
                RPMMax=Rpm;
            }
            RPm=Rpm;
            Aux=QString::number(RPMMax);
            ui->RpmAct->setText(Datos);
            ui->RpmMax->setText(Aux);
            Aux=QString::number(RPMMin);
            ui->RpmMin->setText(Aux);

        }
    }
    else if(cmd==2){
        CurrentAct=data;
    }

    makeplot();

}
void Widget::on_pushButton_clicked()
{
    uint8_t Tam=0;
    QString Txt1,Txt2;
    uint16_t Pwm,Time;
    Txt1 = ui->lineEdit->text();
    Txt2 = ui->lineEdit_2->text();
    if(ui->lineEdit->text() != "" && ui->lineEdit_2->text() != ""){
        if(Txt1.toInt()>=0 && Txt1.toInt()<100){
            if(Txt2.toInt()>=0){
                Txt2 = ui->lineEdit_2->text();
                Pwm=Txt1.toInt();
                Time=Txt2.toInt();
                if(Time<256){
                    Tam=1;
                }
                else{
                    Tam=2;
                }
                Send(4,Time,Tam);  //Va hasta 100
                if(ttl->waitForBytesWritten()){
                    Send(2,Pwm,1);
                }
            }
            else{
                QMessageBox msgBox;
                msgBox.setText("Ingrese un valor de tiempo valido");
                msgBox.exec();
            }
        }
        else{
            QMessageBox msgBox;
            msgBox.setText("En PWM ingrese un valor de 0 a 100");
            msgBox.exec();
        }

    }else{
        QMessageBox msgBox;
        msgBox.setText("Escriba un numero en el campo del PWM y Tiempo");
        msgBox.exec();
    }

}
void Widget::on_pushButton_2_clicked()
{
    QString ttl_port_name = ui->comboBox->currentText();
    if(ui->pushButton_2->text() == "Abrir"){
        foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
            if(ttl_port_name==serialPortInfo.portName()){
                ttl->setPortName(ttl_port_name);
                ttl->open(QSerialPort::ReadWrite);
                ttl->setBaudRate(QSerialPort::Baud115200);
                ttl->setDataBits(QSerialPort::Data8);
                ttl->setFlowControl(QSerialPort::NoFlowControl);
                ttl->setParity(QSerialPort::NoParity);
                ttl->setStopBits(QSerialPort::OneStop);
                QObject::connect(ttl, SIGNAL(readyRead()), this, SLOT(readSerial()));
                Send(1,5,1);
                ui->label_12->setText("Conectado");
                ui->pushButton_2->setText("Cerrar");

            }
            else{
                ui->label_12->setText("Puerto no disponible");
            }
        }
    }else{
        Send(0,2,1); //Le cierra la Flag a la stm para enviar datos
        ttl->close();
        QObject::disconnect(ttl, SIGNAL(readyRead()), this, SLOT(readSerial()));
        ui->pushButton_2->setText("Abrir");
        ui->label_12->setText("Desconectado");
    }

}

void Widget::on_pushButton_3_clicked()
{
    ui->comboBox->clear();
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        QString pname = serialPortInfo.portName();
        ui->comboBox->addItem(pname);
    }
}



void Widget::on_horizontalSlider_valueChanged(int value)
{
    int Tam;
    QString Slide="Valor Ingresado: "+QString::number(value);
    ui->label_9->setText(Slide);
    if(value>=256){
        Tam=2;
    }
    else{
        Tam=1;
    }

    Send(3,value,Tam);
}

