#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDir>
#include <QFileDialog>
#include <QString>
#include <string>
#include <vector>

#include "temperatureanalysis.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_cmdImportCSVFiles_clicked()
{
    haveCSV = false;
    auto files = QFileDialog::getOpenFileNames(
                this,
                "Open CSV files",
                QDir::currentPath(),
                "CSV (*.csv)");

    if(!files.empty()) {
        std::vector<std::string> paths;
        for(const auto &f : files)
            paths.push_back(f.toStdString());
        temperatureAnalysis.setSampleFilePath(paths);
        ui->lblStatus->clear();
        haveCSV = true;
        enableExecute();
    }
}

void MainWindow::on_cmdImportReferenceFile_clicked()
{
    haveRef = false;
    auto file = QFileDialog::getOpenFileName(
                this,
                "Open Reference file",
                QDir::currentPath(),
                "txt (*.txt)");

    if(!file.isEmpty()) {
        temperatureAnalysis.setReferencePath(file.toStdString());
        ui->lblStatus->clear();
        haveRef = true;
        enableExecute();
    }
}

void MainWindow::on_cmdOutputFile_clicked()
{
    haveExp = false;
    auto file = QFileDialog::getSaveFileName(
                this,
                "Export Report",
                QDir::currentPath(),
                "CSV (*.csv)");

    if(!file.isEmpty()) {
        temperatureAnalysis.setOutputDir(file.toStdString());
        ui->lblStatus->clear();
        haveExp = true;
        enableExecute();
    }
}

void MainWindow::on_cmdExecute_clicked()
{
    ui->lblStatus->clear();
    temperatureAnalysis.execute();
    ui->lblStatus->setText("Analyze Completed!");
}

void MainWindow::enableExecute()
{
    ui->cmdExecute->setEnabled(
                haveCSV &&
                haveRef &&
                haveExp);
}
