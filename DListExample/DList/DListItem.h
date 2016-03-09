//
// Created by Arda Oğulcan Pektaş on 09/03/16.
//

#ifndef DLIST_DLISTITEM_H
#define DLIST_DLISTITEM_H

#include <string>

struct DListItem {
    DListItem *prev;
    DListItem *next;


    std::string data;

    DListItem(std::string d=NULL);

};


#endif //DLIST_DLISTITEM_H
