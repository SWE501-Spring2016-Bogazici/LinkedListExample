#include <string>
#include <iostream>
//#include "DList/DList.h"


using namespace std;

template <typename  T>
struct DListItem {

    T data;
    DListItem<T> *prev;
    DListItem<T> *next;

    DListItem(T& d) {
        data = d;
        next = NULL;
        prev = NULL;
    }
};


template  <typename T>
class DList {

    DListItem<T>* head;
    DListItem<T>* tail;
    unsigned int count;

public:
    DList() {
        head=NULL;
        tail=NULL;
        count=0;
    }


    void addFront(T d) {
        if(head==NULL) {
            head = tail = new DListItem<T>(d);

        } else {
            DListItem<T>* tmp = head;

            head=new DListItem<T>(d);
            tmp->prev = head;
            head->next = tmp;

        }
        count++;

    }


    void addBack(T d) {
        if(head==NULL) {
            head = tail = new DListItem<T>(d);
        } else {
            DListItem<T>* tmp = new DListItem<T>(d);
            tail->next = tmp;
            tmp->prev=tail;

            tail=tmp;
        }
        count++;
    }


    bool popFront (T& item) {
        if(head == NULL) return false;
        DListItem<T>* tmp = head;

        head = tmp->next;
        item = tmp->data;
        count--;

        delete tmp;
        return true;

    }


    bool popBack(T& item) {
        if(head == NULL) return false;

        DListItem<T>* tmp = tail;
        item = tmp->data;

        if(head == tail) head = tail = NULL;
        else {
            tail = tmp->prev; tail->next = NULL;
        }
        delete tmp;
        count--;
        return true;

    }

    DListItem<T> *getItemAt(unsigned int position) {
        if(head==NULL) return NULL;
        if(position>=count) return NULL;

        unsigned int i=count-1;
        if(count-position<position) {
            for(DListItem<T>* item = tail;item!=NULL;item=item->prev) {
                if(i == position) {
                    return item;
                }
                i--;
            }
        } else {
            i=0;
            for(DListItem<T>* item = head;item!=NULL;item=item->next) {
                if(i == position) {
                    return item;
                }
                i++;
            }
        }
        return NULL;

    }

    unsigned int size() {
        return count;
    }


    void print() {
        if(head==NULL) {
            std::cout << "Empty List";
            return;
        }
        std::cout << "List With "<< count <<" items."<<"Head : "<< head->data <<" Tail: " << tail->data <<std::endl;
        for(DListItem<T>* p = head;p!=NULL;p=p->next) {
            std::cout << p->data <<" ";
        }
        std::cout << std::endl;
    }
};





int main() {

    DList<string> list;

    DList<int> intList;

    cout << endl << "---------------- String List -------------------" <<endl;
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

    cout <<endl<< "---------------- Int List -------------------" <<endl;

    intList.addFront(3);
    intList.addFront(5);
    intList.addFront(8);

    intList.addBack(7);

    intList.print();

    cout <<endl;
    int restInt;
    while(intList.popBack(restInt)) cout << restInt << endl;

    cout <<endl;
    intList.print();

    return 0;
}