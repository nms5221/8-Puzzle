#include <cstdlib>
#include <iostream>
#include "moves.h"

using namespace std;

//Constructor
moves::moves()
{
    //Loop that sets all game tiles equal to zero
    for(int i = 0; i < 9; i++)
    {
        tile[i] = 0;
    }
}

//Making the game board
void moves::settile(int t[9])
{
    for(int i = 0; i < 9; i++)
    {
        tile[i] = t[i];
    }
}

//Getting the tile values back
void moves::gettile(int t[9])
{
    for(int i = 0; i < 9; i++)
    {
        t[i] = tile[i];
    }
}

//Swapping the upper left tile with the one to the right of it
void moves::swap12()
{
    int temp = tile[0];
    tile[0] = tile[1];
    tile[1] = temp;
}

//Swapping the upper left tile with the one below it
void moves::swap14()
{
    int temp = tile[0];
    tile[0] = tile[3];
    tile[3] = temp;
}

//Swapping the upper middle tile with the one to the right of it
void moves::swap23()
{
    int temp = tile[1];
    tile[1] = tile[2];
    tile[2] = temp;
}

//Swapping the upper middle tile with the one below it
void moves::swap25()
{
    int temp = tile[1];
    tile[1] = tile[4];
    tile[4] = temp;
}

//Swapping the upper right tile with the one below it
void moves::swap36()
{
    int temp = tile[2];
    tile[2] = tile[5];
    tile[5] = temp;
}

//Swapping the middle left tile with the one to the right of it
void moves::swap45()
{
    int temp = tile[3];
    tile[3] = tile[4];
    tile[4] = temp;
}

//Swapping the middle left tile with the one below it
void moves::swap47()
{
    int temp = tile[3];
    tile[3] = tile[6];
    tile[6] = temp;
}

//Swapping the middle tile with the one to the right of it
void moves::swap56()
{
    int temp = tile[4];
    tile[4] = tile[5];
    tile[5] = temp;
}

//Swapping the middle tile with the one below it
void moves::swap58()
{
    int temp = tile[4];
    tile[4] = tile[7];
    tile[7] = temp;
}

//Swapping the middle right tile with the one below it
void moves::swap69()
{
    int temp = tile[5];
    tile[5] = tile[8];
    tile[8] = temp;
}

//Swapping the bottom left tile with the one to the right of it
void moves::swap78()
{
    int temp = tile[6];
    tile[6] = tile[7];
    tile[7] = temp;
}

//Swapping the bottom middle tile with the one to the right of it
void moves::swap89()
{
    int temp = tile[7];
    tile[7] = tile[8];
    tile[8] = temp;
}

//Checking that the game board is a valid board to solve
//In order for it to be valid, count must be an even number
//Count is determined by taking each tile and counting how many tiles after it 
//are less than it
int moves::checkvalid1()
{
    int count = 0;
    
    for(int i = 0; i < 9; i++)
    {
        for(int j = i + 1; j < 9; j++)
        {
            if(tile[i] > tile[j] && tile[j] != -1)
            {
                count++;
            }
        }
    }
    
    return count % 2;
}

//Checking that the game board is valid to solve
//Making sure the numbers entered are not repeated
bool moves::checkvalid2()
{
    bool check = true;

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if (i != j)
            {
                  if (tile[i] == tile[j])
                  {
                      check = false;
                  }
            }
        }
    }
    
    return check;
}

//Checking that the game board is valid to solve
//Making sure the numbers entered are one through eight and negative one
bool moves::checkvalid3()
{
    bool check = true;
    
    for (int i = 0; i < 9; i++)
    {
        if (tile[i] > 8 || tile[i] < -1 || tile[i] == 0)
        {
            check = false;
        }
    }
    
    return check;
}

//Checking to see if board is already solved
bool moves::checksolve()
{
    bool solve = true;
    int j = 1;
    
    for (int i = 0; i < 8; i++)
    {        
        if(tile[i] != j)
        {
            solve = false;
        }
        
        j++;
    }
    
    return solve;
}