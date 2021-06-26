#pragma once
#ifndef BOTON_H
#define BOTON_H

#include "SDL.h"

class BTN
{
public:
	const char* urlimg_c = 0;
	int posy = 0;
	int width = 0;
	int height = 0;
	int no_respuesta = 0;

	SDL_Renderer* r = NULL;
	SDL_Surface* btnsurface;
	SDL_Texture* btntexture;
	SDL_Rect positonAndSize;

	BTN(int posx, int posy, int width, int height, SDL_Renderer* r, const char* urlimg)
	{
		urlimg_c = urlimg;
		btnsurface = SDL_LoadBMP(urlimg_c);
		btntexture = SDL_CreateTextureFromSurface(r, btnsurface);
		positonAndSize = { posx,posy,width,height };


	}


	BTN(int posx, int posy, int width, int height, SDL_Renderer* r, const char* urlimg, int respuesta)
	{

		urlimg_c = urlimg;
		btnsurface = SDL_LoadBMP(urlimg_c);
		btnsurface = SDL_LoadBMP(urlimg);
		btntexture = SDL_CreateTextureFromSurface(r, btnsurface);
		positonAndSize = { posx,posy,width,height };
		no_respuesta = respuesta;

	}

	BTN() {};



private:

};



#endif // !BOTON_H
