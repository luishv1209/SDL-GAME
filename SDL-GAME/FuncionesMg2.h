#pragma once
#ifndef FUNC_MG2
#define FUNC_MG2


#include <SDL_ttf.h>
#include <string>
#include<iostream>
#include "boton.h"
#include "botonmg2.h"
#include <vector>
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <SDL_ttf.h>
#include "score.h"
#include "SDL.h"




void CrearLetrasMg2(botonmg22** p1l1, botonmg22** p1l2, botonmg22** p1l3, botonmg22** p1l4, botonmg22** p1l5, botonmg22** p1l6,
    botonmg22** p2l1, botonmg22** p2l2, botonmg22** p2l3, botonmg22** p2l4, botonmg22** p2l5, botonmg22** p2l6,
    botonmg22** p3l1, botonmg22** p3l2, botonmg22** p3l3, botonmg22** p3l4, botonmg22** p3l5, botonmg22** p3l6,
    botonmg22** p4l1, botonmg22** p4l2, botonmg22** p4l3, botonmg22** p4l4, botonmg22** p4l5, botonmg22** p4l6,
    SDL_Renderer* r, int nivel)
{

    //level 1 
    if (nivel == 1)
    {

        *p1l1 = new botonmg22(380, 80, 40, 40, r, "H");
        *p1l2 = new botonmg22(380, (*p1l1)->positonAndSize.y + 42, 40, 40, r, "T");
        *p1l3 = new botonmg22(380, (*p1l2)->positonAndSize.y + 42, 40, 40, r, "M");
        *p1l4 = new botonmg22(380, (*p1l3)->positonAndSize.y + 42, 40, 40, r, "L");
        *p1l5 = new botonmg22(380, (*p1l4)->positonAndSize.y + 42, 40, 40, r, "0");
        *p1l6 = new botonmg22(380, (*p1l5)->positonAndSize.y + 42, 40, 40, r, "0");

        *p2l1 = new botonmg22(254, 164, 40, 40, r, "F");
        *p2l2 = new botonmg22(296, 164, 40, 40, r, "O");
        *p2l3 = new botonmg22(338, 164, 40, 40, r, "R");
        *p2l4 = new botonmg22(380, 164, 40, 40, r, "M");
        *p2l5 = new botonmg22(422, 164, 40, 40, r, "0");
        *p2l6 = new botonmg22(464, 164, 40, 40, r, "0");

        *p3l1 = new botonmg22(100, 250, 40, 40, r, "B");
        *p3l2 = new botonmg22(142, 250, 40, 40, r, "O");
        *p3l3 = new botonmg22(184, 250, 40, 40, r, "D");
        *p3l4 = new botonmg22(226, 250, 40, 40, r, "Y");
        *p3l5 = new botonmg22(268, 250, 40, 40, r, "0");
        *p3l6 = new botonmg22(0, 200, 40, 40, r, "0");

        *p4l1 = new botonmg22(184, 250, 40, 40, r, "D");
        *p4l2 = new botonmg22(184, 292, 40, 40, r, "I");
        *p4l3 = new botonmg22(184, 334, 40, 40, r, "V");
        *p4l4 = new botonmg22(226, 0, 40, 40, r, "0");
        *p4l5 = new botonmg22(226, 0, 40, 40, r, "0");
        *p4l6 = new botonmg22(226, 0, 40, 40, r, "0");

    }
    else if (nivel == 2)
    {

        *p1l1 = new botonmg22(250, 80, 40, 40, r, "H");
        *p1l2 = new botonmg22(250, (*p1l1)->positonAndSize.y + 42, 40, 40, r, "T");
        *p1l3 = new botonmg22(250, (*p1l2)->positonAndSize.y + 42, 40, 40, r, "M");
        *p1l4 = new botonmg22(250, (*p1l3)->positonAndSize.y + 42, 40, 40, r, "L");
        *p1l5 = new botonmg22(250, (*p1l4)->positonAndSize.y + 42, 40, 40, r, "0");
        *p1l6 = new botonmg22(250, (*p1l5)->positonAndSize.y + 42, 40, 40, r, "0");

        *p2l1 = new botonmg22(250, 164, 40, 40, r, "M");
        *p2l2 = new botonmg22(292, 164, 40, 40, r, "Y");
        *p2l3 = new botonmg22(334, 164, 40, 40, r, "S");
        *p2l4 = new botonmg22(376, 164, 40, 40, r, "Q");
        *p2l5 = new botonmg22(418, 164, 40, 40, r, "L");
        *p2l6 = new botonmg22(460, 164, 40, 40, r, "0");

        *p3l1 = new botonmg22(142, 242, 40, 40, r, "J");
        *p3l2 = new botonmg22(184, 242, 40, 40, r, "S");
        *p3l3 = new botonmg22(184, 200, 40, 40, r, "0");
        *p3l4 = new botonmg22(226, 200, 40, 40, r, "0");
        *p3l5 = new botonmg22(268, 200, 40, 40, r, "0");
        *p3l6 = new botonmg22(0, 200, 40, 40, r, "0");

        *p4l1 = new botonmg22(184, 200, 40, 40, r, "C");
        *p4l2 = new botonmg22(184, 242, 40, 40, r, "S");
        *p4l3 = new botonmg22(184, 284, 40, 40, r, "S");
        *p4l4 = new botonmg22(226, 0, 40, 40, r, "0");
        *p4l5 = new botonmg22(226, 0, 40, 40, r, "0");
        *p4l6 = new botonmg22(226, 0, 40, 40, r, "0");





    }
    else if (nivel == 3)
    {

        *p1l1 = new botonmg22(250, 80, 40, 40, r, "M");
        *p1l2 = new botonmg22(250, (*p1l1)->positonAndSize.y + 42, 40, 40, r, "S");
        *p1l3 = new botonmg22(250, (*p1l2)->positonAndSize.y + 42, 40, 40, r, "S");
        *p1l4 = new botonmg22(250, (*p1l3)->positonAndSize.y + 42, 40, 40, r, "Q");
        *p1l5 = new botonmg22(250, (*p1l4)->positonAndSize.y + 42, 40, 40, r, "L");
        *p1l6 = new botonmg22(250, (*p1l5)->positonAndSize.y + 42, 40, 40, r, "0");

        *p2l1 = new botonmg22(250, 80, 40, 40, r, "M");
        *p2l2 = new botonmg22(292, 80, 40, 40, r, "Y");
        *p2l3 = new botonmg22(334, 80, 40, 40, r, "S");
        *p2l4 = new botonmg22(376, 80, 40, 40, r, "Q");
        *p2l5 = new botonmg22(418, 80, 40, 40, r, "L");
        *p2l6 = new botonmg22(460, 80, 40, 40, r, "0");

        *p3l1 = new botonmg22(142, 326, 40, 40, r, "R");
        *p3l2 = new botonmg22(184, 326, 40, 40, r, "I");
        *p3l3 = new botonmg22(226, 326, 40, 40, r, "A");
        *p3l4 = new botonmg22(268, 326, 40, 40, r, "K");
        *p3l5 = new botonmg22(268, 326, 40, 40, r, "0");
        *p3l6 = new botonmg22(0, 200, 40, 40, r, "0");

        *p4l1 = new botonmg22(184, 200, 40, 40, r, "S");
        *p4l2 = new botonmg22(184, 242, 40, 40, r, "Q");
        *p4l3 = new botonmg22(184, 284, 40, 40, r, "L");
        *p4l4 = new botonmg22(184, 326, 40, 40, r, "I");
        *p4l5 = new botonmg22(184, 368, 40, 40, r, "T");
        *p4l6 = new botonmg22(184, 410, 40, 40, r, "E");





    }
    else if (nivel == 4)
    {

        *p1l1 = new botonmg22(250, 80, 40, 40, r, "B");
        *p1l2 = new botonmg22(250, (*p1l1)->positonAndSize.y + 42, 40, 40, r, "U");
        *p1l3 = new botonmg22(250, (*p1l2)->positonAndSize.y + 42, 40, 40, r, "L");
        *p1l4 = new botonmg22(250, (*p1l3)->positonAndSize.y + 42, 40, 40, r, "M");
        *p1l5 = new botonmg22(250, (*p1l4)->positonAndSize.y + 42, 40, 40, r, "A");
        *p1l6 = new botonmg22(250, (*p1l5)->positonAndSize.y + 42, 40, 40, r, "0");

        *p2l1 = new botonmg22(208, 164, 40, 40, r, "U");
        *p2l2 = new botonmg22(250, 164, 40, 40, r, "L");
        *p2l3 = new botonmg22(292, 164, 40, 40, r, "K");
        *p2l4 = new botonmg22(334, 164, 40, 40, r, "I");
        *p2l5 = new botonmg22(376, 164, 40, 40, r, "T");
        *p2l6 = new botonmg22(460, 164, 40, 40, r, "0");

        *p3l1 = new botonmg22(120, 326, 40, 40, r, "P");
        *p3l2 = new botonmg22(162, 326, 40, 40, r, "U");
        *p3l3 = new botonmg22(204, 326, 40, 40, r, "R");
        *p3l4 = new botonmg22(246, 326, 40, 40, r, "E");
        *p3l5 = new botonmg22(268, 326, 40, 40, r, "0");
        *p3l6 = new botonmg22(0, 200, 40, 40, r, "0");

        *p4l1 = new botonmg22(162, 284, 40, 40, r, "S");
        *p4l2 = new botonmg22(162, 326, 40, 40, r, "U");
        *p4l3 = new botonmg22(162, 368, 40, 40, r, "S");
        *p4l4 = new botonmg22(162, 410, 40, 40, r, "Y");
        *p4l5 = new botonmg22(162, 452, 40, 40, r, "0");
        *p4l6 = new botonmg22(162, 494, 40, 40, r, "0");





    }
    else if (nivel == 5)
    {

        *p1l1 = new botonmg22(250, 80, 40, 40, r, "M");
        *p1l2 = new botonmg22(250, (*p1l1)->positonAndSize.y + 42, 40, 40, r, "E");
        *p1l3 = new botonmg22(250, (*p1l2)->positonAndSize.y + 42, 40, 40, r, "T");
        *p1l4 = new botonmg22(250, (*p1l3)->positonAndSize.y + 42, 40, 40, r, "E");
        *p1l5 = new botonmg22(250, (*p1l4)->positonAndSize.y + 42, 40, 40, r, "O");
        *p1l6 = new botonmg22(250, (*p1l5)->positonAndSize.y + 42, 40, 40, r, "R");

        *p2l1 = new botonmg22(250, 80, 40, 40, r, "M");
        *p2l2 = new botonmg22(292, 80, 40, 40, r, "E");
        *p2l3 = new botonmg22(334, 80, 40, 40, r, "A");
        *p2l4 = new botonmg22(376, 80, 40, 40, r, "N");
        *p2l5 = new botonmg22(418, 80, 40, 40, r, "J");
        *p2l6 = new botonmg22(460, 80, 40, 40, r, "S");

        *p3l1 = new botonmg22(120, 326, 40, 40, r, "V");
        *p3l2 = new botonmg22(162, 326, 40, 40, r, "U");
        *p3l3 = new botonmg22(204, 326, 40, 40, r, "E");
        *p3l4 = new botonmg22(246, 326, 40, 40, r, "0");
        *p3l5 = new botonmg22(268, 326, 40, 40, r, "0");
        *p3l6 = new botonmg22(0, 200, 40, 40, r, "0");

        *p4l1 = new botonmg22(204, 284, 40, 40, r, "R");
        *p4l2 = new botonmg22(204, 326, 40, 40, r, "E");
        *p4l3 = new botonmg22(204, 368, 40, 40, r, "A");
        *p4l4 = new botonmg22(204, 410, 40, 40, r, "C");
        *p4l5 = new botonmg22(204, 452, 40, 40, r, "T");
        *p4l6 = new botonmg22(204, 494, 40, 40, r, "0");





    }
    else if (nivel >= 6)
    {

        *p1l1 = new botonmg22(250, 80, 40, 40, r, "F");
        *p1l2 = new botonmg22(250, (*p1l1)->positonAndSize.y + 42, 40, 40, r, "I");
        *p1l3 = new botonmg22(250, (*p1l2)->positonAndSize.y + 42, 40, 40, r, "R");
        *p1l4 = new botonmg22(250, (*p1l3)->positonAndSize.y + 42, 40, 40, r, "E");
        *p1l5 = new botonmg22(250, (*p1l4)->positonAndSize.y + 42, 40, 40, r, "F");
        *p1l6 = new botonmg22(250, (*p1l5)->positonAndSize.y + 42, 40, 40, r, "O");

        *p2l1 = new botonmg22(124, 290, 40, 40, r, "C");
        *p2l2 = new botonmg22(166, 290, 40, 40, r, "H");
        *p2l3 = new botonmg22(208, 290, 40, 40, r, "R");
        *p2l4 = new botonmg22(250, 290, 40, 40, r, "O");
        *p2l5 = new botonmg22(292, 290, 40, 40, r, "M");
        *p2l6 = new botonmg22(334, 290, 40, 40, r, "E");

        *p3l1 = new botonmg22(380, 326, 40, 40, r, "E");
        *p3l2 = new botonmg22(422, 326, 40, 40, r, "D");
        *p3l3 = new botonmg22(464, 326, 40, 40, r, "G");
        *p3l4 = new botonmg22(506, 326, 40, 40, r, "E");
        *p3l5 = new botonmg22(250, (*p1l6)->positonAndSize.y + 42, 40, 40, r, "X");
        *p3l6 = new botonmg22(204, 494, 40, 40, r, "0");

        *p4l1 = new botonmg22(506, 242, 40, 40, r, "O");
        *p4l2 = new botonmg22(506, 284, 40, 40, r, "P");
        *p4l3 = new botonmg22(506, 326, 40, 40, r, "E");
        *p4l4 = new botonmg22(506, 368, 40, 40, r, "R");
        *p4l5 = new botonmg22(506, 410, 40, 40, r, "A");
        *p4l6 = new botonmg22(506, 452, 40, 40, r, "0");





    }
}



