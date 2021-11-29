//
// Created by polli on 11/28/21.
//

#ifndef LAB_2_TRIEARRAY_H
#define LAB_2_TRIEARRAY_H

#include <vector>
#include <cstring>
#include <string>

using namespace std;

class TrieArray {
    class Node {
    public:

        int res;
        int m[40];

        Node() {
            res = -1;
            for (auto &it: m) {
                it = -1;
            }
        }
    };

    vector<Node> trie;
    int cToI[128];

public:

    TrieArray();
    void buildTrie(vector<string>& controllers);
    int findString(string& s);
};



#endif //LAB_2_TRIEARRAY_H
