//
// Created by polli on 11/28/21.
//

#include <fstream>
#include "Utils.h"
#include <algorithm>
#include <vector>
#include <chrono>

const int numOfQueries = 10000000;

char Utils::genChar(int i)
{
    if (i < 26)
    {
        return 'a' + i;
    }
    else if (i < 36)
    {
        return '0' + (i - 26);
    }
    else if(i == 36)
    {
        return '/';
    }
    else if (i == 37)
    {
        return '?';
    }
    else if (i == 38)
    {
        return '=';
    }
    else
    {
        return '*';
    }
}

string Utils::genRandomStr(int len, int mod) {
    string s;
    string symbol = "";
    for (int i = 0; i < len; i++)
    {
        s += genChar(rand() % mod);
    }
    return s;
}

void Utils::genInput(int n) {
    vector<string> controllers;
    vector<string> qs;

    string s = "";
    for (int i = 0; i < n * 3 / 5; i++) {
        s = genRandomStr(rand() % 20 + 3, 26);
        controllers.push_back(s);
    }
    for (int i = n * 3 / 5; i < n * 4 / 5; i++) {
        s = controllers[rand() % controllers.size()] + genRandomStr(rand() % 5 + 17, 26);
        controllers.push_back(s);
    }
    for (int i = n * 4 / 5; i < n; i++) {
        s = controllers[rand() % controllers.size()] + genRandomStr(rand() % 10 + 2, 26) +
                   genRandomStr(rand() % 5 + 1, 26);
        controllers.push_back(s);
    }

    ofstream inputFile("input.txt");
    inputFile << n << "\n";
    for (auto it : controllers)
    {
        inputFile << it << "\n";
    }
    inputFile << numOfQueries << "\n";

    for (int i = 0; i < numOfQueries; i++) {
        int r = rand() % 127;
        if (r < 27) {
            inputFile << genRandomStr(rand() % 20 + 3, 26) << "\n";
        } else if (r < 42){
            inputFile << genRandomStr(rand() % 30 + 3, 39) << "\n";
        } else if (r < 54) {
            inputFile << controllers[rand() % controllers.size()] << "\n";
        } else if (r < 86) {
            inputFile << controllers[rand() % controllers.size()] << "\n";
        } else {
            int iters = rand() % 5 + 1;
            s = controllers[rand() % controllers.size()];
            for (int j = 0; j < iters; j++) {
                s += "/" + genRandomStr(rand() % 10 + 2, 39);
            }
            inputFile << s << "\n";
        }
    }
    inputFile.close();

}

double Utils::getTime(void(* f)()) {
    auto start = chrono::steady_clock::now();
    f();
    auto end = chrono::steady_clock::now();
    auto elapsed =  chrono::duration_cast< chrono::milliseconds>(end - start);
    return elapsed.count();
}