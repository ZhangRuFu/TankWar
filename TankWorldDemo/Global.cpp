#include "Global.h"

Vector2D::Vector2D(int x, int y)
{
	m_x = x;
	m_y = y;
}

void Vector2D::AddX(int delta)
{
	if (delta <= 0)
		return;
	m_x += delta;
}

void Vector2D::AddY(int delta)
{
	if (delta <= 0)
		return;
	m_y += delta;
}

void Vector2D::ReduceX(int delta)
{
	if (delta <= 0)
		return;
	m_x -= delta;
}

void Vector2D::ReduceY(int delta)
{
	if (delta <= 0)
		return;
	m_y -= delta;
}

bool Vector2D::operator==(Vector2D &another)
{
	if (m_x == another.m_x && m_y == another.m_y)
		return true;
	else
		return false;
}

iRect::iRect(int x, int y, int width, int height)
{
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
}

iRect::operator RECT(void)
{
	RECT rect;
	rect.left = m_x;
	rect.right = m_x + m_width - 1;
	rect.top = m_y;
	rect.bottom = m_y + m_height - 1;

	return rect;
}