void PintarLetrasMg2(botonmg22** p1l1, botonmg22** p1l2, botonmg22** p1l3, botonmg22** p1l4, botonmg22** p1l5, botonmg22** p1l6,
    botonmg22** p2l1, botonmg22** p2l2, botonmg22** p2l3, botonmg22** p2l4, botonmg22** p2l5, botonmg22** p2l6,
    botonmg22** p3l1, botonmg22** p3l2, botonmg22** p3l3, botonmg22** p3l4, botonmg22** p3l5, botonmg22** p3l6,
    botonmg22** p4l1, botonmg22** p4l2, botonmg22** p4l3, botonmg22** p4l4, botonmg22** p4l5, botonmg22** p4l6,
    SDL_Renderer* r, int nivel)
{

    SDL_RenderCopy(r, (*p1l1)->btntexture, NULL, &(*p1l1)->positonAndSize);
    SDL_RenderCopy(r, (*p1l2)->btntexture, NULL, &(*p1l2)->positonAndSize);
    SDL_RenderCopy(r, (*p1l3)->btntexture, NULL, &(*p1l3)->positonAndSize);


    if ((*p1l4)->is_avalible == true)
    {
        SDL_RenderCopy(r, (*p1l4)->btntexture, NULL, &(*p1l4)->positonAndSize);

    }
    if ((*p1l5)->is_avalible == true)
    {
        SDL_RenderCopy(r, (*p1l5)->btntexture, NULL, &(*p1l5)->positonAndSize);

    }
    if ((*p1l6)->is_avalible == true)
    {
        SDL_RenderCopy(r, (*p1l6)->btntexture, NULL, &(*p1l6)->positonAndSize);

    }

    SDL_RenderCopy(r, (*p2l1)->btntexture, NULL, &(*p2l1)->positonAndSize);
    SDL_RenderCopy(r, (*p2l2)->btntexture, NULL, &(*p2l2)->positonAndSize);
    SDL_RenderCopy(r, (*p2l3)->btntexture, NULL, &(*p2l3)->positonAndSize);

    if ((*p2l4)->is_avalible == true)
    {
        SDL_RenderCopy(r, (*p2l4)->btntexture, NULL, &(*p2l4)->positonAndSize);

    }
    if ((*p2l5)->is_avalible == true)
    {
        SDL_RenderCopy(r, (*p2l5)->btntexture, NULL, &(*p2l5)->positonAndSize);

    }
    if ((*p2l6)->is_avalible == true)
    {
        SDL_RenderCopy(r, (*p2l6)->btntexture, NULL, &(*p2l6)->positonAndSize);

    }

    SDL_RenderCopy(r, (*p3l1)->btntexture, NULL, &(*p3l1)->positonAndSize);
    SDL_RenderCopy(r, (*p3l2)->btntexture, NULL, &(*p3l2)->positonAndSize);
    SDL_RenderCopy(r, (*p3l3)->btntexture, NULL, &(*p3l3)->positonAndSize);

    if ((*p3l4)->is_avalible == true)
    {
        SDL_RenderCopy(r, (*p3l4)->btntexture, NULL, &(*p3l4)->positonAndSize);

    }
    if ((*p3l5)->is_avalible == true)
    {
        SDL_RenderCopy(r, (*p3l5)->btntexture, NULL, &(*p3l5)->positonAndSize);

    }
    if ((*p3l6)->is_avalible == true)
    {
        SDL_RenderCopy(r, (*p3l6)->btntexture, NULL, &(*p3l6)->positonAndSize);

    }

    SDL_RenderCopy(r, (*p4l1)->btntexture, NULL, &(*p4l1)->positonAndSize);
    SDL_RenderCopy(r, (*p4l2)->btntexture, NULL, &(*p4l2)->positonAndSize);
    SDL_RenderCopy(r, (*p4l3)->btntexture, NULL, &(*p4l3)->positonAndSize);

    if ((*p4l4)->is_avalible == true)
    {
        SDL_RenderCopy(r, (*p4l4)->btntexture, NULL, &(*p4l4)->positonAndSize);

    }
    if ((*p4l5)->is_avalible == true)
    {
        SDL_RenderCopy(r, (*p4l5)->btntexture, NULL, &(*p4l5)->positonAndSize);

    }
    if ((*p4l6)->is_avalible == true)
    {
        SDL_RenderCopy(r, (*p4l6)->btntexture, NULL, &(*p4l6)->positonAndSize);

    }


}

