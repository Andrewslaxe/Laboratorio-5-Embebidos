#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVector>
#include <QSerialPort>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void makeplot();
    void on_pushButton_clicked();

    void readSerial();
    void processSerial(double data,int Cmd);
    void on_pushButton_2_clicked();
    void Send(int cmd,uint16_t Info,uint8_t Tam,uint8_t Info2);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Widget *ui;
    void setupPlot();
    QVector<double> RpmGraph;
    QVector<double> CurrentGraph;
    QVector<double> x;
    QVector<double> y;
    QSerialPort *ttl;
    static const quint16 ttl_vendor_id = 9476;
    static const quint16 ttl_product_id = 768;
    QByteArray serialData;
    QString serialBuffer;
    QString parsed_data;

};

#endif // WIDGET_H
