
#pragma once
#ifndef _C_SDL_H
#define _C_SDL_H


#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
#include <SDL_ttf.h>
#include <stdio.h>
#include <cstring>
#include <cmath>
#include <iostream>

#include <filesystem>


using std::cin;
using std::cout;

/*
*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, SDL_ttf, SDL_mixer, standard IO, math, and strings



//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Texture wrapper class
class LTexture
{
public:
	//Initializes variables
	LTexture();

	//Deallocates memory
	~LTexture();

	//Loads image at specified path
	virtual bool loadFromFile(std::string path) = 0;

	virtual bool loadFromFile_sub(std::string path) = 0;

#ifdef _SDL_TTF_H
	//Creates image from font string
	virtual bool loadFromRenderedText(std::string textureText, SDL_Color textColor) = 0;

	virtual bool loadFromRenderedText_sub(std::string textureText, SDL_Color textColor) = 0;
#endif

	//Deallocates texture
	virtual void free()=0;

	virtual void free_sub()=0;

	//Set color modulation
	virtual void setColor(Uint8 red, Uint8 green, Uint8 blue) = 0;

	virtual void setColor_sub(Uint8 red, Uint8 green, Uint8 blue) = 0;

	//Set blending
	virtual void setBlendMode(SDL_BlendMode blending) = 0;

	virtual void setBlendMode_sub(SDL_BlendMode blending) = 0;

	//Set alpha modulation
	virtual void setAlpha(Uint8 alpha) = 0;

	virtual void setAlpha_sub(Uint8 alpha) = 0;

	void createWindow();

	void createRenderer();

	//Renders texture at given point
	virtual void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE) =0;

	virtual void render_sub(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE) = 0;
	//Gets image dimensions
	
	SDL_Window* getWindow();

	SDL_Renderer* getRenderer();

	
	void clearWindow();

	void clearRenderer();


	//Starts up SDL and creates window
	bool init();


	//Frees media and shuts down SDL
	void endSDL();

protected:
	//The window we'll be rendering to
	SDL_Window* gWindow = NULL;

	//The window renderer
	SDL_Renderer* gRenderer = NULL;


private:
	//The actual hardware texture
	SDL_Texture* mTexture;
	SDL_Texture* sTexture;

	//Image dimensions
	int mWidth;
	int mHeight;

	int sWidth;
	int sHeight;


};











#endif _C_SDL_H