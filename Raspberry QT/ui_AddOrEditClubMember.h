/********************************************************************************
** Form generated from reading UI file 'AddOrEditClubMember.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDOREDITCLUBMEMBER_H
#define UI_ADDOREDITCLUBMEMBER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_AddOrEditClubMember
{
public:

    void setupUi(QDialog *AddOrEditClubMember)
    {
        if (AddOrEditClubMember->objectName().isEmpty())
            AddOrEditClubMember->setObjectName(QString::fromUtf8("AddOrEditClubMember"));
        AddOrEditClubMember->resize(400, 300);

        retranslateUi(AddOrEditClubMember);

        QMetaObject::connectSlotsByName(AddOrEditClubMember);
    } // setupUi

    void retranslateUi(QDialog *AddOrEditClubMember)
    {
        AddOrEditClubMember->setWindowTitle(QCoreApplication::translate("AddOrEditClubMember", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddOrEditClubMember: public Ui_AddOrEditClubMember {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDOREDITCLUBMEMBER_H
