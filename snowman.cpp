#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include "snowman.hpp"

using namespace std;
const vector<string> Head = {"       \n _===_ ", "  ___  \n ..... ", "   _   \n  /_\\  ", "  ___  \n (_*_) "};
const vector<string> X1 = {" ", "\\", " ", " "};
const vector<string> Eye = {".", "o", "O", "-"};
const vector<string> Nose = {",", ".", "_", " "};
const vector<string> Y1 = {" ", "/", " ", " "};
const vector<string> X2 = {"<", " ", "/", " "};
const vector<string> Torso = {" : ", "] [", "> <", "   "};
const vector<string> Y2 = {">", " ", "\\", " "};
const vector<string> Base = {" : ", "\" \"", "___", "   "};

bool isValid(int num){
    if (num < 11111111 || num > 44444444)
        return false;
    int part = num % 10; 
    for (int i = 0; i < 8; i++)
    {
        if (part > 4 || part < 1)
            return false;
        num /= 10;
        part = num % 10;      
    }
    return true;
}

int charToInt(char part){ return ((part - '0') - 1);}

namespace ariel{
    string snowman(int num){
        string outpt = "";
        if (!isValid(num))
            throw invalid_argument{"Unvalid number format. Requires 8 digits, between 1-4 each. \n"};
        
        string snowy = to_string(num);
        outpt += Head.at(charToInt(snowy[0])) + "\n";
        outpt += X1.at(charToInt(snowy[1])) + "(" + Eye.at(charToInt(snowy[2])) + Nose.at(charToInt(snowy[3]))
                    + Eye.at(charToInt(snowy[4])) + ")" + Y1.at(charToInt(snowy[5])) + "\n";
        outpt += X2.at(charToInt(snowy[1])) + "(" + Torso.at(charToInt(snowy[6])) + ")" + Y2.at(charToInt(snowy[5])) + "\n";
        outpt += " (" + Base.at(charToInt(snowy[7])) + ") ";

        return outpt;
    }
};