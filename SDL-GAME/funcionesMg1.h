#pragma once
#ifndef FUNC_MG1
#define FUNC_MG1


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

void asignar_respuesta(int pregunta, int* respuesta)
{


    switch (pregunta)
    {

    case 1:
        *respuesta = 1;
        break;
    case 2:
        *respuesta = 1;
        break;
    case 3:
        *respuesta = 3;
        break;
    case 4:
        *respuesta = 4;
        break;
    case 5:
        *respuesta = 4;
        break;
    case 6:
        *respuesta = 2;
        break;
    case 7:
        *respuesta = 1;
        break;
    case 8:
        *respuesta = 3;
        break;
    case 9:
        *respuesta = 4;
        break;
    case 10:
        *respuesta = 1;
        break;
    case 11:
        *respuesta = 2;
        break;
    case 12:
        *respuesta = 1;
        break;
    case 13:
        *respuesta = 2;
        break;
    case 14:
        *respuesta = 3;
        break;
    case 15:
        *respuesta = 3;
        break;
    }


}

void Generarbtn_respuesta(const char* dir, std::vector<int>* res_ocupadas, SDL_Renderer* r, std::string* direc, int* respuesta)
{
    int generar_respuestaRand;
    bool n_seleccionado = false; // numero seleccionado


    while (!n_seleccionado)// ciclo hasta que encuentre una respuesta no ocupada
    {
        generar_respuestaRand = rand() % 4 + 1;
        n_seleccionado = true;
        for (size_t i = 0; i < res_ocupadas->size(); i++)
        {
            if (generar_respuestaRand == (*res_ocupadas)[i])
            {
                n_seleccionado = false;
            }
        }
    }

    res_ocupadas->push_back(generar_respuestaRand);

    std::string direccion = dir + std::to_string(generar_respuestaRand) + ".bmp";

    *respuesta = generar_respuestaRand;
    *direc = direccion.c_str();



}

void Actualizar_PreguntasyRespuestas(BTN* res1, BTN* res2, BTN* res3, BTN* res4,
    int* pregunta, int* respuesta, std::string* direccion_pregunta,
    std::vector<int>* preguntas_usadas, std::vector<int>* respuesta_acaparadas
    , SDL_Renderer* r, int* id_respuesta, std::string* direccion_respuesta,
    std::string* direccion)
{

    bool pregunta_usada = false;
    do // verifica si la pregunta ya fue usada y crea una nueva pregunta
    {
        *pregunta = rand() % 15 + 1;
        pregunta_usada = false;



        for (size_t i = 0; i < preguntas_usadas->size(); i++)
        {
            if (*pregunta == (*preguntas_usadas)[i])
            {
                pregunta_usada = true;
            }
        }

    } while (pregunta_usada);


    *direccion_pregunta = "./resource/MG1P/";
    preguntas_usadas->push_back(*pregunta);
    *direccion_pregunta += std::to_string(*pregunta) + ".bmp";
    asignar_respuesta(*pregunta, respuesta);



    SDL_DestroyTexture(res1->btntexture);
    SDL_FreeSurface(res1->btnsurface);
    SDL_DestroyTexture(res2->btntexture);
    SDL_FreeSurface(res2->btnsurface);
    SDL_DestroyTexture(res3->btntexture);
    SDL_FreeSurface(res3->btnsurface);
    SDL_DestroyTexture(res4->btntexture);
    SDL_FreeSurface(res4->btnsurface);

    delete res1;
    delete res2;
    delete res3;
    delete res4;


    respuesta_acaparadas->clear();

    *direccion_respuesta = "./resource/MG1P/";
    *direccion_respuesta += std::to_string(*pregunta) + "/";







}





#endif // !FUNC_MG1
