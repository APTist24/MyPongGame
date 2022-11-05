#ifndef __LoaderParams__
#define __LoaderParams__

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

	int getX() const { return x; }
	int getY() const { return y; }

	int getWidth() const { return width; }
	int getHeight() const { return height; }

	std::string getTextureID() const { return m_textureID; }

private:
	int x;
	int y;
	int width;
	int height;
	std::string m_textureID;
};
#endif