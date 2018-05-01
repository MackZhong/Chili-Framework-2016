/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	MovableGame.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "ChiliWin.h"
#include "MainWindow.h"
#include "MovableGame.h"


void MovableGame::UpdateModel()
{
	if (this->wnd.kbd.KeyIsPressed(VK_LEFT)) {
		m_xMovable--;
	}
	if (this->wnd.kbd.KeyIsPressed(VK_RIGHT)) {
		m_xMovable++;
	}
	if (this->wnd.kbd.KeyIsPressed(VK_UP)) {
		m_yMovable--;
	}
	if (this->wnd.kbd.KeyIsPressed(VK_DOWN)) {
		m_yMovable++;
	}
	if (m_yMovable < 5) {
		m_yMovable = 5;
	}

	m_xMovable = ClampX(m_xMovable);
	m_yMovable = ClampY(m_yMovable);

	this->m_colliding = this->Test(m_xFixed0, m_yFixed0, m_xMovable, m_yMovable) ||
		this->Test(m_xFixed1, m_yFixed1, m_xMovable, m_yMovable) ||
		this->Test(m_xFixed2, m_yFixed2, m_xMovable, m_yMovable) ||
		this->Test(m_xFixed3, m_yFixed3, m_xMovable, m_yMovable);
}

void MovableGame::DrawBox(int x, int y, int r, int g, int b)
{
	this->gfx.PutPixel(x - 5, y - 5, r, g, b);
	this->gfx.PutPixel(x - 5, y - 4, r, g, b);
	this->gfx.PutPixel(x - 5, y - 3, r, g, b);
	this->gfx.PutPixel(x - 4, y - 5, r, g, b);
	this->gfx.PutPixel(x - 3, y - 5, r, g, b);
	this->gfx.PutPixel(x - 5, y + 5, r, g, b);
	this->gfx.PutPixel(x - 5, y + 4, r, g, b);
	this->gfx.PutPixel(x - 5, y + 3, r, g, b);
	this->gfx.PutPixel(x - 4, y + 5, r, g, b);
	this->gfx.PutPixel(x - 3, y + 5, r, g, b);
	this->gfx.PutPixel(x + 5, y - 5, r, g, b);
	this->gfx.PutPixel(x + 5, y - 4, r, g, b);
	this->gfx.PutPixel(x + 5, y - 3, r, g, b);
	this->gfx.PutPixel(x + 4, y - 5, r, g, b);
	this->gfx.PutPixel(x + 3, y - 5, r, g, b);
	this->gfx.PutPixel(x + 5, y + 5, r, g, b);
	this->gfx.PutPixel(x + 5, y + 4, r, g, b);
	this->gfx.PutPixel(x + 5, y + 3, r, g, b);
	this->gfx.PutPixel(x + 4, y + 5, r, g, b);
	this->gfx.PutPixel(x + 3, y + 5, r, g, b);
}

bool MovableGame::Test(int xFixed, int yFixed, int xMovable, int yMovable) const
{
	const int fixed_top = yFixed - 5;
	const int fixed_bottom = yFixed + 5;
	const int fixed_left = xFixed - 5;
	const int fixed_right = xFixed + 5;
	const int movable_top = yMovable - 5;
	const int movable_bottom = yMovable + 5;
	const int movable_left = xMovable - 5;
	const int movable_right = xMovable + 5;

	return (movable_left <= fixed_right &&
		movable_right >= fixed_left &&
		movable_top <= fixed_bottom &&
		movable_bottom >= fixed_top);

	return false;
}

int MovableGame::ClampX(int x)
{
	if (x < 5) {
		return 5;
	}
	if (x > this->gfx.ScreenWidth - 6)
		return this->gfx.ScreenWidth - 6;
	return x;
}

int MovableGame::ClampY(int y)
{
	if (y < 5) {
		return 5;
	}
	if (y > this->gfx.ScreenHeight - 6)
		return this->gfx.ScreenHeight - 6;
	return y;
}

void MovableGame::ComposeFrame()
{
	DrawBox(m_xFixed0, m_yFixed0, 0, 255, 0);
	DrawBox(m_xFixed1, m_yFixed1, 0, 255, 0);
	DrawBox(m_xFixed2, m_yFixed2, 0, 255, 0);
	DrawBox(m_xFixed3, m_yFixed3, 0, 255, 0);

	if (this->m_colliding)
		DrawBox(m_xMovable, m_yMovable, 255, 0, 0);
	else
		DrawBox(m_xMovable, m_yMovable, 255, 255, 255);

}
