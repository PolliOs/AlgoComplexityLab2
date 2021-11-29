//
// Created by polli on 11/28/21.
//

#ifndef LAB_2_UTILS_H
#define LAB_2_UTILS_H

#include <string>
using namespace std;

class Utils {
public:
    void genInput(int n);
    string genRandomStr(int len, int mod);
    char genChar(int ind);
    double getTime(void(* f)());

};


#endif //LAB_2_UTILS_H
