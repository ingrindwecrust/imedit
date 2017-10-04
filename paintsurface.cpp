#include "paintsurface.h"

PaintSurface::PaintSurface(QWidget *parent): QWidget(parent), m_states(), m_currentRectangle(nullptr)
{
}

void PaintSurface::reset()
{
	for (auto &it: m_states)
		delete it;

	m_states.clear();

	if (m_currentRectangle)
	{
		delete m_currentRectangle;
		m_currentRectangle = nullptr;
	}
}

void PaintSurface::onNew(unsigned int w, unsigned int h)
{
	reset();

//	TODO: pixmap creation
}

void PaintSurface::onLoad(const QString &filename)
{
	reset();

//	TODO: pixmap loading

	emit done("loaded");
}

void PaintSurface::onSave(const QString &filename)
{
//	TODO: pixmap saving

	emit done("saved");
}
