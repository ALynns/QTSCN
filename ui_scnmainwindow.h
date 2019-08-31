/********************************************************************************
** Form generated from reading UI file 'scnmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCNMAINWINDOW_H
#define UI_SCNMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SCNMainWindow
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *scnCreateButton;
    QPushButton *scnDisplayButton;
    QPushButton *mayKnowButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SCNMainWindow)
    {
        if (SCNMainWindow->objectName().isEmpty())
            SCNMainWindow->setObjectName(QStringLiteral("SCNMainWindow"));
        SCNMainWindow->resize(400, 300);
        centralWidget = new QWidget(SCNMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(82, 30, 231, 151));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scnCreateButton = new QPushButton(widget);
        scnCreateButton->setObjectName(QStringLiteral("scnCreateButton"));

        verticalLayout->addWidget(scnCreateButton);

        scnDisplayButton = new QPushButton(widget);
        scnDisplayButton->setObjectName(QStringLiteral("scnDisplayButton"));

        verticalLayout->addWidget(scnDisplayButton);

        mayKnowButton = new QPushButton(widget);
        mayKnowButton->setObjectName(QStringLiteral("mayKnowButton"));

        verticalLayout->addWidget(mayKnowButton);

        SCNMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SCNMainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 26));
        SCNMainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SCNMainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SCNMainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SCNMainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SCNMainWindow->setStatusBar(statusBar);

        retranslateUi(SCNMainWindow);

        QMetaObject::connectSlotsByName(SCNMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SCNMainWindow)
    {
        SCNMainWindow->setWindowTitle(QApplication::translate("SCNMainWindow", "SCN", Q_NULLPTR));
        scnCreateButton->setText(QApplication::translate("SCNMainWindow", "SCN Create", Q_NULLPTR));
        scnDisplayButton->setText(QApplication::translate("SCNMainWindow", "SCN Display", Q_NULLPTR));
        mayKnowButton->setText(QApplication::translate("SCNMainWindow", "MayKnow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SCNMainWindow: public Ui_SCNMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCNMAINWINDOW_H
