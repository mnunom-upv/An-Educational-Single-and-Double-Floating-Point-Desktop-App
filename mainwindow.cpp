#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <bitset>
#include <cmath>
#include <sstream>
#include <iostream>
#include <stdio.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// variables globales
double Numero, expoE, numExp;
std::string opcion, exponenteF, mantisaF, numB, procesos;
int nm, signo, expo;

//Solo añade el punto decimal, hasta donde lo probe si jala
std::string addDot1(const std::bitset<32>& bits, int pd) {
    int sign_bit = bits[31];
    std::bitset<31> masked_bits(bits.to_ulong() & 0x7FFFFFFF);

    std::stringstream ss;
    ss << masked_bits.to_string();
    std::string str = ss.str();

    str.insert(pd-1, 1, '.');
    str.insert(0, 1, (sign_bit == 1) ? '1' : '0');

    return str;
}

//Lo mismo que el otro pero para presición doble
std::string addDot2(const std::bitset<64>& bits, int pd) {
    int sign_bit = bits[63];
    std::bitset<63> masked_bits(bits.to_ullong() & 0x7FFFFFFFFFFFFFFF);

    std::stringstream ss;
    ss << masked_bits.to_string();
    std::string str = ss.str();

    str.insert(pd-1, 1, '.');
    str.insert(0, 1, (sign_bit == 1) ? '1' : '0');

    return str;
}

//Aqui se hace el calculo de la mantisa, ignora el nombre de la funcion si hacia eso al inicio xd
std::bitset<32> puntoFijo1(double numero) {
    //Toma el primer valor binario (1 es -, 0 es +)
    signo = (numero < 0) ? 1 : 0;
    //Lee a ver si se ingreso un valor como 2.77e+37 (solo checa si tiene e+)
    //Aqui se hace el calculo del exponente para el sesgo
    int exponente = 0;
    double numero2;
    double numero3;
    if (expoE>0){
        //Si si tiene entonces calcula el exponente como entra
        numero = abs(numExp);
        numero2 = abs(numero);
    }else{
        //Si no lo tiene pues se calcula igual como entra xd (osea sin e+)
        numero = abs(numero);
        numero2 = abs(numero);
    }

    while (numero >= 2.0) {
        numero /= 2.0;
        exponente++;
    }
    while (numero < 1.0) {
        numero *= 2.0;
        exponente--;
    }
    exponente += 127;

    //Se le pone el valor del numero ingresado sin e+ para continuar con los calculos
    numero3 = abs(numero);
    int parteEntera = static_cast<int>(numero2);
    int parteE2 = static_cast<int>(numero3);
    float parteFraccionaria = numero3 - parteE2;

    //A partir de aqui se calcula la mantisa
    std::bitset<8> exponente2(parteEntera);
    std::bitset<23> mantisa;

    for (int i = 0; i < 23; ++i) {
        parteFraccionaria *= 2;
        if (parteFraccionaria >= 1) {
            mantisa.set(22 - i);
            parteFraccionaria -= 1;
        }
    }

    //Aqui ya se agregan el signo, el exponente y la mantisa al resultado
    std::bitset<32> resultado;
    resultado[31] = signo;
    for (int i = 0; i < 8; ++i) {
        resultado[23 + i] = exponente2[i];
    }
    for (int i = 0; i < 23; ++i) {
        resultado[i] = mantisa[i];
    }

    //Tambien se agrega la mantisa del exponente
    std::bitset<sizeof(exponente)> mantisaexp;

    for (int i = 0; i < static_cast<int>(sizeof(exponente)); i++){
        mantisaexp[i] = exponente2[i];
    }

    //Esto solo muestra el exponente en binario
    bitset<8> expBin(exponente);

    expo = exponente;

    //Solo muestra el calculo del sesgo del exponente
    exponenteF = "Exponent = " + std::to_string(exponente - 127) + ";\nSkewed exponent = " + std::to_string(exponente - 127) + " + 127 = " + std::to_string(exponente) + " (In binary: " + expBin.to_string() +")";

    //Se agrega a la variable de mantisa final para mostrarla
    mantisaF = mantisa.to_string();

    return resultado;
}

