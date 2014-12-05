#pragma once
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>

#include <string>

#include "Vec.h"

class Sprite {
public:
	Sprite(std::string resLocation);
	virtual ~Sprite();

	void ReloadImage();
	Vec2D GetSize();
	ALLEGRO_BITMAP* GetSprite();
private:
	ALLEGRO_BITMAP* sourceImage;
	Vec2D size;
	bool isImageLoaded;
	std::string pathToImage;

	bool LoadImageFile();
	void GenErrorImage();
};

