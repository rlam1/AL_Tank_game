#include "Sprite.h"


Sprite::Sprite(std::string resLocation)
{
	pathToImage = resLocation;
	isImageLoaded = LoadImageFile();

	if (!isImageLoaded)
	{
		GenErrorImage();
	}

	size.x = al_get_bitmap_width(sourceImage);
	size.y = al_get_bitmap_height(sourceImage);
}


Sprite::~Sprite()
{
	al_destroy_bitmap(sourceImage);
}


bool Sprite::LoadImageFile()
{
	return false;
}


void Sprite::ReloadImage()
{
}


Vec2D Sprite::GetSize()
{
	return Vec2D();
}
