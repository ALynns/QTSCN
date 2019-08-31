/********************************************************************************
** Form generated from reading UI file 'scndisplaywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCNDISPLAYWINDOW_H
#define UI_SCNDISPLAYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SCNDisplayWindow
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTextEdit *scnDisplayWindowTextEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *scnDisplayWindowOKButton;
    QPushButton *scnDisplayWindowCancelButton;

    void setupUi(QDialog *SCNDisplayWindow)
    {
        if (SCNDisplayWindow->objectName().isEmpty())
            SCNDisplayWindow->setObjectName(QStringLiteral("SCNDisplayWindow"));
        SCNDisplayWindow->resize(400, 300);
        widget = new QWidget(SCNDisplayWindow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(60, 20, 258, 231));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scnDisplayWindowTextEdit = new QTextEdit(widget);
        scnDisplayWindowTextEdit->setObjectName(QStringLiteral("scnDisplayWindowTextEdit"));

        verticalLayout->addWidget(scnDisplayWindowTextEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        scnDisplayWindowOKButton = new QPushButton(widget);
        scnDisplayWindowOKButton->setObjectName(QStringLiteral("scnDisplayWindowOKButton"));

        horizontalLayout->addWidget(scnDisplayWindowOKButton);

        scnDisplayWindowCancelButton = new QPushButton(widget);
        scnDisplayWindowCancelButton->setObjectName(QStringLiteral("scnDisplayWindowCancelButton"));

        horizontalLayout->addWidget(scnDisplayWindowCancelButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(SCNDisplayWindow);

        QMetaObject::connectSlotsByName(SCNDisplayWindow);
    } // setupUi

    void retranslateUi(QDialog *SCNDisplayWindow)
    {
        SCNDisplayWindow->setWindowTitle(QApplication::translate("SCNDisplayWindow", "Display", Q_NULLPTR));
        scnDisplayWindowOKButton->setText(QApplication::translate("SCNDisplayWindow", "OK", Q_NULLPTR));
        scnDisplayWindowCancelButton->setText(QApplication::translate("SCNDisplayWindow", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SCNDisplayWindow: public Ui_SCNDisplayWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCNDISPLAYWINDOW_H
