#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QtCharts"
#include "QtGui"

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

private:
    Ui::MainWindow *ui;
    QLineSeries *series;
    QChart *chart;
    QChartView *chartView;
    QTimer *timer;
    double x;

private slots:
    void updateChart();
};
#endif // MAINWINDOW_H
