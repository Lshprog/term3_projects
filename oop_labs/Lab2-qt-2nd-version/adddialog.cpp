
#include "adddialog.h"

#include <QtWidgets>

//! [0]
AddDialog::AddDialog(QWidget *parent)
    : QDialog(parent),
      nameText(new QLineEdit),
      linkText(new QLineEdit),
      descriptionText(new QTextEdit)
{
    auto nameLabel = new QLabel(tr("Name"));
    auto linkLabel = new QLabel(tr("Link"));
    auto descriptionLabel = new QLabel(tr("Description"));
    auto okButton = new QPushButton(tr("OK"));
    auto cancelButton = new QPushButton(tr("Cancel"));

    auto gLayout = new QGridLayout;
    gLayout->setColumnStretch(1, 3);
    gLayout->addWidget(nameLabel, 0, 0);
    gLayout->addWidget(nameText, 0, 1);

    gLayout->setColumnStretch(1,3);
    gLayout->addWidget(linkLabel,1,0);
    gLayout->addWidget(linkText,1,1);


    gLayout->addWidget(descriptionLabel, 2, 0, Qt::AlignLeft|Qt::AlignTop);
    gLayout->addWidget(descriptionText, 2, 1, Qt::AlignLeft);

    auto buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    gLayout->addLayout(buttonLayout, 2, 1, Qt::AlignRight);

    auto mainLayout = new QVBoxLayout;
    mainLayout->addLayout(gLayout);
    setLayout(mainLayout);

    connect(okButton, &QAbstractButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QAbstractButton::clicked, this, &QDialog::reject);

    setWindowTitle(tr("Add a Hyperlink"));
}

QString AddDialog::name() const
{
    return nameText->text();
}

QString AddDialog::link() const{
    return QString("<a href=\"%1\">%1</a>").arg(linkText->text());
}

QString AddDialog::description() const
{
    return descriptionText->toPlainText();
}

void AddDialog::editAddress(const QString &name,const QString &link, const QString &description)
{
    nameText->setReadOnly(true);
    nameText->setText(name);
    linkText->setText(link);
    descriptionText->setPlainText(description);
}
//! [0]