void LimpiarLetrasMg2(botonmg22** p1l1, botonmg22** p1l2, botonmg22** p1l3, botonmg22** p1l4, botonmg22** p1l5, botonmg22** p1l6,
    botonmg22** p2l1, botonmg22** p2l2, botonmg22** p2l3, botonmg22** p2l4, botonmg22** p2l5, botonmg22** p2l6,
    botonmg22** p3l1, botonmg22** p3l2, botonmg22** p3l3, botonmg22** p3l4, botonmg22** p3l5, botonmg22** p3l6,
    botonmg22** p4l1, botonmg22** p4l2, botonmg22** p4l3, botonmg22** p4l4, botonmg22** p4l5, botonmg22** p4l6,
    SDL_Renderer* r)
{

    SDL_DestroyTexture((*p1l1)->btntexture);
    SDL_DestroyTexture((*p1l2)->btntexture);
    SDL_DestroyTexture((*p1l3)->btntexture);
    SDL_DestroyTexture((*p1l4)->btntexture);
    SDL_DestroyTexture((*p1l5)->btntexture);
    SDL_DestroyTexture((*p1l6)->btntexture);

    SDL_DestroyTexture((*p2l1)->btntexture);
    SDL_DestroyTexture((*p2l2)->btntexture);
    SDL_DestroyTexture((*p2l3)->btntexture);
    SDL_DestroyTexture((*p2l4)->btntexture);
    SDL_DestroyTexture((*p2l5)->btntexture);
    SDL_DestroyTexture((*p2l6)->btntexture);

    SDL_DestroyTexture((*p3l1)->btntexture);
    SDL_DestroyTexture((*p3l2)->btntexture);
    SDL_DestroyTexture((*p3l3)->btntexture);
    SDL_DestroyTexture((*p3l4)->btntexture);
    SDL_DestroyTexture((*p3l5)->btntexture);
    SDL_DestroyTexture((*p3l6)->btntexture);

    SDL_DestroyTexture((*p4l1)->btntexture);
    SDL_DestroyTexture((*p4l2)->btntexture);
    SDL_DestroyTexture((*p4l3)->btntexture);
    SDL_DestroyTexture((*p4l4)->btntexture);
    SDL_DestroyTexture((*p4l5)->btntexture);
    SDL_DestroyTexture((*p4l6)->btntexture);



    SDL_FreeSurface((*p1l1)->btnsurface);
    SDL_FreeSurface((*p1l2)->btnsurface);
    SDL_FreeSurface((*p1l3)->btnsurface);
    SDL_FreeSurface((*p1l4)->btnsurface);
    SDL_FreeSurface((*p1l5)->btnsurface);
    SDL_FreeSurface((*p1l6)->btnsurface);

    SDL_FreeSurface((*p2l1)->btnsurface);
    SDL_FreeSurface((*p2l2)->btnsurface);
    SDL_FreeSurface((*p2l3)->btnsurface);
    SDL_FreeSurface((*p2l4)->btnsurface);
    SDL_FreeSurface((*p2l5)->btnsurface);
    SDL_FreeSurface((*p2l6)->btnsurface);

    SDL_FreeSurface((*p3l1)->btnsurface);
    SDL_FreeSurface((*p3l2)->btnsurface);
    SDL_FreeSurface((*p3l3)->btnsurface);
    SDL_FreeSurface((*p3l4)->btnsurface);
    SDL_FreeSurface((*p3l5)->btnsurface);
    SDL_FreeSurface((*p3l6)->btnsurface);

    SDL_FreeSurface((*p4l1)->btnsurface);
    SDL_FreeSurface((*p4l2)->btnsurface);
    SDL_FreeSurface((*p4l3)->btnsurface);
    SDL_FreeSurface((*p4l4)->btnsurface);
    SDL_FreeSurface((*p4l5)->btnsurface);
    SDL_FreeSurface((*p4l6)->btnsurface);

    delete* p1l1;
    delete* p1l2;
    delete* p1l3;
    delete* p1l4;
    delete* p1l5;
    delete* p1l6;


    delete* p2l3;
    delete* p2l4;
    delete* p2l2;
    delete* p2l1;
    delete* p2l5;
    delete* p2l6;

    delete* p3l1;
    delete* p3l2;
    delete* p3l3;
    delete* p3l4;
    delete* p3l5;
    delete* p3l6;


    delete* p4l1;
    delete* p4l2;
    delete* p4l3;
    delete* p4l4;
    delete* p4l5;
    delete* p4l6;

}


