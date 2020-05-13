#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    prepareWindow();


    connect(ui->pushButtonScenarioStart, SIGNAL(clicked(bool)), ui->pushButtonScenarioStop, SLOT(show()));
    connect(ui->pushButtonScenarioStart, SIGNAL(clicked(bool)), ui->pushButtonScenarioStart, SLOT(hide()));
    connect(ui->pushButtonScenarioStop, SIGNAL(clicked(bool)), ui->pushButtonScenarioStart, SLOT(show()));
    connect(ui->pushButtonScenarioStop, SIGNAL(clicked(bool)), ui->pushButtonScenarioStop, SLOT(hide()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::prepareWindow() {
    ui->tabWidget->setStyleSheet("QTabBar::tab { height: 35px; width: 159px; }");
    ui->tabWidgetDataBase->setStyleSheet("QTabBar::tab { height: 35px; width: 112px; }");
}

