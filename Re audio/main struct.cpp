//#include "main.cpp"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <iostream>

using std::cin;
using std::cout;


//Globally used font

// music and other audio

// Text Rendering & positions

// Image and  other rendering

// events like buttons


struct position{

    int x;

    int y;
};

struct event{


//audio

char* event_music = "Debug/resources/audio/Greenday - 21 Guns.mp3";

// scratch

char* sfx_1 = "Debug/resources/audio/scratch.wav";

// high

char* sfx_2 = "Debug/resources/audio/high.wav";

//medium

char* sfx_3 = "Debug/resources/audio/medium.wav";


char* sfx_4 = "Debug/resources/audio/low.wav";

//image / texture

//image / texture position


//text


char* text_1

//text font

char* event_font = "Debug/resources/image/lazy.ttf";

//text position

position text_1_position;

text_1_position.x = ((SCREEN_WIDTH /2) - gTextTexture.getWidth() )/2, ;

text_1_position.y = (SCREEN_HEIGHT - gTextTexture.getHeight()) / 2;

position text_2_position;

text_2_position.x = (((SCREEN_WIDTH /2) - gTextTexture.getWidth() )/2) + (SCREEN_WIDTH /2);

text_2_position.y = (SCREEN_HEIGHT - gTextTexture.getHeight()) / 2;
//buttons

void schedule_button();

}Main_event;


void event:: schedule_button(){


int mouse_x;
int mouse_y;

SDL_GetMouseState(&mouse_x,&mouse_y);

//if coordinates match return true and do something

int textCenter_1_x = ((SCREEN_WIDTH /2) - gTextTexture.getWidth() )/2;

int textCenter_1_y =  (SCREEN_HEIGHT - gTextTexture.getHeight() ) / 2;																																					
// get objects coordinates																																	

if(((mouse_x >= textCenter_1_x )&&(mouse_x <= (textCenter_1_x + gTextTexture.getWidth()))) &&( (mouse_y >= textCenter_1_y ) &&  (mouse_y <= (textCenter_1_y + gTextTexture.getHeight())))){

cout << "\nHit\n";

return true;
}
	else{


		return false;
	}

} 