/********************************************************************************
** Form generated from reading UI file 'connectionWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTIONWIDGET_H
#define UI_CONNECTIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConnectionWidget
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_1;
    QLineEdit *userName;
    QLabel *label_2;
    QLineEdit *password;
    QCheckBox *outline;
    QPushButton *connection;
    QPushButton *connectionWithoutId;

    void setupUi(QWidget *ConnectionWidget)
    {
        if (ConnectionWidget->objectName().isEmpty())
            ConnectionWidget->setObjectName(QStringLiteral("ConnectionWidget"));
        ConnectionWidget->resize(251, 162);
        ConnectionWidget->setMinimumSize(QSize(0, 0));
        ConnectionWidget->setAutoFillBackground(true);
        formLayoutWidget = new QWidget(ConnectionWidget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 10, 231, 71));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_1 = new QLabel(formLayoutWidget);
        label_1->setObjectName(QStringLiteral("label_1"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_1);

        userName = new QLineEdit(formLayoutWidget);
        userName->setObjectName(QStringLiteral("userName"));

        formLayout->setWidget(0, QFormLayout::FieldRole, userName);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        password = new QLineEdit(formLayoutWidget);
        password->setObjectName(QStringLiteral("password"));
        password->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText|Qt::ImhSensitiveData);
        password->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, password);

        outline = new QCheckBox(formLayoutWidget);
        outline->setObjectName(QStringLiteral("outline"));

        formLayout->setWidget(2, QFormLayout::FieldRole, outline);

        connection = new QPushButton(ConnectionWidget);
        connection->setObjectName(QStringLiteral("connection"));
        connection->setGeometry(QRect(70, 90, 101, 23));
        connectionWithoutId = new QPushButton(ConnectionWidget);
        connectionWithoutId->setObjectName(QStringLiteral("connectionWithoutId"));
        connectionWithoutId->setGeometry(QRect(70, 120, 101, 23));

        retranslateUi(ConnectionWidget);

        QMetaObject::connectSlotsByName(ConnectionWidget);
    } // setupUi

    void retranslateUi(QWidget *ConnectionWidget)
    {
        ConnectionWidget->setWindowTitle(QApplication::translate("ConnectionWidget", "Connexion", 0));
        label_1->setText(QApplication::translate("ConnectionWidget", "Username", 0));
        label_2->setText(QApplication::translate("ConnectionWidget", "Password", 0));
        outline->setText(QApplication::translate("ConnectionWidget", "Mode Hors Ligne", 0));
        connection->setText(QApplication::translate("ConnectionWidget", "Connexion", 0));
        connectionWithoutId->setText(QApplication::translate("ConnectionWidget", "Ne pas s'identifier", 0));
    } // retranslateUi

};

namespace Ui {
    class ConnectionWidget: public Ui_ConnectionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTIONWIDGET_H
