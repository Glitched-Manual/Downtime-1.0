
#pragma once

#include "main_event.h"



using std::cin;
using std::cout;

std::experimental::filesystem::path direct_path = std::experimental::filesystem::current_path();

std::string folder_path = direct_path.u8string();

char* chr_folder_path = const_cast<char*>(folder_path.c_str());




//The music that will be played
Mix_Music *gMusic = NULL;

//The sound effects that will be used
Mix_Chunk *gScratch = NULL;
Mix_Chunk *gHigh = NULL;
Mix_Chunk *gMedium = NULL;
Mix_Chunk *gLow = NULL;


//Globally used font
TTF_Font *gFont = NULL;
TTF_Font *lFont = NULL;




SDL_Texture* background_image = NULL;

std::string background_image_path = (folder_path + "/resources/image/svw_background.jpeg");


MainTexture::MainTexture()
{
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;

	//Initialize
	sTexture = NULL;
	sWidth = 0;
	sHeight = 0;
}

MainTexture::~MainTexture()
{
	//Deallocate
	free();
}

bool MainTexture::loadFromFile(std::string path)
{
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface((*this).getRenderer(), loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}


bool MainTexture::loadFromFile_sub(std::string path)
{
	//Get rid of preexisting texture
	free_sub();

	//The final texture
	SDL_Texture* nuevoTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface_sub = IMG_Load(path.c_str());
	if (loadedSurface_sub == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Color key image
		SDL_SetColorKey(loadedSurface_sub, SDL_TRUE, SDL_MapRGB(loadedSurface_sub->format, 0, 0xFF, 0xFF));

		//Create texture from surface pixels
		nuevoTexture = SDL_CreateTextureFromSurface((*this).getRenderer(), loadedSurface_sub);
		if (nuevoTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			//Get image dimensions
			sWidth = loadedSurface_sub->w;
			sHeight = loadedSurface_sub->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface_sub);
	}

	//Return success
	sTexture = nuevoTexture;
	return sTexture != NULL;
}

#ifdef _SDL_TTF_H


// load main text

bool MainTexture::loadFromRenderedText(std::string textureText, SDL_Color textColor)
{
	//Get rid of preexisting texture
	free();

	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
	if (textSurface != NULL)
	{
		//Create texture from surface pixels
		mTexture = SDL_CreateTextureFromSurface((*this).getRenderer(), textSurface);
		if (mTexture == NULL)
		{
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get image dimensions
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface(textSurface);
	}
	else
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}


	//Return success
	return mTexture != NULL;

}
bool MainTexture::loadFromRenderedText_sub(std::string textureText_sub, SDL_Color textColor)
{
	//Get rid of preexisting texture
	free_sub();

	//Render text surface
	SDL_Surface* textSurface_sub = TTF_RenderText_Solid(gFont, textureText_sub.c_str(), textColor);
	if (textSurface_sub != NULL)
	{
		//Create texture from surface pixels
		sTexture = SDL_CreateTextureFromSurface((*this).getRenderer(), textSurface_sub);
		if (sTexture == NULL)
		{
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get image dimensions
			sWidth = textSurface_sub->w;
			sHeight = textSurface_sub->h;
		}

		//Get rid of old surface
		SDL_FreeSurface(textSurface_sub);
	}
	else
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}


	//Return success
	return sTexture != NULL;
}

#endif

void MainTexture::free()
{
	//Free texture if it exists
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void MainTexture::free_sub()
{
	//Free texture if it exists
	if (sTexture != NULL)
	{
		SDL_DestroyTexture(sTexture);
		sTexture = NULL;
		sWidth = 0;
		sHeight = 0;
	}
}

void MainTexture::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	//Modulate texture rgb
	SDL_SetTextureColorMod(mTexture, red, green, blue);
}

// sub

void MainTexture::setColor_sub(Uint8 red, Uint8 green, Uint8 blue)
{
	//Modulate texture rgb
	SDL_SetTextureColorMod(sTexture, red, green, blue);
}

void MainTexture::setBlendMode(SDL_BlendMode blending)
{
	//Set blending function
	SDL_SetTextureBlendMode(mTexture, blending);
}


void MainTexture::setBlendMode_sub(SDL_BlendMode blending)
{
	//Set blending function
	SDL_SetTextureBlendMode(sTexture, blending);
}

void MainTexture::setAlpha(Uint8 alpha)
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod(mTexture, alpha);
}

//sub

void MainTexture::setAlpha_sub(Uint8 alpha)
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod(sTexture, alpha);
}

