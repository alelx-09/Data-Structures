#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main ()
{
    string str;
    ifstream myfile ("read.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,str) ) /// Reading until End Of File
        {
            cout << str << endl; /// Console Output
        }
        myfile.close(); /// Closing the File
    }

    else
        cout << "Unable to open file";

    return 0;
}