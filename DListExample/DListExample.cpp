#include <string>
#include <iostream>
#include "DList/DList.h"


using namespace std;

int main() {

    DList list;

    list.addFront("lorem");
    list.addFront("ipsum");
    list.addFront("dolar");

    list.addBack("sit");

    list.print();

    cout <<endl;
    string rest;
    while(list.popBack(rest)) cout << rest << endl;

    cout <<endl;
    list.print();

    return 0;
}