#pragma once

#include <GL/glew.h>
#include <SDL_ttf.h>
#include <gl\GL.h>
#include <string>

class Label 
{
	public:

	Label();
	~Label();
	Label(float, float);
		int getHeight();
		int getWidth();
		int getID();
		
		void textToTexture(std::string, TTF_Font *);
		void draw(float, float);

	private:
		float x;
		float y;
		GLuint texID;
		GLuint height;
		GLuint width;
};