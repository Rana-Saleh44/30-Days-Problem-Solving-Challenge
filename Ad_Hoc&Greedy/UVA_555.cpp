/*the ad hoc problem doesn't have a certain way to simulate it (doesn't undergo a certain category like graph theory, number theory) like strings, time and games"not all like game theory"
games considered ad hoc : cards, chess, tic tac toe, snakes/ladders, rock-paper-scissors
ad hoc can be solved recursively
strings and are ad hoc: palindrome (called be also dp, or related DS), anagrams"word rearrange->another word"
1. real life problems
2. problems involving time
3. time waster problems (to handle all case and it could be complicated)
*/
//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > players[4];
const string pattern = "CDSH23456789TJQKA";

pair<int, int> encode(string card) {
    pair<int, int> ret;
    for (int i = 0; i < pattern.length(); ++i) {
        if (card[0] == pattern[i]) {
            ret.first = i;
        }
        if (card[1] == pattern[i]) {
            ret.second = i; // Changed from '==' to '='
        }
    }
    return ret;
}

string decode(pair<int, int> card) {
    string ret = "";
    ret += pattern[card.first];
    ret += pattern[card.second];
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    char c;
    while (cin >> c and c != '#') {
        string line, cards = "";
        for (int i = 0; i < 2; ++i) {
            cin >> line;
            cards += line;
        }
        int st;
        if (c == 'N') st = 1;
        if (c == 'E') st = 2;
        if (c == 'S') st = 3;
        if (c == 'W') st = 0;
        for (int i = 0; i < cards.length(); i += 2) {
            string curCard = "";
            curCard += cards[i];
            curCard += cards[i + 1];

            pair<int, int> cur_card_pair = encode(curCard);
            players[st].push_back(cur_card_pair);
            st = (st + 1) % 4; // 01230
        }
        for (int i = 2, j = 0; j < 4; i = (i + 1) % 4, ++j) {
            if (i == 0) cout << "N:";
            if (i == 1) cout << "E:";
            if (i == 2) cout << "S:";
            if (i == 3) cout << "W:";
            sort(players[i].begin(), players[i].end());
            for (pair<int, int> k : players[i]) {
                cout << " " << decode(k);
            }
            cout << "\n";
        }
        for (int i = 0; i < 4; ++i) {
            players[i].clear();
        }
    }
    return 0;
}

