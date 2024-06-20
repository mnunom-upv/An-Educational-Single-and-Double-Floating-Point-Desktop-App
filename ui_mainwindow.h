/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineE_Num;
    QComboBox *comboBox_Sp;
    QPushButton *pushB_Cal;
    QLabel *label;
    QLineEdit *lineE_Onum;
    QLabel *label_2;
    QLineEdit *lineE_Pf;
    QLabel *label_3;
    QLineEdit *lineE_PfN;
    QLabel *label_4;
    QLineEdit *lineE_Ce;
    QLabel *label_5;
    QLineEdit *lineE_Cm;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineE_fE;
    QLineEdit *lineE_fF;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_12;
    QLineEdit *lineEdit_13;
    QLineEdit *lineEdit_14;
    QLabel *label_6;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridL_num1;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridL_num2;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_3;
    QWidget *gridLayoutWidget_6;
    QGridLayout *gridLayout_4;
    QPlainTextEdit *plainTE_Desc;
    QLabel *label_7;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1219, 550);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lineE_Num = new QLineEdit(centralwidget);
        lineE_Num->setObjectName(QString::fromUtf8("lineE_Num"));
        lineE_Num->setGeometry(QRect(120, 10, 141, 28));
        lineE_Num->setAlignment(Qt::AlignCenter);
        comboBox_Sp = new QComboBox(centralwidget);
        comboBox_Sp->addItem(QString());
        comboBox_Sp->addItem(QString());
        comboBox_Sp->setObjectName(QString::fromUtf8("comboBox_Sp"));
        comboBox_Sp->setGeometry(QRect(380, 10, 131, 28));
        pushB_Cal = new QPushButton(centralwidget);
        pushB_Cal->setObjectName(QString::fromUtf8("pushB_Cal"));
        pushB_Cal->setGeometry(QRect(550, 10, 151, 29));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 70, 161, 31));
        label->setAlignment(Qt::AlignCenter);
        lineE_Onum = new QLineEdit(centralwidget);
        lineE_Onum->setObjectName(QString::fromUtf8("lineE_Onum"));
        lineE_Onum->setGeometry(QRect(260, 70, 551, 28));
        lineE_Onum->setAlignment(Qt::AlignCenter);
        lineE_Onum->setReadOnly(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 109, 161, 31));
        label_2->setAlignment(Qt::AlignCenter);
        lineE_Pf = new QLineEdit(centralwidget);
        lineE_Pf->setObjectName(QString::fromUtf8("lineE_Pf"));
        lineE_Pf->setGeometry(QRect(260, 110, 551, 28));
        lineE_Pf->setAlignment(Qt::AlignCenter);
        lineE_Pf->setReadOnly(true);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(2, 140, 251, 41));
        label_3->setAlignment(Qt::AlignCenter);
        lineE_PfN = new QLineEdit(centralwidget);
        lineE_PfN->setObjectName(QString::fromUtf8("lineE_PfN"));
        lineE_PfN->setGeometry(QRect(260, 150, 551, 28));
        lineE_PfN->setAlignment(Qt::AlignCenter);
        lineE_PfN->setReadOnly(true);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 190, 161, 31));
        label_4->setAlignment(Qt::AlignCenter);
        lineE_Ce = new QLineEdit(centralwidget);
        lineE_Ce->setObjectName(QString::fromUtf8("lineE_Ce"));
        lineE_Ce->setGeometry(QRect(260, 190, 551, 28));
        lineE_Ce->setAlignment(Qt::AlignCenter);
        lineE_Ce->setReadOnly(true);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 230, 191, 31));
        label_5->setAlignment(Qt::AlignCenter);
        lineE_Cm = new QLineEdit(centralwidget);
        lineE_Cm->setObjectName(QString::fromUtf8("lineE_Cm"));
        lineE_Cm->setGeometry(QRect(260, 230, 551, 28));
        lineE_Cm->setAlignment(Qt::AlignCenter);
        lineE_Cm->setReadOnly(true);
        lineEdit_5 = new QLineEdit(centralwidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(60, 270, 71, 31));
        lineEdit_5->setAlignment(Qt::AlignCenter);
        lineEdit_5->setReadOnly(true);
        lineEdit_6 = new QLineEdit(centralwidget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(130, 270, 21, 31));
        QFont font;
        font.setPointSize(9);
        lineEdit_6->setFont(font);
        lineEdit_6->setAlignment(Qt::AlignCenter);
        lineEdit_6->setReadOnly(true);
        lineE_fE = new QLineEdit(centralwidget);
        lineE_fE->setObjectName(QString::fromUtf8("lineE_fE"));
        lineE_fE->setGeometry(QRect(150, 270, 161, 31));
        lineE_fE->setAlignment(Qt::AlignCenter);
        lineE_fE->setReadOnly(true);
        lineE_fF = new QLineEdit(centralwidget);
        lineE_fF->setObjectName(QString::fromUtf8("lineE_fF"));
        lineE_fF->setGeometry(QRect(310, 270, 461, 31));
        lineE_fF->setAlignment(Qt::AlignCenter);
        lineE_fF->setReadOnly(true);
        lineEdit_9 = new QLineEdit(centralwidget);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(60, 330, 71, 31));
        lineEdit_9->setAlignment(Qt::AlignCenter);
        lineEdit_9->setReadOnly(true);
        lineEdit_10 = new QLineEdit(centralwidget);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(60, 360, 71, 31));
        lineEdit_10->setAlignment(Qt::AlignCenter);
        lineEdit_10->setReadOnly(true);
        lineEdit_11 = new QLineEdit(centralwidget);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));
        lineEdit_11->setGeometry(QRect(60, 470, 71, 31));
        lineEdit_11->setAlignment(Qt::AlignCenter);
        lineEdit_11->setReadOnly(true);
        lineEdit_12 = new QLineEdit(centralwidget);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));
        lineEdit_12->setGeometry(QRect(60, 500, 71, 31));
        lineEdit_12->setAlignment(Qt::AlignCenter);
        lineEdit_12->setReadOnly(true);
        lineEdit_13 = new QLineEdit(centralwidget);
        lineEdit_13->setObjectName(QString::fromUtf8("lineEdit_13"));
        lineEdit_13->setGeometry(QRect(60, 410, 71, 31));
        lineEdit_13->setAlignment(Qt::AlignCenter);
        lineEdit_13->setReadOnly(true);
        lineEdit_14 = new QLineEdit(centralwidget);
        lineEdit_14->setObjectName(QString::fromUtf8("lineEdit_14"));
        lineEdit_14->setGeometry(QRect(130, 410, 641, 31));
        lineEdit_14->setAlignment(Qt::AlignCenter);
        lineEdit_14->setReadOnly(true);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(290, 10, 81, 31));
        label_6->setAlignment(Qt::AlignCenter);
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(130, 330, 641, 31));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(130, 470, 641, 31));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget_3 = new QWidget(centralwidget);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(130, 300, 641, 31));
        gridL_num1 = new QGridLayout(gridLayoutWidget_3);
        gridL_num1->setObjectName(QString::fromUtf8("gridL_num1"));
        gridL_num1->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget_4 = new QWidget(centralwidget);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(130, 440, 641, 31));
        gridL_num2 = new QGridLayout(gridLayoutWidget_4);
        gridL_num2->setObjectName(QString::fromUtf8("gridL_num2"));
        gridL_num2->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget_5 = new QWidget(centralwidget);
        gridLayoutWidget_5->setObjectName(QString::fromUtf8("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(130, 360, 641, 31));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget_6 = new QWidget(centralwidget);
        gridLayoutWidget_6->setObjectName(QString::fromUtf8("gridLayoutWidget_6"));
        gridLayoutWidget_6->setGeometry(QRect(130, 500, 641, 31));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        plainTE_Desc = new QPlainTextEdit(centralwidget);
        plainTE_Desc->setObjectName(QString::fromUtf8("plainTE_Desc"));
        plainTE_Desc->setGeometry(QRect(820, 70, 391, 461));
        plainTE_Desc->setReadOnly(true);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(930, 30, 201, 20));
        label_7->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        lineE_fF->raise();
        lineE_Num->raise();
        comboBox_Sp->raise();
        pushB_Cal->raise();
        label->raise();
        lineE_Onum->raise();
        label_2->raise();
        lineE_Pf->raise();
        label_3->raise();
        lineE_PfN->raise();
        label_4->raise();
        lineE_Ce->raise();
        label_5->raise();
        lineE_Cm->raise();
        lineEdit_5->raise();
        lineEdit_6->raise();
        lineE_fE->raise();
        lineEdit_9->raise();
        lineEdit_10->raise();
        lineEdit_11->raise();
        lineEdit_12->raise();
        lineEdit_13->raise();
        lineEdit_14->raise();
        label_6->raise();
        gridLayoutWidget->raise();
        gridLayoutWidget_2->raise();
        gridLayoutWidget_3->raise();
        gridLayoutWidget_4->raise();
        gridLayoutWidget_5->raise();
        gridLayoutWidget_6->raise();
        plainTE_Desc->raise();
        label_7->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        comboBox_Sp->setItemText(0, QCoreApplication::translate("MainWindow", "Simple", nullptr));
        comboBox_Sp->setItemText(1, QCoreApplication::translate("MainWindow", "Double", nullptr));

        pushB_Cal->setText(QCoreApplication::translate("MainWindow", "Calculate", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Original Number:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Fixed point number:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Fixed point number (Normalized):", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Exponent calculation:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Calculation of the mantissa:", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("MainWindow", "Format", nullptr));
        lineEdit_6->setText(QCoreApplication::translate("MainWindow", "S", nullptr));
        lineE_fE->setText(QCoreApplication::translate("MainWindow", "Exponent", nullptr));
        lineE_fF->setText(QCoreApplication::translate("MainWindow", "Mantissa", nullptr));
        lineEdit_9->setText(QCoreApplication::translate("MainWindow", "Binary", nullptr));
        lineEdit_10->setText(QCoreApplication::translate("MainWindow", "Hexa", nullptr));
        lineEdit_11->setText(QCoreApplication::translate("MainWindow", "Binary", nullptr));
        lineEdit_12->setText(QCoreApplication::translate("MainWindow", "Hexa", nullptr));
        lineEdit_13->setText(QCoreApplication::translate("MainWindow", "Format", nullptr));
        lineEdit_14->setText(QCoreApplication::translate("MainWindow", "Mantissa", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Precision:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Process description", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
