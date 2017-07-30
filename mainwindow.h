#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "temperatureanalysis.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_cmdImportCSVFiles_clicked();
    void on_cmdImportReferenceFile_clicked();
    void on_cmdOutputFile_clicked();
    void on_cmdExecute_clicked();

private:
    void enableExecute();

    Ui::MainWindow *ui;
    TemperatureAnalysis temperatureAnalysis;

    bool haveCSV = false;
    bool haveRef = false;
    bool haveExp = false;
};

#endif // MAINWINDOW_H
