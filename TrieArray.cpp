//
// Created by polli on 11/28/21.
//

#include "TrieArray.h"


TrieArray::TrieArray() {
    memset(cToI, -1, sizeof(int) * 128);

    for (char c = 'a'; c <= 'z'; c++) {
        cToI[c] = c - 'a';
    }
    for (char c = '0'; c <= '9'; c++) {
        cToI[c] = c - '0' + 26;
    }
    cToI['/'] = 36;
    cToI['?'] = 37;
    cToI['='] = 38;

    trie.push_back(Node());
}

void TrieArray::buildTrie(vector<string> &controllers) {
    int i = 0;
    for (string &s: controllers) {
        int pos = 0;

        for (char c: s) {
            int ic = cToI[c];

            if (trie[pos].m[ic] == -1) {
                trie[pos].m[ic] = trie.size();
                trie.push_back(Node());
            }
            pos = trie[pos].m[ic];
        }

        trie[pos].res = i;
        i++;
    }
}

int TrieArray::findString(string &s) {
    int res = -1, pos = 0;

    for (char c: s) {
        int ic = cToI[c];

        if (trie[pos].m[ic] == -1) {
            break;
        }

        pos = trie[pos].m[ic];
        if (trie[pos].res != -1) {
            res = trie[pos].res;
        }
    }
    return res;
}