void MainTexture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx((*this).getRenderer(), mTexture, clip, &renderQuad, angle, center, flip);
}


// sub render


void MainTexture::render_sub(int x, int y, SDL_Rect* clip_sub, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad_sub = { x, y, sWidth, sHeight };

	//Set clip rendering dimensions
	if (clip_sub != NULL)
	{
		renderQuad_sub.w = clip_sub->w;
		renderQuad_sub.h = clip_sub->h;
	}

	//Render to screen
	SDL_RenderCopyEx((*this).getRenderer(), sTexture, clip_sub, &renderQuad_sub, angle, center, flip);
}

int MainTexture::getWidth()
{
	return mWidth;
}

int MainTexture::getHeight()
{
	return mHeight;
}

// sub

int MainTexture::getWidth_sub()
{
	return sWidth;
}

int MainTexture::getHeight_sub()
{
	return sHeight;
}
//

void MainTexture::free_Background()
{
	//Free texture if it is present
	if (background_image != NULL)
	{
		SDL_DestroyTexture(background_image);
		background_image = NULL;

	}
}

// load

bool MainTexture::load_Background(std::string background_path) {

	background_image = IMG_LoadTexture((*this).getRenderer(), background_path.c_str());

	if (background_image == NULL) {

		std::cout << "\nError failed to load " << background_path << "\n";

		return false;
	}
	return true;

}


//render

void MainTexture::renderBackground() {



	SDL_Rect background_rect;

	background_rect.x = 0;

	background_rect.y = 0;

	background_rect.w = SCREEN_WIDTH;

	background_rect.h = SCREEN_HEIGHT;



	SDL_RenderCopy(this->getRenderer(), background_image, NULL, &background_rect);

}




