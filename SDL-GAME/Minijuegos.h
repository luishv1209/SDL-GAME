#pragma once
#ifndef MINIJUEGOS_H
#define MINIJUEGOS_H

#include "SDL.h"
#include <vector>
#include "boton.h"
#include "botonmg2.h"
#include <string>

void RenderGame1(SDL_Renderer* r);
void RenderGame2(SDL_Renderer* r);
void RenderGame3(SDL_Renderer* r);
void RenderGame4(SDL_Renderer* r);





void CrearLetrasMg2(botonmg22** p1l1, botonmg22** p1l2, botonmg22** p1l3, botonmg22** p1l4, botonmg22** p1l5, botonmg22** p1l6,
    botonmg22** p2l1, botonmg22** p2l2, botonmg22** p2l3, botonmg22** p2l4, botonmg22** p2l5, botonmg22** p2l6,
    botonmg22** p3l1, botonmg22** p3l2, botonmg22** p3l3, botonmg22** p3l4, botonmg22** p3l5, botonmg22** p3l6,
    botonmg22** p4l1, botonmg22** p4l2, botonmg22** p4l3, botonmg22** p4l4, botonmg22** p4l5, botonmg22** p4l6,
    SDL_Renderer* r, int nivel);


void PintarLetrasMg2(botonmg22** p1l1, botonmg22** p1l2, botonmg22** p1l3, botonmg22** p1l4, botonmg22** p1l5, botonmg22** p1l6,
    botonmg22** p2l1, botonmg22** p2l2, botonmg22** p2l3, botonmg22** p2l4, botonmg22** p2l5, botonmg22** p2l6,
    botonmg22** p3l1, botonmg22** p3l2, botonmg22** p3l3, botonmg22** p3l4, botonmg22** p3l5, botonmg22** p3l6,
    botonmg22** p4l1, botonmg22** p4l2, botonmg22** p4l3, botonmg22** p4l4, botonmg22** p4l5, botonmg22** p4l6,
    SDL_Renderer* r, int nivel);


void LimpiarLetrasMg2(botonmg22** p1l1, botonmg22** p1l2, botonmg22** p1l3, botonmg22** p1l4, botonmg22** p1l5, botonmg22** p1l6,
    botonmg22** p2l1, botonmg22** p2l2, botonmg22** p2l3, botonmg22** p2l4, botonmg22** p2l5, botonmg22** p2l6,
    botonmg22** p3l1, botonmg22** p3l2, botonmg22** p3l3, botonmg22** p3l4, botonmg22** p3l5, botonmg22** p3l6,
    botonmg22** p4l1, botonmg22** p4l2, botonmg22** p4l3, botonmg22** p4l4, botonmg22** p4l5, botonmg22** p4l6,
    SDL_Renderer* r);

void verificar_letra(botonmg22** p1l1, botonmg22** p1l2, botonmg22** p1l3, botonmg22** p1l4, botonmg22** p1l5, botonmg22** p1l6,
    botonmg22** p2l1, botonmg22** p2l2, botonmg22** p2l3, botonmg22** p2l4, botonmg22** p2l5, botonmg22** p2l6,
    botonmg22** p3l1, botonmg22** p3l2, botonmg22** p3l3, botonmg22** p3l4, botonmg22** p3l5, botonmg22** p3l6,
    botonmg22** p4l1, botonmg22** p4l2, botonmg22** p4l3, botonmg22** p4l4, botonmg22** p4l5, botonmg22** p4l6,
    SDL_Renderer* r, std::string letra);


bool Verificar_ganar(botonmg22** p1l1, botonmg22** p1l2, botonmg22** p1l3, botonmg22** p1l4, botonmg22** p1l5, botonmg22** p1l6,
    botonmg22** p2l1, botonmg22** p2l2, botonmg22** p2l3, botonmg22** p2l4, botonmg22** p2l5, botonmg22** p2l6,
    botonmg22** p3l1, botonmg22** p3l2, botonmg22** p3l3, botonmg22** p3l4, botonmg22** p3l5, botonmg22** p3l6,
    botonmg22** p4l1, botonmg22** p4l2, botonmg22** p4l3, botonmg22** p4l4, botonmg22** p4l5, botonmg22** p4l6,
    SDL_Renderer* r);


bool Exitbtn();


#endif // !MINIJUEGOS_H


