#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPixmap"
#include <QApplication>
#include <QCoreApplication>
#include <QWidget>
#include <QPushButton>
#include <QListWidget>
#include <QStyledItemDelegate>
#include <QPainter>
#include <QFile>
#include <QTextStream>

using namespace std;

class CenteredItemDelegate : public QStyledItemDelegate
{
public:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override
    {
        QStyleOptionViewItem opt = option;
        opt.displayAlignment = Qt::AlignCenter;
        QStyledItemDelegate::paint(painter, opt, index);
    }
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->btnDelete->hide();
    ui->history->hide();
    ui->btnBack->hide();
    ui->txtName->hide();
    ui->inpName->hide();
    ui->txtCat->hide();
    ui->inpCat->hide();
    ui->txtStoreWeight->hide();
    ui->inpStoreWeight->hide();
    QWidget::setWindowTitle("Grade Calculator");
    QPixmap pix(":/images/ecuLogo.png");
    int w = ui->ecuLogo->width();
    int h = ui->ecuLogo->height();
    ui->ecuLogo->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->history->setItemDelegate(new CenteredItemDelegate);
    ui->history->setStyleSheet("background-color: rgba(89, 42, 138, 0.5);");
}

double grades[1000];
double weights[1000];
static int i = 0;

void MainWindow::on_btnNext_clicked()
{
    grades[i] = ui->inpGrade->text().toDouble();
    weights[i] = ui->inpWeight->text().toDouble();
    i++;
    ui->inpGrade->clear();
    ui->inpWeight->clear();
    ui->inpGrade->setFocus();
}

void MainWindow::on_btnEnd_clicked()
{
    grades[i] = ui->inpGrade->text().toDouble();
    weights[i] = ui->inpWeight->text().toDouble();
    ui->inpGrade->clear();
    ui->inpWeight->clear();
    ui->inpGrade->setFocus();

    double sum = 0;
    double sumWeights = 0;
    for (int i = 0; i < 1000; i++)
    {
        if (grades[i] == 0)
        {
            break;
        }
        sum += grades[i] * weights[i];
        sumWeights += weights[i];
    }

    double average = sum / sumWeights ;
    ui->lineEdit->setText(QString::number(average, 'f', 2));
}

void MainWindow::on_inpGrade_returnPressed()
{
    if (ui->inpGrade->text().isEmpty())
    {
        on_btnEnd_clicked();
    }
    else
    {
        ui->inpWeight->setFocus();
    }
}


void MainWindow::on_inpWeight_returnPressed()
{
    if (ui->inpGrade->text().isEmpty())
    {
        on_btnEnd_clicked();
    }
    else
    {
        on_btnNext_clicked();
    }
}

void MainWindow::on_btnHistory_clicked()
{
    ui->inpGrade->hide();
    ui->inpWeight->hide();
    ui->btnNext->hide();
    ui->btnEnd->hide();
    ui->btnHistory->hide();
    ui->lineEdit->hide();
    ui->txtGrade->hide();
    ui->txtWeight->hide();
    ui->txtOut->hide();
    ui->ecuLogo->hide();
    ui->btnHistory->hide();
    ui->btnDelete->show();
    ui->history->show();
    ui->btnBack->show();

    for (int i = 0; i < 1000; i++)
    {
        if (grades[i] == 0)
        {
            break;
        }
        ui->history->addItem("Grade: " + QString::number(grades[i]) + " " + "Weight: " + QString::number(weights[i]));
    }
}


void MainWindow::on_btnDelete_clicked()
{
    int index = ui->history->currentRow();

    QListWidgetItem *item = ui->history->takeItem(index);
    delete item;

    for (int j = index; j < 1000; j++)
    {
        grades[j] = grades[j + 1];
        weights[j] = weights[j + 1];
    }
    i--;
}


void MainWindow::on_btnBack_clicked()
{
    ui->inpGrade->show();
    ui->inpWeight->show();
    ui->btnNext->show();
    ui->btnEnd->show();
    ui->btnHistory->show();
    ui->lineEdit->show();
    ui->txtGrade->show();
    ui->txtWeight->show();
    ui->txtOut->show();
    ui->ecuLogo->show();
    ui->btnDelete->hide();
    ui->history->hide();
    ui->btnBack->hide();

    ui->inpGrade->clear();
    ui->inpWeight->clear();
    ui->inpGrade->setFocus();

    ui->inpGrade->clear();
    ui->inpWeight->clear();
    ui->inpGrade->setFocus();

    double sum = 0;
    double sumWeights = 0;
    for (int i = 0; i < 1000; i++)
    {
        if (grades[i] == 0)
        {
            break;
        }
        sum += grades[i] * weights[i];
        sumWeights += weights[i];
    }

    double average = sum / sumWeights ;
    ui->lineEdit->setText(QString::number(average, 'f', 2));

    ui->history->clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_textActivated(const QString &arg1)
{
    if (arg1 == "Add New")
    {
        ui->inpGrade->hide();
        ui->inpWeight->hide();
        ui->btnNext->hide();
        ui->btnEnd->hide();
        ui->btnHistory->hide();
        ui->lineEdit->hide();
        ui->txtGrade->hide();
        ui->txtWeight->hide();
        ui->txtOut->hide();
        ui->ecuLogo->hide();
        ui->btnHistory->hide();
        ui->btnDelete->hide();
        ui->history->hide();
        ui->btnBack->hide();
        ui->txtName->show();
        ui->inpName->show();
        ui->inpName->setFocus();
        ui->txtCat->show();
        ui->inpCat->show();
        ui->txtStoreWeight->show();
        ui->inpStoreWeight->show();
    }
}

void MainWindow::on_inpName_returnPressed()
{
    ui->comboBox->addItem(ui->inpName->text());
    ui->inpCat->setFocus();
    // create a file named test
    QFile file(":/test.txt");
    // open the file in write mode
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return;
    }
    QTextStream out(&file);
    out << ui->inpName->text();
}

string cat[100];
string storeWeight[100];

void MainWindow::on_inpCat_returnPressed()
{
    cat[i] = ui->inpCat->text().toStdString();
    ui->inpStoreWeight->setFocus();
}

void MainWindow::on_inpStoreWeight_returnPressed()
{
    storeWeight[i] = ui->inpStoreWeight->text().toStdString();
    ui->inpCat->setFocus();
}

