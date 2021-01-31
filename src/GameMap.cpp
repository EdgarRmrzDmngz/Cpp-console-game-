#include "GameMap.h"
#include <iostream>
#include <fstream>

using namespace std;

GameMap::GameMap()
{
    //ctor
    PlayerCell = NULL;
    LoadMapFromFile();
    isGameOver = false;
}


void GameMap::Draw()
{
    for(int i = 0; i < 15; i = i + 1)
    {
     for(int p = 0; p < 10; p = p + 1)
        {
            cout << cells[i][p].id;
        }

        cout << endl;
    }
}

bool GameMap::SetPlayerCell(int PlayerX, int PlayerY)
{
        if ( cells[PlayerY][PlayerX].IsBlocked() == false)
        {
            if( cells[PlayerY][PlayerX].id == '$')
            {


                DrawVictory();
                isGameOver = true;
                return true;


            }
            else
            {
                if (PlayerCell != NULL )
                {
                    PlayerCell->id = 0;
                }
                PlayerCell = &cells[PlayerY][PlayerX];
                PlayerCell->id = 'o';


            }






        return true;
    }
    else
    {
        return false;
    }





    //cout << "Las coordenadas del jugador estan en: " << PlayerX << "," << PlayerY;
}

void GameMap::DrawIntro()
{
    string line;
    int row = 0;
    ifstream MyFile("Intro.txt");



    if(MyFile.is_open())
    {
        while ( getline(MyFile, line))
        {
            cout << line << endl;
        }
        cin >> line;
    }
    else
    {
    cout << "Fatal error: INTRO COULD NOT BE LOADED";
    }
}




void GameMap::DrawVictory()
{
    string line;
    int row = 0;
    ifstream MyFile("Victory.txt");



    if(MyFile.is_open())
    {

        while ( getline(MyFile, line))
        {
            cout << line << endl;
        }
        cin >> line;
    }
    else
    {
    cout << "Fatal error: VICTORY COULD NOT BE LOADED!";
    }
}















void GameMap::LoadMapFromFile()
{
        /*ofstream FileCreated("Map.txt");

        if(FileCreated.is_open())
        {



        }
        else
        {
            cout << "Fatal error: MAP FILE COULD NoT BE LOADED";
        }*/




    string line;
    int row = 0;
    ifstream MyFile("Map.txt");



    if(MyFile.is_open())
    {

        while ( getline(MyFile, line))
        {
            for(int p=0; p < line.length(); p = p + 1)
            {
                if (line[p] == '0')
                {
                    cells[row][p].id = 0;
                }
                else
                {
                    cells[row][p].id = line[p];
                }

            }
            row++;
        }

    }
    else
    {
    cout << "Fatal error: MAP FILE COULD NOT BE LOADED";
    }
}
