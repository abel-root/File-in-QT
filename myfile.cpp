/**
 * =========================================================================================
 *
 * @date : 16-01-2025
 *
 * ========================================================================================
 *
 * @author : KONAN Kouakou Abel
 *
 * =========================================================================================
 *
 * @version : V-1.0
 *
 * =========================================================================================
 *
 * Modul - .H
 *
 * =========================================================================================
 *
 */


#include "myfile.h"
#include "ui_myfile.h"
#include <QFileDialog>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>

MyFile::MyFile(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyFile)
{
    ui->setupUi(this);

    connect(ui->read, &QPushButton::clicked, this, &MyFile::readFile);
    connect(ui->write, &QPushButton::clicked,this,&MyFile::writeFile);
    connect(ui->print, &QPushButton::clicked, this, &MyFile::printFile);



}

MyFile::~MyFile()
{
    delete ui;
}

void MyFile::readFile(){

    QString filename =  QFileDialog::getOpenFileName(this, "Read file");

    if(filename.isEmpty()){
        QMessageBox::information(this,"information","File name don't existe.");
        return ;
    }

    QFile file(filename);

    if (!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::information(this,"information","File can not open !");
        return;
    }

    currentFile = filename;

    this->setWindowTitle(filename);

    QTextStream in(&file);

    QString text=in.readAll();

    ui->textEdit->setText(text);

    file.close();

}
void MyFile::writeFile(){

    QString filename=QFileDialog::getSaveFileName(this, "Save As");

    if(filename.isEmpty()){
        QMessageBox::information(this,"Warning","File name don't existe.");
        return ;
    }

    QFile file(filename);

    if (!file.open(QIODevice::WriteOnly | QFile::Text)){
        QMessageBox::information(this,"Warning","File can not write !");
        return;
    }

    currentFile = filename;
    this->setWindowTitle(filename);
    QTextStream out (&file);
    QString text= ui->textEdit->toPlainText();
    out<< text;
    file.close();

}
void MyFile::printFile(){
 QPrinter printer;
 QPrintDialog dialog(&printer, this);
    dialog.setWindowTitle(tr("Print Document"));

    if (dialog.exec() != QDialog::Accepted)
        return;

    ui->textEdit->print(&printer);

}
