#pragma once

#include "boton.h"
#include <string>
#ifndef BOTONMG2_H
#define NOTONMG2_H


class botonmg22 :public BTN
{
public:

	bool is_visible = false;
	bool is_avalible = false;
	std::string direction_letter = "./resource/MG2L/";
	std::string direction_vacio = "./resource/MG2L/vacio.bmp";
	std::string letter = "";


	botonmg22(int posx, int posy, int width, int height, SDL_Renderer* r, const char* leter) :BTN()
	{
		this->letter = leter;
		direction_letter += *leter;
		direction_letter += ".bmp\0";
		urlimg_c = direction_vacio.c_str();
		btnsurface = SDL_LoadBMP(urlimg_c);
		btntexture = SDL_CreateTextureFromSurface(r, btnsurface);
		positonAndSize = { posx,posy,width,height };
		is_avalible = true;

		if (leter == "0")
		{
			is_avalible = false;

		}

	}


	void resetsurface(SDL_Renderer* r)
	{
		SDL_FreeSurface(btnsurface);
		SDL_DestroyTexture(btntexture);
		btnsurface = SDL_LoadBMP(urlimg_c);
		btntexture = SDL_CreateTextureFromSurface(r, btnsurface);

	}
private:

};

#endif // !
