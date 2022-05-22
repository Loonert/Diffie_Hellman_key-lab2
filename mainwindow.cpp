#include <QtMath>
#include <QDebug>
#include <QRandomGenerator>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    double G = pow(6,13);
    qDebug() << "G = " << G;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Create_K_clicked()
{

    ui->plainTextEdit_Alice->clear();
    ui->plainTextEdit_Bob->clear();

    int value = QRandomGenerator::global()->bounded(1,10);

    ui->plainTextEdit_Alice->insertPlainText("Private a = ");
    ui->plainTextEdit_Alice->insertPlainText(QString::number(value));
    QString str = "g = " + QString::number(g) + "    " + "p = " + QString::number(p);
    ui->plainTextEdit_Alice->appendPlainText(str);
    int A = static_cast<int>(pow(g, value)) % p;
    QString str_2 = "A = g^a mod p = " + QString::number(A);
    ui->plainTextEdit_Alice->appendPlainText(str_2);

    int value_2 = QRandomGenerator::global()->bounded(1,10);
    ui->plainTextEdit_Bob->insertPlainText("Private b = ");
    ui->plainTextEdit_Bob->insertPlainText(QString::number(value_2));
    ui->plainTextEdit_Bob->appendPlainText(str);
    int B = static_cast<int>(pow(g, value_2)) % p;
    QString str_3 = "B = g^b mod p = " + QString::number(B);
    ui->plainTextEdit_Bob->appendPlainText(str_3);
    int K_Alice = static_cast<int>(pow(B, value)) % p;
    int K_Bob = static_cast<int>(pow(A, value_2)) % p;

    QString str_K_Alice = "K = B^a mod p = " + QString::number(K_Alice);
    ui->plainTextEdit_Alice->appendPlainText(str_K_Alice);

    QString str_K_Bob = "K = A^b mod p = " + QString::number(K_Bob);
    ui->plainTextEdit_Bob->appendPlainText(str_K_Bob);


}

