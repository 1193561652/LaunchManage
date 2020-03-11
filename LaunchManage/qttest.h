#ifndef QTTEST_H
#define QTTEST_H

#include <QtWidgets/QMainWindow>
#include "ui_qttest.h"
#include "dlg.h"
#include "Work/DesktopItemDir.h"
#include <qstandarditemmodel>

class QtTest : public QMainWindow
{
	Q_OBJECT

public:
	QtTest(QWidget *parent = 0);
	~QtTest();

private:
	Ui::QtTestClass ui;
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

#endif // QTTEST_H
