#include "Login_And_Registre.h"
#include <string>
#include <SDL_ttf.h>




bool Detect_CLick(SDL_Rect object_size_position)
{

    int posx, posy;
    SDL_GetMouseState(&posx, &posy);


    if ((posx >= object_size_position.x && posx <= object_size_position.x + object_size_position.w) && (posy >= object_size_position.y && posy <= object_size_position.y + object_size_position.h))
    {
        return true;
    }
    return false;


}



char Get_letter_press(SDL_Event* event)
{
    if (event->key.keysym.sym == SDLK_a)
    {
        return 'A';
    }
    if (event->key.keysym.sym == SDLK_b)
    {
        return 'B';
    }
    if (event->key.keysym.sym == SDLK_c)
    {
        return 'C';
    }
    if (event->key.keysym.sym == SDLK_d)
    {
        return 'D';
    }
    if (event->key.keysym.sym == SDLK_e)
    {
        return 'E';
    }
    if (event->key.keysym.sym == SDLK_f)
    {
        return 'F';
    }
    if (event->key.keysym.sym == SDLK_g)
    {
        return 'G';
    }
    if (event->key.keysym.sym == SDLK_h)
    {
        return 'H';
    }
    if (event->key.keysym.sym == SDLK_i)
    {
        return 'I';
    }
    if (event->key.keysym.sym == SDLK_j)
    {
        return 'J';
    }
    if (event->key.keysym.sym == SDLK_k)
    {
        return 'K';
    }
    if (event->key.keysym.sym == SDLK_l)
    {
        return 'L';
    }
    if (event->key.keysym.sym == SDLK_m)
    {
        return 'M';
    }
    if (event->key.keysym.sym == SDLK_n)
    {
        return 'N';
    }
    if (event->key.keysym.sym == SDLK_o)
    {
        return 'O';
    }
    if (event->key.keysym.sym == SDLK_p)
    {
        return 'P';
    }
    if (event->key.keysym.sym == SDLK_q)
    {
        return 'Q';
    }
    if (event->key.keysym.sym == SDLK_r)
    {
        return 'R';
    }
    if (event->key.keysym.sym == SDLK_s)
    {
        return 'S';
    }
    if (event->key.keysym.sym == SDLK_t)
    {
        return 'T';
    }
    if (event->key.keysym.sym == SDLK_u)
    {
        return 'U';
    }
    if (event->key.keysym.sym == SDLK_v)
    {
        return 'V';
    }
    if (event->key.keysym.sym == SDLK_w)
    {
        return 'W';
    }
    if (event->key.keysym.sym == SDLK_x)
    {
        return 'X';
    }
    if (event->key.keysym.sym == SDLK_y)
    {
        return 'Y';
    }
    if (event->key.keysym.sym == SDLK_z)
    {
        return 'Z';
    }
    if (event->key.keysym.sym == SDLK_BACKSPACE)
    {
        return '_';
    }

    return '|';


}


void render_login(SDL_Renderer* r)
{

    TTF_Init();
    TTF_Font* FONT = TTF_OpenFont("./resource/MG3T/mg3_font.TTF", 24); //abre la fuente y establece el tamaño


    SDL_Color color = { 0,0,0 };
    // bool que permite que el render se mantenga
    bool quit = false;
    bool on_text_box = false;


    std::string user;
    User* u_temp = nullptr;

    SDL_Event event;

    SDL_Surface* fondo = SDL_LoadBMP("./resource/login/background.bmp");
    SDL_Texture* fondo_text = SDL_CreateTextureFromSurface(r, fondo);

    SDL_Surface* text_box = SDL_LoadBMP("./resource/login/text-box.bmp");
    SDL_Texture* text_box_text = SDL_CreateTextureFromSurface(r, text_box);
    SDL_Rect size_text_box = { 180,150,400,100 };


    SDL_Surface* btn_signup = SDL_LoadBMP("./resource/login/sign_up.bmp");
    SDL_Texture* text_btn_signup = SDL_CreateTextureFromSurface(r, btn_signup);
    SDL_Rect size_btn_signup = { 280,250,200,100 };




    SDL_Surface* surf_TEXT = TTF_RenderText_Solid(FONT, user.c_str(), color); //establece el mensaje
    SDL_Texture* text_user = SDL_CreateTextureFromSurface(r, surf_TEXT); //establece el mensaje
    SDL_Rect user_size = { 190,165,20,85 };

    char let;
    bool coincidencia = false;


    while (!quit)
    {

        //RECOGE LOS EVENTOS QUE SUCEDEN EN LA WINDOW
        SDL_WaitEvent(&event);


        switch (event.type) // COMPARA EL TYPO DE EVENTO
        {
        case SDL_KEYDOWN:
            if (on_text_box)
            {

                let = Get_letter_press(&event);
                if (let == '_')
                {
                    if (user.length() > 0)
                    {
                        user = user.substr(0, user.length() - 1);

                        surf_TEXT = TTF_RenderText_Solid(FONT, user.c_str(), color);
                        text_user = SDL_CreateTextureFromSurface(r, surf_TEXT); //

                        if (user_size.w > 20)
                        {
                            user_size.w -= 20;

                        }


                    }
                }
                else if (let == '|')
                {


                }
                else if (user.length() < 20)
                {
                    user += let;


                    SDL_DestroyTexture(text_user);
                    SDL_FreeSurface(surf_TEXT);
                    if (user_size.w < 380)
                    {
                        user_size.w += 20;

                    }


                    surf_TEXT = TTF_RenderText_Solid(FONT, user.c_str(), color);
                    text_user = SDL_CreateTextureFromSurface(r, surf_TEXT); //


                }




            }


            break;
        case SDL_MOUSEBUTTONDOWN:
            if (Detect_CLick(size_text_box))
            {
                on_text_box = true;
            }
            else
            {
                on_text_box = false;
            }

            if (Detect_CLick(size_btn_signup))
            {
                if (user.length() > 0)
                {
                    for (auto i = 0; i < puntaje::users->size(); i++)
                    {
                        if (strcmp(user.c_str(), (*puntaje::users)[i].name) == 0)
                        {
                            puntaje::user = &(*puntaje::users)[i];
                            coincidencia = true;
                        }


                    }


                    if (!coincidencia)
                    {
                        User new_user;
                        strcpy_s(new_user.name, user.c_str());
                        puntaje::users->push_back(new_user);

                        for (auto i = 0; i < puntaje::users->size(); i++)
                        {
                            if (strcmp(user.c_str(), (*puntaje::users)[i].name) == 0)
                            {
                                puntaje::user = &(*puntaje::users)[i];
                            }


                        }



                    }

                    return;
                }

            }



            break;
        }



        SDL_RenderCopy(r, fondo_text, NULL, NULL);
        SDL_RenderCopy(r, text_box_text, NULL, &size_text_box);
        SDL_RenderCopy(r, text_user, NULL, &user_size);
        SDL_RenderCopy(r, text_btn_signup, NULL, &size_btn_signup);



        SDL_RenderPresent(r);

        SDL_RenderClear(r);
        //LIMPA LA PANTALLA
    }





}