bool MainTexture::loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load prompt texture

	//Load music

	/*

	uses relative location from the directory recorded in folder_path

	should work anywhere
	*/

	// because you cannot add char pointers

	std::string music_path = folder_path + "/resources/audio/Greenday - 21 Guns.mp3";



	char* chr_music_path = const_cast<char*>(music_path.c_str());

	gMusic = Mix_LoadMUS(chr_music_path);
	if (gMusic == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	//Load sound effects

	std::string scratch_path = folder_path + "/resources/audio/scratch.wav";

	char* chr_scratch_path = const_cast<char*>(scratch_path.c_str());

	gScratch = Mix_LoadWAV(chr_scratch_path);
	if (gScratch == NULL)
	{
		printf("Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}


	std::string high_path = folder_path + "/resources/audio/high.wav";

	char* chr_high_path = const_cast<char*>(high_path.c_str());


	gHigh = Mix_LoadWAV(chr_high_path);
	if (gHigh == NULL)
	{
		printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	std::string medium_path = folder_path + "/resources/audio/medium.wav";

	char* chr_medium_path = const_cast<char*>(medium_path.c_str());

	gMedium = Mix_LoadWAV(chr_medium_path);
	if (gMedium == NULL)
	{


		printf("Failed to load medium sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	std::string low_path = folder_path + "/resources/audio/low.wav";



	char* chr_low_path = const_cast<char*>(low_path.c_str());

	gLow = Mix_LoadWAV(chr_low_path);
	if (gLow == NULL)
	{
		printf("Failed to load low sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}


	//Open the font
	std::string font_path = folder_path + "/resources/image/lazy.ttf";

	char* chr_font_path = const_cast<char*>(font_path.c_str());

	gFont = TTF_OpenFont(chr_font_path, 48);
	if (gFont == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	else
	{
		//Render text 1
		SDL_Color textColor = { 0, 0, 0 };
		if (!this->loadFromRenderedText("Work", textColor))
		{
			printf("Failed to render text texture! -Render text 1\n");
			success = false;
		}

		//Render text 2
		SDL_Color textColor_sub = { 0, 0, 0 };
		if (!this->loadFromRenderedText_sub("Play", textColor_sub))
		{
			printf("Failed to render text texture! -Render text 2\n");
			success = false;
		}

	}

	//loads background needs to be here

	if (this->load_Background(background_image_path)) {


	}


	return success;
}

void MainTexture::close()
{
	//Free loaded images


	this->free();
	this->free_sub();

	//Free the sound effects
	Mix_FreeChunk(gScratch);
	Mix_FreeChunk(gHigh);
	Mix_FreeChunk(gMedium);
	Mix_FreeChunk(gLow);
	gScratch = NULL;
	gHigh = NULL;
	gMedium = NULL;
	gLow = NULL;

	//Free the music
	Mix_FreeMusic(gMusic);
	gMusic = NULL;

	//Destroy window	
	SDL_DestroyRenderer((*this).getRenderer());
	SDL_DestroyWindow((*this).getWindow());
	this->clearRenderer();
	this->clearWindow();

	//Quit SDL subsystems
	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();

}

bool MainTexture::triggerMouseEvent() {



	int mouse_x;
	int mouse_y;

	SDL_GetMouseState(&mouse_x, &mouse_y);

	//if coordinates match return true and do something

	int textCenter_1_x = ((SCREEN_WIDTH / 2) - (*this).getWidth()) / 2;

	int textCenter_1_y = (SCREEN_HEIGHT - (*this).getHeight()) / 2;

	//  (SCREEN_HEIGHT - gTextTexture.getHeight()) / 2);
	int textCenter_2_x = (((SCREEN_WIDTH / 2) - (*this).getWidth()) / 2) + (SCREEN_WIDTH / 2);
	int textCenter_2_y = (SCREEN_HEIGHT - (*this).getHeight()) / 2;

	// get objects coordinates																																	

	//set links



	if (((mouse_x >= textCenter_1_x) && (mouse_x <= (textCenter_1_x + (*this).getWidth()))) && ((mouse_y >= textCenter_1_y) && (mouse_y <= (textCenter_1_y + (*this).getHeight())))) {

		cout << "\nHit\n";

		//after start and url insert path to chrome or a web browser

		std::string link_1 = "start C:/Program Files(x86)/Google/Chrome/Application/chrome.exe https://www.theodinproject.com/dashboard";

		char* chr_linl_1 = const_cast<char*>(link_1.c_str());

		system(chr_linl_1);

		std::string link_2 = "start C:/Program Files(x86)/Google/Chrome/Application/chrome.exe https://github.com";

		char* chr_link_2 = const_cast<char*>(link_2.c_str());

		system(chr_link_2);

		return true;
	}


	if (((mouse_x >= textCenter_2_x) && (mouse_x <= (textCenter_2_x + (*this).getWidth_sub()))) && ((mouse_y >= textCenter_2_y) && (mouse_y <= (textCenter_2_y + (*this).getHeight_sub()))))
	{
		cout << "\nHit\n";

		std::string youtube_link = "\"start C:/Program Files(x86)/Google/Chrome/Application/chrome.exe https://www.youtube.com\"";

		char* chr_youtube_link = const_cast<char*>(youtube_link.c_str());

		system(chr_youtube_link);

		return true;

	}

	else {


		return false;
	}
}



bool MainTexture::mainEvent(SDL_Event main_event)
{
	bool activated = false;
	//event method
	//Handle events on queue


		//event if click
		//left mouse press == 1025 ,release == 1026
	if (main_event.type == 1026) {

		cout << "\nmouse button pressed\n";

		if ((*this).triggerMouseEvent()) {
			cout << "true";

			activated = true;

		}


	}


	//Handle key press
	else if (main_event.type == SDL_KEYDOWN)
	{
		switch (main_event.key.keysym.sym)
		{
			//Play high sound effect
		case SDLK_1:
			Mix_PlayChannel(-1, gHigh, 0);

			activated = true;
			break;

			//Play medium sound effect
		case SDLK_2:
			Mix_PlayChannel(-1, gMedium, 0);

			activated = true;
			break;

			//Play low sound effect
		case SDLK_3:
			Mix_PlayChannel(-1, gLow, 0);

			activated = true;
			break;

			//Play scratch sound effect
		case SDLK_4:
			Mix_PlayChannel(-1, gScratch, 0);
			activated = true;
			break;

		case SDLK_9:
			//If there is no music playing
			if (Mix_PlayingMusic() == 0)
			{
				//Play the music
				Mix_PlayMusic(gMusic, -1);
				activated = true;
			}
			//If music is being played
			else
			{
				//If the music is paused
				if (Mix_PausedMusic() == 1)
				{
					//Resume the music
					Mix_ResumeMusic();
					activated = true;
				}
				//If the music is playing
				else
				{
					//Pause the music
					Mix_PauseMusic();
					activated = true;
				}
			}
			break;

		case SDLK_0:
			//Stop the music
			Mix_HaltMusic();
			activated = true;
			break;
		}
	}

	return activated;
}


void MainTexture::endSDL()
{
	//Quit SDL subsystems
	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();

}



