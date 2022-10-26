/********************************************************************************
** Form generated from reading UI file 'inputhyper.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTHYPER_H
#define UI_INPUTHYPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_inputhyper
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;

    void setupUi(QDialog *inputhyper)
    {
        if (inputhyper->objectName().isEmpty())
            inputhyper->setObjectName("inputhyper");
        inputhyper->resize(704, 472);
        buttonBox = new QDialogButtonBox(inputhyper);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(220, 330, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(inputhyper);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(80, 120, 491, 131));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        verticalLayout_2->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName("lineEdit");

        verticalLayout->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName("lineEdit_2");

        verticalLayout->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(layoutWidget);
        lineEdit_3->setObjectName("lineEdit_3");

        verticalLayout->addWidget(lineEdit_3);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(inputhyper);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, inputhyper, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, inputhyper, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(inputhyper);
    } // setupUi

    void retranslateUi(QDialog *inputhyper)
    {
        inputhyper->setWindowTitle(QCoreApplication::translate("inputhyper", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("inputhyper", "Name", nullptr));
        label_2->setText(QCoreApplication::translate("inputhyper", "Link", nullptr));
        label_3->setText(QCoreApplication::translate("inputhyper", "Description", nullptr));
    } // retranslateUi

};

namespace Ui {
    class inputhyper: public Ui_inputhyper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTHYPER_H
