#include <cstdlib>
#include <iostream>

using namespace std;

//User-Defined Class Moves
class moves
{
    //Purposes of public functions explained in .cpp file
    public:
           moves();
           void settile(int t[9]);
           void gettile(int t[9]);
           void swap12();
           void swap14();
           void swap23();
           void swap25();
           void swap36();
           void swap45();
           void swap47();
           void swap56();
           void swap58();
           void swap69();
           void swap78();
           void swap89();
           int checkvalid1();
           bool checkvalid2();
           bool checkvalid3();
           bool checksolve();
    private:
            int tile[9]; //Used as the game board
};