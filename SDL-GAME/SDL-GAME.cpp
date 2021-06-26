

#include "SDL.h"
#include "Render.h"
#include "map.h"
#include "boton.h"
#include <vector>
#include "Login_And_Registre.h"
#include <fstream>
#include <iostream>

int main(int argc, char* argv[])
{

    std::vector<User> users;

    //User usertemp;
    //strcpy_s(usertemp.name, "enny");
    //usertemp.score_mg1 = 1030;
    //usertemp.score_mg2 = 120;
    //usertemp.score_mg3 = 320;
    //usertemp.score_mg4 = 200;

|
    //std::ofstream ofst;
    //ofst.open("./registro.dat", std::ios::out | std::ios::binary | std::ios::trunc);
    //ofst.write((char*)&usertemp, sizeof(usertemp));
    //ofst.close();



    User usertemp;

    std::ifstream ifs;
    ifs.open("./registro.dat", std::ios::binary | std::ios::in);


    if (!ifs)
    {
        std::cout << "error";

    }
    else
    {
        ifs.read((char*)&usertemp, sizeof(usertemp));
        users.push_back(usertemp);
        while (!ifs.eof())
        {
            ifs.read((char*)&usertemp, sizeof(usertemp));
            if (ifs.eof()) {
                break;
            }
            users.push_back(usertemp);

        }

    }


    puntaje::users = &users;



    for (size_t i = 0; i < users.size(); i++)
    {
        std::cout << users[i].name << " " << users[i].score_mg1 << " " << users[i].score_mg2 << " " << users[i].score_mg3 << " " << users[i].score_mg4;
    }

    // bool que permite que el render se mantenga
    bool quit = false;

    //clase que contiene los que estan ocurriendo
    SDL_Event event;

    //inicializa todo
    SDL_Init(SDL_INIT_EVERYTHING);

    // crea una ventana apuntador 
    SDL_Window* window = SDL_CreateWindow("GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);


    //INDICADOR DE OPCIONES
    int pos = 1;




    while (!quit)
    {

        //RECOGE LOS EVENTOS QUE SUCEDEN EN LA WINDOW
        SDL_WaitEvent(&event);


        switch (event.type) // COMPARA EL TYPO DE EVENTO
        {
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_RIGHT)
            {
                if (pos < 3)
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
                if (pos == 3)
                {
                    quit = true;

                    std::ofstream ofst;
                    ofst.open("./registro.dat", std::ios::out | std::ios::binary | std::ios::trunc);


                    for (size_t i = 0; i < users.size(); i++)
                    {
                        ofst.write((char*)&users[i], sizeof(usertemp));
                    }


                    ofst.close();
                }
                else if (pos == 1)
                {
                    render_login(renderer);
                    rendermap(renderer);
                }
                else if (pos == 2)
                {

                    for (size_t i = 0; i < users.size(); i++)
                    {
                        for (size_t j = 0; j < users.size() - 1; j++)
                        {
                            if ((users[j].score_mg1 + users[j].score_mg2 + users[j].score_mg3 + users[j].score_mg4) < (users[j + 1].score_mg1 + users[j + 1].score_mg2 + users[j + 1].score_mg3 + users[j + 1].score_mg4))
                            {
                                User temp = users[j];
                                users[j] = users[j + 1];
                                users[j + 1] = temp;
                            }
                        }
                    }
                    std::cout << "\n";

                    for (size_t i = 0; i < users.size(); i++)
                    {
                        std::cout << users[i].name << " " << users[i].score_mg1 << " " << users[i].score_mg2 << " " << users[i].score_mg3 << " " << users[i].score_mg4 << "\n";
                    }

                    Render_Estadisticas(renderer);




                }
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            if (SDL_BUTTON(SDL_BUTTON_LEFT)) {


                if (MouseClickButton() == 1)
                {
                    render_login(renderer);
                    rendermap(renderer);


                }
                else if (MouseClickButton() == 3)
                {
                    quit = true;


                    std::ofstream ofst;
                    ofst.open("./registro.dat", std::ios::out | std::ios::binary | std::ios::trunc);


                    for (size_t i = 0; i < users.size(); i++)
                    {
                        ofst.write((char*)&users[i], sizeof(usertemp));
                    }


                    ofst.close();

                }
                else if (MouseClickButton() == 2)
                {
                    for (size_t i = 0; i < users.size(); i++)
                    {
                        for (size_t j = 0; j < users.size() - 1; j++)
                        {
                            if ((users[j].score_mg1 + users[j].score_mg2 + users[j].score_mg3 + users[j].score_mg4) < (users[j + 1].score_mg1 + users[j + 1].score_mg2 + users[j + 1].score_mg3 + users[j + 1].score_mg4))
                            {
                                User temp = users[j];
                                users[j] = users[j + 1];
                                users[j + 1] = temp;
                            }
                        }
                    }
                    std::cout << "\n";

                    for (size_t i = 0; i < users.size(); i++)
                    {
                        std::cout << users[i].name << " " << users[i].score_mg1 << " " << users[i].score_mg2 << " " << users[i].score_mg3 << " " << users[i].score_mg4 << "\n";
                    }

                    Render_Estadisticas(renderer);

                }
            }
            break;
        case SDL_QUIT:
            quit = true;
            break;
        }

        RenderWindow(renderer, pos);

        //LIMPA LA PANTALLA
        SDL_RenderClear(renderer);
    }



    return 0;
}
