//
// Created by SWQXDBA on 2021/5/30.
//

#define _CRT_SECURE_NO_WARNINGS

#include"RetroSnaker.h"


void Game(Snaker* snaker, Food* food)
{
    Keyboard(snaker);
    EatFood(snaker, food);
    SnakerMove(snaker);
    SnakerDie(snaker, food);
    GameDraw(snaker,food);
}

int main()
{
    srand((unsigned int) time(NULL));
    Snaker snaker = { 0 };
    Food food = { 0 };
    initgraph(LENGTH+200, WIDTH/*,SHOWCONSOLE*/);//Í¼Ïñ´óÐ¡
    /*IMAGE img;
    loadimage(&img, "±³¾°.jpg", 0, 0);
    putimage(0, 0, &img);*/
    //_getch();
    //int Input;
    BeginBatchDraw();//Ë«»º³å¿ªÊ¼
    while (menu()) {
        Init(&snaker, &food);
        do
        {
            //cleardevice();
            Game(&snaker, &food);
            Sleep(snaker.s);

        }while (snaker.flag);
        Sleep(1000);
        cleardevice();
    }
    return 0;
}