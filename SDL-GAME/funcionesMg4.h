#pragma once

#ifndef FUNC_MG4
#define FUNC_MG4

#include "Minijuegos.h"
#include <string>
#include<iostream>
#include "boton.h"
#include <vector>
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <SDL_ttf.h>
#include "score.h"
#include "botonmg4.h"



void SetPregunta(std::vector<int>* preguntas_usadas, std::string* direccion, int* pregunta_dir)
{
    int pregunta;

    while (true)
    {
        pregunta = rand() % 4 + 1;
        if (!(std::find(preguntas_usadas->begin(), preguntas_usadas->end(), pregunta) != preguntas_usadas->end())) //verifica si la pregunta ya fue usada
        {
            *direccion = "./resource/MG4D/Q/" + std::to_string(pregunta) + ".bmp";
            preguntas_usadas->push_back(pregunta);
            *pregunta_dir = pregunta;
            break;
        }
    }


}

void Set_Respuestas(std::vector<int>* Respuesta_usada, botonmg4** res, int* pregunta, SDL_Renderer* r, int posx, int posy)
{
    int respuesta;
    std::string direccion = "./resource/MG4D/A/" + std::to_string(*pregunta) + "/";
    while (true)
    {
        respuesta = rand() % 4 + 1;
        if (!(std::find(Respuesta_usada->begin(), Respuesta_usada->end(), respuesta) != Respuesta_usada->end()))
        {
            direccion += std::to_string(respuesta) + ".bmp";
            *res = new botonmg4(posx, posy, 200, 50, r, respuesta, direccion);
            Respuesta_usada->push_back(respuesta);
            break;
        }

    }




}

void Verify_Dragged(int x, int y, botonmg4** R)
{
    if ((x >= (*R)->positonAndSize.x && x <= (*R)->positonAndSize.x + (*R)->positonAndSize.w) && (y >= (*R)->positonAndSize.y && y <= (*R)->positonAndSize.y + (*R)->positonAndSize.h))
    {
        (*R)->is_dragged = true;
    }

}

void Move_Dragged(botonmg4** R, int x, int y, int xi, int yi)
{
    (*R)->positonAndSize.x += (xi - x);
    (*R)->positonAndSize.y += (yi - y);


}

void Clear_Dragged(botonmg4** R)
{

    (*R)->is_dragged = false;
}

void adjust(botonmg4** R, int* espacios)
{
    if (((*R)->positonAndSize.x >= 68 && 270 >= (*R)->positonAndSize.x) && ((*R)->positonAndSize.y >= 468 && 518 >= (*R)->positonAndSize.y))
    {
        (*R)->positonAndSize.x = 70;
        (*R)->positonAndSize.y = 468;
        espacios[0] = (*R)->answer_n;
    }


    if (((*R)->positonAndSize.x >= 428 && 630 >= (*R)->positonAndSize.x) && ((*R)->positonAndSize.y >= 468 && 518 >= (*R)->positonAndSize.y))
    {
        (*R)->positonAndSize.x = 430;
        (*R)->positonAndSize.y = 467;
        espacios[1] = (*R)->answer_n;

    }


    if (((*R)->positonAndSize.x >= 68 && 270 >= (*R)->positonAndSize.x) && ((*R)->positonAndSize.y >= 537 && 587 >= (*R)->positonAndSize.y))
    {
        (*R)->positonAndSize.x = 70;
        (*R)->positonAndSize.y = 535;
        espacios[2] = (*R)->answer_n;

    }


    if (((*R)->positonAndSize.x >= 428 && 630 >= (*R)->positonAndSize.x) && ((*R)->positonAndSize.y >= 537 && 587 >= (*R)->positonAndSize.y))
    {
        (*R)->positonAndSize.x = 430;
        (*R)->positonAndSize.y = 537;
        espacios[3] = (*R)->answer_n;

    }

}


bool Click_Verificar()
{
    int mouse_x, mouse_y;
    SDL_GetMouseState(&mouse_x, &mouse_y);

    if ((mouse_x >= 720 && mouse_x <= 720 + 60 && (mouse_y >= 470 && mouse_y <= 470 + 60)))
    {
        return true;

    }

    return false;


}








#endif // !FUNC_MG4


