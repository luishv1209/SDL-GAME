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
#include "funcionesMg1.h"
#include "funcionesMg2.h"
#include "funcionesMg3.h"
#include "funcionesMg4.h"
#include "botonmg3.h"
#include "botonmg4.h"






void RenderGame1(SDL_Renderer* r)
{
    int pregunta = 0; // variable de 1 -15 que representa la pregunta seleccionada
    int respuesta = 0;//variable de 1 -15 que representa la respuesta seleccionada
    int id_respuesta = 0; // respresenta la respuesta que se escogio -- variable
    int vidas = 3;// VIDAS
    std::vector<int> respuesta_acaparadas; // respuestas ya usadas
    std::vector<int> preguntas_usadas; // preguntas ya usadas
    bool quit = false; // mantiene el ciclo del juego abierto
    SDL_Event event;
    std::string direccion_pregunta = "./resource/MG1P/";
    TTF_Font* FONT = TTF_OpenFont("./resource/m12.TTF", 24); //abre la fuente y establece el tamaño
    int respuesta_mostrar = 0;
    puntaje::user->score_mg1 = 0;

    //pregunta random 1-15
    pregunta = rand() % 15 + 1; // numero aleatorio del 1 - 15
    preguntas_usadas.push_back(pregunta); // agrega al vector de preguntas usadas
    direccion_pregunta += std::to_string(pregunta) + ".bmp"; // asigna la direccion de la pregunta
    asignar_respuesta(pregunta, &respuesta); // busca la respuesta en base la pregunta



    //crear los botones de respuestas 
    std::string direccion_respuesta = "./resource/MG1P/";
    direccion_respuesta += std::to_string(pregunta) + "/"; // concatena para entrar al fichero de las respuesta de la pregunta
    std::string* direccion = new std::string();
    Generarbtn_respuesta(direccion_respuesta.c_str(), &respuesta_acaparadas, r, direccion, &id_respuesta); // genera una direcion y un id_respuesta para el boton
    BTN* res1 = new BTN(10, 20, 250, 100, r, direccion->c_str(), id_respuesta);
    Generarbtn_respuesta(direccion_respuesta.c_str(), &respuesta_acaparadas, r, direccion, &id_respuesta);
    BTN* res2 = new BTN(250, 20, 250, 100, r, direccion->c_str(), id_respuesta);
    Generarbtn_respuesta(direccion_respuesta.c_str(), &respuesta_acaparadas, r, direccion, &id_respuesta);
    BTN* res3 = new BTN(10, 100, 250, 100, r, direccion->c_str(), id_respuesta);
    Generarbtn_respuesta(direccion_respuesta.c_str(), &respuesta_acaparadas, r, direccion, &id_respuesta);
    BTN* res4 = new BTN(250, 100, 250, 100, r, direccion->c_str(), id_respuesta);


    TTF_Init(); //inicializa lo de escribir

    while (!quit)
    {

        SDL_WaitEvent(&event);

        switch (event.type) // COMPARA EL TYPO DE EVENTO
        {
        case SDL_MOUSEBUTTONDOWN:
            if (SDL_BUTTON(SDL_BUTTON_LEFT)) {

                quit = Exitbtn();

                int a, b;
                SDL_GetMouseState(&a, &b);

                //si las cordenadas del mouse concuerdan con el boton 
                if ((a > res1->positonAndSize.x && a <= res1->positonAndSize.w + res1->positonAndSize.x) && (b > res1->positonAndSize.y && b < res1->positonAndSize.h + res1->positonAndSize.y))
                {

                    if (res1->no_respuesta == respuesta) // si el no_respuesta del btn1 es igual a la respuesta de la pregunta
                    {
                        respuesta_mostrar = 1;
                        std::cout << "CORRECTO";
                        if (puntaje::user->score_mg1 <= 200) {
                            puntaje::user->score_mg1 += 30;
                            if (puntaje::user->score_mg1 > 200)
                            {
                                puntaje::user->score_mg1 = 200;
                            }
                        }
                    }
                    else
                    {
                        respuesta_mostrar = 2;
                        std::cout << "INCORRECTO";
                        puntaje::user->score_mg1 -= 10;
                        vidas--;
                    }

                    if (preguntas_usadas.size() >= 15 || vidas <= 0)
                    {
                        quit = true;
                        break;
                    }

                    Actualizar_PreguntasyRespuestas(res1, res2, res3, res4, &pregunta, &respuesta, &direccion_pregunta,
                        &preguntas_usadas, &respuesta_acaparadas, r, &id_respuesta,
                        &direccion_respuesta, direccion);
                    Generarbtn_respuesta(direccion_respuesta.c_str(), &respuesta_acaparadas, r, direccion, &id_respuesta);
                    res1 = new BTN(10, 20, 250, 100, r, direccion->c_str(), id_respuesta);
                    Generarbtn_respuesta(direccion_respuesta.c_str(), &respuesta_acaparadas, r, direccion, &id_respuesta);
                    res2 = new BTN(250, 20, 250, 100, r, direccion->c_str(), id_respuesta);
                    Generarbtn_respuesta(direccion_respuesta.c_str(), &respuesta_acaparadas, r, direccion, &id_respuesta);
                    res3 = new BTN(10, 100, 250, 100, r, direccion->c_str(), id_respuesta);
                    Generarbtn_respuesta(direccion_respuesta.c_str(), &respuesta_acaparadas, r, direccion, &id_respuesta);
                    res4 = new BTN(250, 100, 250, 100, r, direccion->c_str(), id_respuesta);






                }
                else if ((a > res2->positonAndSize.x && a <= res2->positonAndSize.w + res2->positonAndSize.x) && (b > res2->positonAndSize.y && b < res2->positonAndSize.h + res2->positonAndSize.y))
                {

                    if (res2->no_respuesta == respuesta)
                    {
                        std::cout << "CORRECTO";
                        if (puntaje::user->score_mg1 < 200) { puntaje::user->score_mg1 += 30; }
                        respuesta_mostrar = 1;

                    }
                    else
                    {
                        std::cout << "INCORRECTO";
                        vidas--;
                        respuesta_mostrar = 2;

                    }


                    if (preguntas_usadas.size() >= 15 || vidas <= 0)
                    {
                        quit = true;
                        break;
                    }

                    Actualizar_PreguntasyRespuestas(res1, res2, res3, res4, &pregunta, &respuesta, &direccion_pregunta, &preguntas_usadas, &respuesta_acaparadas, r, &id_respuesta, &direccion_respuesta, direccion);
                    Generarbtn_respuesta(direccion_respuesta.c_str(), &respuesta_acaparadas, r, direccion, &id_respuesta);
                    res1 = new BTN(10, 20, 250, 100, r, direccion->c_str(), id_respuesta);
                    Generarbtn_respuesta(direccion_respuesta.c_str(), &respuesta_acaparadas, r, direccion, &id_respuesta);
                    res2 = new BTN(250, 20, 250, 100, r, direccion->c_str(), id_respuesta);
                    Generarbtn_respuesta(direccion_respuesta.c_str(), &respuesta_acaparadas, r, direccion, &id_respuesta);
                    res3 = new BTN(10, 100, 250, 100, r, direccion->c_str(), id_respuesta);
                    Generarbtn_respuesta(direccion_respuesta.c_str(), &respuesta_acaparadas, r, direccion, &id_respuesta);
                    res4 = new BTN(250, 100, 250, 100, r, direccion->c_str(), id_respuesta);

                }
                else if ((a > res3->positonAndSize.x && a <= res3->positonAndSize.w + res3->positonAndSize.x) && (b > res3->positonAndSize.y && b < res3->positonAndSize.h + res3->positonAndSize.y))
                {

                    if (res3->no_respuesta == respuesta)
                    {
                        respuesta_mostrar = 1;
                        std::cout << "CORRECTO";
                        if (puntaje::user->score_mg1 < 200) { puntaje::user->score_mg1 += 30; }

                    }
                    else
                    {
                        respuesta_mostrar = 2;
                        std::cout << "INCORRECTO";
                        vidas--;

                    }


                    if (preguntas_usadas.size() >= 15 || vidas <= 0)
                    {
                        quit = true;
                        break;
                    }

                    Actualizar_PreguntasyRespuestas(res1, res2, res3, res4, &pregunta, &respuesta, &direccion_pregunta, &preguntas_usadas, &respuesta_acaparadas, r, &id_respuesta, &direccion_respuesta, direccion);
                    Generarbtn_respuesta(direccion_respuesta.c_str(), &respuesta_acaparadas, r, direccion, &id_respuesta);
                    res1 = new BTN(10, 20, 250, 100, r, direccion->c_str(), id_respuesta);
                    Generarbtn_respuesta(direccion_respuesta.c_str(), &respuesta_acaparadas, r, direccion, &id_respuesta);
                    res2 = new BTN(250, 20, 250, 100, r, direccion->c_str(), id_respuesta);
                    Generarbtn_respuesta(direccion_respuesta.c_str(), &respuesta_acaparadas, r, direccion, &id_respuesta);
                    res3 = new BTN(10, 100, 250, 100, r, direccion->c_str(), id_respuesta);
                    Generarbtn_respuesta(direccion_respuesta.c_str(), &respuesta_acaparadas, r, direccion, &id_respuesta);
                    res4 = new BTN(250, 100, 250, 100, r, direccion->c_str(), id_respuesta);

                }
                else if ((a > res4->positonAndSize.x && a <= res4->positonAndSize.w + res4->positonAndSize.x) && (b > res4->positonAndSize.y && b < res4->positonAndSize.h + res4->positonAndSize.y))
                {

                    if (res4->no_respuesta == respuesta)
                    {
                        respuesta_mostrar = 1;
                        std::cout << "CORRECTO";
                        if (puntaje::user->score_mg1 < 200) { puntaje::user->score_mg1 += 30; }

                    }
                    else
                    {
                        respuesta_mostrar = 2;
                        std::cout << "INCORRECTO";
                        vidas--;

                    }


                    if (preguntas_usadas.size() >= 15 || vidas <= 0)
                    {
                        quit = true;
                        break;
                    }

                    Actualizar_PreguntasyRespuestas(res1, res2, res3, res4, &pregunta, &respuesta, &direccion_pregunta, &preguntas_usadas, &respuesta_acaparadas, r, &id_respuesta, &direccion_respuesta, direccion);
                    Generarbtn_respuesta(direccion_respuesta.c_str(), &respuesta_acaparadas, r, direccion, &id_respuesta);
                    res1 = new BTN(10, 20, 250, 100, r, direccion->c_str(), id_respuesta);
                    Generarbtn_respuesta(direccion_respuesta.c_str(), &respuesta_acaparadas, r, direccion, &id_respuesta);
                    res2 = new BTN(250, 20, 250, 100, r, direccion->c_str(), id_respuesta);
                    Generarbtn_respuesta(direccion_respuesta.c_str(), &respuesta_acaparadas, r, direccion, &id_respuesta);
                    res3 = new BTN(10, 100, 250, 100, r, direccion->c_str(), id_respuesta);
                    Generarbtn_respuesta(direccion_respuesta.c_str(), &respuesta_acaparadas, r, direccion, &id_respuesta);
                    res4 = new BTN(250, 100, 250, 100, r, direccion->c_str(), id_respuesta);

                }
                else if ((a > res1->positonAndSize.x && a <= res1->positonAndSize.w) && (b > res1->positonAndSize.y && b < res1->positonAndSize.h))
                {

                    if (res1->no_respuesta == respuesta)
                    {
                        respuesta_mostrar = 1;
                        std::cout << "CORRECTO";
                        if (puntaje::user->score_mg1 < 200) { puntaje::user->score_mg1 += 30; }

                    }
                    else
                    {
                        respuesta_mostrar = 2;
                        std::cout << "INCORRECTO";
                        vidas--;

                    }


                    if (preguntas_usadas.size() >= 15 || vidas <= 0)
                    {
                        quit = true;
                        break;
                    }

                    Actualizar_PreguntasyRespuestas(res1, res2, res3, res4, &pregunta, &respuesta, &direccion_pregunta, &preguntas_usadas, &respuesta_acaparadas, r, &id_respuesta, &direccion_respuesta, direccion);
                    Generarbtn_respuesta(direccion_respuesta.c_str(), &respuesta_acaparadas, r, direccion, &id_respuesta);
                    res1 = new BTN(10, 20, 250, 100, r, direccion->c_str(), id_respuesta);
                    Generarbtn_respuesta(direccion_respuesta.c_str(), &respuesta_acaparadas, r, direccion, &id_respuesta);
                    res2 = new BTN(250, 20, 250, 100, r, direccion->c_str(), id_respuesta);
                    Generarbtn_respuesta(direccion_respuesta.c_str(), &respuesta_acaparadas, r, direccion, &id_respuesta);
                    res3 = new BTN(10, 100, 250, 100, r, direccion->c_str(), id_respuesta);
                    Generarbtn_respuesta(direccion_respuesta.c_str(), &respuesta_acaparadas, r, direccion, &id_respuesta);
                    res4 = new BTN(250, 100, 250, 100, r, direccion->c_str(), id_respuesta);

                }




            }
            break;


        }


        //cuadro de preguntas
        BTN* preguntaDialog = new BTN(500, 400, 300, 200, r, direccion_pregunta.c_str());


        //RECOGE LAS IMAGENES
        SDL_Surface* fondo = SDL_LoadBMP("./resource/backgroundmg1.bmp");
        SDL_Surface* returnbtn = SDL_LoadBMP("./resource/leftA.bmp");


        //CREA LAS TEXTURAS CON LAS IMAGENES RECOGIDAS
        SDL_Texture* texture = SDL_CreateTextureFromSurface(r, fondo);
        SDL_Texture* BTN_EXI = SDL_CreateTextureFromSurface(r, returnbtn);


        //ESTABLECE EL TAMÑAO Y POSICION DEL CURSOR y los botones
        const SDL_Rect resize = { 400,200,35,40 };
        const SDL_Rect size_btnexit = { 20,350,40,40 };




        //PINTA EN PANTALLA
        SDL_RenderCopy(r, texture, NULL, NULL);
        SDL_RenderCopy(r, BTN_EXI, NULL, &size_btnexit);
        SDL_RenderCopy(r, preguntaDialog->btntexture, NULL, &preguntaDialog->positonAndSize);
        SDL_RenderCopy(r, res1->btntexture, NULL, &res1->positonAndSize);
        SDL_RenderCopy(r, res2->btntexture, NULL, &res2->positonAndSize);
        SDL_RenderCopy(r, res3->btntexture, NULL, &res3->positonAndSize);
        SDL_RenderCopy(r, res4->btntexture, NULL, &res4->positonAndSize);

        //PINTA EL SCORE y las vidas


        SDL_Color color = { 255, 255, 255 };  //establece el color usando rgb

        std::string puntaje = "PUNTAJE --- " + std::to_string(puntaje::user->score_mg1);
        std::string lifes = "VIDAS --- " + std::to_string(vidas);



        SDL_Surface* surfaceMessage_score = TTF_RenderText_Solid(FONT, puntaje.c_str(), color); //establece el mensaje
        SDL_Surface* surfaceMessage_lifes = TTF_RenderText_Solid(FONT, lifes.c_str(), color); //establece el mensaje
        SDL_Surface* surfaceMessage_respuesta = NULL;

        SDL_Texture* score_text = SDL_CreateTextureFromSurface(r, surfaceMessage_score); //lo convierte en una textura
        SDL_Texture* lifes_text = SDL_CreateTextureFromSurface(r, surfaceMessage_lifes); //lo convierte en una textura
        SDL_Texture* respuesta_Text = NULL;

        SDL_Rect score_rect = { 610,3,100,25 }; //create a rect
        SDL_Rect lifes_rect = { 610,40,100,25 }; //create a rect
        SDL_Rect respu_rect = { 610,80,100,25 }; //create a rect



        if (respuesta_mostrar == 1)
        {

            if (surfaceMessage_respuesta != NULL)
            {
                SDL_FreeSurface(surfaceMessage_respuesta);
                SDL_DestroyTexture(respuesta_Text);

            }
            surfaceMessage_respuesta = TTF_RenderText_Solid(FONT, "CORRECTO", color); //establece el mensaje
            respuesta_Text = SDL_CreateTextureFromSurface(r, surfaceMessage_respuesta);

        }
        else if (respuesta_mostrar == 2)
        {

            if (surfaceMessage_respuesta != NULL)
            {
                SDL_FreeSurface(surfaceMessage_respuesta);
                SDL_DestroyTexture(respuesta_Text);

            }
            surfaceMessage_respuesta = TTF_RenderText_Solid(FONT, "INCORRECTO", color); //establece el mensaje
            respuesta_Text = SDL_CreateTextureFromSurface(r, surfaceMessage_respuesta);

        }
        else
        {

            surfaceMessage_respuesta = NULL;
        }



        SDL_RenderCopy(r, score_text, NULL, &score_rect);
        SDL_RenderCopy(r, lifes_text, NULL, &lifes_rect);

        if (surfaceMessage_respuesta != NULL)
        {
            SDL_RenderCopy(r, respuesta_Text, NULL, &respu_rect);
        }


        SDL_RenderPresent(r);

        SDL_DestroyTexture(texture);
        SDL_DestroyTexture(BTN_EXI);
        SDL_DestroyTexture(preguntaDialog->btntexture);
        SDL_DestroyTexture(score_text);
        SDL_DestroyTexture(lifes_text);



        SDL_FreeSurface(fondo);
        SDL_FreeSurface(returnbtn);
        SDL_FreeSurface(preguntaDialog->btnsurface);
        SDL_FreeSurface(surfaceMessage_score);
        SDL_FreeSurface(surfaceMessage_lifes);



    }




}
void RenderGame2(SDL_Renderer* r)
{

    /*RESPUESTAS:

       1- BODY , DIV , HTML , FORM
       2- HTML , MYSQL , CSS , JS
       3- MYSQL, SQLITE , RIAK , MSSQL
       4- ULKIT , BULMA , PURE , SUSY
       5- MEANJS , METEOR , REACT , VUE
       6- FIREFOX , CHROME , EDGE , OPERA


      */
    int game_time = 180; // tiempo de juego en segundos
    int time_start = SDL_GetTicks(); // toma el tiempo de ejecucion del programa para asi calcular los segundos que han pasado
    int nivel = 1; // nivel en el que inicia
    puntaje::user->score_mg2 = 0;
    TTF_Init(); // inicializa la lib para renderizar texto


    puntaje::user->life_mg2 = 5; // establece el numero de oportunidades
    bool quit = false;
    SDL_Event event;
    SDL_Color color = { 255, 255, 255 };  //establece el color usando rgb
    SDL_Rect time_rect = { 580,100,200,25 }; //create a rect
    SDL_Rect chance_rect = { 580,150,200,25 }; //create a rect
    SDL_Rect pregunta_rect = { 20,10,300,25 }; //create a rect
    SDL_Rect ultletra_rect = { 20,570,300,25 }; //create a rect
    SDL_Rect puntaje_rect = { 580,200,200,25 }; //create a rect


    std::string ultLetra = " ";
    std::string ultLetra_msg = "ULTIMA LETRA PRESIONADA : " + ultLetra;
    std::string puntaje = "PUNTOS : " + puntaje::user->score_mg2;


    TTF_Font* FONT = TTF_OpenFont("./resource/m12.TTF", 24); //abre la fuente y establece el tamaño

    SDL_Surface* surfaceMessage_time;//establece el mensaje
    SDL_Texture* time_text; //lo convierte en una textura

    SDL_Surface* surfaceMessage_Chance;//establece el mensaje
    SDL_Texture* Chance_text; //lo convierte en una textura

    SDL_Surface* surfaceMessage_UltLetra;//establece el mensaje
    SDL_Texture* UltLetra_text; //lo convierte en una textura

    SDL_Surface* surfaceMessage_pregunta;
    SDL_Texture* pregunta_text;

    SDL_Surface* surfaceMessage_puntaje;
    SDL_Texture* puntaje_text;

    //array de preguntas que seran mostradas por nivel
    std::string Preguntas[] = { "ETIQUETAS COMUNES EN HTML : " , "TENOLOGIAS PARA CREAR UNA PAGINA WEB : " , "MOTORES DE BASES DE DATOS : " , " FRAMEWORKS DE CSS : " , "FRAMEWORKS DE JS : ","NAVEGADORES MAS USADOS : " };

    SDL_Surface* fondo;
    SDL_Surface* returnbtn;
    SDL_Texture* texture;
    SDL_Texture* BTN_EXI;


    //creando letras


    //botonmg22 hereda de BTN , usado unicamente para este minijuego

    //palabra 1
    botonmg22* letra1_p1 = NULL;
    botonmg22* letra2_p1 = NULL;
    botonmg22* letra3_p1 = NULL;
    botonmg22* letra4_p1 = NULL;
    botonmg22* letra5_p1 = NULL;
    botonmg22* letra6_p1 = NULL;

    //palabra 2
    botonmg22* letra1_p2 = NULL;
    botonmg22* letra2_p2 = NULL;
    botonmg22* letra3_p2 = NULL;
    botonmg22* letra4_p2 = NULL;
    botonmg22* letra5_p2 = NULL;
    botonmg22* letra6_p2 = NULL;

    //palabra 3
    botonmg22* letra1_p3 = NULL;
    botonmg22* letra2_p3 = NULL;
    botonmg22* letra3_p3 = NULL;
    botonmg22* letra4_p3 = NULL;
    botonmg22* letra5_p3 = NULL;
    botonmg22* letra6_p3 = NULL;

    //palabra 4
    botonmg22* letra1_p4 = NULL;
    botonmg22* letra2_p4 = NULL;
    botonmg22* letra3_p4 = NULL;
    botonmg22* letra4_p4 = NULL;
    botonmg22* letra5_p4 = NULL;
    botonmg22* letra6_p4 = NULL;


    //varibale para pausa
    bool en_pausa = false;


    //crea las fichas de las letras segun el nivel en el que se esta
    CrearLetrasMg2(&letra1_p1, &letra2_p1, &letra3_p1, &letra4_p1, &letra5_p1, &letra6_p1,
        &letra1_p2, &letra2_p2, &letra3_p2, &letra4_p2, &letra5_p2, &letra6_p2,
        &letra1_p3, &letra2_p3, &letra3_p3, &letra4_p3, &letra5_p3, &letra6_p3,
        &letra1_p4, &letra2_p4, &letra3_p4, &letra4_p4, &letra5_p4, &letra6_p4, r, nivel);



    while (!quit)
    {

        SDL_PollEvent(&event);

        switch (event.type) // COMPARA EL TYPO DE EVENTO
        {
        case SDL_MOUSEBUTTONDOWN:

            if (SDL_BUTTON(SDL_BUTTON_LEFT)) {

                quit = Exitbtn();
            }
            if (SDL_BUTTON(SDL_BUTTON_RIGHT)) {

            }
            break;

        case SDL_KEYDOWN: //validacion de todas las letras


            if (event.key.keysym.sym == SDLK_SPACE)
            {
                en_pausa = !en_pausa;
                break;
            }

            if (en_pausa)
            {
                break;
            }

            if (event.key.keysym.sym == SDLK_a)
            {
                verificar_letra(&letra1_p1, &letra2_p1, &letra3_p1, &letra4_p1, &letra5_p1, &letra6_p1,
                    &letra1_p2, &letra2_p2, &letra3_p2, &letra4_p2, &letra5_p2, &letra6_p2,
                    &letra1_p3, &letra2_p3, &letra3_p3, &letra4_p3, &letra5_p3, &letra6_p3,
                    &letra1_p4, &letra2_p4, &letra3_p4, &letra4_p4, &letra5_p4, &letra6_p4, r, "A");

                ultLetra = "A";
            }
            if (event.key.keysym.sym == SDLK_b)
            {
                verificar_letra(&letra1_p1, &letra2_p1, &letra3_p1, &letra4_p1, &letra5_p1, &letra6_p1,
                    &letra1_p2, &letra2_p2, &letra3_p2, &letra4_p2, &letra5_p2, &letra6_p2,
                    &letra1_p3, &letra2_p3, &letra3_p3, &letra4_p3, &letra5_p3, &letra6_p3,
                    &letra1_p4, &letra2_p4, &letra3_p4, &letra4_p4, &letra5_p4, &letra6_p4, r, "B");
                ultLetra = "B";

            }
            if (event.key.keysym.sym == SDLK_c)
            {
                verificar_letra(&letra1_p1, &letra2_p1, &letra3_p1, &letra4_p1, &letra5_p1, &letra6_p1,
                    &letra1_p2, &letra2_p2, &letra3_p2, &letra4_p2, &letra5_p2, &letra6_p2,
                    &letra1_p3, &letra2_p3, &letra3_p3, &letra4_p3, &letra5_p3, &letra6_p3,
                    &letra1_p4, &letra2_p4, &letra3_p4, &letra4_p4, &letra5_p4, &letra6_p4, r, "C");
                ultLetra = "C";

            }
            if (event.key.keysym.sym == SDLK_d)
            {
                verificar_letra(&letra1_p1, &letra2_p1, &letra3_p1, &letra4_p1, &letra5_p1, &letra6_p1,
                    &letra1_p2, &letra2_p2, &letra3_p2, &letra4_p2, &letra5_p2, &letra6_p2,
                    &letra1_p3, &letra2_p3, &letra3_p3, &letra4_p3, &letra5_p3, &letra6_p3,
                    &letra1_p4, &letra2_p4, &letra3_p4, &letra4_p4, &letra5_p4, &letra6_p4, r, "D");
                ultLetra = "D";

            }
            if (event.key.keysym.sym == SDLK_e)
            {
                verificar_letra(&letra1_p1, &letra2_p1, &letra3_p1, &letra4_p1, &letra5_p1, &letra6_p1,
                    &letra1_p2, &letra2_p2, &letra3_p2, &letra4_p2, &letra5_p2, &letra6_p2,
                    &letra1_p3, &letra2_p3, &letra3_p3, &letra4_p3, &letra5_p3, &letra6_p3,
                    &letra1_p4, &letra2_p4, &letra3_p4, &letra4_p4, &letra5_p4, &letra6_p4, r, "E");
                ultLetra = "E";

            }
            if (event.key.keysym.sym == SDLK_f)
            {
                verificar_letra(&letra1_p1, &letra2_p1, &letra3_p1, &letra4_p1, &letra5_p1, &letra6_p1,
                    &letra1_p2, &letra2_p2, &letra3_p2, &letra4_p2, &letra5_p2, &letra6_p2,
                    &letra1_p3, &letra2_p3, &letra3_p3, &letra4_p3, &letra5_p3, &letra6_p3,
                    &letra1_p4, &letra2_p4, &letra3_p4, &letra4_p4, &letra5_p4, &letra6_p4, r, "F");
                ultLetra = "F";

            }
            if (event.key.keysym.sym == SDLK_g)
            {
                verificar_letra(&letra1_p1, &letra2_p1, &letra3_p1, &letra4_p1, &letra5_p1, &letra6_p1,
                    &letra1_p2, &letra2_p2, &letra3_p2, &letra4_p2, &letra5_p2, &letra6_p2,
                    &letra1_p3, &letra2_p3, &letra3_p3, &letra4_p3, &letra5_p3, &letra6_p3,
                    &letra1_p4, &letra2_p4, &letra3_p4, &letra4_p4, &letra5_p4, &letra6_p4, r, "G");
                ultLetra = "G";

            }
            if (event.key.keysym.sym == SDLK_h)
            {
                verificar_letra(&letra1_p1, &letra2_p1, &letra3_p1, &letra4_p1, &letra5_p1, &letra6_p1,
                    &letra1_p2, &letra2_p2, &letra3_p2, &letra4_p2, &letra5_p2, &letra6_p2,
                    &letra1_p3, &letra2_p3, &letra3_p3, &letra4_p3, &letra5_p3, &letra6_p3,
                    &letra1_p4, &letra2_p4, &letra3_p4, &letra4_p4, &letra5_p4, &letra6_p4, r, "H");
                ultLetra = "H";

            }
            if (event.key.keysym.sym == SDLK_i)
            {
                verificar_letra(&letra1_p1, &letra2_p1, &letra3_p1, &letra4_p1, &letra5_p1, &letra6_p1,
                    &letra1_p2, &letra2_p2, &letra3_p2, &letra4_p2, &letra5_p2, &letra6_p2,
                    &letra1_p3, &letra2_p3, &letra3_p3, &letra4_p3, &letra5_p3, &letra6_p3,
                    &letra1_p4, &letra2_p4, &letra3_p4, &letra4_p4, &letra5_p4, &letra6_p4, r, "I");
                ultLetra = "I";

            }
            if (event.key.keysym.sym == SDLK_j)
            {
                verificar_letra(&letra1_p1, &letra2_p1, &letra3_p1, &letra4_p1, &letra5_p1, &letra6_p1,
                    &letra1_p2, &letra2_p2, &letra3_p2, &letra4_p2, &letra5_p2, &letra6_p2,
                    &letra1_p3, &letra2_p3, &letra3_p3, &letra4_p3, &letra5_p3, &letra6_p3,
                    &letra1_p4, &letra2_p4, &letra3_p4, &letra4_p4, &letra5_p4, &letra6_p4, r, "J");
                ultLetra = "J";

            }
            if (event.key.keysym.sym == SDLK_k)
            {
                verificar_letra(&letra1_p1, &letra2_p1, &letra3_p1, &letra4_p1, &letra5_p1, &letra6_p1,
                    &letra1_p2, &letra2_p2, &letra3_p2, &letra4_p2, &letra5_p2, &letra6_p2,
                    &letra1_p3, &letra2_p3, &letra3_p3, &letra4_p3, &letra5_p3, &letra6_p3,
                    &letra1_p4, &letra2_p4, &letra3_p4, &letra4_p4, &letra5_p4, &letra6_p4, r, "K");
                ultLetra = "K";

            }
            if (event.key.keysym.sym == SDLK_l)
            {
                verificar_letra(&letra1_p1, &letra2_p1, &letra3_p1, &letra4_p1, &letra5_p1, &letra6_p1,
                    &letra1_p2, &letra2_p2, &letra3_p2, &letra4_p2, &letra5_p2, &letra6_p2,
                    &letra1_p3, &letra2_p3, &letra3_p3, &letra4_p3, &letra5_p3, &letra6_p3,
                    &letra1_p4, &letra2_p4, &letra3_p4, &letra4_p4, &letra5_p4, &letra6_p4, r, "L");
                ultLetra = "L";

            }
            if (event.key.keysym.sym == SDLK_m)
            {
                verificar_letra(&letra1_p1, &letra2_p1, &letra3_p1, &letra4_p1, &letra5_p1, &letra6_p1,
                    &letra1_p2, &letra2_p2, &letra3_p2, &letra4_p2, &letra5_p2, &letra6_p2,
                    &letra1_p3, &letra2_p3, &letra3_p3, &letra4_p3, &letra5_p3, &letra6_p3,
                    &letra1_p4, &letra2_p4, &letra3_p4, &letra4_p4, &letra5_p4, &letra6_p4, r, "M");
                ultLetra = "M";

            }
            if (event.key.keysym.sym == SDLK_n)
            {
                verificar_letra(&letra1_p1, &letra2_p1, &letra3_p1, &letra4_p1, &letra5_p1, &letra6_p1,
                    &letra1_p2, &letra2_p2, &letra3_p2, &letra4_p2, &letra5_p2, &letra6_p2,
                    &letra1_p3, &letra2_p3, &letra3_p3, &letra4_p3, &letra5_p3, &letra6_p3,
                    &letra1_p4, &letra2_p4, &letra3_p4, &letra4_p4, &letra5_p4, &letra6_p4, r, "N");
                ultLetra = "N";

            }
            if (event.key.keysym.sym == SDLK_o)
            {
                verificar_letra(&letra1_p1, &letra2_p1, &letra3_p1, &letra4_p1, &letra5_p1, &letra6_p1,
                    &letra1_p2, &letra2_p2, &letra3_p2, &letra4_p2, &letra5_p2, &letra6_p2,
                    &letra1_p3, &letra2_p3, &letra3_p3, &letra4_p3, &letra5_p3, &letra6_p3,
                    &letra1_p4, &letra2_p4, &letra3_p4, &letra4_p4, &letra5_p4, &letra6_p4, r, "O");
                ultLetra = "O";

            }
            if (event.key.keysym.sym == SDLK_p)
            {
                verificar_letra(&letra1_p1, &letra2_p1, &letra3_p1, &letra4_p1, &letra5_p1, &letra6_p1,
                    &letra1_p2, &letra2_p2, &letra3_p2, &letra4_p2, &letra5_p2, &letra6_p2,
                    &letra1_p3, &letra2_p3, &letra3_p3, &letra4_p3, &letra5_p3, &letra6_p3,
                    &letra1_p4, &letra2_p4, &letra3_p4, &letra4_p4, &letra5_p4, &letra6_p4, r, "P");
                ultLetra = "P";

            }
            if (event.key.keysym.sym == SDLK_q)
            {
                verificar_letra(&letra1_p1, &letra2_p1, &letra3_p1, &letra4_p1, &letra5_p1, &letra6_p1,
                    &letra1_p2, &letra2_p2, &letra3_p2, &letra4_p2, &letra5_p2, &letra6_p2,
                    &letra1_p3, &letra2_p3, &letra3_p3, &letra4_p3, &letra5_p3, &letra6_p3,
                    &letra1_p4, &letra2_p4, &letra3_p4, &letra4_p4, &letra5_p4, &letra6_p4, r, "Q");
                ultLetra = "Q";

            }
            if (event.key.keysym.sym == SDLK_r)
            {
                verificar_letra(&letra1_p1, &letra2_p1, &letra3_p1, &letra4_p1, &letra5_p1, &letra6_p1,
                    &letra1_p2, &letra2_p2, &letra3_p2, &letra4_p2, &letra5_p2, &letra6_p2,
                    &letra1_p3, &letra2_p3, &letra3_p3, &letra4_p3, &letra5_p3, &letra6_p3,
                    &letra1_p4, &letra2_p4, &letra3_p4, &letra4_p4, &letra5_p4, &letra6_p4, r, "R");
                ultLetra = "R";

            }
            if (event.key.keysym.sym == SDLK_s)
            {
                verificar_letra(&letra1_p1, &letra2_p1, &letra3_p1, &letra4_p1, &letra5_p1, &letra6_p1,
                    &letra1_p2, &letra2_p2, &letra3_p2, &letra4_p2, &letra5_p2, &letra6_p2,
                    &letra1_p3, &letra2_p3, &letra3_p3, &letra4_p3, &letra5_p3, &letra6_p3,
                    &letra1_p4, &letra2_p4, &letra3_p4, &letra4_p4, &letra5_p4, &letra6_p4, r, "S");
                ultLetra = "S";

            }
            if (event.key.keysym.sym == SDLK_t)
            {
                verificar_letra(&letra1_p1, &letra2_p1, &letra3_p1, &letra4_p1, &letra5_p1, &letra6_p1,
                    &letra1_p2, &letra2_p2, &letra3_p2, &letra4_p2, &letra5_p2, &letra6_p2,
                    &letra1_p3, &letra2_p3, &letra3_p3, &letra4_p3, &letra5_p3, &letra6_p3,
                    &letra1_p4, &letra2_p4, &letra3_p4, &letra4_p4, &letra5_p4, &letra6_p4, r, "T");
                ultLetra = "T";

            }
            if (event.key.keysym.sym == SDLK_u)
            {
                verificar_letra(&letra1_p1, &letra2_p1, &letra3_p1, &letra4_p1, &letra5_p1, &letra6_p1,
                    &letra1_p2, &letra2_p2, &letra3_p2, &letra4_p2, &letra5_p2, &letra6_p2,
                    &letra1_p3, &letra2_p3, &letra3_p3, &letra4_p3, &letra5_p3, &letra6_p3,
                    &letra1_p4, &letra2_p4, &letra3_p4, &letra4_p4, &letra5_p4, &letra6_p4, r, "U");
                ultLetra = "U";

            }
            if (event.key.keysym.sym == SDLK_v)
            {
                verificar_letra(&letra1_p1, &letra2_p1, &letra3_p1, &letra4_p1, &letra5_p1, &letra6_p1,
                    &letra1_p2, &letra2_p2, &letra3_p2, &letra4_p2, &letra5_p2, &letra6_p2,
                    &letra1_p3, &letra2_p3, &letra3_p3, &letra4_p3, &letra5_p3, &letra6_p3,
                    &letra1_p4, &letra2_p4, &letra3_p4, &letra4_p4, &letra5_p4, &letra6_p4, r, "V");
                ultLetra = "V";

            }
            if (event.key.keysym.sym == SDLK_w)
            {
                verificar_letra(&letra1_p1, &letra2_p1, &letra3_p1, &letra4_p1, &letra5_p1, &letra6_p1,
                    &letra1_p2, &letra2_p2, &letra3_p2, &letra4_p2, &letra5_p2, &letra6_p2,
                    &letra1_p3, &letra2_p3, &letra3_p3, &letra4_p3, &letra5_p3, &letra6_p3,
                    &letra1_p4, &letra2_p4, &letra3_p4, &letra4_p4, &letra5_p4, &letra6_p4, r, "W");
                ultLetra = "W";

            }
            if (event.key.keysym.sym == SDLK_x)
            {
                verificar_letra(&letra1_p1, &letra2_p1, &letra3_p1, &letra4_p1, &letra5_p1, &letra6_p1,
                    &letra1_p2, &letra2_p2, &letra3_p2, &letra4_p2, &letra5_p2, &letra6_p2,
                    &letra1_p3, &letra2_p3, &letra3_p3, &letra4_p3, &letra5_p3, &letra6_p3,
                    &letra1_p4, &letra2_p4, &letra3_p4, &letra4_p4, &letra5_p4, &letra6_p4, r, "X");
                ultLetra = "X";

            }
            if (event.key.keysym.sym == SDLK_y)
            {
                verificar_letra(&letra1_p1, &letra2_p1, &letra3_p1, &letra4_p1, &letra5_p1, &letra6_p1,
                    &letra1_p2, &letra2_p2, &letra3_p2, &letra4_p2, &letra5_p2, &letra6_p2,
                    &letra1_p3, &letra2_p3, &letra3_p3, &letra4_p3, &letra5_p3, &letra6_p3,
                    &letra1_p4, &letra2_p4, &letra3_p4, &letra4_p4, &letra5_p4, &letra6_p4, r, "Y");
                ultLetra = "Y";

            }
            if (event.key.keysym.sym == SDLK_z)
            {
                verificar_letra(&letra1_p1, &letra2_p1, &letra3_p1, &letra4_p1, &letra5_p1, &letra6_p1,
                    &letra1_p2, &letra2_p2, &letra3_p2, &letra4_p2, &letra5_p2, &letra6_p2,
                    &letra1_p3, &letra2_p3, &letra3_p3, &letra4_p3, &letra5_p3, &letra6_p3,
                    &letra1_p4, &letra2_p4, &letra3_p4, &letra4_p4, &letra5_p4, &letra6_p4, r, "Z");
                ultLetra = "Z";

            }

            //verifica si hay letras aun sin mostrar
            if (Verificar_ganar(&letra1_p1, &letra2_p1, &letra3_p1, &letra4_p1, &letra5_p1, &letra6_p1,
                &letra1_p2, &letra2_p2, &letra3_p2, &letra4_p2, &letra5_p2, &letra6_p2,
                &letra1_p3, &letra2_p3, &letra3_p3, &letra4_p3, &letra5_p3, &letra6_p3,
                &letra1_p4, &letra2_p4, &letra3_p4, &letra4_p4, &letra5_p4, &letra6_p4, r))
            {

                //libera la memoria de los apuntadores , texture , surface usados
                LimpiarLetrasMg2(&letra1_p1, &letra2_p1, &letra3_p1, &letra4_p1, &letra5_p1, &letra6_p1,
                    &letra1_p2, &letra2_p2, &letra3_p2, &letra4_p2, &letra5_p2, &letra6_p2,
                    &letra1_p3, &letra2_p3, &letra3_p3, &letra4_p3, &letra5_p3, &letra6_p3,
                    &letra1_p4, &letra2_p4, &letra3_p4, &letra4_p4, &letra5_p4, &letra6_p4, r);
                nivel++;
                puntaje::user->score_mg2 += 50;
                //crea nueva letras en base al nivel
                CrearLetrasMg2(&letra1_p1, &letra2_p1, &letra3_p1, &letra4_p1, &letra5_p1, &letra6_p1,
                    &letra1_p2, &letra2_p2, &letra3_p2, &letra4_p2, &letra5_p2, &letra6_p2,
                    &letra1_p3, &letra2_p3, &letra3_p3, &letra4_p3, &letra5_p3, &letra6_p3,
                    &letra1_p4, &letra2_p4, &letra3_p4, &letra4_p4, &letra5_p4, &letra6_p4, r, nivel);





            }




            break;

        }


        //RECOGE LAS IMAGENES
        fondo = SDL_LoadBMP("./resource/MG2L/fondo.bmp");
        returnbtn = SDL_LoadBMP("./resource/leftA.bmp");


        //CREA LAS TEXTURAS CON LAS IMAGENES RECOGIDAS
        texture = SDL_CreateTextureFromSurface(r, fondo);
        BTN_EXI = SDL_CreateTextureFromSurface(r, returnbtn);


        //ESTABLECE EL TAMÑAO Y POSICION DEL CURSOR y los botones
        const SDL_Rect resize = { 400,200,35,40 };
        const SDL_Rect size_btnexit = { 20,350,40,40 };


        //PINTA EL tiempo

        std::string str_time = "tiempo --- " + std::to_string(game_time);
        surfaceMessage_time = TTF_RenderText_Solid(FONT, str_time.c_str(), color); //establece el mensaje
        time_text = SDL_CreateTextureFromSurface(r, surfaceMessage_time);
        if (nivel < 7)
        {
            surfaceMessage_pregunta = TTF_RenderText_Solid(FONT, Preguntas[nivel - 1].c_str(), color); //establece el mensaje
            pregunta_text = SDL_CreateTextureFromSurface(r, surfaceMessage_pregunta);
        }
        else
        {
            surfaceMessage_pregunta = TTF_RenderText_Solid(FONT, Preguntas[4].c_str(), color); //establece el mensaje
            pregunta_text = SDL_CreateTextureFromSurface(r, surfaceMessage_pregunta);

        }


        //pinta el puntaje
        puntaje = "PUNTOS : " + std::to_string(puntaje::user->score_mg2);
        surfaceMessage_puntaje = TTF_RenderText_Solid(FONT, puntaje.c_str(), color);
        puntaje_text = SDL_CreateTextureFromSurface(r, surfaceMessage_puntaje);


        //oportunidades
        std::string str_chance = "OPORTUNIDADES --- " + std::to_string(puntaje::user->life_mg2);
        surfaceMessage_Chance = TTF_RenderText_Solid(FONT, str_chance.c_str(), color);
        Chance_text = SDL_CreateTextureFromSurface(r, surfaceMessage_Chance);


        //ULT LETRA

        ultLetra_msg = "ULTIMA LETRA PRESIONADA : " + ultLetra;
        if (!en_pausa)
        {
            surfaceMessage_UltLetra = TTF_RenderText_Solid(FONT, ultLetra_msg.c_str(), color);
        }
        else
        {
            surfaceMessage_UltLetra = TTF_RenderText_Solid(FONT, "EN PAUSA", color);

        }
        UltLetra_text = SDL_CreateTextureFromSurface(r, surfaceMessage_UltLetra);



        //PINTA EN PANTALLA
        SDL_RenderCopy(r, texture, NULL, NULL);
        SDL_RenderCopy(r, BTN_EXI, NULL, &size_btnexit);
        SDL_RenderCopy(r, time_text, NULL, &time_rect);
        SDL_RenderCopy(r, pregunta_text, NULL, &pregunta_rect);
        SDL_RenderCopy(r, Chance_text, NULL, &chance_rect);
        SDL_RenderCopy(r, UltLetra_text, NULL, &ultletra_rect);
        SDL_RenderCopy(r, puntaje_text, NULL, &puntaje_rect);


        //pinta las letras 
        PintarLetrasMg2(&letra1_p1, &letra2_p1, &letra3_p1, &letra4_p1, &letra5_p1, &letra6_p1,
            &letra1_p2, &letra2_p2, &letra3_p2, &letra4_p2, &letra5_p2, &letra6_p2,
            &letra1_p3, &letra2_p3, &letra3_p3, &letra4_p3, &letra5_p3, &letra6_p3,
            &letra1_p4, &letra2_p4, &letra3_p4, &letra4_p4, &letra5_p4, &letra6_p4, r, nivel);

        SDL_RenderPresent(r);

        SDL_DestroyTexture(texture);
        SDL_DestroyTexture(BTN_EXI);
        SDL_DestroyTexture(time_text);
        SDL_DestroyTexture(pregunta_text);
        SDL_DestroyTexture(Chance_text);
        SDL_DestroyTexture(UltLetra_text);
        SDL_DestroyTexture(puntaje_text);



        SDL_FreeSurface(fondo);
        SDL_FreeSurface(returnbtn);
        SDL_FreeSurface(surfaceMessage_time);
        SDL_FreeSurface(surfaceMessage_pregunta);
        SDL_FreeSurface(surfaceMessage_Chance);
        SDL_FreeSurface(surfaceMessage_UltLetra);
        SDL_FreeSurface(surfaceMessage_puntaje);


        if (int(SDL_GetTicks()) - time_start >= 1000 && !en_pausa)
        {
            game_time -= 1;
            time_start = SDL_GetTicks();

            if (game_time == 0)
            {
                quit = true;
            }
        }


        if (nivel == 7 || puntaje::user->life_mg2 == 0)
        {
            quit = true;
        }
    }




}
void RenderGame3(SDL_Renderer* r)
{
    puntaje::user->score_mg3 = 0;

    //turnos de la computadora
    int TURNOS_COMPUTADORA = 2;

    //nivel
    int nivel = 1;

    //solicitar el jugador
    int player = PlayerSelect(r);
    int IA = 0;
    IA = (player == 1) ? 2 : 1;


    //turnos
    bool player_turn = (player == 1) ? true : false;

    TTF_Init();

    TTF_Font* FONT = TTF_OpenFont("./resource/MG3T/mg3_font.TTF", 24); //abre la fuente y establece el tamaño

    //TEXTO DE PREGUNTA
    SDL_Surface* surface_Question;//establece el mensaje
    SDL_Texture* Quenstion_Text;
    SDL_Color color = { 255,255,255 };
    SDL_Color color2 = { 0,0,0 };

    const SDL_Rect size_PREGUNTA = { 550,90,150,20 };


    //TEXTO RESULTADO
    SDL_Surface* surface_result;//establece el mensaje
    SDL_Texture* result_Text;
    const SDL_Rect size_Result = { 150,485,300,30 };
    std::string resultado_text = "";


    //puntos
    SDL_Surface* surface_puntos;//establece el mensaje
    SDL_Texture* puntos_text;
    std::string puntos = "PUNTOS";
    const SDL_Rect size_Puntos = { 20,20,100,30 };


    //BOTONES DE RESPUESTA
    SDL_Surface* surface_ANSWER1;
    SDL_Texture* ANSWER1_Text;
    const SDL_Rect size_R1 = { 540,250,190,30 };

    SDL_Surface* surface_ANSWER2;
    SDL_Texture* ANSWER2_Text;
    const SDL_Rect size_R2 = { 540,340,190,30 };

    SDL_Surface* surface_ANSWER3;
    SDL_Texture* ANSWER3_Text;
    const SDL_Rect size_R3 = { 540,430,190,30 };

    SDL_Surface* surface_ANSWER4;
    SDL_Texture* ANSWER4_Text;
    const SDL_Rect size_R4 = { 540,510,190,30 };

    std::vector<SDL_Rect> QuestionAns;
    QuestionAns.push_back(size_R1);
    QuestionAns.push_back(size_R2);
    QuestionAns.push_back(size_R3);
    QuestionAns.push_back(size_R4);


    //activar el selecionar espacio
    bool Select_space = false;
    int result = 0;


    //preguntas
    std::string preguntas[] =
    { "QUE ES HTML", "QUE ES CSS", "QUE ES URL" , "QUE SIGNIFICA WWW",
      "QUE ES JS","QUE ES NODEJS","QUE ES FRONT-END","QUE ES BACK-END",
      "QUE SIGNIFICA HTTP" };
    std::vector<int> preguntas_usadas;
    int index_pregunta = rand() % 9;
    preguntas_usadas.push_back(index_pregunta);

    //respuestas
    std::string respuestas[9][4] = {
        {"LENGUAJE DE ETIQUETAS","LENGUAJE DE PROGRAMACION","UN PROGRAMA","UN NAVEGADOR"},
        {"LENGUAJE DE ETIQUETAS","LENGUAJE DE ESTILOS","BASE DE DATOS","PROGRMAGA"},
        {"LOCALIZADOR DE RECURSOS UNIFORME","DIRECCION","LENGUAJE DE PROGRAMACION","PROGRAMA"},
        {"WEB WITH WORLD" ,"WEB WITH WASTE", "WALL WEB WIDE", "WORLD WIDE WEB"},
        {"LENGUAJE DE DISEÑO","BASE DE DATOS","SERVIDOR","LENGUAJE DE PROGRAMACION"},
        {"FRAMEWORK","LENGUAJE DE ETIQUETA","LENGUAJE DE DISEÑO","IDE"},
        {"DESARROLLO EN EL ASPECTO VISUAL","DESARROLLO CLIENTE SEVIDOR","DESARROLLADOR JUNIOR","DEARROLLADOR SENIOR"},
        {"DESARROLLO EN EL ASPECTO VISUAL","DESARROLLADOR DE JUEGOS","DESARROLLO CLIENTE SEVIDOR","BETA TESTER"},
        {"HYPERTEXT TRANSFER PROTOCOL","HYPER TEXT TRANFER PRACTIQUE","HIGH TRANSFER TEXT PROTOCOL","HIGH TECH TEXT PROTOCOL"}
    };


    //RECOGE LAS IMAGENES
    SDL_Surface* fondo;
    SDL_Surface* returnbtn;


    //CREA LAS TEXTURAS CON LAS IMAGENES RECOGIDAS
    SDL_Texture* texture;
    SDL_Texture* BTN_EXI;

    //BOTONES DE X 0 
    std::vector<btnmg3> espacios;
    espacios.push_back(btnmg3(200, 100, 40, 40, r));
    espacios.push_back(btnmg3(265, 100, 40, 40, r));
    espacios.push_back(btnmg3(340, 100, 40, 40, r));

    espacios.push_back(btnmg3(200, 190, 40, 40, r));
    espacios.push_back(btnmg3(265, 190, 40, 40, r));
    espacios.push_back(btnmg3(340, 190, 40, 40, r));

    espacios.push_back(btnmg3(200, 280, 40, 40, r));
    espacios.push_back(btnmg3(265, 280, 40, 40, r));
    espacios.push_back(btnmg3(340, 280, 40, 40, r));




    //ESTABLECE EL TAMÑAO Y POSICION DEL CURSOR y los botones
    const SDL_Rect resize = { 400,200,35,40 };
    const SDL_Rect size_btnexit = { 20,350,40,40 };

    bool quit = false;
    SDL_Event event;
    while (!quit)
    {

        SDL_WaitEvent(&event);

        switch (event.type) // COMPARA EL TYPO DE EVENTO
        {
        case SDL_MOUSEBUTTONDOWN:
            if (SDL_BUTTON(SDL_BUTTON_LEFT)) {

                quit = Exitbtn();
            }


            if (Select_space)
            {
                bool check = Click_table(&espacios, player);
                if (check)
                {
                    Select_space = false;
                    player_turn = false;
                    while (true)
                    {
                        index_pregunta = rand() % 9;
                        if (!(std::find(preguntas_usadas.begin(), preguntas_usadas.end(), index_pregunta) != preguntas_usadas.end()))
                        {
                            preguntas_usadas.push_back(index_pregunta);
                            break;
                        }
                        else if (preguntas_usadas.size() == 9)
                        {
                            break;
                        }


                    }


                }
            }

            result = click_Answer(QuestionAns, index_pregunta);
            if (result == 1)
            {
                Select_space = true;
                resultado_text = "CORRECTA";
            }
            else if (result == 2)
            {
                player_turn = false;
                while (true)
                {
                    index_pregunta = rand() % 9;
                    if (!(std::find(preguntas_usadas.begin(), preguntas_usadas.end(), index_pregunta) != preguntas_usadas.end()))
                    {
                        preguntas_usadas.push_back(index_pregunta);
                        break;
                    }

                }
                resultado_text = "INCORRECTA";

            }
            break;

        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_SPACE)
            {
                Marcar_IA(&espacios, 2);
            }
        }



        fondo = SDL_LoadBMP("./resource/MG3T/background.bmp");
        returnbtn = SDL_LoadBMP("./resource/leftA.bmp");

        texture = SDL_CreateTextureFromSurface(r, fondo);
        BTN_EXI = SDL_CreateTextureFromSurface(r, returnbtn);


        //PREGUNTA
        surface_Question = TTF_RenderText_Solid(FONT, preguntas[index_pregunta].c_str(), color); //establece el mensaje
        Quenstion_Text = SDL_CreateTextureFromSurface(r, surface_Question);


        //ESTADO
        surface_result = TTF_RenderText_Solid(FONT, resultado_text.c_str(), color); //establece el mensaje
        result_Text = SDL_CreateTextureFromSurface(r, surface_result);


        //RESPUESTA
        surface_ANSWER1 = TTF_RenderText_Solid(FONT, respuestas[index_pregunta][0].c_str(), color); //establece el mensaje
        ANSWER1_Text = SDL_CreateTextureFromSurface(r, surface_ANSWER1);

        surface_ANSWER2 = TTF_RenderText_Solid(FONT, respuestas[index_pregunta][1].c_str(), color); //establece el mensaje
        ANSWER2_Text = SDL_CreateTextureFromSurface(r, surface_ANSWER2);


        surface_ANSWER3 = TTF_RenderText_Solid(FONT, respuestas[index_pregunta][2].c_str(), color); //establece el mensaje
        ANSWER3_Text = SDL_CreateTextureFromSurface(r, surface_ANSWER3);

        surface_ANSWER4 = TTF_RenderText_Solid(FONT, respuestas[index_pregunta][3].c_str(), color); //establece el mensaje
        ANSWER4_Text = SDL_CreateTextureFromSurface(r, surface_ANSWER4);


        //puntaje
        puntos = "PUNTOS    " + std::to_string(puntaje::user->score_mg3);
        surface_puntos = TTF_RenderText_Solid(FONT, puntos.c_str(), color); //establece el mensaje
        puntos_text = SDL_CreateTextureFromSurface(r, surface_puntos);


        //movimiento IA
        if (player_turn == false && !Espacios_llenos(&espacios))
        {
            if (result == 2)
            {
                for (size_t i = 0; i < TURNOS_COMPUTADORA; i++)
                {
                    Marcar_IA(&espacios, IA);
                }
            }
            else
            {
                Marcar_IA(&espacios, IA);

            }


            player_turn = true;
        }


        //verificar ganador
        int estado = Verificar_Partida(&espacios);
        if (estado == player)
        {
            std::cout << "jugador gano";
            Reset(&espacios);
            preguntas_usadas.clear();
            resultado_text = " ";
            nivel++;
            puntaje::user->score_mg3 += 100;
            if (nivel == 4) { quit = true; };

        }
        else if (estado == IA)
        {
            std::cout << "IA gano";
            Reset(&espacios);
            preguntas_usadas.clear();
            resultado_text = " ";
            quit = true;

        }
        else if (estado == 3)
        {
            std::cout << "jugador gano";
            Reset(&espacios);
            preguntas_usadas.clear();
            resultado_text = " ";
            puntaje::user->score_mg3 += 100;
            nivel++;
            if (nivel == 4) { quit = true; };

        }



        //PINTA EN PANTALLA
        SDL_RenderCopy(r, texture, NULL, NULL);
        SDL_RenderCopy(r, BTN_EXI, NULL, &size_btnexit);
        SDL_RenderCopy(r, result_Text, NULL, &size_Result);
        SDL_RenderCopy(r, puntos_text, NULL, &size_Puntos);


        if (!Select_space)
        {
            SDL_RenderCopy(r, Quenstion_Text, NULL, &size_PREGUNTA);
            SDL_RenderCopy(r, ANSWER1_Text, NULL, &size_R1);
            SDL_RenderCopy(r, ANSWER2_Text, NULL, &size_R2);
            SDL_RenderCopy(r, ANSWER3_Text, NULL, &size_R3);
            SDL_RenderCopy(r, ANSWER4_Text, NULL, &size_R4);
        }

        for (auto i = espacios.begin(); i != espacios.end(); i++)
        {
            SDL_RenderCopy(r, i->btntexture, NULL, &i->positonAndSize);

        }




        SDL_RenderPresent(r);

        SDL_DestroyTexture(texture);
        SDL_DestroyTexture(BTN_EXI);
        SDL_DestroyTexture(Quenstion_Text);
        SDL_DestroyTexture(ANSWER1_Text);
        SDL_DestroyTexture(ANSWER2_Text);
        SDL_DestroyTexture(ANSWER3_Text);
        SDL_DestroyTexture(ANSWER4_Text);
        SDL_DestroyTexture(puntos_text);



        SDL_FreeSurface(fondo);
        SDL_FreeSurface(returnbtn);
        SDL_FreeSurface(surface_Question);
        SDL_FreeSurface(surface_ANSWER1);
        SDL_FreeSurface(surface_ANSWER2);
        SDL_FreeSurface(surface_ANSWER3);
        SDL_FreeSurface(surface_ANSWER4);
        SDL_FreeSurface(surface_puntos);

        SDL_RenderClear(r);

    }




}





