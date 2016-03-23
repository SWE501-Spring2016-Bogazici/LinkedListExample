//
// Created by Arda Oğulcan Pektaş on 09/03/16.
//
#include <iostream>

#include "DList/DList.h"

using namespace std;

DList splitString(string source, string seperator) {
    DList temp;

    while (source.find(seperator) != string::npos) {
        temp.addBack(source.substr(0,source.find(seperator)));
        source = source.substr(source.find(seperator)+1);
    }
    temp.addBack(source);

    return temp;
}
string getLongestWord(DList& dictionary) {
    string biggestWord=dictionary.getItemAt(0)->data;

    for (unsigned int i=0;i<dictionary.size();i++) {
        string word = dictionary.getItemAt(i)->data;
        if(word.size()>biggestWord.size()) biggestWord=word;
    }

    return biggestWord;
}
string fillWithChar(string c, long size) {
    int i=0;
    string temp="";
    while (i<size) {
        temp += c;
        i++;
    }
    return temp;
}
void printFrame(string& input) {

    DList dictionary = splitString(input, ",");

    string longestWord = getLongestWord(dictionary);

    cout << fillWithChar("*",longestWord.size()+4);

    for (unsigned int i=0;i<dictionary.size();i++) {
        string word = dictionary.getItemAt(i)->data;
        cout << endl<<"* " << word << fillWithChar(" ",longestWord.size()-word.size()) << " *";
    }

    cout << endl<< fillWithChar("*",longestWord.size()+4);


}


int main() {

    cout << "Write words to frame, use comma (,) to seperate each word"<<endl;

    string inputString;

    cin >> inputString;
    cin.ignore();

    printFrame(inputString);

    return 0;
}