#pragma once
#include "Colors.h"
#include <vector>
#include <memory>
#include <string>

class Surface {
private:
	std::unique_ptr<Color[]> m_Pixels{ nullptr };
	int m_Width{ 0 };
	int m_Height{ 0 };

public:
	Surface(const std::wstring& fileName);
	Surface(int width, int height);
	Surface(const Surface& surface);
	Surface& operator=(const Surface& other);
	~Surface();
	void PutPixel(int x, int y, Color clr);
	Color GetPixel(int x, int y) const;
	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }
};