//Hace lo mismo que el otro pero para presición doble
std::bitset<64> puntoFijo2(double numero) {
    signo = (numero < 0) ? 1 : 0;
    double numero2;

    if (expoE>0){
        numero = abs(numExp);
        numero2 = abs(numero);
    }else{
        numero = abs(numero);
        numero2 = abs(numero);
    }

    int exponente = 0;
    while (numero >= 2.0) {
        numero /= 2.0;
        exponente++;
    }
    while (numero < 1.0) {
        numero *= 2.0;
        exponente--;
    }
    exponente += 1023;

    double numero3 = abs(numero);
    int parteEntera = static_cast<int>(numero2);
    int parteE2 = static_cast<int>(numero3);
    double parteFraccionaria = numero3 - parteE2;

    std::bitset<11> exponente2(parteEntera);
    std::bitset<52> mantisa;

    for (int i = 0; i < 52; ++i) {
        parteFraccionaria *= 2;
        if (parteFraccionaria >= 1) {
            mantisa.set(51 - i);
            parteFraccionaria -= 1;
        }
    }

    std::bitset<64> resultado;
    resultado[63] = signo;
    for (int i = 0; i < 11; ++i) {
        resultado[52 + i] = exponente2[i];
    }
    for (int i = 0; i < 52; ++i) {
        resultado[0 + i] = mantisa[i];
    }

    std::bitset<sizeof(exponente)> mantisaexp;

    for (int i = 0; i < static_cast<int>(sizeof(exponente)); i++){
        mantisaexp[i] = exponente2[i];
    }

    bitset<11> expBin(exponente);

    expo = exponente;

    exponenteF = "Exponent = " + std::to_string(exponente - 1023) + ";\nSkewed exponent = " + std::to_string(exponente - 1023) + " + 1023 = " + std::to_string(exponente) + " (In binary: " + expBin.to_string() +")";

    mantisaF = mantisa.to_string();
    return resultado;
}

//Pues es la funcion de normalizar que recorre el punto decimal al primer 1
void normalizar1(std::bitset<32>& numero) {
    int i = 31 - 1;
    while (!numero.test(i)) {
        i--;
        if (i==0){
            break;
        }
    }
    int shift = 31 - i;
    numero <<= shift;
}

//Lo mismo que explique
void normalizar2(std::bitset<64>& numero) {
    int i = 63 - 1;
    while (!numero.test(i)) {
        i--;
        if (i==0){
            break;
        }
    }
    int shift = 63 - i;
    numero <<= shift;
}

//Binario a hexa
QString binHexa(const QString& binario) {
    int numBin = binario.toInt(nullptr, 2);

    std::stringstream stream;
    stream << std::hex << numBin;

    std::string hexadecimalStr = stream.str();

    return QString::fromStdString(hexadecimalStr);
}

