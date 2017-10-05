#pragma once

#include <QDialog>

#include <QDialogButtonBox>
#include <QSpinBox>

class NewDialog: QDialog
{
	Q_OBJECT

public:
	NewDialog(QWidget *parent = nullptr);

private:
	QSpinBox *m_wfield, *m_hfield;
	QDialogButtonBox *m_okcancel;
};