void verificar_letra(botonmg22** p1l1, botonmg22** p1l2, botonmg22** p1l3, botonmg22** p1l4, botonmg22** p1l5, botonmg22** p1l6,
    botonmg22** p2l1, botonmg22** p2l2, botonmg22** p2l3, botonmg22** p2l4, botonmg22** p2l5, botonmg22** p2l6,
    botonmg22** p3l1, botonmg22** p3l2, botonmg22** p3l3, botonmg22** p3l4, botonmg22** p3l5, botonmg22** p3l6,
    botonmg22** p4l1, botonmg22** p4l2, botonmg22** p4l3, botonmg22** p4l4, botonmg22** p4l5, botonmg22** p4l6,
    SDL_Renderer* r, std::string letra)
{
    bool coincidencia = false;
    if (letra == (*p1l1)->letter)
    {
        (*p1l1)->urlimg_c = (*p1l1)->direction_letter.c_str();
        (*p1l1)->resetsurface(r);
        (*p1l1)->is_visible = true;
        coincidencia = true;
    }
    if (letra == (*p1l2)->letter)
    {
        (*p1l2)->urlimg_c = (*p1l2)->direction_letter.c_str();
        (*p1l2)->resetsurface(r);
        (*p1l2)->is_visible = true;
        coincidencia = true;

    }
    if (letra == (*p1l3)->letter)
    {
        (*p1l3)->urlimg_c = (*p1l3)->direction_letter.c_str();
        (*p1l3)->resetsurface(r);
        (*p1l3)->is_visible = true;
        coincidencia = true;

    }
    if (letra == (*p1l4)->letter)
    {
        (*p1l4)->urlimg_c = (*p1l4)->direction_letter.c_str();
        (*p1l4)->resetsurface(r);
        (*p1l4)->is_visible = true;
        coincidencia = true;

    }
    if (letra == (*p1l5)->letter)
    {
        (*p1l5)->urlimg_c = (*p1l5)->direction_letter.c_str();
        (*p1l5)->resetsurface(r);
        (*p1l5)->is_visible = true;
        coincidencia = true;

    }
    if (letra == (*p1l6)->letter)
    {
        (*p1l6)->urlimg_c = (*p1l6)->direction_letter.c_str();
        (*p1l6)->resetsurface(r);
        (*p1l6)->is_visible = true;
        coincidencia = true;

    }
    if (letra == (*p2l1)->letter)
    {
        (*p2l1)->urlimg_c = (*p2l1)->direction_letter.c_str();
        (*p2l1)->resetsurface(r);
        (*p2l1)->is_visible = true;
        coincidencia = true;

    }
    if (letra == (*p2l2)->letter)
    {
        (*p2l2)->urlimg_c = (*p2l2)->direction_letter.c_str();
        (*p2l2)->resetsurface(r);
        (*p2l2)->is_visible = true;
        coincidencia = true;

    }
    if (letra == (*p2l3)->letter)
    {
        (*p2l3)->urlimg_c = (*p2l3)->direction_letter.c_str();
        (*p2l3)->resetsurface(r);
        (*p2l3)->is_visible = true;
        coincidencia = true;

    }
    if (letra == (*p2l4)->letter)
    {
        (*p2l4)->urlimg_c = (*p2l4)->direction_letter.c_str();
        (*p2l4)->resetsurface(r);
        (*p2l4)->is_visible = true;
        coincidencia = true;

    }
    if (letra == (*p2l5)->letter)
    {
        (*p2l5)->urlimg_c = (*p2l5)->direction_letter.c_str();
        (*p2l5)->resetsurface(r);
        (*p2l5)->is_visible = true;
        coincidencia = true;

    }
    if (letra == (*p2l6)->letter)
    {
        (*p2l6)->urlimg_c = (*p2l6)->direction_letter.c_str();
        (*p2l6)->resetsurface(r);
        (*p2l6)->is_visible = true;

    }
    if (letra == (*p3l1)->letter)
    {
        (*p3l1)->urlimg_c = (*p3l1)->direction_letter.c_str();
        (*p3l1)->resetsurface(r);
        (*p3l1)->is_visible = true;
        coincidencia = true;

    }
    if (letra == (*p3l2)->letter)
    {
        (*p3l2)->urlimg_c = (*p3l2)->direction_letter.c_str();
        (*p3l2)->resetsurface(r);
        (*p3l2)->is_visible = true;
        coincidencia = true;

    }
    if (letra == (*p3l3)->letter)
    {
        (*p3l3)->urlimg_c = (*p3l3)->direction_letter.c_str();
        (*p3l3)->resetsurface(r);
        (*p3l3)->is_visible = true;
        coincidencia = true;

    }
    if (letra == (*p3l4)->letter)
    {
        (*p3l4)->urlimg_c = (*p3l4)->direction_letter.c_str();
        (*p3l4)->resetsurface(r);
        (*p3l4)->is_visible = true;
        coincidencia = true;

    }
    if (letra == (*p3l5)->letter)
    {
        (*p3l5)->urlimg_c = (*p3l5)->direction_letter.c_str();
        (*p3l5)->resetsurface(r);
        (*p3l5)->is_visible = true;
        coincidencia = true;

    }
    if (letra == (*p3l6)->letter)
    {
        (*p3l6)->urlimg_c = (*p3l6)->direction_letter.c_str();
        (*p3l6)->resetsurface(r);
        (*p3l6)->is_visible = true;
        coincidencia = true;

    }
    if (letra == (*p4l1)->letter)
    {
        (*p4l1)->urlimg_c = (*p4l1)->direction_letter.c_str();
        (*p4l1)->resetsurface(r);
        (*p4l1)->is_visible = true;
        coincidencia = true;

    }
    if (letra == (*p4l2)->letter)
    {
        (*p4l2)->urlimg_c = (*p4l2)->direction_letter.c_str();
        (*p4l2)->resetsurface(r);
        (*p4l2)->is_visible = true;
        coincidencia = true;

    }
    if (letra == (*p4l3)->letter)
    {
        (*p4l3)->urlimg_c = (*p4l3)->direction_letter.c_str();
        (*p4l3)->resetsurface(r);
        (*p4l3)->is_visible = true;
        coincidencia = true;

    }
    if (letra == (*p4l4)->letter)
    {
        (*p4l4)->urlimg_c = (*p4l4)->direction_letter.c_str();
        (*p4l4)->resetsurface(r);
        (*p4l4)->is_visible = true;
        coincidencia = true;

    }
    if (letra == (*p4l5)->letter)
    {
        (*p4l5)->urlimg_c = (*p4l5)->direction_letter.c_str();
        (*p4l5)->resetsurface(r);
        (*p4l5)->is_visible = true;

    }
    if (letra == (*p4l6)->letter)
    {
        (*p4l6)->urlimg_c = (*p4l6)->direction_letter.c_str();
        (*p4l6)->resetsurface(r);
        (*p4l6)->is_visible = true;
        coincidencia = true;

    }

    if (coincidencia == false)
    {
        puntaje::user->life_mg2--;
    }






}

