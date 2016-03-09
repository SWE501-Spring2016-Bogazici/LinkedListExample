//
// Created by Arda Oğulcan Pektaş on 09/03/16.
//

#include <stddef.h>
#include "DListItem.h"

DListItem::DListItem(std::string d) {
    data = d;
    next = NULL;
    prev = NULL;
}