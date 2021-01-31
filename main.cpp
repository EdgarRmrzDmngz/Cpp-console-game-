#include <iostream>
#include "Player.h"
#include "MapCell.h"
#include "GameMap.h"



using namespace std;


int main()
{

    GameMap Map;
    Player Hero;
    Map.DrawIntro();
    Map.Draw();



    while(Map.isGameOver == false)
    {
        //Aqui es el loop de nuestro juego
        Hero.CallInput();

        //Actualizado de la información del jugador del heroe hacia el mapa
        if (Map.SetPlayerCell(Hero.x, Hero.y ))
        {
            Map.Draw();
        }
        else
        {
            Hero.ResetToSafePosition();
            Map.Draw();
        }




    }



    return 0;
}
