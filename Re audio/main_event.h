
#ifndef MAINEVENT_H
#define MAINEVENT_H


#pragma once


#include "C_SDL.h"



//Texture wrapper class
class MainTexture:public LTexture
{
public:
	//Initializes variables
	MainTexture();

	//Deallocates memory
	~MainTexture();

	//Loads image at specified path
	bool loadFromFile(std::string path);

	bool loadFromFile_sub(std::string path);

#ifdef _SDL_TTF_H
	//Creates image from font string
	bool loadFromRenderedText(std::string textureText, SDL_Color textColor);

	bool loadFromRenderedText_sub(std::string textureText, SDL_Color textColor);

#endif

	void free_Background();

	bool loadMedia();

	//Deallocates texture
	void free();

	void free_sub();

	//Set color modulation
	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	void setColor_sub(Uint8 red, Uint8 green, Uint8 blue);

	//Set blending
	void setBlendMode(SDL_BlendMode blending);

	void setBlendMode_sub(SDL_BlendMode blending);

	//Set alpha modulation
	void setAlpha(Uint8 alpha);

	void setAlpha_sub(Uint8 alpha);

	//Renders texture at given point
	void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void render_sub(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	bool load_Background(std::string background_path);

	void renderBackground();

	//Gets image dimensions
	// mTexture
	int getWidth();
	int getHeight();

	// sTexture

	int getWidth_sub();
	int getHeight_sub();
	bool triggerMouseEvent();
	bool mainEvent(SDL_Event main_event);
	void close();

	void endSDL();

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



#endif