/********************************************************************************
** Form generated from reading UI file 'settingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QAction *actiontest;
    QVBoxLayout *verticalLayout_5;
    QFrame *line_4;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_4;
    QListWidget *savedTickList;
    QVBoxLayout *verticalLayout_4;
    QPushButton *addTickerButton;
    QPushButton *delTickerButton;
    QSpacerItem *verticalSpacer;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName("SettingsDialog");
        SettingsDialog->resize(254, 309);
        actiontest = new QAction(SettingsDialog);
        actiontest->setObjectName("actiontest");
        verticalLayout_5 = new QVBoxLayout(SettingsDialog);
        verticalLayout_5->setObjectName("verticalLayout_5");
        line_4 = new QFrame(SettingsDialog);
        line_4->setObjectName("line_4");
        line_4->setFrameShape(QFrame::Shape::HLine);
        line_4->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_5->addWidget(line_4);

        label_2 = new QLabel(SettingsDialog);
        label_2->setObjectName("label_2");

        verticalLayout_5->addWidget(label_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        savedTickList = new QListWidget(SettingsDialog);
        savedTickList->setObjectName("savedTickList");
        QFont font;
        font.setPointSize(8);
        savedTickList->setFont(font);
        savedTickList->setAutoFillBackground(false);
        savedTickList->setFrameShape(QFrame::StyledPanel);
        savedTickList->setFrameShadow(QFrame::Sunken);
        savedTickList->setLineWidth(1);
        savedTickList->setMidLineWidth(0);
        savedTickList->setDragDropMode(QAbstractItemView::InternalMove);
        savedTickList->setDefaultDropAction(Qt::MoveAction);
        savedTickList->setAlternatingRowColors(true);
        savedTickList->setSelectionMode(QAbstractItemView::MultiSelection);
        savedTickList->setProperty("isWrapping", QVariant(false));
        savedTickList->setLayoutMode(QListView::SinglePass);
        savedTickList->setViewMode(QListView::ListMode);
        savedTickList->setModelColumn(0);
        savedTickList->setUniformItemSizes(false);
        savedTickList->setWordWrap(false);
        savedTickList->setSelectionRectVisible(false);

        horizontalLayout_4->addWidget(savedTickList);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(-1, -1, 0, -1);
        addTickerButton = new QPushButton(SettingsDialog);
        addTickerButton->setObjectName("addTickerButton");
        addTickerButton->setMaximumSize(QSize(30, 30));
        addTickerButton->setToolTipDuration(5);
        addTickerButton->setFlat(false);

        verticalLayout_4->addWidget(addTickerButton);

        delTickerButton = new QPushButton(SettingsDialog);
        delTickerButton->setObjectName("delTickerButton");
        delTickerButton->setMaximumSize(QSize(30, 30));
        delTickerButton->setToolTipDuration(5);

        verticalLayout_4->addWidget(delTickerButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        horizontalLayout_4->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_4);

        line_3 = new QFrame(SettingsDialog);
        line_3->setObjectName("line_3");
        line_3->setFrameShape(QFrame::Shape::HLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_5->addWidget(line_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        okButton = new QPushButton(SettingsDialog);
        okButton->setObjectName("okButton");
        okButton->setToolTipDuration(5);

        horizontalLayout_3->addWidget(okButton);

        cancelButton = new QPushButton(SettingsDialog);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setToolTipDuration(5);

        horizontalLayout_3->addWidget(cancelButton);


        verticalLayout_5->addLayout(horizontalLayout_3);


        retranslateUi(SettingsDialog);
        QObject::connect(actiontest, &QAction::triggered, SettingsDialog, qOverload<>(&QDialog::close));

        addTickerButton->setDefault(false);
        delTickerButton->setDefault(false);
        okButton->setDefault(false);
        cancelButton->setDefault(true);


        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QCoreApplication::translate("SettingsDialog", "Settings", nullptr));
        actiontest->setText(QCoreApplication::translate("SettingsDialog", "test", nullptr));
#if QT_CONFIG(shortcut)
        actiontest->setShortcut(QCoreApplication::translate("SettingsDialog", "Ctrl+T", nullptr));
#endif // QT_CONFIG(shortcut)
        label_2->setText(QCoreApplication::translate("SettingsDialog", "Saved Tickers", nullptr));
#if QT_CONFIG(whatsthis)
        savedTickList->setWhatsThis(QCoreApplication::translate("SettingsDialog", "<html><head/><body><p>This is a list containing all stock tickers to be displayed in the main window. </p><p>You can change the order by dragging items around or add/delete items using the two buttons to the right.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(tooltip)
        addTickerButton->setToolTip(QCoreApplication::translate("SettingsDialog", "Add a ticker", nullptr));
#endif // QT_CONFIG(tooltip)
        addTickerButton->setText(QCoreApplication::translate("SettingsDialog", "+", nullptr));
#if QT_CONFIG(shortcut)
        addTickerButton->setShortcut(QCoreApplication::translate("SettingsDialog", "+", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        delTickerButton->setToolTip(QCoreApplication::translate("SettingsDialog", "Delete selected ticker(s)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        delTickerButton->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        delTickerButton->setText(QCoreApplication::translate("SettingsDialog", "-", nullptr));
#if QT_CONFIG(shortcut)
        delTickerButton->setShortcut(QCoreApplication::translate("SettingsDialog", "-", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        okButton->setToolTip(QCoreApplication::translate("SettingsDialog", "Save changes and close window", nullptr));
#endif // QT_CONFIG(tooltip)
        okButton->setText(QCoreApplication::translate("SettingsDialog", "OK", nullptr));
#if QT_CONFIG(tooltip)
        cancelButton->setToolTip(QCoreApplication::translate("SettingsDialog", "Close window without saving", nullptr));
#endif // QT_CONFIG(tooltip)
        cancelButton->setText(QCoreApplication::translate("SettingsDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H
