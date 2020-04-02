#include "mainwindow.h"
#include <QMouseEvent>
#include <qfilesystemwatcher.h>
#include <QTextCodec>
#include <QFileSystemModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    //connect(ui.pushButton, &QPushButton::clicked, this, &QtTest::btnClick);
    //connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(btnClick()));
    //connect(ui.pushButton, SIGNAL(clicked()), this, SIGNAL(signal1()));
    //connect(this, SIGNAL(signal1()), this, SLOT(btnClick()));

    //QFileSystemModel* mode = new QFileSystemModel();
   // mode->setRootPath("D:\\Users\\V\\Documents\\Visual Studio 2013\\Projects\\LaunchManage\\Win32\\applications");

    mModel = new QStandardItemModel();
    mModel->setColumnCount(2);
    mModel->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("Name"));
    mModel->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit(""));


    //QTextCodec *BianMa = QTextCodec::codecForName("GBK");

    ui.treeView->setModel(mModel);

    //this->setWindowFlags(Qt::FramelessWindowHint);
    loadDir();
    QObject::connect(mModel, SIGNAL(itemChanged(QStandardItem *)), this, SLOT(itemChanged(QStandardItem *)));

    QFileSystemWatcher *watcher;
    watcher = new QFileSystemWatcher();

    connect(watcher, SIGNAL(directoryChanged(QString)), this, SLOT(directoryChanged(QString)));
    connect(watcher, SIGNAL(fileChanged(QString)), this, SLOT(fileChanged(QString)));
}

void MainWindow::itemChanged(QStandardItem *item)
{
    QString text = item->text();
    QStandardItem *parentItem = item->parent();
    if (parentItem)
    {
        int colnum = item->column();
        int row = item->row();
        if (colnum == 1)
        {
            QString value = item->text();
            QStandardItem * keyItem = parentItem->child(row, 0);
            mDesktopItemDir.setValue(parentItem->text(), keyItem->text(), value);
            mDesktopItemDir.save(parentItem->text());
        }
        //mDesktopItemDir.save();
    }
    else
    {

    }
}

void MainWindow::directoryChanged(QString msg)
{
    int a = 0;
}

void MainWindow::fileChanged(QString msg)
{
    int a = 0;
}

MainWindow::~MainWindow()
{

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    int a = 0;
    QPoint pt = event->pos();
    a = pt.x();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    int a = 0;
    //event->ignore();
}

void MainWindow::btnClick()
{
    //int a = 0;
    //dlg.setModal(true);
    //dlg.show();
    //int res = dlg.exec();
    //if (res == QDialog::Accepted)
    //{
    //}
    //else if (res == QDialog::Rejected)
    //{
    //}
    //else
    //{
    //}
}

void MainWindow::loadDir()
{
    mDesktopItemDir.setPath("/usr/share/applications");
    int errcode;
    mDesktopItemDir.reload(errcode);

    mModel->removeRows(0, mModel->rowCount());
    const QList<DesktopItem*> itemList = mDesktopItemDir.getItemList();
    for (int i = 0; i < itemList.count(); i++)
    {
        const DesktopItem* item = itemList[i];
        QStandardItem* newItem = new QStandardItem(item->getFileName());
        mModel->setItem(i, 0, newItem);


        QList<QStandardItem *> childItems;
        QStandardItem* subItem = nullptr;

        for (int j = 0; j < KEY_COUNT; j++)
        {
            childItems.clear();
            subItem = new QStandardItem(DesktopItem::findKeyFromIndex(j));
            childItems.push_back(subItem);
            subItem = new QStandardItem(item->getValueFromIndex(j));

            childItems.push_back(subItem);
            newItem->appendRow(childItems);
        }
    }
}
