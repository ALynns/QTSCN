#ifndef SCNCREATEWINDOW_H
#define SCNCREATEWINDOW_H

#include <QDialog>
#include <QString>
#include <QMessagebox>

namespace Ui {
class SCNCreateWindow;
}

class SCNCreateWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SCNCreateWindow(QWidget *parent = nullptr);
    ~SCNCreateWindow();
	friend class SCNMainWindow;
private slots:
	void scnCreateOKButton_clicked();
	void scnCreateCancelButton_clicked();
private:
    Ui::SCNCreateWindow *ui;
	int personNum;
	QString nameLine;
	QString knowLine;
	QStringList knowList;
	
};

#endif // SCNCREATEWINDOW_H