//No creo que sea necesario modificar algo de aqui abajo, practicamente el problema estara en las funciones de puntoFijo
//Pero por si acaso checa lo siguiente
void MainWindow::on_pushB_Cal_clicked()
{
    opcion = ui->comboBox_Sp->currentText().toStdString();

    expoE = 0;

    QString input = ui->lineE_Num->text();
    const std::string nhex = ui->lineE_Num->text().toStdString();
    //Aqui inicia el proceso para checar si es numero hexadecimal
    static QRegularExpression hexPattern("[0-9a-fA-F]+");
    bool isHex = false;
    if (input.startsWith("0x", Qt::CaseInsensitive)) {
        input.remove(0, 2); // Eliminar 0x
        isHex = input.length() > 0 && hexPattern.match(input).hasMatch();
    }

    //Si si es checa si esta en presición Simple o Doble
    if (isHex){
        if (nhex.length()>10){
            opcion = "Double";
            ui->comboBox_Sp->setCurrentIndex(1);
        }else{
            if (nhex.length()<18){
                opcion = "Simple";
                ui->comboBox_Sp->setCurrentIndex(0);
            }else{
                ui->plainTE_Desc->setPlainText("You cannot calculate a number greater than double precision");
            }
        }
        if (opcion == "Simple"){
            float f;
            sscanf(input.toStdString().c_str(), "%x", &nm);
            f = *((float*)&nm);
            Numero = f;
        } else if (opcion == "Double"){
            double d = 0.0;
            try{
                *reinterpret_cast<unsigned long long*>(&d) = std::stoull(nhex, nullptr, 16);
            }
            catch(...){}
            Numero = d;
        }
    } else {
        //Si no es numero hexadecimal solo toma el valor ingresado
        Numero = ui->lineE_Num->text().toDouble();
    }

    //Aqui toma el valor ingresado en numExp
    numExp = Numero;
    ui->lineE_Onum->setText(QString::number(Numero));
    procesos = "First, the number entered and already processed is taken: " + QString::number(Numero).toStdString() + "\n\n";

    //Practicamente verifica si tiene e+ y lo separa para manejar el calculo del exponente y mantisa
    QString input2 = ui->lineE_Onum->text();
    if(input2.contains("e") || input2.contains("E")){
        QStringList parts = input2.split(QRegularExpression("[eE]"));
        double base = parts[0].toDouble();
        int exponent = parts[1].toInt();
        double test1 = base;
        expoE = abs(exponent);
        Numero = test1;
    } else {
        Numero = ui->lineE_Num->text().replace(" ", "").toDouble();
    }


    //A partir de aqui ya es solo muestreo de las cosas, no es necesario checarlo
    if (opcion == "Simple"){
        ui->gridLayout_2->parentWidget()->setVisible(false);
        ui->gridL_num2->parentWidget()->setVisible(false);
        ui->gridLayout_4->parentWidget()->setVisible(false);
        ui->lineE_fE->setFixedWidth(161);
        std::bitset<32> numeroPf = puntoFijo1(Numero);
        procesos = procesos + "Then we convert it to binary: " + numeroPf.to_string() + "\n\n";
        ui->lineE_Pf->setText(QString::fromStdString(addDot1(numeroPf, 9)));
        procesos = procesos + "Later we add the decimal point in the ninth position: " + addDot1(numeroPf, 9) + "\n\n";
        normalizar1(numeroPf);
        ui->lineE_PfN->setText(QString::fromStdString(addDot1(numeroPf, 1)+"x2^"+to_string(expo-127)));
        procesos = procesos + "Now we proceed to normalize it: " + addDot1(numeroPf, 1)+"x2^"+to_string(expo-127) + "\n\n";
        ui->lineE_Ce->setText(QString::fromStdString(exponenteF));
        procesos = procesos + "Then the bias of the exponent is obtained: " + exponenteF + "\n\n";
        if(isHex){
            ui->lineE_Cm->setText(QString::fromStdString(mantisaF));
            procesos = procesos + "Finally we obtain the mantissa: " + mantisaF + "\n\n";
        }else{
            ui->lineE_Cm->setText(QString::fromStdString(mantisaF));
            procesos = procesos + "Finally we obtain the mantissa: " + mantisaF + "\n\n";
        }
        QHBoxLayout *rowLayout = new QHBoxLayout();
        rowLayout->setSpacing(0);
        QHBoxLayout *rowL_num1 = new QHBoxLayout();
        rowL_num1->setSpacing(0);

        for (int i = 0; i < 32; ++i) {
            QLineEdit *bitLineEdit = new QLineEdit(QString::number(31 - i));
            bitLineEdit->setFixedHeight(31);
            bitLineEdit->setFixedWidth(21);
            bitLineEdit->setReadOnly(true);
            bitLineEdit->setAlignment(Qt::AlignHCenter);
            rowL_num1->addWidget(bitLineEdit);
        }

        bitset<8> expBin(expo);

        QStringList valHex;
        QString val = "";

        for (int i = 0; i < 32; ++i) {
            if (i == 0){
                QLineEdit *bitLineEdit = new QLineEdit(QString::number(signo));
                bitLineEdit->setFixedHeight(31);
                bitLineEdit->setFixedWidth(21);
                bitLineEdit->setReadOnly(true);
                bitLineEdit->setAlignment(Qt::AlignHCenter);
                rowLayout->addWidget(bitLineEdit);
                val = val + bitLineEdit->text();
            }else if(i < 9){
                QLineEdit *bitLineEdit = new QLineEdit(QString::number(expBin[8 - i]));
                bitLineEdit->setFixedHeight(31);
                bitLineEdit->setFixedWidth(21);
                bitLineEdit->setReadOnly(true);
                bitLineEdit->setAlignment(Qt::AlignHCenter);
                rowLayout->addWidget(bitLineEdit);
                val = val + bitLineEdit->text();
            }else{
                QLineEdit *bitLineEdit = new QLineEdit(QString(mantisaF[i-9]));
                bitLineEdit->setFixedHeight(31);
                bitLineEdit->setFixedWidth(21);
                bitLineEdit->setReadOnly(true);
                bitLineEdit->setAlignment(Qt::AlignHCenter);
                rowLayout->addWidget(bitLineEdit);
                val = val + bitLineEdit->text();
            }
        }

        procesos = procesos + "Then we calculate its hexadecimal value using its binary value\nwith the sign (1), the exponent (8) and the mantissa (23)\n";

        string binproces = "          ";
        string hexproces = "  ";

        for (int i = 0; i < val.length(); i += 4) {
            QString segmento = val.mid(i, 4);
            QString valorHexadecimal = binHexa(segmento);
            valHex.append(valorHexadecimal);
            binproces = binproces + segmento.toStdString() + " ";
            hexproces = hexproces + "   " +valorHexadecimal.toStdString() + "    ";
        }

        procesos = procesos + "                       s|      e         |                        m\n";
        procesos = procesos + "Binary:  "+ binproces + "\nHexadecimal:";
        procesos = procesos + hexproces;

        ui->gridL_num1->addLayout(rowL_num1, 0, 0, 1, 0);
        ui->gridLayout->addLayout(rowLayout, 0, 0, 1, 0);

        QHBoxLayout *hexGridLayout = new QHBoxLayout();

        for (int i = 0; i < 8; ++i) {
            QLineEdit *bitLineEdit = new QLineEdit(valHex[i]);
            bitLineEdit->setFixedHeight(31);
            bitLineEdit->setFixedWidth(80);
            bitLineEdit->setReadOnly(true);
            bitLineEdit->setAlignment(Qt::AlignHCenter);
            hexGridLayout->addWidget(bitLineEdit);
        }

        ui->gridLayout_3->addLayout(hexGridLayout, 0, 0, 1, 0);

        QString qProcesos = QString::fromStdString(procesos);
        ui->plainTE_Desc->setPlainText(qProcesos);

    } else if (opcion== "Double") {
        ui->gridLayout_2->parentWidget()->setVisible(true);
        ui->gridL_num2->parentWidget()->setVisible(true);
        ui->gridLayout_4->parentWidget()->setVisible(true);
        ui->lineE_fE->setFixedWidth(221);
        std::bitset<64> numeroPf = puntoFijo2(Numero);
        procesos = procesos + "Then we convert it to binary: " + numeroPf.to_string() + "\n\n";
        ui->lineE_Pf->setText(QString::fromStdString(addDot2(numeroPf, 12)));
        procesos = procesos + "Later we add the decimal point in the twelfth position: " + addDot2(numeroPf, 12) + "\n\n";
        normalizar2(numeroPf);
        ui->lineE_PfN->setText(QString::fromStdString(addDot2(numeroPf, 1)+"x2^"+to_string(expo-1023)));
        procesos = procesos + "Now we proceed to normalize it: " + addDot2(numeroPf, 1)+"x2^"+to_string(expo-1023) + "\n\n";
        ui->lineE_Ce->setText(QString::fromStdString(exponenteF));
        procesos = procesos + "Then the bias of the exponent is obtained: " + exponenteF + "\n\n";
        ui->lineE_Cm->setText(QString::fromStdString(mantisaF));
        if(isHex){
            ui->lineE_Cm->setText(QString::fromStdString(mantisaF));
            procesos = procesos + "Finally we obtain the mantissa: " + mantisaF + "\n\n";
        }else{
            ui->lineE_Cm->setText(QString::fromStdString(mantisaF));
            procesos = procesos + "Finally we obtain the mantissa: " + mantisaF + "\n\n";
        }

        QHBoxLayout *rowL_num1 = new QHBoxLayout();
        rowL_num1->setSpacing(0);
        QHBoxLayout *rowL_num2 = new QHBoxLayout();
        rowL_num2->setSpacing(0);

        QHBoxLayout *rowLayout = new QHBoxLayout();
        rowLayout->setSpacing(0);
        QHBoxLayout *rowLayout2 = new QHBoxLayout();
        rowLayout2->setSpacing(0);

        for (int i = 0; i < 32; ++i) {
            QLineEdit *bitLineEdit = new QLineEdit(QString::number(63 - i));
            bitLineEdit->setFixedHeight(31);
            bitLineEdit->setFixedWidth(21);
            bitLineEdit->setReadOnly(true);
            bitLineEdit->setAlignment(Qt::AlignHCenter);
            rowL_num1->addWidget(bitLineEdit);
        }

        for (int i = 0; i < 32; ++i) {
            QLineEdit *bitLineEdit = new QLineEdit(QString::number(31 - i));
            bitLineEdit->setFixedHeight(31);
            bitLineEdit->setFixedWidth(21);
            bitLineEdit->setReadOnly(true);
            bitLineEdit->setAlignment(Qt::AlignHCenter);
            rowL_num2->addWidget(bitLineEdit);
        }

        bitset<11> expBin(expo);

        QStringList valHex;
        QString val = "";

        for (int i = 0; i < 64; ++i) {
            if (i == 0){
                QLineEdit *bitLineEdit = new QLineEdit(QString::number(signo));
                bitLineEdit->setFixedHeight(31);
                bitLineEdit->setFixedWidth(21);
                bitLineEdit->setReadOnly(true);
                bitLineEdit->setAlignment(Qt::AlignHCenter);
                rowLayout->addWidget(bitLineEdit);
                val = val + bitLineEdit->text();
            }else if(i < 12){
                QLineEdit *bitLineEdit = new QLineEdit(QString::number(expBin[11 - i]));
                bitLineEdit->setFixedHeight(31);
                bitLineEdit->setFixedWidth(21);
                bitLineEdit->setReadOnly(true);
                bitLineEdit->setAlignment(Qt::AlignHCenter);
                rowLayout->addWidget(bitLineEdit);
                val = val + bitLineEdit->text();
            }else if(i < 32){
                QLineEdit *bitLineEdit = new QLineEdit(QString(mantisaF[i-12]));
                bitLineEdit->setFixedHeight(31);
                bitLineEdit->setFixedWidth(21);
                bitLineEdit->setReadOnly(true);
                bitLineEdit->setAlignment(Qt::AlignHCenter);
                rowLayout->addWidget(bitLineEdit);
                val = val + bitLineEdit->text();
            }else{
                QLineEdit *bitLineEdit = new QLineEdit(QString(mantisaF[i-12]));
                bitLineEdit->setFixedHeight(31);
                bitLineEdit->setFixedWidth(21);
                bitLineEdit->setReadOnly(true);
                bitLineEdit->setAlignment(Qt::AlignHCenter);
                rowLayout2->addWidget(bitLineEdit);
                val = val + bitLineEdit->text();
            }
        }

        procesos = procesos + "Then we calculate its hexadecimal value using its binary value\nwith the sign (1), the exponent (11) and the mantissa (52)\n";

        string binproces = "          ";
        string hexproces = "  ";
        string binproces2 = "          ";
        string hexproces2 = "  ";

        for (int i = 0; i < val.length(); i += 4) {
            QString segmento = val.mid(i, 4);
            QString valorHexadecimal = binHexa(segmento);
            valHex.append(valorHexadecimal);
            if(i < 32){
                binproces = binproces + segmento.toStdString() + " ";
                hexproces = hexproces + "   " +valorHexadecimal.toStdString() + "    ";
            }else{
                binproces2 = binproces2 + segmento.toStdString() + " ";
                hexproces2 = hexproces2 + "   " +valorHexadecimal.toStdString() + "    ";
            }
        }

        procesos = procesos + "                       s|      e         |                        m\n";
        procesos = procesos + "Binary:   "+ binproces + "\nHexadecimal:";
        procesos = procesos + hexproces;
        procesos = procesos + "\nBinary:   "+ binproces2 + "\nHexadecimal:";
        procesos = procesos + hexproces2;

        ui->gridL_num1->addLayout(rowL_num1, 0, 0, 1, 0);
        ui->gridLayout->addLayout(rowLayout, 0, 0, 1, 0);
        ui->gridL_num2->addLayout(rowL_num2, 0, 0, 1, 0);
        ui->gridLayout_2->addLayout(rowLayout2, 0, 0, 1, 0);

        QHBoxLayout *hexGridLayout = new QHBoxLayout();
        QHBoxLayout *hexGridLayout2 = new QHBoxLayout();

        for (int i = 0; i < 8; ++i) {
            QLineEdit *bitLineEdit = new QLineEdit(valHex[i]);
            bitLineEdit->setFixedHeight(31);
            bitLineEdit->setFixedWidth(80);
            bitLineEdit->setReadOnly(true);
            bitLineEdit->setAlignment(Qt::AlignHCenter);
            hexGridLayout->addWidget(bitLineEdit);
        }

        for (int i = 8; i < 16; ++i) {
            QLineEdit *bitLineEdit = new QLineEdit(valHex[i]);
            bitLineEdit->setFixedHeight(31);
            bitLineEdit->setFixedWidth(80);
            bitLineEdit->setReadOnly(true);
            bitLineEdit->setAlignment(Qt::AlignHCenter);
            hexGridLayout2->addWidget(bitLineEdit);
        }

        ui->gridLayout_3->addLayout(hexGridLayout, 0, 0, 1, 0);
        ui->gridLayout_4->addLayout(hexGridLayout2, 0, 0, 1, 0);

        QString qProcesos = QString::fromStdString(procesos);
        ui->plainTE_Desc->setPlainText(qProcesos);

    }
}
