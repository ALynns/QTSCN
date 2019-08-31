#include <QMainWindow>
#include <QDialog>
#include <QMenu>
#include <QMenuBar>
#include <qtextcodec.h> 
#include <vector>

#include "scncreatewindow.h"
#include "scndisplaywindow.h"
#include "mayknowwindow.h"

namespace Ui {
class SCNMainWindow;
}

class SCNMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SCNMainWindow(QWidget *parent = nullptr);
    ~SCNMainWindow();
private slots:
    void scnCreateButton_clicked();
    void scnDisplayButton_clicked();
    void mayKnowButton_clicked();
	void actionHelpButton_clicked();
private:
    Ui::SCNMainWindow *ui;
	QMenu *menuBarHelp;
	QAction *actionHelpOpen;

	int personNum;
	QStringList nameList;
	std::vector<QStringList> knowNameList;
	MGraph *SCN;
};

