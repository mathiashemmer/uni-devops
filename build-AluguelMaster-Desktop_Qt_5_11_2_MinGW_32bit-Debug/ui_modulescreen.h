/********************************************************************************
** Form generated from reading UI file 'modulescreen.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODULESCREEN_H
#define UI_MODULESCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>

QT_BEGIN_NAMESPACE

class Ui_ModuleScreen
{
public:
    QGroupBox *groupBox;
    QSplitter *splitter;
    QPushButton *pbtn_Veiculos;
    QPushButton *p;
    QPushButton *pbtn_Financeiro;
    QPushButton *pbtn_Contratos;
    QPushButton *pbtn_Funcionarios;

    void setupUi(QDialog *ModuleScreen)
    {
        if (ModuleScreen->objectName().isEmpty())
            ModuleScreen->setObjectName(QStringLiteral("ModuleScreen"));
        ModuleScreen->resize(750, 461);
        groupBox = new QGroupBox(ModuleScreen);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 711, 121));
        splitter = new QSplitter(groupBox);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(90, 20, 541, 91));
        splitter->setOrientation(Qt::Horizontal);
        pbtn_Veiculos = new QPushButton(splitter);
        pbtn_Veiculos->setObjectName(QStringLiteral("pbtn_Veiculos"));
        splitter->addWidget(pbtn_Veiculos);
        p = new QPushButton(splitter);
        p->setObjectName(QStringLiteral("p"));
        splitter->addWidget(p);
        pbtn_Financeiro = new QPushButton(splitter);
        pbtn_Financeiro->setObjectName(QStringLiteral("pbtn_Financeiro"));
        splitter->addWidget(pbtn_Financeiro);
        pbtn_Contratos = new QPushButton(splitter);
        pbtn_Contratos->setObjectName(QStringLiteral("pbtn_Contratos"));
        splitter->addWidget(pbtn_Contratos);
        pbtn_Funcionarios = new QPushButton(splitter);
        pbtn_Funcionarios->setObjectName(QStringLiteral("pbtn_Funcionarios"));
        splitter->addWidget(pbtn_Funcionarios);

        retranslateUi(ModuleScreen);

        QMetaObject::connectSlotsByName(ModuleScreen);
    } // setupUi

    void retranslateUi(QDialog *ModuleScreen)
    {
        ModuleScreen->setWindowTitle(QApplication::translate("ModuleScreen", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("ModuleScreen", "M\303\263dulos", nullptr));
        pbtn_Veiculos->setText(QApplication::translate("ModuleScreen", "Veiculos", nullptr));
        p->setText(QApplication::translate("ModuleScreen", "Clientes", nullptr));
        pbtn_Financeiro->setText(QApplication::translate("ModuleScreen", "Financeiro", nullptr));
        pbtn_Contratos->setText(QApplication::translate("ModuleScreen", "Contratos", nullptr));
        pbtn_Funcionarios->setText(QApplication::translate("ModuleScreen", "Funcionarios", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModuleScreen: public Ui_ModuleScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODULESCREEN_H
