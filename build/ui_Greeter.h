/********************************************************************************
** Form generated from reading UI file 'Greeter.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GREETER_H
#define UI_GREETER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Greeter
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *layoutInput;
    QLineEdit *inputName;
    QPushButton *buttonGreet;
    QLabel *labelOut;
    QWidget *centralwidget;
    QLabel *label;

    void setupUi(QWidget *Greeter)
    {
        if (Greeter->objectName().isEmpty())
            Greeter->setObjectName(QString::fromUtf8("Greeter"));
        Greeter->resize(320, 240);
        verticalLayout = new QVBoxLayout(Greeter);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        layoutInput = new QHBoxLayout();
        layoutInput->setObjectName(QString::fromUtf8("layoutInput"));
        inputName = new QLineEdit(Greeter);
        inputName->setObjectName(QString::fromUtf8("inputName"));
        inputName->setClearButtonEnabled(false);

        layoutInput->addWidget(inputName);

        buttonGreet = new QPushButton(Greeter);
        buttonGreet->setObjectName(QString::fromUtf8("buttonGreet"));

        layoutInput->addWidget(buttonGreet);


        verticalLayout->addLayout(layoutInput);

        labelOut = new QLabel(Greeter);
        labelOut->setObjectName(QString::fromUtf8("labelOut"));

        verticalLayout->addWidget(labelOut);

        centralwidget = new QWidget(Greeter);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(300, 160, 211, 231));
        label->setPixmap(QPixmap(QString::fromUtf8("../src/22158.png")));

        verticalLayout->addWidget(centralwidget);


        retranslateUi(Greeter);

        QMetaObject::connectSlotsByName(Greeter);
    } // setupUi

    void retranslateUi(QWidget *Greeter)
    {
        Greeter->setWindowTitle(QCoreApplication::translate("Greeter", "Step 3", nullptr));
        inputName->setInputMask(QString());
        inputName->setText(QString());
        buttonGreet->setText(QCoreApplication::translate("Greeter", "Saludar", nullptr));
        labelOut->setText(QCoreApplication::translate("Greeter", "Ingrese un nombre", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Greeter: public Ui_Greeter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GREETER_H
