#pragma once

#include "Minijuegos.h"
#include <string>
#include<iostream>
#include "boton.h"
#include "botonmg2.h"
#include <vector>
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <SDL_ttf.h>
#include "score.h"
#include "botonmg3.h"


int PlayerSelect(SDL_Renderer* r)
{


    TTF_Init();

    TTF_Font* FONT = TTF_OpenFont("./resource/MG3T/mg3_font.TTF", 24); //abre la fuente y establece el tamaño



    //RECOGE LAS IMAGENES
    SDL_Surface* fondo;
    SDL_Surface* returnbtn;
    SDL_Surface* Surface_msg;
    SDL_Surface* Surface_X;
    SDL_Surface* Surface_O;



    //CREA LAS TEXTURAS CON LAS IMAGENES RECOGIDAS
    SDL_Texture* texture;

    //mensaje
    SDL_Texture* text_msg;
    SDL_Color color = { 255,255,255 };


    //letras
    SDL_Texture* text_X;
    SDL_Texture* text_O;



    //ESTABLECE EL TAMÑAO Y POSICION DEL CURSOR y los botones
    const SDL_Rect resize = { 400,200,35,40 };
    const SDL_Rect size_msg = { 20,100,700,40 };

    const SDL_Rect size_x = { 250,200,80,80 };
    const SDL_Rect size_o = { 500,200,80,80 };



    bool quit = false;
    SDL_Event event;
    while (!quit)
    {

        SDL_WaitEvent(&event);

        switch (event.type) // COMPARA EL TYPO DE EVENTO
        {
        case SDL_MOUSEBUTTONDOWN:
            int m_posx, m_posy;
            SDL_GetMouseState(&m_posx, &m_posy);
            if (SDL_BUTTON(SDL_BUTTON_LEFT)) {

                if ((m_posx > 250 && m_posx < 330) && (m_posy > 200 && m_posy < 280))
                {
                    return 1;
                }

                if ((m_posx > 500 && m_posx < 580) && (m_posy > 200 && m_posy < 280))
                {
                    return 2;
                }

            }
            break;


        }



        fondo = SDL_LoadBMP("./resource/MG3T/selection_background.bmp");
        Surface_X = SDL_LoadBMP("./resource/MG3T/x.bmp");
        Surface_O = SDL_LoadBMP("./resource/MG3T/o.bmp");


        texture = SDL_CreateTextureFromSurface(r, fondo);



        Surface_msg = TTF_RenderText_Solid(FONT, "Selecione con que desea jugar: ", color); //establece el mensaje
        text_msg = SDL_CreateTextureFromSurface(r, Surface_msg);

        text_X = SDL_CreateTextureFromSurface(r, Surface_X);

        text_O = SDL_CreateTextureFromSurface(r, Surface_O);



        //PINTA EN PANTALLA
        SDL_RenderCopy(r, texture, NULL, NULL);
        SDL_RenderCopy(r, text_msg, NULL, &size_msg);
        SDL_RenderCopy(r, text_O, NULL, &size_o);
        SDL_RenderCopy(r, text_X, NULL, &size_x);




        SDL_RenderPresent(r);

        SDL_DestroyTexture(texture);
        SDL_DestroyTexture(text_msg);
        SDL_DestroyTexture(text_X);
        SDL_DestroyTexture(text_O);




        SDL_FreeSurface(fondo);
        SDL_FreeSurface(Surface_msg);
        SDL_FreeSurface(Surface_X);
        SDL_FreeSurface(Surface_O);



    }




    return 0;


}

