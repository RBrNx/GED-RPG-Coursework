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

		int getHeight();
		int getWidth();
		int getID();
		
		void textToTexture(std::string, TTF_Font *);
		void draw(float, float);

	private:

		GLuint texID;
		GLuint height;
		GLuint width;
};