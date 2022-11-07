#pragma once

#include <string>

class LoaderParams
{
public:
	LoaderParams(	int x_, int y_,
					int width_, int height_,
					std::string textureID) : x(x_), y(y_),
											 width(width_), height(height_),
											 m_textureID(textureID) 
	{}

	const int& getX() const { return x; }
	const int& getY() const { return y; }

	const int& getWidth() const { return width; }
	const int& getHeight() const { return height; }

	const std::string& getTextureID() const { return m_textureID; }

private:
	int x;
	int y;
	int width;
	int height;
	std::string m_textureID;
};
