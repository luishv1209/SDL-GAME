#include "map.h"
#include "Minijuegos.h"
#include "boton.h"
#include "score.h"
#include <SDL_ttf.h>
#include <string>

void rendermap(SDL_Renderer* r)
{
    bool quit = false;
    int pos = 1;

    SDL_Event event;

    while (!quit)
    {
        puntaje::score = puntaje::user->score_mg1 + puntaje::user->score_mg2 + puntaje::user->score_mg3 + puntaje::user->score_mg4;

        //RECOGE LOS EVENTOS QUE SUCEDEN EN LA WINDOW
        SDL_WaitEvent(&event);

        switch (event.type) // COMPARA EL TYPO DE EVENTO
        {
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_RIGHT)
            {
                if (pos < 4)
                {
                    pos += 1;

                }
            }
            else if (event.key.keysym.sym == SDLK_LEFT)
            {
                if (pos > 1)
                {
                    pos -= 1;

                }
            }
            else if (event.key.keysym.sym == 13)
            {
                switch (pos)
                {
                case 1:
                    RenderGame1(r);
                    puntaje::score = puntaje::user->score_mg1 + puntaje::user->score_mg2 + puntaje::user->score_mg3 + puntaje::user->score_mg4;
                    break;
                case 2:
                    if (puntaje::score >= 200)
                    {
                        RenderGame2(r);
                        puntaje::score = puntaje::user->score_mg1 + puntaje::user->score_mg2 + puntaje::user->score_mg3 + puntaje::user->score_mg4;

                    }
                    break;
                case 3:
                    if (puntaje::score >= 500)
                    {
                        RenderGame3(r);
                        puntaje::score = puntaje::user->score_mg1 + puntaje::user->score_mg2 + puntaje::user->score_mg3 + puntaje::user->score_mg4;

                    }
                    break;
                case 4:
                    if (puntaje::score >= 800)
                    {
                        RenderGame4(r);
                        puntaje::score = puntaje::user->score_mg1 + puntaje::user->score_mg2 + puntaje::user->score_mg3 + puntaje::user->score_mg4;
                    }
                    break;
                }
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            if (SDL_BUTTON(SDL_BUTTON_LEFT)) {

                if (MouseClickButton_map() == 1 || MouseClickButton_map() == -1)
                {

                    pos += MouseClickButton_map();
                    if (pos < 1 || pos > 4)
                    {
                        pos = 1;
                    }

                }
                else if (MouseClickButton_map() == -2)
                {
                    quit = true;
                }
                else if (MouseClickButton_map() == 2)
                {
                    switch (pos)
                    {
                    case 1:
                        RenderGame1(r);
                        puntaje::score = puntaje::user->score_mg1 + puntaje::user->score_mg2 + puntaje::user->score_mg3 + puntaje::user->score_mg4;

                        break;
                    case 2:
                        if (puntaje::score >= 200)
                        {
                            RenderGame2(r);
                            puntaje::score = puntaje::user->score_mg1 + puntaje::user->score_mg2 + puntaje::user->score_mg3 + puntaje::user->score_mg4;

                        }
                        break;
                    case 3:
                        if (puntaje::score >= 500)
                        {
                            RenderGame3(r);
                            puntaje::score = puntaje::user->score_mg1 + puntaje::user->score_mg2 + puntaje::user->score_mg3 + puntaje::user->score_mg4;

                        }
                        break;
                    case 4:
                        if (puntaje::score >= 800)
                        {
                            RenderGame4(r);
                            puntaje::score = puntaje::user->score_mg1 + puntaje::user->score_mg2 + puntaje::user->score_mg3 + puntaje::user->score_mg4;
                        }
                        break;
                    }



                }


            }
            break;
        case SDL_QUIT:
            quit = true;
            break;
        }




        drawmap(r, pos);

        //LIMPA LA PANTALLA
        SDL_RenderClear(r);
    }





}



