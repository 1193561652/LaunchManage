#ifndef DLG_H_
#define DLG_H_

#include <QtWidgets/QDialog>
#include "ui_dlg.h"

class Dlg : public QDialog
{
    Q_OBJECT

public:
    Dlg();
    ~Dlg();

protected:
    Ui_Dialog   ui;
};

#endif
