#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->radioButton->setText("Вариант 1");
    ui->radioButton_2->setText("Вариант 2");

    updateComboBoxItems(true);

    ui->pushButton->setText("Переключить");

    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(10);
    ui->progressBar->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int currentValue = ui->progressBar->value();
    if (currentValue >= 10) {
        ui->progressBar->setValue(0);
    } else {
        ui->progressBar->setValue(currentValue + 1);
    }
}

void MainWindow::on_radioButton_toggled(bool checked)
{
    if (checked) {
        updateComboBoxItems(true);
    }
}

void MainWindow::on_radioButton_2_toggled(bool checked)
{
    if (checked) {
        updateComboBoxItems(false);
    }
}

void MainWindow::updateComboBoxItems(bool firstSet)
{
    ui->comboBox->clear();
    if (firstSet) {
        ui->comboBox->addItem("Элемент 1");
        ui->comboBox->addItem("Элемент 2");
        ui->comboBox->addItem("Элемент 3");
        ui->comboBox->addItem("Элемент 4");
        ui->comboBox->addItem("Элемент 5");
    } else {
        ui->comboBox->addItem("Элемент 6");
        ui->comboBox->addItem("Элемент 7");
        ui->comboBox->addItem("Элемент 8");
        ui->comboBox->addItem("Элемент 9");
        ui->comboBox->addItem("Элемент 10");
    }
}