bool Defender_IA(std::vector<btnmg3>* espacios, int sign)
{





    //defensa pendientes

    if (((espacios->begin())->is_avalible) || ((espacios->begin() + (4))->is_avalible) || ((espacios->begin() + (8))->is_avalible))
    {
        if ((!(espacios->begin())->is_avalible) && (!(espacios->begin() + (4))->is_avalible) ||
            (!(espacios->begin() + (4))->is_avalible) && (!(espacios->begin() + (8))->is_avalible) ||
            (!(espacios->begin())->is_avalible) && (!(espacios->begin() + (8))->is_avalible))
        {
            if (((espacios->begin())->is_avalible))
            {
                (espacios->begin())->Re_Create(sign);
                return true;
            }
            if (((espacios->begin() + 4)->is_avalible))
            {
                (espacios->begin() + 4)->Re_Create(sign);
                return true;
            }
            if (((espacios->begin() + 8)->is_avalible))
            {
                (espacios->begin() + 8)->Re_Create(sign);
                return true;
            }

        }
    }



    if (((espacios->begin() + 2)->is_avalible) || ((espacios->begin() + (4))->is_avalible) || ((espacios->begin() + (6))->is_avalible))
    {
        if ((!(espacios->begin() + 2)->is_avalible) && (!(espacios->begin() + (4))->is_avalible) ||
            (!(espacios->begin() + (4))->is_avalible) && (!(espacios->begin() + (6))->is_avalible) ||
            (!(espacios->begin() + 2)->is_avalible) && (!(espacios->begin() + (6))->is_avalible))
        {
            if (((espacios->begin() + 2)->is_avalible))
            {
                (espacios->begin() + 2)->Re_Create(sign);
                return true;
            }
            if (((espacios->begin() + 4)->is_avalible))
            {
                (espacios->begin() + 4)->Re_Create(sign);
                return true;
            }
            if (((espacios->begin() + 6)->is_avalible))
            {
                (espacios->begin() + 6)->Re_Create(sign);
                return true;
            }

        }

    }









    //defensa horizontal
    for (size_t i = 0; i < 7; i += 3)
    {
        if (((espacios->begin() + i)->is_avalible) || ((espacios->begin() + (i + 1))->is_avalible) || ((espacios->begin() + (i + 2))->is_avalible))
        {


            if ((!(espacios->begin() + i)->is_avalible) && (!(espacios->begin() + (i + 1))->is_avalible) ||
                (!(espacios->begin() + (i + 1))->is_avalible) && (!(espacios->begin() + (i + 2))->is_avalible) ||
                (!(espacios->begin() + i)->is_avalible) && (!(espacios->begin() + (i + 2))->is_avalible))
            {
                if (((espacios->begin() + i)->is_avalible))
                {
                    (espacios->begin() + i)->Re_Create(sign);
                    return true;
                }
                if (((espacios->begin() + i + 1)->is_avalible))
                {
                    (espacios->begin() + i + 1)->Re_Create(sign);
                    return true;
                }
                if (((espacios->begin() + i + 2)->is_avalible))
                {
                    (espacios->begin() + i + 2)->Re_Create(sign);
                    return true;
                }

            }


        }

    }



    //defensa vertical
    for (size_t i = 0; i < 3; i += 1)
    {
        if (((espacios->begin() + i)->is_avalible) || ((espacios->begin() + (i + 3))->is_avalible) || ((espacios->begin() + (i + 6))->is_avalible))
        {


            if ((!(espacios->begin() + i)->is_avalible) && (!(espacios->begin() + (i + 3))->is_avalible) ||
                (!(espacios->begin() + (i + 3))->is_avalible) && (!(espacios->begin() + (i + 6))->is_avalible) ||
                (!(espacios->begin() + i)->is_avalible) && (!(espacios->begin() + (i + 6))->is_avalible))
            {
                if (((espacios->begin() + i)->is_avalible))
                {
                    (espacios->begin() + i)->Re_Create(sign);
                    return true;
                }
                if (((espacios->begin() + i + 3)->is_avalible))
                {
                    (espacios->begin() + i + 3)->Re_Create(sign);
                    return true;
                }
                if (((espacios->begin() + i + 6)->is_avalible))
                {
                    (espacios->begin() + i + 6)->Re_Create(sign);
                    return true;
                }

            }


        }

    }


    return false;

}

void Marcar_IA(std::vector<btnmg3>* espacios, int sign)
{
    int selection = rand() % 9;

    if (Defender_IA(espacios, sign))
    {
        return;
    }


    while (true)
    {
        auto a = espacios->begin() + selection;

        if (a->is_avalible)
        {
            a->Re_Create(sign);
            break;
        }
        else
        {
            selection = rand() % 9;
        }
    }



}

