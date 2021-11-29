//
// Created by polli on 11/28/21.
//

#ifndef LAB_2_TRIE_H
#define LAB_2_TRIE_H

#include <unordered_map>
#include <vector>

using namespace std;

class Trie{
    class Node
    {
    public:
        int res = -1;
        unordered_map<char, int> m;
    };

    vector <Node> trie;

public:

    Trie(){
        trie.push_back(Node());
    }

    void buildTrie(vector<string>& controllers);

    int findString(string& s);
};

#endif //LAB_2_TRIE_H
