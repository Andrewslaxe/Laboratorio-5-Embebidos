/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QCustomPlot *customPlot;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QComboBox *comboBox;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_5;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *RpmMax;
    QLabel *RpmAct;
    QLabel *RpmMin;
    QLabel *label_6;
    QLabel *label_7;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_3;
    QLabel *label_9;
    QLabel *label_8;
    QLineEdit *lineEdit_4;
    QLabel *label_10;
    QPushButton *pushButton_4;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_11;
    QLabel *label_12;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(772, 581);
        customPlot = new QCustomPlot(Widget);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        customPlot->setGeometry(QRect(10, 150, 531, 421));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 50, 551, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(13);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout->addWidget(lineEdit_2);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font);

        horizontalLayout->addWidget(pushButton);

        layoutWidget1 = new QWidget(Widget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 80, 399, 51));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(0, 0));
        label_3->setMaximumSize(QSize(57, 16777215));
        label_3->setFont(font);

        horizontalLayout_2->addWidget(label_3);

        comboBox = new QComboBox(layoutWidget1);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(100, 0));
        comboBox->setFont(font);

        horizontalLayout_2->addWidget(comboBox);

        pushButton_2 = new QPushButton(layoutWidget1);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font);

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget1);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setFont(font);

        horizontalLayout_2->addWidget(pushButton_3);

        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(290, 0, 171, 41));
        QFont font1;
        font1.setPointSize(25);
        label_5->setFont(font1);
        gridLayoutWidget = new QWidget(Widget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(560, 480, 211, 101));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font2;
        font2.setPointSize(12);
        label_4->setFont(font2);

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        RpmMax = new QLabel(gridLayoutWidget);
        RpmMax->setObjectName(QString::fromUtf8("RpmMax"));

        gridLayout->addWidget(RpmMax, 1, 1, 1, 1);

        RpmAct = new QLabel(gridLayoutWidget);
        RpmAct->setObjectName(QString::fromUtf8("RpmAct"));

        gridLayout->addWidget(RpmAct, 0, 1, 1, 1);

        RpmMin = new QLabel(gridLayoutWidget);
        RpmMin->setObjectName(QString::fromUtf8("RpmMin"));

        gridLayout->addWidget(RpmMin, 2, 1, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font2);

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font2);

        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        gridLayoutWidget_2 = new QWidget(Widget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(560, 150, 211, 87));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_3 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout_2->addWidget(lineEdit_3, 0, 1, 1, 1);

        label_9 = new QLabel(gridLayoutWidget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font2);

        gridLayout_2->addWidget(label_9, 1, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font2);

        gridLayout_2->addWidget(label_8, 0, 0, 1, 1);

        lineEdit_4 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout_2->addWidget(lineEdit_4, 1, 1, 1, 1);

        label_10 = new QLabel(Widget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(640, 0, 131, 16));
        pushButton_4 = new QPushButton(Widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(630, 240, 80, 29));
        pushButton_4->setFont(font);
        horizontalLayoutWidget = new QWidget(Widget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(410, 80, 331, 51));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(horizontalLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(0, 0));
        label_11->setMaximumSize(QSize(57, 16777215));
        label_11->setFont(font);

        horizontalLayout_3->addWidget(label_11);

        label_12 = new QLabel(horizontalLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(0, 0));
        label_12->setMaximumSize(QSize(500, 16777215));
        label_12->setFont(font);

        horizontalLayout_3->addWidget(label_12);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "RPM & Corriente CACD", nullptr));
        label->setText(QApplication::translate("Widget", "PWM", nullptr));
        label_2->setText(QApplication::translate("Widget", "Tiempo(mS)", nullptr));
        pushButton->setText(QApplication::translate("Widget", "Enviar", nullptr));
        label_3->setText(QApplication::translate("Widget", "Puerto:", nullptr));
        pushButton_2->setText(QApplication::translate("Widget", "Abrir", nullptr));
        pushButton_3->setText(QApplication::translate("Widget", "Actualizar", nullptr));
        label_5->setText(QApplication::translate("Widget", "RPM y PWM", nullptr));
        label_4->setText(QApplication::translate("Widget", "RPM Actual", nullptr));
        RpmMax->setText(QString());
        RpmAct->setText(QString());
        RpmMin->setText(QString());
        label_6->setText(QApplication::translate("Widget", "RPM M\303\241ximas", nullptr));
        label_7->setText(QApplication::translate("Widget", "RPM M\303\255nimas", nullptr));
        label_9->setText(QApplication::translate("Widget", "Tiempo(mS)", nullptr));
        label_8->setText(QApplication::translate("Widget", "PWM(%)", nullptr));
        label_10->setText(QApplication::translate("Widget", "Designed By: Jaime Peraza", nullptr));
        pushButton_4->setText(QApplication::translate("Widget", "Enviar", nullptr));
        label_11->setText(QApplication::translate("Widget", "Status:", nullptr));
        label_12->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
