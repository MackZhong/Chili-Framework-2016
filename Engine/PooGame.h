#pragma once
#include "Game.h"
#include "MainWindow.h"
#include <gdiplus.h>
#include <time.h>

class PooGame :
	public Game
{
private:
	class Poo {
	public:
		Poo() {
			x = std::rand() % 500 + 100;
			y = std::rand() % 500 + 100;
		}
		Poo(int x, int y) :x(x), y(y) {}
		bool Eaten() const { return eaten; }
		void Eaten(bool eat) { eaten = eat; }
		int X() const { return x; }
		int Y() const { return y; }
	private:
		int x, y;
		bool eaten = false;
	};
	class Dude {
	public:
		Dude() {
			x = std::rand() % 500 + 100;
			y = std::rand() % 500 + 100;
		}
		Dude(int x, int y) : x(x), y(y) {}
		int X() const { return x; }
		int Y() const { return y; }
	private:
		int x, y;
	};
	const int poos = 6;
	std::unique_ptr<Poo[]> m_Poos;
	std::unique_ptr<Dude> m_Dude;
	std::unique_ptr<Gdiplus::Bitmap> m_PooData;
	std::unique_ptr<Gdiplus::Bitmap> m_DudeData;
	ULONG_PTR           gdiplusToken;

	void DrawPoo(const Poo& poo);
	void DrawDude();

	Gdiplus::Bitmap* LoadData(const wchar_t* bmpFile) const;

public:
	PooGame(MainWindow& wnd) : Game(wnd) {
		using namespace Gdiplus;
		GdiplusStartupInput gdiplusStartupInput;
		GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

		std::srand((unsigned)time(NULL));
		m_Dude = std::make_unique<Dude>();
		m_Poos = std::make_unique<Poo[]>(poos);
		m_PooData = std::unique_ptr<Gdiplus::Bitmap>(LoadData(L"poo.bmp"));
		m_DudeData = std::unique_ptr<Gdiplus::Bitmap>(LoadData(L"awsom.bmp"));
	};

	~PooGame() {
		Gdiplus::GdiplusShutdown(gdiplusToken);
	}

	// Í¨¹ý Game ¼Ì³Ð
	virtual void ComposeFrame() override;
	virtual void UpdateModel() override;
};

