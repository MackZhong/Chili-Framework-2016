#include "ChiliWin.h"
#include "Surface.h"
#include <cassert>
#include <fstream>

Surface::Surface(const std::wstring & fileName)
{
	std::ifstream file(fileName, std::ios::binary);
	assert(file);

	BITMAPFILEHEADER bmFileHeader;
	file.read((char*)&bmFileHeader, sizeof(bmFileHeader));

	BITMAPINFOHEADER bmInfoHeader;
	file.read((char*)&bmInfoHeader, sizeof(bmInfoHeader));

	assert(bmInfoHeader.biBitCount == 24 || bmInfoHeader.biBitCount == 32);
	assert(bmInfoHeader.biCompression == BI_RGB);

	m_Width = bmInfoHeader.biWidth;
	m_Height = bmInfoHeader.biHeight;
	m_Pixels = std::make_unique<Color[]>(m_Width * m_Height);

	file.seekg(bmFileHeader.bfOffBits);
	const int padding = (4 - (m_Width * 3) % 4) % 4;

	for (int y = m_Height - 1; y >= 0; y--) {
		for (int x = 0; x < m_Width; x++) {
			Color clr(file.get(), file.get(), file.get());
			if (bmInfoHeader.biBitCount == 32) {
				clr.SetA(file.get());
			}
			this->PutPixel(x, y, clr);
		}
		file.seekg(padding, std::ios::cur);
	}
}

Surface::Surface(int width, int height)
	: m_Width(width)
	, m_Height(height)
	, m_Pixels(std::make_unique<Color[]>(width * height))
{
}

Surface::Surface(const Surface & surface)
	: Surface(surface.m_Width, surface.m_Height)
{
	*this = surface;
}

Surface & Surface::operator=(const Surface & other)
{
	this->m_Width = other.m_Width;
	this->m_Height = other.m_Height;
	this->m_Pixels.release();
	this->m_Pixels = std::make_unique<Color[]>(other.m_Width * other.m_Height);

	for (int p = 0; p < m_Width * m_Height; p++) {
		this->m_Pixels[p] = other.m_Pixels[p];
	}

	return *this;
}

Surface::~Surface()
{
}

void Surface::PutPixel(int x, int y, Color clr)
{
	assert(x >= 0);
	assert(x < m_Width);
	assert(y >= 0);
	assert(y < m_Height);
	m_Pixels[y * m_Width + x] = clr;
}

Color Surface::GetPixel(int x, int y) const
{
	assert(x >= 0);
	assert(x < m_Width);
	assert(y >= 0);
	assert(y < m_Height);
	return m_Pixels[y * m_Width + x];
}