/********************************************************************************
** Form generated from reading UI file 'scncreatewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCNCREATEWINDOW_H
#define UI_SCNCREATEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SCNCreateWindow
{
public:
    QLabel *personNumLabel;
    QTextEdit *personNumTextEdit;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *personNumLabel_2;
    QTextEdit *nameTextEdit;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *personNumLabel_3;
    QLabel *label;
    QLabel *label_2;
    QTextEdit *knowTextEdit;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *scnCreateOKButton;
    QPushButton *scnCreateCancelButton;

    void setupUi(QDialog *SCNCreateWindow)
    {
        if (SCNCreateWindow->objectName().isEmpty())
            SCNCreateWindow->setObjectName(QStringLiteral("SCNCreateWindow"));
        SCNCreateWindow->resize(828, 606);
        personNumLabel = new QLabel(SCNCreateWindow);
        personNumLabel->setObjectName(QStringLiteral("personNumLabel"));
        personNumLabel->setGeometry(QRect(130, 60, 41, 16));
        personNumTextEdit = new QTextEdit(SCNCreateWindow);
        personNumTextEdit->setObjectName(QStringLiteral("personNumTextEdit"));
        personNumTextEdit->setGeometry(QRect(180, 50, 141, 31));
        layoutWidget = new QWidget(SCNCreateWindow);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 90, 711, 401));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        personNumLabel_2 = new QLabel(layoutWidget);
        personNumLabel_2->setObjectName(QStringLiteral("personNumLabel_2"));

        horizontalLayout_2->addWidget(personNumLabel_2);

        nameTextEdit = new QTextEdit(layoutWidget);
        nameTextEdit->setObjectName(QStringLiteral("nameTextEdit"));

        horizontalLayout_2->addWidget(nameTextEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        personNumLabel_3 = new QLabel(layoutWidget);
        personNumLabel_3->setObjectName(QStringLiteral("personNumLabel_3"));

        verticalLayout_2->addWidget(personNumLabel_3);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);


        horizontalLayout_3->addLayout(verticalLayout_2);

        knowTextEdit = new QTextEdit(layoutWidget);
        knowTextEdit->setObjectName(QStringLiteral("knowTextEdit"));

        horizontalLayout_3->addWidget(knowTextEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        widget = new QWidget(SCNCreateWindow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(210, 530, 381, 41));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        scnCreateOKButton = new QPushButton(widget);
        scnCreateOKButton->setObjectName(QStringLiteral("scnCreateOKButton"));

        horizontalLayout->addWidget(scnCreateOKButton);

        scnCreateCancelButton = new QPushButton(widget);
        scnCreateCancelButton->setObjectName(QStringLiteral("scnCreateCancelButton"));

        horizontalLayout->addWidget(scnCreateCancelButton);


        retranslateUi(SCNCreateWindow);

        QMetaObject::connectSlotsByName(SCNCreateWindow);
    } // setupUi

    void retranslateUi(QDialog *SCNCreateWindow)
    {
        SCNCreateWindow->setWindowTitle(QApplication::translate("SCNCreateWindow", "Create", Q_NULLPTR));
        personNumLabel->setText(QApplication::translate("SCNCreateWindow", "\344\272\272\346\225\260", Q_NULLPTR));
        personNumLabel_2->setText(QApplication::translate("SCNCreateWindow", "\345\247\223\345\220\215\357\274\210\347\224\250;\351\232\224\345\274\200\357\274\211", Q_NULLPTR));
        personNumLabel_3->setText(QApplication::translate("SCNCreateWindow", "\346\234\213\345\217\213", Q_NULLPTR));
        label->setText(QApplication::translate("SCNCreateWindow", "\357\274\210\347\224\250;\345\210\206\351\232\224\344\270\215\345\220\214\344\272\272\350\256\244\350\257\206\347\232\204\344\272\272\357\274\211", Q_NULLPTR));
        label_2->setText(QApplication::translate("SCNCreateWindow", "\357\274\210\347\224\250\347\251\272\346\240\274\345\210\206\351\232\224\345\220\214\344\270\200\344\272\272\350\256\244\350\257\206\347\232\204\344\272\272\357\274\211", Q_NULLPTR));
        scnCreateOKButton->setText(QApplication::translate("SCNCreateWindow", "OK", Q_NULLPTR));
        scnCreateCancelButton->setText(QApplication::translate("SCNCreateWindow", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SCNCreateWindow: public Ui_SCNCreateWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCNCREATEWINDOW_H
