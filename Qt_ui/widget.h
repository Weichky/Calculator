#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QMessageBox>
#include <QStack>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_0_clicked();
    void on_pushButton_clear_clicked();
    void on_pushButton_div_clicked();
    void on_pushButton_del_clicked();
    void on_pushButton_dot_clicked();
    void on_pushButton_equal_clicked();
    void on_pushButton_minus_clicked();
    void on_pushButton_plus_clicked();
    void on_pushButton_time_clicked();
    void on_pushButton_perc_clicked();

private:
    Ui::Widget *ui;
    QString experession;
};

#endif // WIDGET_H