bool Verificar_ganar(botonmg22** p1l1, botonmg22** p1l2, botonmg22** p1l3, botonmg22** p1l4, botonmg22** p1l5, botonmg22** p1l6,
    botonmg22** p2l1, botonmg22** p2l2, botonmg22** p2l3, botonmg22** p2l4, botonmg22** p2l5, botonmg22** p2l6,
    botonmg22** p3l1, botonmg22** p3l2, botonmg22** p3l3, botonmg22** p3l4, botonmg22** p3l5, botonmg22** p3l6,
    botonmg22** p4l1, botonmg22** p4l2, botonmg22** p4l3, botonmg22** p4l4, botonmg22** p4l5, botonmg22** p4l6,
    SDL_Renderer* r)
{


    if (!(*p1l1)->is_visible && (*p1l1)->is_avalible)
    {
        return false;

    }
    if (!(*p1l2)->is_visible && (*p1l2)->is_avalible)
    {
        return false;

    }
    if (!(*p1l3)->is_visible && (*p1l3)->is_avalible)
    {
        return false;

    }
    if (!(*p1l4)->is_visible && (*p1l4)->is_avalible)
    {
        return false;

    }
    if (!(*p1l5)->is_visible && (*p1l5)->is_avalible)
    {
        return false;

    }
    if (!(*p1l6)->is_visible && (*p1l6)->is_avalible)
    {
        return false;

    }




    if (!(*p2l1)->is_visible && (*p2l1)->is_avalible)
    {
        return false;

    }
    if (!(*p2l2)->is_visible && (*p2l2)->is_avalible)
    {
        return false;

    }
    if (!(*p2l3)->is_visible && (*p2l3)->is_avalible)
    {
        return false;

    }
    if (!(*p2l4)->is_visible && (*p2l4)->is_avalible)
    {
        return false;

    }
    if (!(*p2l5)->is_visible && (*p2l5)->is_avalible)
    {
        return false;

    }
    if (!(*p2l6)->is_visible && (*p2l6)->is_avalible)
    {
        return false;

    }



    if (!(*p3l1)->is_visible && (*p3l1)->is_avalible)
    {
        return false;

    }
    if (!(*p3l2)->is_visible && (*p3l2)->is_avalible)
    {
        return false;

    }
    if (!(*p3l3)->is_visible && (*p3l3)->is_avalible)
    {
        return false;

    }
    if (!(*p3l4)->is_visible && (*p3l4)->is_avalible)
    {
        return false;

    }
    if (!(*p3l5)->is_visible && (*p3l5)->is_avalible)
    {
        return false;

    }
    if (!(*p3l6)->is_visible && (*p3l6)->is_avalible)
    {
        return false;

    }



    if (!(*p4l1)->is_visible && (*p4l1)->is_avalible)
    {
        return false;

    }
    if (!(*p4l2)->is_visible && (*p4l2)->is_avalible)
    {
        return false;

    }
    if (!(*p4l3)->is_visible && (*p4l3)->is_avalible)
    {
        return false;

    }
    if (!(*p4l4)->is_visible && (*p4l4)->is_avalible)
    {
        return false;

    }
    if (!(*p4l5)->is_visible && (*p4l5)->is_avalible)
    {
        return false;

    }
    if (!(*p4l6)->is_visible && (*p4l6)->is_avalible)
    {
        return false;

    }


    return true;

}





#endif