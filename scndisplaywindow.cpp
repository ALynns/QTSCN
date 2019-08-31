#include "scndisplaywindow.h"
#include "ui_scndisplaywindow.h"

SCNDisplayWindow::SCNDisplayWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SCNDisplayWindow)
{
    ui->setupUi(this);
	connect(ui->scnDisplayWindowOKButton, SIGNAL(clicked()), this, SLOT(scnDisplayWindowOKButton_clicked()));
	connect(ui->scnDisplayWindowCancelButton, SIGNAL(clicked()), this, SLOT(scnDisplayWindowCancelButton_clicked()));

}

SCNDisplayWindow::~SCNDisplayWindow()
{
    delete ui;
}

void SCNDisplayWindow::setP(MGraph *SCN)
{
	m = SCN;
	return;
}

void SCNDisplayWindow::scnDisplayWindowOKButton_clicked()
{
	Paint *p = new Paint;
	if (m->LocateVex(ui->scnDisplayWindowTextEdit->toPlainText()) - 1 < 0)
	{
		QMessageBox *failMessageBox;
		failMessageBox = new QMessageBox("Failed", "Not Found", QMessageBox::Information, QMessageBox::Ok, 0, 0);
		failMessageBox->exec();
		close();
		return;
	}
	person = &m->vex[m->LocateVex(ui->scnDisplayWindowTextEdit->toPlainText()) - 1];
	personList = m->vex;
	p->setPerson(person, personList);
	p->show();
	close();
}
void SCNDisplayWindow::scnDisplayWindowCancelButton_clicked()
{
	close();
}
