
#include "Render.h"
#include "boton.h"
#include <SDL_ttf.h>
#include "score.h"
#include <string>

using namespace std;


void RenderWindow(SDL_Renderer* r, int pos)
{


    //SDL_RenderPresent(r);
    int posi = pos;
    if (posi == 1)
        posi = 225;//POS DE INICIO
    else if (posi == 2)
        posi = 375;// POS DE SALIDA
    else if (posi == 3)
        posi = 530;

    //RECOGE LAS IMAGENES
    SDL_Surface* Menu = SDL_LoadBMP("./resource/menu.bmp");
    SDL_Surface* cursor = SDL_LoadBMP("./resource/hand.bmp");
    //SDL_Surface* btnstart = SDL_LoadBMP("./resource/btnstart.bmp");
    //SDL_Surface* btnexit = SDL_LoadBMP("./resource/btnexit.bmp");


    //CREA LAS TEXTURAS CON LAS IMAGENES RECOGIDAS
    SDL_Texture* texture = SDL_CreateTextureFromSurface(r, Menu);
    SDL_Texture* T_cursor = SDL_CreateTextureFromSurface(r, cursor);
    //SDL_Texture* BTN_ST = SDL_CreateTextureFromSurface(r, btnstart);
    //SDL_Texture* BTN_EXI = SDL_CreateTextureFromSurface(r, btnexit);


    //ESTABLECE EL TAMÑAO Y POSICION DEL CURSOR y los botones
    const SDL_Rect resize = { posi,300,35,40 };
    //const SDL_Rect size_btnstart = { 110,150,110,50 };
    //const SDL_Rect size_btnexit = { 350,150,110,50};


    //Creando botones
    BTN* btnstart = new BTN(200, 250, 110, 50, &(*r), "./resource/btnstart.bmp");
    BTN* btn_estadistica = new BTN(350, 250, 110, 50, &(*r), "./resource/btnestadistica.bmp");
    BTN* btnexit = new BTN(520, 250, 110, 50, &(*r), "./resource/btnexit.bmp");




    //PINTA EN PANTALLA
    SDL_RenderCopy(r, texture, NULL, NULL);
    SDL_RenderCopy(r, btnstart->btntexture, NULL, &btnstart->positonAndSize);
    SDL_RenderCopy(r, btn_estadistica->btntexture, NULL, &btn_estadistica->positonAndSize);
    SDL_RenderCopy(r, btnexit->btntexture, NULL, &btnexit->positonAndSize);
    SDL_RenderCopy(r, T_cursor, NULL, &resize);


    SDL_RenderPresent(r);

    SDL_DestroyTexture(texture);
    SDL_DestroyTexture(T_cursor);
    SDL_DestroyTexture(btnexit->btntexture);
    SDL_DestroyTexture(btn_estadistica->btntexture);
    SDL_DestroyTexture(btnstart->btntexture);

    SDL_FreeSurface(Menu);
    SDL_FreeSurface(cursor);
    SDL_FreeSurface(btnstart->btnsurface);
    SDL_FreeSurface(btn_estadistica->btnsurface);
    SDL_FreeSurface(btnexit->btnsurface);






}




