#pragma once
#include "main.h"



int main(int argc, char* args[])
{


	//Start up SDL and create window
	if (!gTextTexture.init())
	{
		printf("Failed to initialize!\n");
		//test for errors

		//cin.get();
	}
	else
	{
		//Load media
		if (!gTextTexture.loadMedia())
		{
		
			
			printf("Failed to load media!\n");
		//test for errors
			//cin.get();
		}
		else
		{

			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;


			//While application is running
			while (!quit)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					if(gTextTexture.mainEvent(e)){



					}

					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}


				//Clear screen
				SDL_SetRenderDrawColor(gTextTexture.getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gTextTexture.getRenderer());

				//Render current frame

				gTextTexture.renderBackground();

				// text 1
				gTextTexture.render(((SCREEN_WIDTH / 2) - gTextTexture.getWidth()) / 2, (SCREEN_HEIGHT - gTextTexture.getHeight()) / 2);
				//  text 2


				gTextTexture.render_sub((((SCREEN_WIDTH / 2) - gTextTexture.getWidth()) / 2) + (SCREEN_WIDTH / 2), (SCREEN_HEIGHT - gTextTexture.getHeight()) / 2);





				//Update screen
				SDL_RenderPresent(gTextTexture.getRenderer());
			}
		}
	}

	//Free resources and close SDL
	//cin.get does nothing
	cin.get();
	
	gTextTexture.endSDL();

	return 0;
}