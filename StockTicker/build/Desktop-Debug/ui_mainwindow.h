/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLabel *symbolColumn;
    QSpacerItem *spacer1;
    QLabel *priceColumn;
    QSpacerItem *spacer2;
    QLabel *changColumn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(187, 97);
        MainWindow->setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setStyleSheet(QString::fromUtf8("background-color:white"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setStyleSheet(QString::fromUtf8("background-color:black\n"
""));
        frame->setFrameShape(QFrame::Shape::Box);
        frame->setFrameShadow(QFrame::Shadow::Sunken);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName("horizontalLayout");
        symbolColumn = new QLabel(frame);
        symbolColumn->setObjectName("symbolColumn");
        symbolColumn->setEnabled(false);
        symbolColumn->setStyleSheet(QString::fromUtf8("color:lightgray"));

        horizontalLayout->addWidget(symbolColumn);

        spacer1 = new QSpacerItem(10, 0, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(spacer1);

        priceColumn = new QLabel(frame);
        priceColumn->setObjectName("priceColumn");
        priceColumn->setEnabled(false);
        priceColumn->setStyleSheet(QString::fromUtf8("color:lightgray"));
        priceColumn->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        priceColumn->setMargin(0);
        priceColumn->setIndent(3);

        horizontalLayout->addWidget(priceColumn);

        spacer2 = new QSpacerItem(10, 0, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(spacer2);

        changColumn = new QLabel(frame);
        changColumn->setObjectName("changColumn");
        changColumn->setEnabled(false);
        changColumn->setStyleSheet(QString::fromUtf8("color:lightgray"));
        changColumn->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout->addWidget(changColumn);

        symbolColumn->raise();
        priceColumn->raise();
        changColumn->raise();

        verticalLayout->addWidget(frame);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MiniStocks", nullptr));
        symbolColumn->setText(QCoreApplication::translate("MainWindow", "s", nullptr));
        priceColumn->setText(QCoreApplication::translate("MainWindow", "p", nullptr));
        changColumn->setText(QCoreApplication::translate("MainWindow", "ch", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