void RenderGame4(SDL_Renderer* r)
{

    TTF_Init();
    TTF_Font* FONT = TTF_OpenFont("./resource/MG3T/mg3_font.TTF", 24); //abre la fuente y establece el tamaño
    puntaje::user->score_mg4 = 0;


    int oportunidades = 2; // oportunidades
    int espacios[] = { 0,0,0,0 }; // 1,2,3,4
    int nivel = 1;

    int mouse_x, mouse_y;
    int mouse_clicked_x, mouse_clicked_y;
    bool verificar_respuesta = false;
    bool respuesta_correcta = false;

    //SURFACES BASICAS
    SDL_Surface* fondo;
    SDL_Surface* returnbtn;


    //RUN BTN
    SDL_Surface* surf_run;
    SDL_Texture* text_run;
    SDL_Rect size_run = { 720,470,60,60 };

    //PREGUNTAS
    int pregunta;
    std::string direccion;
    std::vector<int> preguntas_usadas;
    SetPregunta(&preguntas_usadas, &direccion, &pregunta);
    SDL_Surface* surf_pregunta;
    SDL_Texture* text_pregunta;
    SDL_Rect size_pregunta = { 10,10,500,180 };

    //RESPUESTAS
    std::vector<int> respuestas_usadas;
    botonmg4* Res1;
    botonmg4* Res2;
    botonmg4* Res3;
    botonmg4* Res4;
    Set_Respuestas(&respuestas_usadas, &Res1, &pregunta, r, 300, 250);
    Set_Respuestas(&respuestas_usadas, &Res2, &pregunta, r, 550, 250);
    Set_Respuestas(&respuestas_usadas, &Res3, &pregunta, r, 300, 350);
    Set_Respuestas(&respuestas_usadas, &Res4, &pregunta, r, 550, 350);

    //mostrador
    SDL_Surface* surf_puntos;
    SDL_Texture* text_puntos;
    SDL_Rect size_puntos = { 600,10,180,50 };
    SDL_Surface* surf_vidas;
    SDL_Texture* text_vidas;
    SDL_Rect size_vidas = { 600,70,180,50 };

    SDL_Color color = { 255,255,255 };

    std::string opotunidades_txt;
    std::string puntos;
    /*

    1 cuadro -> 70 , 468
    2 cuadro -> 430 ,467
    3 cuadro -> 70 , 537
    4 cuadro -> 430, 537


    */

    //CREA LAS TEXTURAS CON LAS IMAGENES RECOGIDAS
    SDL_Texture* texture;
    SDL_Texture* BTN_EXI;


    //ESTABLECE EL TAMÑAO Y POSICION DEL CURSOR y los botones
    const SDL_Rect resize = { 400,200,35,40 };
    const SDL_Rect size_btnexit = { 20,350,40,40 };



    bool quit = false;
    SDL_Event event;
    while (!quit)
    {
        SDL_GetMouseState(&mouse_x, &mouse_y);
        SDL_WaitEvent(&event);

        switch (event.type) // COMPARA EL TYPO DE EVENTO
        {
        case SDL_MOUSEBUTTONDOWN:

            if (SDL_BUTTON(SDL_BUTTON_LEFT)) {
                quit = Exitbtn();
                SDL_GetMouseState(&mouse_clicked_x, &mouse_clicked_y);
                Verify_Dragged(mouse_clicked_x, mouse_clicked_y, &Res1);
                Verify_Dragged(mouse_clicked_x, mouse_clicked_y, &Res2);
                Verify_Dragged(mouse_clicked_x, mouse_clicked_y, &Res3);
                Verify_Dragged(mouse_clicked_x, mouse_clicked_y, &Res4);

                verificar_respuesta = Click_Verificar();
            }
            break;
        case SDL_MOUSEBUTTONUP:
            if (SDL_BUTTON(SDL_BUTTON_LEFT)) {
                if (Res1->is_dragged)
                {
                    adjust(&Res1, espacios);
                }
                else if (Res2->is_dragged)
                {
                    adjust(&Res2, espacios);
                }
                else if (Res3->is_dragged)
                {
                    adjust(&Res3, espacios);
                }
                else if (Res4->is_dragged)
                {
                    adjust(&Res4, espacios);
                }

                Clear_Dragged(&Res1);
                Clear_Dragged(&Res2);
                Clear_Dragged(&Res3);
                Clear_Dragged(&Res4);



            }
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_SPACE)
            {
                for (size_t i = 0; i < 4; i++)
                {
                    std::cout << espacios[i];
                }
            }
        }



        //run btn
        surf_run = SDL_LoadBMP("./resource/MG4D/run.bmp");
        text_run = SDL_CreateTextureFromSurface(r, surf_run);


        //Dragged move
        if (Res1->is_dragged)
        {
            SDL_GetMouseState(&mouse_clicked_x, &mouse_clicked_y);
            Move_Dragged(&Res1, mouse_x, mouse_y, mouse_clicked_x, mouse_clicked_y);
        }
        else if (Res2->is_dragged)
        {
            SDL_GetMouseState(&mouse_clicked_x, &mouse_clicked_y);
            Move_Dragged(&Res2, mouse_x, mouse_y, mouse_clicked_x, mouse_clicked_y);
        }
        else if (Res3->is_dragged)
        {
            SDL_GetMouseState(&mouse_clicked_x, &mouse_clicked_y);
            Move_Dragged(&Res3, mouse_x, mouse_y, mouse_clicked_x, mouse_clicked_y);
        }
        else if (Res4->is_dragged)
        {
            SDL_GetMouseState(&mouse_clicked_x, &mouse_clicked_y);
            Move_Dragged(&Res4, mouse_x, mouse_y, mouse_clicked_x, mouse_clicked_y);
        }



        //verificar respuesta
        if (verificar_respuesta)
        {
            respuesta_correcta = true;

            for (size_t i = 0; i < 4; i++)
            {
                if (!(espacios[i] == i + 1))
                {
                    respuesta_correcta = false;
                    break;
                }

            }

            if (respuesta_correcta)
            {
                puntaje::user->score_mg4 += 100;

                nivel++;
                if (nivel > 4)
                {
                    quit = true;
                    break;
                }

                // limpia la memoria 
                SDL_DestroyTexture(Res1->btntexture);
                SDL_FreeSurface(Res1->btnsurface);
                SDL_DestroyTexture(Res2->btntexture);
                SDL_FreeSurface(Res2->btnsurface);
                SDL_DestroyTexture(Res3->btntexture);
                SDL_FreeSurface(Res3->btnsurface);
                SDL_DestroyTexture(Res4->btntexture);
                SDL_FreeSurface(Res4->btnsurface);

                // borra los apuntadores
                delete Res1;
                delete Res2;
                delete Res3;
                delete Res4;

                respuestas_usadas.clear(); // limpia las respuesta

                SetPregunta(&preguntas_usadas, &direccion, &pregunta); //asigna una nueva pregunta

                Set_Respuestas(&respuestas_usadas, &Res1, &pregunta, r, 300, 250);
                Set_Respuestas(&respuestas_usadas, &Res2, &pregunta, r, 550, 250);
                Set_Respuestas(&respuestas_usadas, &Res3, &pregunta, r, 300, 350);
                Set_Respuestas(&respuestas_usadas, &Res4, &pregunta, r, 550, 350);

                SDL_Surface* surf_mensaje = TTF_RenderText_Solid(FONT, "CORRECTO", color); //establece el mensaje
                SDL_Texture* text_mensaje = SDL_CreateTextureFromSurface(r, surf_mensaje); //establece el mensaje
                SDL_Rect size_msg = { 10,10,500,400 };

                SDL_RenderCopy(r, text_mensaje, NULL, &size_msg);

                SDL_RenderPresent(r); // muestra el render actual
                SDL_Delay(3000); // espera 3 segundos

                SDL_DestroyTexture(text_mensaje);
                SDL_FreeSurface(surf_mensaje);


            }
            else
            {


                SDL_DestroyTexture(Res1->btntexture);
                SDL_FreeSurface(Res1->btnsurface);
                SDL_DestroyTexture(Res2->btntexture);
                SDL_FreeSurface(Res2->btnsurface);
                SDL_DestroyTexture(Res3->btntexture);
                SDL_FreeSurface(Res3->btnsurface);
                SDL_DestroyTexture(Res4->btntexture);
                SDL_FreeSurface(Res4->btnsurface);


                delete Res1;
                delete Res2;
                delete Res3;
                delete Res4;


                respuestas_usadas.clear();


                Set_Respuestas(&respuestas_usadas, &Res1, &pregunta, r, 300, 250);
                Set_Respuestas(&respuestas_usadas, &Res2, &pregunta, r, 550, 250);
                Set_Respuestas(&respuestas_usadas, &Res3, &pregunta, r, 300, 350);
                Set_Respuestas(&respuestas_usadas, &Res4, &pregunta, r, 550, 350);


                SDL_Surface* surf_mensaje = TTF_RenderText_Solid(FONT, "INCORRECTO", color); //establece el mensaje
                SDL_Texture* text_mensaje = SDL_CreateTextureFromSurface(r, surf_mensaje); //establece el mensaje
                SDL_Rect size_msg = { 10,10,500,400 };

                SDL_RenderCopy(r, text_mensaje, NULL, &size_msg);

                SDL_RenderPresent(r);
                SDL_Delay(3000);

                SDL_DestroyTexture(text_mensaje);
                SDL_FreeSurface(surf_mensaje);


                oportunidades--;

                if (oportunidades == 0)
                {
                    quit = true;
                }

            }


            verificar_respuesta = false;
        }



        //pregunta
        surf_pregunta = SDL_LoadBMP(direccion.c_str());
        text_pregunta = SDL_CreateTextureFromSurface(r, surf_pregunta);


        fondo = SDL_LoadBMP("./resource/MG4D/background.bmp");
        returnbtn = SDL_LoadBMP("./resource/leftA.bmp");


        texture = SDL_CreateTextureFromSurface(r, fondo);
        BTN_EXI = SDL_CreateTextureFromSurface(r, returnbtn);


        //estado
        opotunidades_txt = ("OPORTUNIDADES   " + std::to_string(oportunidades));
        puntos = ("PUNTOS   " + std::to_string(puntaje::user->score_mg4));
        surf_puntos = TTF_RenderText_Solid(FONT, puntos.c_str(), color); //establece el mensaje
        text_puntos = SDL_CreateTextureFromSurface(r, surf_puntos);
        surf_vidas = TTF_RenderText_Solid(FONT, opotunidades_txt.c_str(), color); //establece el mensaje
        text_vidas = SDL_CreateTextureFromSurface(r, surf_vidas);

        //PINTA EN PANTALLA
        SDL_RenderCopy(r, texture, NULL, NULL);
        SDL_RenderCopy(r, BTN_EXI, NULL, &size_btnexit);
        SDL_RenderCopy(r, text_pregunta, NULL, &size_pregunta);
        SDL_RenderCopy(r, text_run, NULL, &size_run);
        SDL_RenderCopy(r, Res1->btntexture, NULL, &Res1->positonAndSize);
        SDL_RenderCopy(r, Res2->btntexture, NULL, &Res2->positonAndSize);
        SDL_RenderCopy(r, Res3->btntexture, NULL, &Res3->positonAndSize);
        SDL_RenderCopy(r, Res4->btntexture, NULL, &Res4->positonAndSize);
        SDL_RenderCopy(r, text_puntos, NULL, &size_puntos);
        SDL_RenderCopy(r, text_vidas, NULL, &size_vidas);





        SDL_RenderPresent(r);

        SDL_DestroyTexture(texture);
        SDL_DestroyTexture(BTN_EXI);
        SDL_DestroyTexture(text_pregunta);
        SDL_DestroyTexture(text_run);
        SDL_DestroyTexture(text_vidas);
        SDL_DestroyTexture(text_puntos);




        SDL_FreeSurface(fondo);
        SDL_FreeSurface(returnbtn);
        SDL_FreeSurface(surf_pregunta);
        SDL_FreeSurface(surf_run);
        SDL_FreeSurface(surf_vidas);
        SDL_FreeSurface(surf_puntos);


        SDL_RenderClear(r);

    }




}


bool Exitbtn()
{
    int a, b;
    SDL_GetMouseState(&a, &b);

    if ((a > 20 && a <= 60) && (b > 350 && b < 390))
    {
        return true;
    }


    return false;


}