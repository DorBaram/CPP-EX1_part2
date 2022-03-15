/**
 * mat exercise Main file
 * 
 * Author: Dor Baram
 * Since : 2022-03
 */

#include "mat.cpp"
using namespace ariel;
#include <string>       //for strings
#include <iostream>     //for output
using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Hello there, \nThis Is The MCFC- 'Mat Creator For Carpets'\nPlease Choose What To Do:\n1-\tMake Your Own Carpet\n2-\tRandom Carpet (RECOMENDED)\nOther-\tExit\n";
    char input;
    cin >> input;
    if(input == '1')
    {
        cout << "Please Enter Two Odd Numbers, Then Two Characters.\nInput:\t";
        int i1,i2;
        char i3,i4;
        cin >> i1;
        cin >> i2;
        cin >> i3;
        cin >> i4;
        try{
           cout << "Your Carpet:\n" << mat(i1,i2,i3,i4) <<endl; 
        }
        catch (exception& except) {
	 	cout << "Exception Was Caught:\t" << except.what() << endl << "Please Run The Program Again" << endl;  
	    }
    }
    else if(input == '2')
    {
        cout <<"Here Is A Random Example:\n";
        int r1,r2,r3,r4;
        srand (time(NULL));
        r1 = (rand() % 20)*2+1;
        r2 = (rand() % 20)*2+1;
        r3 = (rand() % (LASTCHAR - FIRSTCHAR))+FIRSTCHAR;
        r4 = (rand() % (LASTCHAR - FIRSTCHAR))+FIRSTCHAR;
        cout << mat(r1,r2,r3,r4);  
    }
    else
    {
        cout << "Bye\n";
    }
    return 0;
}