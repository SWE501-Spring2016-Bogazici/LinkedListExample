//
// Created by Arda Oğulcan Pektaş on 09/03/16.
//

#ifndef DLIST_DLIST_H
#define DLIST_DLIST_H

#include <string>
#include "DListItem.h"


class DList {
    DListItem *head;
    DListItem *tail;
    unsigned int count;

public:
    DList();

    void addFront(std::string d);

    void addBack(std::string d);

    bool popFront (std::string& item);

    bool popBack(std::string& item);

    DListItem *getItemAt(unsigned int position);

    unsigned int size();

    void print();

};


#endif //DLIST_DLIST_H
