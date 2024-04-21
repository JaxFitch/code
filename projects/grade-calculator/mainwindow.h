#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnNext_clicked();

    void on_btnEnd_clicked();

    void on_inpGrade_returnPressed();

    void on_inpWeight_returnPressed();

    void on_btnHistory_clicked();

    void on_btnDelete_clicked();

    void on_btnBack_clicked();

    void on_comboBox_textActivated(const QString &arg1);

    void on_inpName_returnPressed();

    void on_inpCat_returnPressed();

    void on_inpStoreWeight_returnPressed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
