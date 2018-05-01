#include "ChiliWin.h"
#include "PooGame.h"
#include <gdiplus.h>
#include <comdef.h>
#pragma comment(lib, "Gdiplus.lib")

void PooGame::DrawPoo(const Poo & poo)
{
	Gdiplus::Color alphakey(255, 255, 255);
	Gdiplus::Color pixel;

	for (UINT y = 0; y < m_PooData->GetHeight(); y++)
	{
		for (UINT x = 0; x < m_PooData->GetWidth(); x++)
		{
			m_PooData->GetPixel(x, y, &pixel);
			if (pixel.GetValue() != alphakey.GetValue())
			{
				this->gfx.PutPixel(poo.X() + x, poo.Y() + y, pixel.GetR(), pixel.GetG(), pixel.GetB());
			}
		}
	}
}

void PooGame::DrawDude()
{
	Gdiplus::Color alphakey(255, 0, 255);
	Gdiplus::Color pixel;

	for (UINT y = 0; y < m_DudeData->GetHeight(); y++)
	{
		for (UINT x = 0; x < m_DudeData->GetWidth(); x++)
		{
			m_DudeData->GetPixel(x, y, &pixel);
			if (pixel.GetValue() != alphakey.GetValue())
			{
				this->gfx.PutPixel(m_Dude->X() + x, m_Dude->Y() + y, pixel.GetR(), pixel.GetG(), pixel.GetB());
			}
		}
	}
}

Gdiplus::Bitmap* PooGame::LoadData(const wchar_t * bmpFile) const
{
	Gdiplus::Bitmap bitmap(bmpFile);

	return bitmap.Clone(0, 0, bitmap.GetWidth(), bitmap.GetHeight(), bitmap.GetPixelFormat());
}

void PooGame::ComposeFrame()
{
	DrawDude();
	for (int i = 0; i < poos; i++) {
		if (!m_Poos[i].Eaten()) {
			DrawPoo(m_Poos[i]);
		}
	}
}

void PooGame::UpdateModel()
{
}
