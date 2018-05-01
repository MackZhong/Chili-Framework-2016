#pragma once
#include "Game.h"
#include "MainWindow.h"
#include "Surface.h"

class SpriteGame :
	public Game
{
public:
	SpriteGame(MainWindow& wnd);
	SpriteGame(const SpriteGame&) = delete;
	SpriteGame& operator=(const SpriteGame&) = delete;

	~SpriteGame();

	// Í¨¹ý Game ¼Ì³Ð
	virtual void ComposeFrame() override;
	virtual void UpdateModel() override;

private:
	Surface m_Surface;
};

