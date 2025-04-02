#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QTabWidget>
#include <QLabel>

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
    void on_quitButton_clicked();

    void on_quitButton_4_clicked();

    void on_transferFunctionButton_4_clicked();

private:
    Ui::MainWindow *ui;
    QWidget *transferFunctionTab = Q_NULLPTR;
};
#endif // MAINWINDOW_H
