#include "scncreatewindow.h"
#include "ui_scncreatewindow.h"

SCNCreateWindow::SCNCreateWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SCNCreateWindow)
{
    ui->setupUi(this);
	connect(ui->scnCreateOKButton,SIGNAL(clicked()),this,SLOT(scnCreateOKButton_clicked()));
	connect(ui->scnCreateCancelButton, SIGNAL(clicked()), this, SLOT(scnCreateCancelButton_clicked()));
}

void SCNCreateWindow::scnCreateOKButton_clicked()
{
	personNum = ui->personNumTextEdit->toPlainText().toInt();
	nameLine = ui->nameTextEdit->toPlainText();
	knowLine = ui->knowTextEdit->toPlainText();
	knowList = knowLine.split(";");
	QMessageBox *CreateSuccessMessageBox;
	CreateSuccessMessageBox = new QMessageBox("Success", "Create success", QMessageBox::Information, QMessageBox::Ok, 0, 0);
	CreateSuccessMessageBox->exec();
	close();
}

void SCNCreateWindow::scnCreateCancelButton_clicked()
{
	close();
}

SCNCreateWindow::~SCNCreateWindow()
{
    delete ui;
}


