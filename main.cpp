#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <string>
#include "Utils.h"
#include "Trie.h"
#include "TrieArray.h"

using namespace std;

vector<string> controllers;
vector<string> qs;
Utils utils;


vector<int> runBrute(int n, int q) {
    vector<int> results;
    results.reserve(qs.size());

    for (int i = 0; i < q; i++) {
        int res = -1, bestLen = -1;

        for (int j = 0; j < n; j++) {
            int size = min(controllers[j].size(), qs[i].size());
            int l = 0;

            for (; l < size; l++) {
                if (controllers[j][l] != qs[i][l]) {
                    break;
                }
            }

            if (l == controllers[j].size()) {
                if (size > bestLen) {
                    res = j;
                    bestLen = l;
                }
            }
        }
        results.push_back(res);
    }
    return move(results);
}

void readData(int &n, int &q) {
    controllers.clear();
    qs.clear();

    string ts;
    ifstream input("input.txt");

    input >> n;
    for (int i = 0; i < n; i++) {
        input >> ts;
        controllers.push_back(ts);
    }
    input >> q;
    qs.reserve(q);
    for (int i = 0; i < q; i++) {
        input >> ts;
        qs.push_back(ts);
    }
}

void bruteForceSolution() {
    cout.precision(5);
    int n, q;
    readData(n, q);
    vector<int> res = runBrute(n, q);
    //  cout << " n = " << n << " q = " << q << "\n!!!1";
//    for(auto r:res){
//        cout << r << "\n";
//    }
}


vector<int> runTrieArray(int n, int q) {
    vector<int> allRes;
    allRes.reserve(qs.size());

    TrieArray mp;
    mp.buildTrie(controllers);
    for (int i = 0; i < q; i++) {
        allRes.push_back(mp.findString(qs[i]));
    }

    return move(allRes);
}

void BorArraySolution() {

    int n, q;
    readData(n, q);
    vector<int> res;
    res = runTrieArray(n, q);//utils.genInput(100);

}

int main() {
    utils.genInput(700);
    cout << utils.getTime(bruteForceSolution) << "\n";
    cout << utils.getTime(BorArraySolution);

    return 0;
}