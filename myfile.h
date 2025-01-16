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




#ifndef MYFILE_H
#define MYFILE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MyFile;
}
QT_END_NAMESPACE

class MyFile : public QMainWindow
{
    Q_OBJECT

public:
    MyFile(QWidget *parent = nullptr);
    ~MyFile();

public slots :
    void readFile();
    void writeFile();
    void printFile();

private:
    Ui::MyFile *ui;
    QString currentFile;
};
#endif // MYFILE_H
