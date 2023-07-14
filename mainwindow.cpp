#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

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


void MainWindow::on_tabWidget_windowTitleChanged(const QString &title)
{
    QWidget::setWindowTitle(title);
}

QChar Parsel(QChar charText, QChar charKey){
    return ((short) charText.unicode()+charKey.unicode()-5);
}

QChar Desparsel(QChar charText, QChar charKey){
    return ((short) charText.unicode()-charKey.unicode()+5);
}

QString Criptografar(QString text, QString key){
    QString crypText;
    int countkey = 0;
    for(int i =0; i<text.length(); i++){

        crypText += Parsel(text.at(i),key.at(countkey));

        if(countkey == key.length()-1){
            countkey = 0;
        }
        else{
            countkey++;
        }
    }
    return crypText;
}

QString Descriptografar(QString text, QString key){
    QString crypText;
    int countkey = 0;
    for(int i =0; i<text.length(); i++){

        crypText += Desparsel(text.at(i),key.at(countkey));

        if(countkey == key.length()-1){
            countkey = 0;
        }
        else{
            countkey++;
        }
    }
    return crypText;
}

void MainWindow::on_pushButton_clicked()
{
    QString text = ui->textEdit->toPlainText();
    QString key = ui->lineEdit->text();
    if(key.length() >=1 && text.length() >= 1){
        ui->textEdit_2->setText(Criptografar(text,key));
    }
    else{
        QMessageBox::warning(this, "Campos vazios", "Preencha os campos de \"Texto para Criptografar\" e \"Chave de criptografia\"");
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    QString cript = ui->textEdit_3->toPlainText();
    QString key = ui->lineEdit_2->text();
    if(key.length() >=1 && cript.length() >= 1){
        ui->textEdit_4->setText(Descriptografar(cript,key));
    }
    else{
        QMessageBox::warning(this, "Campos vazios", "Preencha os campos de \"Texto para descriptografar\" e \"Chave de criptografia\"");
    }

}

