#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle("Calculator");

    connect(ui->pushButton_no_use,&QPushButton::clicked,[this](){
        QMessageBox::information(this,"Calculator version 0.1-beta","for Weichky learning use");
    });

    QIcon icon_del("../calculator/icons/img_del.png");
    ui->pushButton_del->setIcon(icon_del);

    QIcon icon_clear("../calculator/icons/img_clear.png");
    ui->pushButton_clear->setIcon(icon_clear);

    ui->pushButton_equal->setStyleSheet("background:orange");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_1_clicked(){
    experession += "1";
    ui->mainlineEdit->setText(experession);
}

void Widget::on_pushButton_2_clicked(){
    experession += "2";
    ui->mainlineEdit->setText(experession);
}

void Widget::on_pushButton_3_clicked(){
    experession += "3";
    ui->mainlineEdit->setText(experession);
}

void Widget::on_pushButton_4_clicked(){
    experession += "4";
    ui->mainlineEdit->setText(experession);
}

void Widget::on_pushButton_5_clicked(){
    experession += "5";
    ui->mainlineEdit->setText(experession);
}

void Widget::on_pushButton_6_clicked(){
    experession += "6";
    ui->mainlineEdit->setText(experession);
}

void Widget::on_pushButton_7_clicked(){
    experession += "7";
    ui->mainlineEdit->setText(experession);
}

void Widget::on_pushButton_8_clicked(){
    experession += "8";
    ui->mainlineEdit->setText(experession);
}

void Widget::on_pushButton_9_clicked(){
    experession += "9";
    ui->mainlineEdit->setText(experession);
}

void Widget::on_pushButton_0_clicked(){
    experession += "0";
    ui->mainlineEdit->setText(experession);
}

void Widget::on_pushButton_clear_clicked(){
    experession.clear();
    ui->mainlineEdit->clear();
}

void Widget::on_pushButton_div_clicked(){
    experession += "/";
    ui->mainlineEdit->setText(experession);
}

void Widget::on_pushButton_dot_clicked(){
    experession += ".";
    ui->mainlineEdit->setText(experession);
}

void Widget::on_pushButton_del_clicked(){
    experession.chop(1);
    ui->mainlineEdit->setText(experession);
}

void Widget::on_pushButton_minus_clicked(){
    experession += "-";
    ui->mainlineEdit->setText(experession);
}

void Widget::on_pushButton_plus_clicked(){
    experession += "+";
    ui->mainlineEdit->setText(experession);
}

void Widget::on_pushButton_time_clicked(){
    experession += "*";
    ui->mainlineEdit->setText(experession);
}

void Widget::on_pushButton_perc_clicked(){
    experession += "%";
    ui->mainlineEdit->setText(experession);
}

void Widget::on_pushButton_equal_clicked(){
    experession += "=";
    ui->mainlineEdit->setText(experession);
};
