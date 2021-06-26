#pragma once
#include "boton.h"
#include <string>
#ifndef BOTONMG3_H
#define BOTONMG3_H

class btnmg3 :public BTN
{
public:

	bool is_avalible = false;
	std::string direction_x = "./resource/MG3T/x.bmp";
	std::string direction_o = "./resource/MG3T/o.bmp";
	int sign = 0;
	SDL_Renderer* r;

	btnmg3(int posx, int posy, int width, int height, SDL_Renderer* r) :BTN() {

		this->r = r;

		btnsurface = SDL_LoadBMP("./");
		btntexture = SDL_CreateTextureFromSurface(r, btnsurface);
		positonAndSize = { posx,posy,width,height };
		is_avalible = true;
	}


	void Re_Create(int signal)
	{
		sign = signal;
		SDL_DestroyTexture(btntexture);
		SDL_FreeSurface(btnsurface);

		if (signal == 1)
		{
			btnsurface = SDL_LoadBMP(direction_x.c_str());
			btntexture = SDL_CreateTextureFromSurface(r, btnsurface);
			is_avalible = false;
		}
		if (signal == 2)
		{
			btnsurface = SDL_LoadBMP(direction_o.c_str());
			btntexture = SDL_CreateTextureFromSurface(r, btnsurface);
			is_avalible = false;
		}
	}


	void Clear()
	{

		sign = 0;
		SDL_DestroyTexture(btntexture);
		SDL_FreeSurface(btnsurface);


		btnsurface = SDL_LoadBMP("./");
		btntexture = SDL_CreateTextureFromSurface(r, btnsurface);
		is_avalible = true;
	}
};



#endif // !BOTONMG3_H
