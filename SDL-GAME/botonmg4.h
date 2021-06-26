#pragma once
#pragma once

#include "boton.h"
#include <string>
#ifndef BOTONMG4_H
#define NOTONMG4_H


class botonmg4 :public BTN
{
public:

	int answer_n = 0;
	int pos = 0;
	bool is_dragged = false;

	botonmg4(int posx, int posy, int width, int height, SDL_Renderer* r, int ans, std::string direccion) :BTN()
	{

		urlimg_c = direccion.c_str();
		btnsurface = SDL_LoadBMP(urlimg_c);
		btntexture = SDL_CreateTextureFromSurface(r, btnsurface);
		positonAndSize = { posx,posy,width,height };
		answer_n = ans;

	}


private:

};

#endif // !
