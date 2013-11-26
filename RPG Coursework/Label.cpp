#include "Label.h"

Label::Label() 
{
	height = NULL;
	width = NULL;
	texID = NULL;
	x = NULL;
	y = NULL;
	glGenTextures(1, &texID);
}

Label::Label(float x, float y)
{
	height = NULL;
	width = NULL;
	texID = NULL;
	this->x = x;
	this->y = y;
}

void Label::draw(float x ,float y) 
{
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);

	glBindTexture(GL_TEXTURE_2D, texID); 
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_QUADS);

		glTexCoord2d(0,1);	glVertex3f(x, y, 0.0); 
		glTexCoord2d(1,1);	glVertex3f(x + 0.002f * width, y, 0.0); 
		glTexCoord2d(1,0);	glVertex3f(x + 0.002f * width, y + 0.002f * height, 0.0); 
		glTexCoord2d(0,0);	glVertex3f(x, y + 0.002f * height, 0.0); 

	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void Label::textToTexture(std::string str, TTF_Font * textFont) 
{
	SDL_Surface *stringImage;
	SDL_Color colour = { 255, 255, 255 };
	
	stringImage = TTF_RenderText_Blended(textFont, str.c_str(), colour);

	GLuint colours = stringImage->format->BytesPerPixel;
	GLuint format, internalFormat;
	
	if (colours == 4) {   
		if (stringImage->format->Rmask == 0x000000ff)
			format = GL_RGBA;
		else
			format = GL_BGRA;
	} 
	else{           
		if (stringImage->format->Rmask == 0x000000ff)
			format = GL_RGB;
		else
			format = GL_BGR;
	}

	internalFormat = (colours == 4) ? GL_RGBA : GL_RGB;

	glBindTexture(GL_TEXTURE_2D, texID); 

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_CLAMP);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	height =  stringImage->h;
	width =  stringImage->w;
	
	glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, stringImage->w, stringImage->h, 0, format, GL_UNSIGNED_BYTE, stringImage->pixels);
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);

	SDL_FreeSurface(stringImage);
}

int Label::getHeight() 
{
	return height;
}

int Label::getWidth() 
{
	return width;
}

int Label::getID() 
{
	return texID;
}

Label::~Label() 
{
}