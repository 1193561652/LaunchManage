#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include "dlg.h"
#include "Work/DesktopItemDir.h"
#include <qstandarditemmodel.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow ui;
    Dlg dlg;
    DesktopItemDir mDesktopItemDir;
    QStandardItemModel *mModel = nullptr;

    void loadDir();
protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void closeEvent(QCloseEvent *event);
protected slots:
    void btnClick();
    void directoryChanged(QString);
    void fileChanged(QString);
    void itemChanged(QStandardItem *item);
signals:
    void signal1();
};

#endif // MAINWINDOW_H
