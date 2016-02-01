/************** Data format Notes ****************
The data are gonna be formated into two files, a
test file and a learning set.
Each line represent one set of data
There is two half on each set of data, the inputs
and desired output value both separated by '|'
In each set, each values are read as double, and 
are separated by ';'
*************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

#define SET_SIZE 100000
#define BUFFER_SIZE 100

using namespace std;

/**
 *  The transfer function that you want to make you network learn
 */
unsigned transferFunction (unsigned val1, unsigned val2)
{
    return val1^val2; //Xor
}

//Main code
int main() 
{
    //Declarations
    string data;
    
    //Folder creation
    system("mkdir data");

   //Open files in write mode
   ofstream learnFile("./data/learn.dat");
   
   //Open files in write mode
   ofstream testFile("./data/test.dat");
   
   //Init random seed
   srand(time(NULL));
   
   for (unsigned d = 0; d < SET_SIZE; d++)
   {
        //Create a value between -1000 and 1000
        unsigned startVal1 = (rand() % 2);
        unsigned startVal2 = (rand() % 2);
       
        //Calculate the output desired value
        unsigned endVal = transferFunction(startVal1,startVal2);
       
        //Write the data line (see top note for format)
        data = to_string(startVal1);
        data += ";";
        data += to_string(startVal2);
        data += "|";
        data += to_string(endVal);
        
        //Write to file 
        if (d < (SET_SIZE * 9 / 10)) learnFile << data << endl;
        else testFile << data << endl;
   }
   
   //Close file
   learnFile.close();
   testFile.close();

   return 0;
}