bool Click_table(std::vector<btnmg3>* espacios, int sign)
{
    int x, y;
    SDL_GetMouseState(&x, &y);

    for (auto i = espacios->begin(); i < espacios->end(); i++)
    {

        if ((x > i->positonAndSize.x && x < i->positonAndSize.x + i->positonAndSize.w) && (y > i->positonAndSize.y && y < i->positonAndSize.y + i->positonAndSize.h))
        {
            i->Re_Create(sign);
            return true;
            break;
        }

    }


    return false;


}

int  click_Answer(std::vector<SDL_Rect>QUESTIONANS, int Question)
{
    int respuestas[] = { 1,2,1,4,4,1,1,3,1 };
    int x, y;
    SDL_GetMouseState(&x, &y);
    int cont = 0;

    for (auto i = QUESTIONANS.begin(); i < QUESTIONANS.end(); i++)
    {


        if ((x > i->x && x < i->x + i->w) && (y > i->y && y < i->y + i->h))
        {
            std::cout << "pregunta : " << respuestas[Question] - 1 << std::endl;
            std::cout << "btn : " << cont << std::endl;

            if (respuestas[Question] - 1 == cont)
            {
                return 1;
            }
            else
            {
                return 2;
            }
            break;
        }

        cont++;
    }


    return 0;
}

int Verificar_Partida(std::vector<btnmg3>* espacios)
{
    for (size_t i = 1; i < 3; i++)
    {


        //verificacion vertical

        if ((espacios->begin())->sign == (espacios->begin() + 3)->sign && (espacios->begin())->sign == (espacios->begin() + 6)->sign && (espacios->begin())->sign == i)
        {
            return i;
        }
        if ((espacios->begin() + 1)->sign == (espacios->begin() + 4)->sign && (espacios->begin() + 1)->sign == (espacios->begin() + 7)->sign && (espacios->begin() + 1)->sign == i)
        {
            return i;
        }
        if ((espacios->begin() + 2)->sign == (espacios->begin() + 5)->sign && (espacios->begin() + 2)->sign == (espacios->begin() + 8)->sign && (espacios->begin() + 2)->sign == i)
        {
            return i;
        }

        //verificiar horizontal

        if ((espacios->begin())->sign == (espacios->begin() + 1)->sign && (espacios->begin())->sign == (espacios->begin() + 2)->sign && (espacios->begin())->sign == i)
        {
            return i;
        }
        if ((espacios->begin() + 3)->sign == (espacios->begin() + 4)->sign && (espacios->begin() + 3)->sign == (espacios->begin() + 5)->sign && (espacios->begin() + 3)->sign == i)
        {
            return i;
        }
        if ((espacios->begin() + 6)->sign == (espacios->begin() + 7)->sign && (espacios->begin() + 6)->sign == (espacios->begin() + 8)->sign && (espacios->begin() + 6)->sign == i)
        {
            return i;
        }

        //verificar cruz
        if ((espacios->begin())->sign == (espacios->begin() + 4)->sign && (espacios->begin())->sign == (espacios->begin() + 8)->sign && (espacios->begin())->sign == i)
        {
            return i;
        }

        if ((espacios->begin() + 2)->sign == (espacios->begin() + 4)->sign && (espacios->begin() + 2)->sign == (espacios->begin() + 6)->sign && (espacios->begin() + 2)->sign == i)
        {
            return i;
        }
    }

    for (auto i = espacios->begin(); i < espacios->end(); i++)
    {
        if (i->is_avalible)
        {
            return 0;
        }

    }



    return 3;
}

void Reset(std::vector<btnmg3>* espacios)
{
    for (auto i = espacios->begin(); i < espacios->end(); i++)
    {
        i->Clear();
    }
}


bool Espacios_llenos(std::vector<btnmg3>* espacios)
{
    for (auto i = espacios->begin(); i < espacios->end(); i++)
    {
        if (i->is_avalible)
        {
            return false;
        }
    }

    return true;
}