/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	MovableGame.h																				  *
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
#pragma once

#include "Game.h"

class MovableGame : public Game
{
public:
	MovableGame(class MainWindow& wnd) : Game(wnd) {
	};
	MovableGame(const MovableGame&) = delete;
	MovableGame& operator=(const MovableGame&) = delete;

protected:
	/********************************/
	/*  User Functions              */
	/********************************/
	virtual void ComposeFrame() override;
	virtual void UpdateModel() override;
	void DrawBox(int x, int y, int r, int g, int b);
	bool Test(int xFixed, int yFixed, int xMovable, int yMovable) const;
	int ClampX(int x);
	int ClampY(int y);

private:
	/********************************/
	/*  User Variables              */
	/********************************/
	bool m_colliding = false;
	int m_xFixed0 = 340, m_yFixed0 = 260;
	int m_xFixed1 = 460, m_yFixed1 = 260;
	int m_xFixed2 = 340, m_yFixed2 = 340;
	int m_xFixed3 = 460, m_yFixed3 = 340;
	int m_xMovable = 400, m_yMovable = 300;
};