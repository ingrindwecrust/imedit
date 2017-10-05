#include "newdialog.h"

#include <QFrame>
#include <QLabel>

#include <QVBoxLayout>
#include <QHBoxLayout>

NewDialog::NewDialog(QWidget *parent): QDialog(parent)
{
	m_wfield = new QSpinBox;
	m_hfield = new QSpinBox;

	QVBoxLayout *fieldLayout = new QVBoxLayout;

	{
		QHBoxLayout *box = new QHBoxLayout;

		box->addWidget(new QLabel("width:"));
		box->addWidget(m_wfield);
		box->addWidget(new QLabel("px"));

		fieldLayout->addLayout(box);
	}

	{
		QHBoxLayout *box = new QHBoxLayout;

		box->addWidget(new QLabel("height:"));
		box->addWidget(m_hfield);
		box->addWidget(new QLabel("px"));

		fieldLayout->addLayout(box);
	}

	QFrame *fieldsFrame = new QFrame;
	fieldsFrame->setFrameShape(QFrame::StyledPanel);
	fieldsFrame->setLayout(fieldLayout);

	m_okcancel = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
	connect(m_okcancel, &QDialogButtonBox::accepted, this, &QDialog::accept);
	connect(m_okcancel, &QDialogButtonBox::rejected, this, &QDialog::reject);

	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addWidget(fieldsFrame);
	mainLayout->addWidget(m_okcancel);
	setLayout(mainLayout);
}
