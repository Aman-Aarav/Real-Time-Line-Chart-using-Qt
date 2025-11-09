#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), x(0.0)
{
    ui->setupUi(this);
    series = new QLineSeries();

    chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Real-Time Line Chart");
    chart->createDefaultAxes(); // Auto fits to the current data

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    setCentralWidget(chartView);
    resize(800, 600);

    // Timer for updating chart
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateChart);
    timer->start(50); // update every 50ms
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::updateChart() {
    const double y = qSin(x);
    series->append(x, y);

    // Limit number of points to avoid memory bloat
    if (series->count() > 500)
        series->remove(0); // remove oldest point

    chart->removeSeries(series); // re-adding series updates auto-axes
    chart->addSeries(series);
    chart->createDefaultAxes();

    x += 0.1;
}
