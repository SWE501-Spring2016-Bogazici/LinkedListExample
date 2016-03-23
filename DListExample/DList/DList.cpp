//
// Created by Arda Oğulcan Pektaş on 09/03/16.
//

#include <stddef.h>
#include <string>
#include <iostream>
#include "DList.h"

DList::DList() {
    head=NULL;
    tail=NULL;
    count=0;
}

void DList::addFront(std::string d) {
    if(head==NULL) {
        head = tail = new DListItem(d);

    } else {
        DListItem* tmp = head;

        head=new DListItem(d);
        tmp->prev = head;
        head->next = tmp;

    }
    count++;

}

void DList::addBack(std::string d) {
    if(head==NULL) {
        head = tail = new DListItem(d);
    } else {
        DListItem* tmp = new DListItem(d);
        tail->next = tmp;
        tmp->prev=tail;

        tail=tmp;
    }
    count++;
}

bool DList::popFront (std::string& item) {
    if(head == NULL) return false;
    DListItem* tmp = head;

    head = tmp->next;
    item = tmp->data;
    count--;

    delete tmp;
    return true;

}

bool DList::popBack(std::string& item) {
    if(head == NULL) return false;

    DListItem* tmp = tail;
    item = tmp->data;

    if(head == tail) head = tail = NULL;
    else {
        tail = tmp->prev; tail->next = NULL;
    }
    delete tmp;
    count--;
    return true;

}
DListItem *DList::getItemAt(unsigned int position) {
    if(head==NULL) return NULL;
    if(position>=count) return NULL;

    unsigned int i=count-1;
    if(count-position<position) {
        for(DListItem* item = tail;item!=NULL;item=item->prev) {
            if(i == position) {
                return item;
            }
            i--;
        }
    } else {
        i=0;
        for(DListItem* item = head;item!=NULL;item=item->next) {
            if(i == position) {
                return item;
            }
            i++;
        }
    }
    return NULL;

}
unsigned int DList::size() {
    return count;
}

void DList::print() {
    if(head==NULL) {
        std::cout << "Empty List";
        return;
    }
    std::cout << "List With "<< count <<" items."<<"Head : "<< head->data <<" Tail: " << tail->data <<std::endl;
    for(DListItem* p = head;p!=NULL;p=p->next) {
        std::cout << p->data <<" ";
    }
    std::cout << std::endl;
}