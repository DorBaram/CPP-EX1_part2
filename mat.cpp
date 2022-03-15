/**
 * mat exercise
 * 
 * Author: Dor Baram
 * Since : 2022-03
 */
#include "mat.hpp"
using namespace ariel;
#include <string>       //for strings
#include <iostream>     //for output
#include <stdexcept>    //for runtime exeptions
#include <vector>       //for Mat representation
using namespace std;

string ariel::mat(int col,int row, char c1, char c2){  
    //checks if col and row are positive (1), and odd (2). and if c1 and c2 are valid chars (3).
    if (row <1 || col<1)
    {
        throw invalid_argument("Mat Size Should Be Positive");       //(1)
    }
    if (row % 2 == 0 || col % 2 == 0)
    {
        throw invalid_argument("Mat Size Should Be An Odd Number");  //(2)
    }
    if (c1 < FIRSTCHAR || c2 < FIRSTCHAR || c1 > LASTCHAR || c2 > LASTCHAR)
    {
        throw invalid_argument("Charecter Is Invalid");             //(3)
    }
    /**
     * generates two mats that is represented by vectors of vectors.
     * creates a minimum table in the first (1), and a transpose in the second (2).
     * then it checks the minimum of the same place in both (3).
     * lastly it does mod 2, if even it is c1, else- c2. and put it in string (4).
     * took the idea from the link that was provided with the excersise https://codegolf.stackexchange.com/questions/241219/mat-printing-matrix
     */
    vector<vector<int>> m1(row,vector<int>(col));
    vector<vector<int>> m2(row,vector<int>(col));
    string out;
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            m1.at(i).at(j) = min(i,j);                              //(1)
            m2.at(i).at(j) = min(row-i-1,col-j-1);                  //(2)
            m1.at(i).at(j) = min(m1.at(i).at(j),m2.at(i).at(j));    //(3)
        }
    }
    //convert the mats to string (4)
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (m1.at(i).at(j) % 2 ==0)
            {
                out.push_back(c1);
            }
            else
            {
                out.push_back(c2);
            }
        }
        out.push_back('\n');
    }
    return out;
}