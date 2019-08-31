#ifndef SCNDISPLAYWINDOW_H
#define SCNDISPLAYWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include "scndisplay.h"

namespace Ui {
class SCNDisplayWindow;
}

class SCNDisplayWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SCNDisplayWindow(QWidget *parent = nullptr);
    ~SCNDisplayWindow();
	void setP(MGraph *SCN);
private slots:
	void scnDisplayWindowOKButton_clicked();
	void scnDisplayWindowCancelButton_clicked();
private:
    Ui::SCNDisplayWindow *ui;
	MGraph *m;
	Vertex *person;
	Vertex *personList;
};

#endif // SCNDISPLAYWINDOW_H