void drawmap(SDL_Renderer* r, int opt)
{



    //SDL_RenderPresent(r);
    int posix, posiy;
    if (opt == 1)
    {

        posix = 490;
        posiy = 70;//POS DE INICIO
    }
    else if (opt == 2)
    {
        posix = 488;// POS DE SALIDA
        posiy = 220;//POS DE INICIO

    }
    else if (opt == 3)
    {
        posix = 310;// POS DE SALIDA
        posiy = 420;//POS DE INICIO

    }
    else if (opt == 4)
    {
        posix = 740;// POS DE SALIDA
        posiy = 370;//POS DE INICIO

    }

    //PINTA EL SCORE
    TTF_Init();

    TTF_Font* FONT = TTF_OpenFont("./resource/m12.TTF", 24); //abre la fuente y establece el tamaño

    SDL_Color color = { 255, 255, 255 };  //establece el color usando rgb

    std::string puntaje = "PUNTAJE --- " + std::to_string(puntaje::score);

    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(FONT, puntaje.c_str(), color); //establece el mensaje

    SDL_Texture* Message = SDL_CreateTextureFromSurface(r, surfaceMessage); //lo convierte en una textura

    SDL_Rect Message_rect; //create a rect
    Message_rect.x = 610;  //controls the rect's x coordinate 
    Message_rect.y = 3; // controls the rect's y coordinte
    Message_rect.w = 100; // controls the width of the rect
    Message_rect.h = 25; // controls the height of the rect





    //RECOGE LAS IMAGENES
    SDL_Surface* fondo = SDL_LoadBMP("./resource/map.bmp");
    SDL_Surface* character = SDL_LoadBMP("./resource/map_character.bmp");
    SDL_Surface* leftA = SDL_LoadBMP("./resource/leftA.bmp");
    SDL_Surface* RightA = SDL_LoadBMP("./resource/rightA.bmp");
    SDL_Surface* Homebtn = SDL_LoadBMP("./resource/homebtn.bmp");
    SDL_Surface* startbtn = SDL_LoadBMP("./resource/start.bmp");




    //CREA LAS TEXTURAS CON LAS IMAGENES RECOGIDAS
    SDL_Texture* texture = SDL_CreateTextureFromSurface(r, fondo);
    SDL_Texture* T_CHAR = SDL_CreateTextureFromSurface(r, character);
    SDL_Texture* T_AL = SDL_CreateTextureFromSurface(r, leftA);
    SDL_Texture* T_AR = SDL_CreateTextureFromSurface(r, RightA);
    SDL_Texture* T_Home = SDL_CreateTextureFromSurface(r, Homebtn);
    SDL_Texture* T_start = SDL_CreateTextureFromSurface(r, startbtn);





    //ESTABLECE EL TAMÑAO Y POSICION DE los botones
    const SDL_Rect resize = { posix,posiy,35,40 };
    const SDL_Rect size_T_AL = { 20,550,40,40 };
    const SDL_Rect size_T_RA = { 70,550,40,40 };
    const SDL_Rect size_T_HOME = { 10,10,40,40 };
    const SDL_Rect size_T_start = { 700,500,100,100 };







    //PINTA EN PANTALLA
    SDL_RenderCopy(r, texture, NULL, NULL);
    SDL_RenderCopy(r, T_CHAR, NULL, &resize);
    SDL_RenderCopy(r, T_AL, NULL, &size_T_AL);
    SDL_RenderCopy(r, T_AR, NULL, &size_T_RA);
    SDL_RenderCopy(r, T_Home, NULL, &size_T_HOME);
    SDL_RenderCopy(r, T_start, NULL, &size_T_start);
    SDL_RenderCopy(r, Message, NULL, &Message_rect);



    SDL_RenderPresent(r);


    //limpia la memoria 
    SDL_DestroyTexture(texture);
    SDL_DestroyTexture(T_CHAR);
    SDL_DestroyTexture(T_AR);
    SDL_DestroyTexture(T_AL);
    SDL_DestroyTexture(T_Home);
    SDL_DestroyTexture(T_start);
    SDL_DestroyTexture(Message);



    SDL_FreeSurface(fondo);
    SDL_FreeSurface(character);
    SDL_FreeSurface(leftA);
    SDL_FreeSurface(RightA);
    SDL_FreeSurface(Homebtn);
    SDL_FreeSurface(startbtn);
    SDL_FreeSurface(surfaceMessage);






}




int MouseClickButton_map()
{

    int a, b;
    SDL_GetMouseState(&a, &b);

    if ((a > 20 && a <= 60) && (b > 550 && b < 590))
    {
        return -1;
    }

    if ((a > 70 && a <= 110) && (b > 550 && b < 590))
    {
        return 1;
    }

    if ((a > 10 && a <= 50) && (b > 10 && b < 50))
    {
        return -2;
    }


    if ((a > 700 && a <= 800) && (b > 500 && b < 600))
    {
        return 2;
    }



    return 0;

}
