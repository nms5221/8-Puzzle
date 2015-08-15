#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "moves.h"

using namespace std;

//Function prototypes (purposes are explained above each function header)
void getInfo(int t[]);
void display(moves &move, int t[]);
void getone(moves &move, int t[]);
void gettwo(moves &move, int t[]);
void getthree(moves &move, int t[]);
void getfour(moves &move, int t[]);
void getseven(moves &move, int t[]);
void getfive(moves &move, int t[]);
void getsix(moves &move, int t[]);
void geteight(moves &move, int t[]);

int main(int argc, char *argv[])
{
    //Defining variables
    moves move; //Using the user-defined class moves
    int c; //Used to check validity of game board
    int t[9]; //Game board
    bool solved; //Checking if the board is solved already
    bool c2, c3; //Used to check validity of game board
    
    //Setting up the game board
    getInfo(t); //Getting game board set-up from user
    move.settile(t); //Setting the tiles
    cout << "Initial State: " << endl;
    display(move, t); //Displaying the game board
    c = move.checkvalid1(); //Checking to see if game board is valid
    c2 = move.checkvalid2(); //Checking to see if the game board is valid
    c3 = move.checkvalid3(); //Checking to see if the game board is valid
    if(c != 0 || !c2 || !c3) //If game board is not valid, letting the user know and terminating program
    {
        cout << "Valid board not entered." << endl << endl;
        system("PAUSE");
        return EXIT_SUCCESS;
    }
    solved = move.checksolve(); //Checking if the puzzle is already solved
    if(solved) //Letting the user know if it is solved
    {
        cout << "Puzzle is solved!" << endl << endl;
        system("PAUSE");
        return EXIT_SUCCESS;
    }
    cout << "Sequence of Moves:" << endl;
    
    //Getting the one in the correct position
    if (t[0] != 1)
    {
        getone(move, t);
    }
    
    //Getting the two in the correct position
    if (t[1] != 2)
    {
        gettwo(move, t);
    }
    
    //Getting the three in the correct position
    if (t[2] != 3)
    {
        getthree(move, t);
    }
    
    //Getting the four in the correct position
    if (t[3] != 4)
    {
        getfour(move, t);
    }
    
    //Getting the seven in the correct position
    if (t[6] != 7)
    {
        getseven(move, t);
    }
    
    //Getting the five in the correct position
    if (t[4] != 5)
    {
        getfive(move, t);
    }
    
    //Getting the six in the correct position
    if (t[5] != 6)
    {
        getsix(move, t);
    }
    
    //Getting the eight in the correct position
    if (t[7] != 8)
    {
        geteight(move, t);
    }
    
    cout << "Puzzle is solved!  (Look above for the sequence of moves.)" << endl << endl;
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

//Function that gets the game board set-up from the user
void getInfo(int t[])
{
    cout << "Enter the first row, second row, then third row of the puzzle you would" << endl;
    cout << "like to solve using the numbers 1 through 8 with a -1 for the blank space." << endl;
    cout << "Separate the entries with a space or return.  Make sure to hit enter after" << endl;
    cout << "you have entered all nine tiles." << endl;
    
    for(int i = 0; i < 9; i++)
    {
        cin >> t[i];
    }
    cout << endl;
}

//Displaying the game board
void display(moves &move, int t[])
{
    move.gettile(t);
    
    //First Row
    cout << "|" << setw(2);
    if (t[0] == -1)
        cout << " ";
    else
        cout << t[0];
    cout << " |" << setw(2);
    if (t[1] == -1)
        cout << " ";
    else
        cout << t[1];
    cout << " |" << setw(2);
    if (t[2] == -1)
        cout << " ";
    else
        cout << t[2];
    cout << " |" << endl;
    
    //Second Row
    cout << "|" << setw(2);
    if (t[3] == -1)
        cout << " ";
    else
        cout << t[3];
    cout << " |" << setw(2);
    if (t[4] == -1)
        cout << " ";
    else
        cout << t[4];
    cout << " |" << setw(2);
    if (t[5] == -1)
        cout << " ";
    else
        cout << t[5];
    cout << " |" << endl;
    
    //Third Row
    cout << "|" << setw(2);
    if (t[6] == -1)
        cout << " ";
    else
        cout << t[6];
    cout << " |" << setw(2);
    if (t[7] == -1)
        cout << " ";
    else
        cout << t[7];
    cout << " |" << setw(2);
    if (t[8] == -1)
        cout << " ";
    else
        cout << t[8];
    cout << " |" << endl;
    cout << endl << endl;
}

//Getting the one in the right position
void getone(moves &move, int t[])
{
    //Taking care of one being in the top row
    if (t[1] == 1 || t[2] == 1)
    {
        if(t[6] == -1)
        {
            move.swap47();
            display(move,t);
        }
        if(t[7] == -1)
        {
            move.swap58();
            display(move,t);
        }
        if(t[8] == -1)
        {
            move.swap69();
            display(move,t);
        }
        
        if(t[0] == -1 || t[1] == -1 || t[2] == -1)
        {
            if(t[2] == 1)
            {
                if(t[0] == -1)
                {
                    move.swap12();
                    display(move,t);
                }
                
                if(t[1] == -1)
                {
                    move.swap23();
                    display(move,t);
                }
            }
            if(t[1] == 1)
            {
                if(t[0] == -1)
                {
                    move.swap12();
                    display(move,t);
                }
                if(t[2] == -1)
                {
                    move.swap36();
                    display(move,t);
                }
            }
        }
        
        if(t[3] == -1)
        {
            if(t[1] == 1)
            {
                move.swap14();
                display(move,t);
                
                move.swap12();
                display(move,t);
            }
            if(t[2] == 1)
            {
                move.swap45();
                display(move,t);
            }
        }
        
        if(t[4] == -1)
        {
            if(t[1] == 1)
            {
                move.swap25();
                display(move,t);
            }
            if(t[2] == 1)
            {
                move.swap56();
                display(move,t);
                
                move.swap36();
                display(move,t);
            }
        }
        
        if(t[5] == -1)
        {
            if(t[1] == 1)
            {
                move.swap56();
                display(move,t);
                
                move.swap25();
                display(move,t);
            }
            if(t[2] == 1)
            {
                move.swap36();
                display(move,t);
            }
        }
    }
    
    //Taking care of one being in the middle row
    if (t[3] == 1 || t[4] == 1 || t[5] == 1)
    {
         if(t[3] == -1 || t[4] == -1 || t[5] == -1)
         {
             if(t[5] == -1)
             {
                 move.swap36();
                 display(move,t);
             }
             if(t[4] == -1)
             {
                 move.swap25();
                 display(move,t);
             }
             if(t[3] == -1)
             {
                 move.swap14();
                 display(move,t);
             }
         }
         
         if(t[0] == -1 || t[1] == -1 || t[2] == -1)
         {
             if(t[3] == 1)
             {
                 if(t[2] == -1)
                 {
                     move.swap23();
                     display(move,t);
                 }
                 if(t[1] == -1)
                 {
                     move.swap12();
                     display(move,t);
                 }
                 if(t[0] == -1)
                 {
                     move.swap14();
                     display(move,t);
                 }
             }
             
             if(t[4] == 1)
             {
                 if(t[2] == -1)
                 {
                     move.swap23();
                     display(move,t);
                 }
                 if(t[0] == -1)
                 {
                     move.swap12();
                     display(move,t);
                 }
                 if(t[1] == -1)
                 {
                     move.swap25();
                     display(move,t);
                 }
                 
                 move.swap45();
                 display(move,t);
                 
                 move.swap14();
                 display(move,t);
                 
                 move.swap12();
                 display(move,t);
             }
             
             if(t[5] == 1)
             {
                 if(t[0] == -1)
                 {
                     move.swap12();
                     display(move,t);
                 }
                 if(t[1] == -1)
                 {
                     move.swap23();
                     display(move,t);
                 }
                 if(t[2] == -1)
                 {
                     move.swap36();
                     display(move,t);
                 }
                 
                 move.swap56();
                 display(move,t);
                 
                 move.swap25();
                 display(move,t);
                 
                 move.swap23();
                 display(move,t);
                 
                 move.swap36();
                 display(move,t);
                 
                 move.swap56();
                 display(move,t);
                 
                 move.swap45();
                 display(move,t);
                 
                 move.swap14();
                 display(move,t);
                 
                 move.swap12();
                 display(move,t);
             }
         }
         
         if(t[6] == -1 || t[7] == -1 || t[8] == -1)
         {
             if (t[3] == 1)
             {
                 if(t[8] == -1)
                 {
                     move.swap89();
                     display(move,t);
                 }
                 if(t[7] == -1)
                 {
                     move.swap78();
                     display(move,t);
                 }
                 if(t[6] == -1)
                 {
                     move.swap47();
                     display(move,t);
                 }
             }
             
             if(t[4] == 1)
             {
                 if(t[6] == -1)
                 {
                     move.swap78();
                     display(move,t);
                 }
                 if(t[8] == -1)
                 {
                     move.swap89();
                     display(move,t);
                 }
                 if(t[7] == -1)
                 {
                     move.swap58();
                     display(move,t);
                 }
             }
         }
    }
    
    //Taking care of one being in the bottom row
    if(t[6] == 1 || t[7] == 1 || t[8] == 1)
    {
         if (t[0] == -1 || t[1] == -1 || t[2] == -1)
         {
             if (t[0] == -1)
             {
                 move.swap14();
                 display(move,t);
             }
             if (t[1] == -1)
             {
                 move.swap25();
                 display(move,t);
             }
             if (t[2] == -1)
             {
                 move.swap36();
                 display(move,t);
             }
         }
         
         if(t[6] == -1 || t[7] == -1 || t[8] == -1)
         {
             if(t[6] == -1)
             {
                 move.swap47();
                 display(move,t);
             }
             if(t[7] == -1)
             {
                 move.swap58();
                 display(move,t);
             }
             if(t[8] == -1)
             {
                 move.swap69();
                 display(move,t);
             }
         }
         
         if (t[6] == 1)
         {
             if (t[5] == -1)
             {
                 move.swap56();
                 display(move,t);
             }
             if (t[4] == -1)
             {
                 move.swap45();
                 display(move,t);
             }
             if (t[3] == -1)
             {
                 move.swap47();
                 display(move,t);
             }
             
             move.swap78();
             display(move,t);
             
             move.swap58();
             display(move,t);
             
             move.swap25();
             display(move,t);
             
             move.swap12();
             display(move,t);
             
             move.swap14();
             display(move,t);
         }
         
         if(t[7] == 1)
         {
             if(t[3] == -1)
             {
                 move.swap45();
                 display(move,t);
             }
             if(t[5] == -1)
             {
                 move.swap56();
                 display(move,t);
             }
             if(t[4] == -1)
             {
                 move.swap58();
                 display(move,t);
             }
             
             move.swap78();
             display(move,t);
             
             move.swap47();
             display(move,t);
             
             move.swap14();
             display(move,t);
             
             move.swap12();
             display(move,t);
             
             move.swap25();
             display(move,t);
             
             move.swap45();
             display(move,t);
             
             move.swap14();
             display(move,t);
             
             move.swap12();
             display(move,t);
         }
         
         if(t[8] == 1)
         {
             if(t[3] == -1)
             {
                 move.swap45();
                 display(move,t);
             }
             if(t[4] == -1)
             {
                 move.swap56();
                 display(move,t);
             }
             if(t[5] == -1)
             {
                 move.swap69();
                 display(move,t);
             }
             
             move.swap89();
             display(move,t);
             
             move.swap58();
             display(move,t);
             
             move.swap56();
             display(move,t);
             
             move.swap36();
             display(move,t);
             
             move.swap23();
             display(move,t);
             
             move.swap25();
             display(move,t);
             
             move.swap45();
             display(move,t);
             
             move.swap14();
             display(move,t);
             
             move.swap12();
             display(move,t);
         }
    }
}


//Getting the two in the correct position
void gettwo(moves &move, int t[])
{
    //Taking care of two if it is in the first row
    if(t[2] == 2)
    {
        if(t[6] == -1)
        {
            move.swap78();
            display(move,t);
        }
        if(t[8] == -1)
        {
            move.swap89();
            display(move,t);
        }
        if(t[7] == -1)
        {
            move.swap58();
            display(move,t);
        }
        if(t[3] == -1)
        {
            move.swap45();
            display(move,t);
        }
        if(t[5] == -1)
        {
            move.swap56();
            display(move,t);
        }
        if(t[4] == -1)
        {
            move.swap25();
            display(move,t);
        }
        if(t[1] == -1)
        {
            move.swap23();
            display(move,t);
        }
    }
    
    //Taking care of two being in the middle row
    if (t[3] == 2 || t[4] == 2 || t[5] == 2)
    {
        if(t[3] == -1 || t[4] == -1 || t[5] == -1)
        {
             if (t[3] == -1)
             {
                 move.swap47();
                 display(move,t);
             }
             if (t[4] == -1)
             {
                 move.swap25();
                 display(move,t);
             }
             if (t[5] == -1)
             {
                 move.swap36();
                 display(move,t);
             }
        }
        
        if (t[6] == -1 || t[7] == -1 || t[8] == -1)
        {
            if (t[3] == 2)
            {
                if (t[8] == -1)
                {
                    move.swap89();
                    display(move,t);
                }
                if (t[7] == -1)
                {
                    move.swap78();
                    display(move,t);
                }
                
                move.swap47();
                display(move,t);
            }
            if (t[4] == 2)
            {
                if (t[6] == -1)
                {
                    move.swap78();
                    display(move,t);
                }
                if (t[8] == -1)
                {
                    move.swap89();
                    display(move,t);
                }
                
                move.swap58();
                display(move,t);
            }
            if (t[5] == 2)
            {
                if (t[6] == -1)
                {
                    move.swap78();
                    display(move,t);
                }
                if (t[7] == -1)
                {
                    move.swap89();
                    display(move,t);
                }
                
                move.swap69();
                display(move,t);
            }
        }
        
        if (t[1] == -1 || t[2] == -1)
        {
            if (t[3] == 2)
            {
                if (t[2] == -1)
                {
                    move.swap23();
                    display(move,t);
                }
                
                move.swap25();
                display(move,t);
                
                move.swap45();
                display(move,t);
                
                move.swap47();
                display(move,t);
                
                move.swap78();
                display(move,t);
                
                move.swap89();
                display(move,t);
                
                move.swap69();
                display(move,t);
                
                move.swap36();
                display(move,t);
                
                move.swap23();
                display(move,t);
            }
            
            if (t[4] == 2)
            {
                if (t[2] == -1)
                {
                    move.swap23();
                    display(move,t);
                }
                
                move.swap25();
                display(move,t);
            }
            
            if (t[5] == 2)
            {
                if (t[1] == -1)
                {
                    move.swap23();
                    display(move,t);
                }
                
                move.swap36();
                display(move,t);
                
                move.swap56();
                display(move,t);
                
                move.swap25();
                display(move,t);
                
                move.swap23();
                display(move,t);
            }
        }
    }
    
    //Taking care of two being in the bottom row
    if (t[6] == 2 || t[7] == 2 || t[8] == 2)
    {
        if(t[6] == -1 || t[7] == -1 || t[8] == -1)
        {
            if (t[6] == -1)
            {
                move.swap47();
                display(move,t);
            }
            if (t[7] == -1)
            {
                move.swap58();
                display(move,t);
            }
            if (t[8] == -1)
            {
                move.swap69();
                display(move,t);
            }
        }
        
        if (t[1] == -1 || t[2] == -1 || t[3] == -1 || t[4] == -1 || t[5] == -1)
        {
            if (t[2] == -1)
            {
                move.swap23();
                display(move,t);
            }
            if (t[1] == -1)
            {
                move.swap25();
                display(move,t);
            }
            if (t[3] == -1)
            {
                move.swap45();
                display(move,t);
            }
            if (t[5] == -1)
            {
                move.swap56();
                display(move,t);
            }
            if (t[4] == -1 && (t[6] == 2 || t[8] == 2))
            {
                move.swap58();
                display(move,t);
            }
            if (t[6] == 2 || t[8] == 2)
            {
                if (t[6] == 2)
                {
                    move.swap78();
                    display(move,t);
                    
                    move.swap47();
                    display(move,t);
                    
                    move.swap45();
                    display(move,t);
                }
                if (t[8] == 2)
                {
                    move.swap89();
                    display(move,t);
                    
                    move.swap69();
                    display(move,t);
                    
                    move.swap56();
                    display(move,t);
                }
            }
            
            if (t[7] == 2)
            {
                move.swap58();
                display(move,t);
                
                move.swap89();
                display(move,t);
                
                move.swap69();
                display(move,t);
                
                move.swap36();
                display(move,t);
                
                move.swap23();
                display(move,t);
                
                move.swap25();
                display(move,t);
            }
        }
    }    
}

//Getting three in the correct position
void getthree(moves &move, int t[])
{
     //Putting the black space in the upper right corner if it isn't already there
     if (t[2] != -1)
     {
         if (t[3] == -1)
         {
             move.swap45();
             display(move,t);
         }
         if (t[4] == -1)
         {
             move.swap56();
             display(move,t);
         }
         if (t[6] == -1)
         {
             move.swap78();
             display(move,t);
         }
         if (t[7] == -1)
         {
             move.swap89();
             display(move,t);
         }
         if (t[8] == -1)
         {
             move.swap69();
             display(move,t);
         }
         if (t[5] == -1)
         {
             move.swap36();
             display(move,t);
         }
     }
     
          
     //If the space is in the upper right and the three is right below it
     if (t[5] == 3 && t[2] == -1)
     {
         move.swap36();
         display(move,t);
     }
     
     //If the space is in the upper right and the three is in the middle
     if (t[4] == 3 && t[2] == -1)
     {
         move.swap36();
         display(move,t);
         
         move.swap56();
         display(move,t);
         
         move.swap58();
         display(move,t);
         
         move.swap89();
         display(move,t);
         
         move.swap69();
         display(move,t);
         
         move.swap36();
         display(move,t);
         
         move.swap23();
         display(move,t);
         
         move.swap25();
         display(move,t);
         
         move.swap56();
         display(move,t);
         
         move.swap69();
         display(move,t);
         
         move.swap89();
         display(move,t);
         
         move.swap58();
         display(move,t);
         
         move.swap25();
         display(move,t);
         
         move.swap23();
         display(move,t);
         
         move.swap36();
         display(move,t);
     }
     
     //If the space is in the upper right and the three is not in the middle or right below it
     if (t[4] != 3 && t[5] != 3 && t[2] == -1)
     {
         move.swap23();
         display(move,t);
         
         move.swap25();
         display(move,t);
         
         if (t[3] == 3)
         {
             move.swap45();
             display(move,t);
             
             move.swap47();
             display(move,t);
             
             move.swap78();
             display(move,t);
             
             move.swap89();
             display(move,t);
             
             move.swap69();
             display(move,t);
             
             move.swap56();
             display(move,t);
             
             move.swap25();
             display(move,t);
             
             move.swap23();
             display(move,t);
             
             move.swap36();
             display(move,t);
         }
         
         if (t[6] == 3)
         {
             move.swap45();
             display(move,t);
             
             move.swap47();
             display(move,t);
             
             move.swap78();
             display(move,t);
             
             move.swap58();
             display(move,t);
             
             move.swap45();
             display(move,t);
             
             move.swap47();
             display(move,t);
             
             move.swap78();
             display(move,t);
             
             move.swap89();
             display(move,t);
             
             move.swap69();
             display(move,t);
             
             move.swap56();
             display(move,t);
             
             move.swap25();
             display(move,t);
             
             move.swap23();
             display(move,t);
             
             move.swap36();
             display(move,t);
         }
         
         if (t[7] == 3)
         {
             move.swap58();
             display(move,t);
             
             move.swap89();
             display(move,t);
             
             move.swap69();
             display(move,t);
             
             move.swap56();
             display(move,t);
             
             move.swap25();
             display(move,t);
             
             move.swap23();
             display(move,t);
             
             move.swap36();
             display(move,t);
         }
         
         if (t[8] == 3)
         {
             move.swap56();
             display(move,t);
             
             move.swap69();
             display(move,t);
             
             move.swap89();
             display(move,t);
             
             move.swap58();
             display(move,t);
             
             move.swap25();
             display(move,t);
             
             move.swap23();
             display(move,t);
             
             move.swap36();
             display(move,t);
         }
     }
}

//Getting the four in the correct position
void getfour(moves &move, int t[])
{
    //If the four is in the bottom right
    if (t[8] == 4)
    {
        if (t[3] == -1)
        {
            move.swap45();
            display(move,t);
        }
        if (t[4] == -1)
        {
            move.swap56();
            display(move,t);
        }
        if (t[5] == -1)
        {
            move.swap69();
            display(move,t);
        }
        if (t[6] == -1)
        {
            move.swap78();
            display(move,t);
        }
        if (t[7] == -1)
        {
            move.swap89();
            display(move,t);
        }
    }
    
    //If the four is in the bottom middle
    if (t[7] == 4)
    {
        if (t[6] == -1)
        {
            move.swap47();
            display(move,t);
        }
        if (t[3] == -1)
        {
            move.swap45();
            display(move,t);
        }
        if (t[8] == -1)
        {
            move.swap69();
            display(move,t);
        }
        if (t[5] == -1)
        {
            move.swap56();
            display(move,t);
        }
        if (t[4] == -1)
        {
            move.swap58();
            display(move,t);
        }
    }
    
    //If the four is in the bottom left
    if (t[6] == 4)
    {
        if (t[8] == -1)
        {
            move.swap69();
            display(move,t);
        }
        if (t[7] == -1)
        {
            move.swap58();
            display(move,t);
        }
        if (t[5] == -1)
        {
            move.swap56();
            display(move,t);
        }
        if (t[4] == -1)
        {
            move.swap45();
            display(move,t);
        }
        if (t[3] == -1)
        {
            move.swap47();
            display(move,t);
        }
    }
    
    //If the four is in the middle right
    if (t[5] == 4)
    {
        if (t[8] == -1)
        {
            move.swap78();
            display(move,t);
        }
        if (t[7] == -1)
        {
            move.swap58();
            display(move,t);
        }
        if (t[6] == -1)
        {
            move.swap47();
            display(move,t);
        }
        if (t[3] == -1)
        {
            move.swap45();
            display(move,t);
        }
        if (t[4] == -1)
        {
            move.swap56();
            display(move,t);
        }
    }
    
    //If the four is in the middle
    if (t[4] == 4)
    {
        if (t[5] == -1)
        {
            move.swap69();
            display(move,t);
        }
        if (t[8] == -1)
        {
            move.swap89();
            display(move,t);
        }
        if (t[7] == -1)
        {
            move.swap78();
            display(move,t);
        }
        if (t[6] == -1)
        {
            move.swap47();
            display(move,t);
        }
        if (t[3] == -1)
        {
            move.swap45();
            display(move,t);
        }
    }
}

//Getting the seven in the correct position
void getseven(moves &move, int t[])
{
    //Putting the space in the bottom right corner if it isn't already there
    if (t[6] != -1)
    {
        if (t[5] == -1)
        {
            move.swap69();
            display(move,t);
        }
        if (t[4] == -1)
        {
            move.swap58();
            display(move,t);
        }
        if (t[8] == -1)
        {
            move.swap89();
            display(move,t);
        }
        if (t[7] == -1)
        {
            move.swap78();
            display(move,t);
        }
    }
    
    //If the space is in the bottom right and the seven is right next to it
    if (t[7] == 7 && t[6] == -1)
    {
        move.swap78();
        display(move,t);
    }
    
    //If the space is in the bottom right and the seven is in the middle
    if (t[4] == 7 && t[6] == -1)
    {
        move.swap78();
        display(move,t);
        
        move.swap58();
        display(move,t);
        
        move.swap56();
        display(move,t);
        
        move.swap69();
        display(move,t);
        
        move.swap89();
        display(move,t);
        
        move.swap78();
        display(move,t);
    }
    
    //If the space is in the bottom right and the three is not in the middle or right next to it
    if (t[7] != 3 && t[4] != 3 && t[6] == -1)
    { 
        move.swap47();
        display(move,t);
        
        move.swap45();
        display(move,t);
        
        if (t[5] == 7)
        {
            move.swap56();
            display(move,t);
            
            move.swap69();
            display(move,t);
            
            move.swap89();
            display(move,t);
            
            move.swap58();
            display(move,t);
            
            move.swap45();
            display(move,t);
            
            move.swap47();
            display(move,t);
            
            move.swap78();
            display(move,t);
        }
        
        if (t[8] == 7)
        {
            move.swap58();
            display(move,t);
            
            move.swap89();
            display(move,t);
            
            move.swap69();
            display(move,t);
            
            move.swap56();
            display(move,t);
            
            move.swap45();
            display(move,t);
            
            move.swap47();
            display(move,t);
            
            move.swap78();
            display(move,t);
        }
        
        if (t[7] == 7)
        {
            move.swap45();
            display(move,t);
            
            move.swap47();
            display(move,t);
            
            move.swap78();
            display(move,t);
        }
    }
}

//Getting the five in the correct position
void getfive(moves &move, int t[])
{
     //If the five is in the middle right
     if (t[5] == 5)
     {
         if (t[8] == -1)
         {
             move.swap89();
             display(move,t);
         }
         
         if (t[7] == -1)
         {
             move.swap58();
             display(move,t);
         }
         
         if (t[4] == -1)
         {
             move.swap56();
             display(move,t);
         }
     }
     
     //If the five is in the bottom middle
     if (t[7] == 5)
     {
         if (t[8] == -1)
         {
             move.swap69();
             display(move,t);
         }
         
         if (t[5] == -1)
         {
             move.swap56();
             display(move,t);
         }
         
         if (t[4] == -1)
         {
             move.swap58();
             display(move,t);
         }
     }
     
     //If the five is in the bottom right
     if (t[8] == 5)
     {
         if (t[4] == -1)
         {
             move.swap56();
             display(move,t);
         }
         
         if (t[5] == -1)
         {
             move.swap69();
             display(move,t);
             
             move.swap89();
             display(move,t);
             
             move.swap58();
             display(move,t);
             
             move.swap56();
             display(move,t);
         }
         
         if (t[7] == -1 && t[8] == 5)
         {
             move.swap89();
             display(move,t);
             
             move.swap69();
             display(move,t);
             
             move.swap56();
             display(move,t);
             
             move.swap58();
             display(move,t);
         }
     }
}

//Getting the six in the correct position
void getsix(moves &move, int t[])
{
    move.swap69();
    display(move,t);
}

//Getting the eight in the correct position
void geteight(moves &move, int t[])
{
    move.swap89();
    display(move,t);
}