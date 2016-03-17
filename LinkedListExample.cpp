//============================================================================
// Name        : dlinked_list.cpp
// Author      : Gokce Yucel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct DNode {
    DNode *prev;
    DNode *next;
    int data;

public:
    DNode(int d) {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

struct DList {
    DNode *head;
    DNode *tail;
    int count;

public:
    DList() {
        head=NULL;
        tail=NULL;
        count=0;
    }

    void AddFront(int x) {
        if (head == NULL) {
            head = tail = new DNode(x);
        }
        else {
            DNode *tmp = head;
            head = new DNode(x);
            tmp->prev = head;
            head->next = tmp;
        }
        count++;
    }

    void AddBack(int x) {
        if (tail == NULL) {
            tail = head = new DNode(x);
        }
        else {
            DNode *tmp = tail;
            tail = new DNode(x);
            tmp->next = tail;
            tail->prev = tmp;
        }
        count++;
    }

    bool PopFront(int& ret) {
        if (head == NULL) return false;
        DNode* tmp = head;
        head = tmp->next;
        ret = tmp->data;
        delete tmp;
        count--;
        return true;
    }

    bool PopBack(int& ret) {
        if (tail == NULL) return false;
        DNode* tmp = tail;
        tail = tmp->prev;
        ret = tmp->data;
        delete tmp;
        count--;
        return true;
    }

    DNode* GetElementAtPos(unsigned int pos) {
        if (pos > count || head == NULL) return NULL;
        unsigned int idx;
        if (pos - count < pos) {
            idx = count;
            for (DNode* p = tail; p->prev != NULL; p = p->prev){
                if (idx-- == pos) return p;
            }
        }
        else {
            idx = 0;
            for (DNode* p = head; p->next != NULL; p = p->next){
                if (++idx == pos) return p;
            }
        }
        return NULL;
    }

    void Print() {
        for (DNode* p = head; p != NULL; p = p->next) {
            cout << p->data << " ";
        }
        cout << endl;
    }
};

int main() {
    DList dl;
    dl.AddFront(1);
    dl.AddFront(2);
    dl.AddBack(3);
    dl.AddFront(4);
    dl.AddBack(9);
    dl.Print();

//  int ret;
//  while(dl.PopBack(ret)) cout << ret << endl;

    DNode* p = dl.GetElementAtPos(5);
    cout << p->data << endl;
}
