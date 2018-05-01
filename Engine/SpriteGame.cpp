#include "ChiliWin.h"
#include "SpriteGame.h"


SpriteGame::SpriteGame(MainWindow& wnd)
	: Game(wnd)
	, m_Surface(L"marle32x48.bmp")
{
	//for (int y = 0; y < m_Surface.GetHeight(); y++) {
	//	for (int x = 0; x < m_Surface.GetWidth(); x++) {
	//		m_Surface.PutPixel(x, y, Color(
	//			(x - 25)*(x - 25) + (y - 25)*(y - 25),
	//			(x - 50)*(x - 50) + (y - 50)*(y - 50),
	//			(x - 75)*(x - 75) + (y - 75)*(y - 75)
	//			));
	//	}
	//}
}


SpriteGame::~SpriteGame()
{
}

void SpriteGame::ComposeFrame()
{

	this->gfx.DrawSprite({ this->wnd.mouse.GetPosX() - 8, this->wnd.mouse.GetPosY() - 16 },
		{ 32, 64, 48, 96 }, 
		this->gfx.GetRect(),
		m_Surface);
}

void SpriteGame::UpdateModel()
{
}
