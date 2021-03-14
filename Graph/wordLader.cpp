using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
#include<map>
#define loop(start, end, i) for (int i = start; i < end; i++)
#define loopRev(start, end, i) for (int i = start; i >= end; i++)

int ladderLength(string beginWord, string endWord, vector<string> &wordList) {

    int wordLength = beginWord.length();
    int words = wordList.size();

    map<string, vector<string>> wordGraph;

    for (int i = 0; i < words;i++) {
        
        for (int j = 0;j<wordLength;j++) {
            string newString = wordList[i].substr(0, j) + '*' + wordList[i].substr(j + 1, wordLength);

            if(wordGraph.find(newString) != wordGraph.end()) {
                wordGraph[newString].push_back(wordList[i]);
            } else {
                vector<string> newList;
                newList.push_back(wordList[i]);
                wordGraph.insert(make_pair(newString, newList));
            }
        }
    }
}




int main()
{

    string begin;
    string end;

    cin >> begin >> end;

    vector<string> wordList;
    int words;
    cin >> words;
    loop(0,words,i) {
        
        string addition;
        cin >> addition;

        wordList.push_back(addition);
    }

    int result = ladderLength(begin, end, wordList);
}