void Render_Estadisticas(SDL_Renderer* r)
{
    int cont = 1;
    bool quit = false;
    int posy = 150;

    SDL_Surface* back = SDL_LoadBMP("./resource/estadisticas.bmp");
    SDL_Texture* back_text = SDL_CreateTextureFromSurface(r, back);

    TTF_Init();
    TTF_Font* FONT = TTF_OpenFont("./resource/MG3T/mg3_font.TTF", 24); //abre la fuente y establece el tamaño
    SDL_Color color = { 255,255,255 };

    int t1;
    std::string n1_text;
    int t2;
    std::string n2_text;
    int t3;
    std::string n3_text;
    int t4;
    std::string n4_text;
    int t5;
    std::string n5_text;

    SDL_RenderCopy(r, back_text, NULL, NULL);


    if (puntaje::users->size() > 0)
    {
        t1 = (*puntaje::users)[0].score_mg1 + (*puntaje::users)[0].score_mg2 + (*puntaje::users)[0].score_mg3 + (*puntaje::users)[0].score_mg4;
        n1_text = std::string((*puntaje::users)[0].name) + "         " + std::to_string((*puntaje::users)[0].score_mg1) + "         " + std::to_string((*puntaje::users)[0].score_mg2) + "         " + std::to_string((*puntaje::users)[0].score_mg3) + "         " + std::to_string((*puntaje::users)[0].score_mg4) + "         " + std::to_string(t1);
        SDL_Surface* n1_Surf = TTF_RenderText_Solid(FONT, n1_text.c_str(), color); //establece el mensaje
        SDL_Texture* text_n1 = SDL_CreateTextureFromSurface(r, n1_Surf); //establece el mensaje
        SDL_Rect size_pos = { 75,posy,620,20 };
        SDL_RenderCopy(r, text_n1, NULL, &size_pos);

    }


    if (puntaje::users->size() > 1)
    {
        t2 = (*puntaje::users)[1].score_mg1 + (*puntaje::users)[01].score_mg2 + (*puntaje::users)[1].score_mg3 + (*puntaje::users)[1].score_mg4;
        n2_text = std::string((*puntaje::users)[1].name) + "         " + std::to_string((*puntaje::users)[1].score_mg1) + "         " + std::to_string((*puntaje::users)[1].score_mg2) + "         " + std::to_string((*puntaje::users)[1].score_mg3) + "         " + std::to_string((*puntaje::users)[1].score_mg4) + "         " + std::to_string(t2);
        SDL_Surface* n2_Surf = TTF_RenderText_Solid(FONT, n2_text.c_str(), color); //establece el mensaje
        SDL_Texture* text_n2 = SDL_CreateTextureFromSurface(r, n2_Surf); //establece el mensaje
        SDL_Rect size_pos2 = { 75,posy + 25,620,20 };
        SDL_RenderCopy(r, text_n2, NULL, &size_pos2);

    }


    if (puntaje::users->size() > 2)
    {
        t3 = (*puntaje::users)[2].score_mg1 + (*puntaje::users)[2].score_mg2 + (*puntaje::users)[2].score_mg3 + (*puntaje::users)[2].score_mg4;
        n3_text = std::string((*puntaje::users)[2].name) + "         " + std::to_string((*puntaje::users)[2].score_mg1) + "         " + std::to_string((*puntaje::users)[2].score_mg2) + "         " + std::to_string((*puntaje::users)[2].score_mg3) + "         " + std::to_string((*puntaje::users)[2].score_mg4) + "         " + std::to_string(t3);
        SDL_Surface* n3_Surf = TTF_RenderText_Solid(FONT, n3_text.c_str(), color); //establece el mensaje
        SDL_Texture* text_n3 = SDL_CreateTextureFromSurface(r, n3_Surf); //establece el mensaje
        SDL_Rect size_pos3 = { 75,posy + 45,620,20 };
        SDL_RenderCopy(r, text_n3, NULL, &size_pos3);

    }


    if (puntaje::users->size() > 3)
    {
        t4 = (*puntaje::users)[3].score_mg1 + (*puntaje::users)[3].score_mg2 + (*puntaje::users)[3].score_mg3 + (*puntaje::users)[3].score_mg4;
        n4_text = std::string((*puntaje::users)[3].name) + "         " + std::to_string((*puntaje::users)[3].score_mg1) + "         " + std::to_string((*puntaje::users)[3].score_mg2) + "         " + std::to_string((*puntaje::users)[3].score_mg3) + "         " + std::to_string((*puntaje::users)[3].score_mg4) + "         " + std::to_string(t4);
        SDL_Surface* n4_Surf = TTF_RenderText_Solid(FONT, n4_text.c_str(), color); //establece el mensaje
        SDL_Texture* text_n4 = SDL_CreateTextureFromSurface(r, n4_Surf); //establece el mensaje
        SDL_Rect size_pos4 = { 75,posy + 85,620,20 };
        SDL_RenderCopy(r, text_n4, NULL, &size_pos4);

    }

    if (puntaje::users->size() > 4)
    {
        t5 = (*puntaje::users)[4].score_mg1 + (*puntaje::users)[4].score_mg2 + (*puntaje::users)[4].score_mg3 + (*puntaje::users)[4].score_mg4;
        n5_text = std::string((*puntaje::users)[4].name) + "         " + std::to_string((*puntaje::users)[4].score_mg1) + "         " + std::to_string((*puntaje::users)[4].score_mg2) + "         " + std::to_string((*puntaje::users)[4].score_mg3) + "         " + std::to_string((*puntaje::users)[4].score_mg4) + "         " + std::to_string(t5);
        SDL_Surface* n5_Surf = TTF_RenderText_Solid(FONT, n5_text.c_str(), color); //establece el mensaje
        SDL_Texture* text_n5 = SDL_CreateTextureFromSurface(r, n5_Surf); //establece el mensaje
        SDL_Rect size_pos5 = { 75,posy + 105,620,20 };
        SDL_RenderCopy(r, text_n5, NULL, &size_pos5);
    }



    while (!quit)
    {

        SDL_Event event;


        //RECOGE LOS EVENTOS QUE SUCEDEN EN LA WINDOW
        SDL_WaitEvent(&event);


        switch (event.type) // COMPARA EL TYPO DE EVENTO
        {
        case SDL_KEYDOWN: //validacion de todas las letras


            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                quit = true;
                break;
            }
            break;
        case SDL_QUIT:
            quit = true;
            break;
        }


        SDL_RenderPresent(r);


        //LIMPA LA PANTALLA
    }





}


int MouseClickButton()
{

    int a, b;
    SDL_GetMouseState(&a, &b);

    if ((a > 200 && a <= 200 + 110) && (b > 250 && b < 300))
    {
        return 1;
    }

    if ((a > 350 && a <= 460) && (b > 250 && b < 300))
    {
        return 2;
    }

    if ((a > 520 && a <= 630) && (b > 250 && b < 300))
    {
        return 3;
    }



    return 0;

}
