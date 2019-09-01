#include "scnmainwindow.h"
#include "ui_scnmainwindow.h"

SCNMainWindow::SCNMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SCNMainWindow)
{
    ui->setupUi(this);

	this->setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowMinimizeButtonHint);

	QMenuBar *pMenuBar = menuBar();

	//工具栏创建
    menuBarHelp = new QMenu(QStringLiteral("帮助(Alt+&H)"));
	//工具栏菜单创建
    actionHelpOpen = new QAction(QStringLiteral("关于软件"), this);
	actionHelpOpen->setShortcut(Qt::CTRL | Qt::Key_A);
	menuBarHelp->addAction(actionHelpOpen);
	//将菜单添加至工具栏按钮
	pMenuBar->addMenu(menuBarHelp);

    connect(ui->scnCreateButton,SIGNAL(clicked()),this,SLOT(scnCreateButton_clicked()));
    connect(ui->scnDisplayButton,SIGNAL(clicked()),this,SLOT(scnDisplayButton_clicked()));
    connect(ui->mayKnowButton,SIGNAL(clicked()),this,SLOT(mayKnowButton_clicked()));
	connect(actionHelpOpen, SIGNAL(triggered()), this, SLOT(actionHelpButton_clicked()));
}

SCNMainWindow::~SCNMainWindow()
{
    delete ui;
}

void SCNMainWindow::scnCreateButton_clicked()
{
    SCNCreateWindow *form=new SCNCreateWindow;
    form->exec();
	personNum = form->personNum;
	nameList = form->nameLine.split(";");
	for (int i = 0; i < personNum; i++)
	{
		if (i >= form->knowList.size())
			knowNameList.push_back(QStringList(""));
		else
			knowNameList.push_back(form->knowList.at(i).split(" "));
	}
	SCN = new MGraph(DG, personNum);
	for (int i = 0; i < personNum; i++)
		SCN->PutVex(i + 1, nameList.at(i));
	for (int i = 0; i < personNum; i++)
		for (int j = 0; j < knowNameList[i].size(); j++)
			SCN->CreateGraph(nameList.at(i), knowNameList[i].at(j), 1);
	//a;b;c;d
	//b c;a c d;a b d;b c
}

void SCNMainWindow::scnDisplayButton_clicked()
{
    SCNDisplayWindow *form=new SCNDisplayWindow;
	form->setP(SCN);
    form->exec();
	
}

int vexCompare(Vertex v0,Vertex v1)
{
    ArcCell *a0,*a1;
    int i=0;
    a0=v0.arc;
    a1=v1.arc;
    while(a0!=nullptr&&a1!=nullptr)
    {
        if(a0->vex1>a1->vex1)
        {
            a0=a0->next;
            continue;
        }

        if(a1->vex1>a0->vex1)
        {
            a1=a1->next;
            continue;
        }

        if(a0->vex1==a1->vex1)
        {
            a0=a0->next;
            a1=a1->next;
            i++;
            continue;
        }
    }
    return i;
}

bool comp(const Vertex v0,const Vertex v1)
{
    return v0.i>v1.i;
}

void SCNMainWindow::mayKnowButton_clicked()
{
    MayKnowWindow *form= new MayKnowWindow;
	form->exec();
    QString name=form->getName();
    SCN->LocateVex(name);
    std::vector<Vertex>mayKnow;
    ArcCell *a=SCN->vex[SCN->LocateVex(name)-1].arc;

    for(a;a!=nullptr;a=a->next)
        SCN->vex[a->vex1-1].flag=0;
    for(int i=0;i<personNum;i++)
        if(SCN->vex[i].flag&&i!=SCN->LocateVex(name)-1)
            mayKnow.push_back(SCN->vex[i]);

    for(int i=0;i<mayKnow.size();i++)
        mayKnow[i].i=vexCompare(SCN->vex[SCN->LocateVex(name)-1],mayKnow[i]);
    sort(mayKnow.begin(),mayKnow.end(),comp);

    QString m;
    m=name+QStringLiteral("可能认识的人")+'\n';
    for(int i=0;i<mayKnow.size();i++)
    {
        m = m + mayKnow[i].info + "   " + QStringLiteral("关联度：") + QString::number(mayKnow[i].i) + '\n';
    }

    QMessageBox *messageBox;
    messageBox = new QMessageBox(QStringLiteral("可能认识的人"), m, QMessageBox::Information, QMessageBox::Ok, 0, 0);
    messageBox->exec();
}


void SCNMainWindow::actionHelpButton_clicked()
{
	QMessageBox *helpMessageBox;
    QString helpString = QStringLiteral("同济大学计算机系2019年课程设计\n作者：夏子寒\n学号：1753935");
	helpMessageBox = new QMessageBox("About", helpString, QMessageBox::Information, QMessageBox::Ok, 0, 0);
	helpMessageBox->exec();
}
//a;b;c;d;e
//b c;a d e;a d;b c;c
