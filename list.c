#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "console.h"
#include "borders.h"
#include "Game/player.h"

typedef struct node {
    int x,y;
    char symbol;
    struct node* next;
}Node;

typedef struct lists {
    int size;
    Node* head;
}List;

List* createList() {
    List* l = (List*) malloc(sizeof(List));
    l->size = 0;
    l->head = NULL;
    return l;
}

List* push(List* l, char symbol, int x, int y) {
    Node* node = (Node*) malloc(sizeof(List));
    node->x = x;
    node->y = y;
    node->symbol = symbol;
    node->next = l->head;
    l->head = node;
    l->size++;
    return l;
}

void printList(List* l) {
    if (l->size < 1) {
        printf("Vazio");
        return;
    }
    Node* p = l->head;
    while(p != NULL) {
        gotoxy(p->x,p->y);
        printf("%c", p->symbol);
        p = p->next;
    }
}

int listSize(List* l) {
    return l->size;
}

List* listFree(List* l) {
    do {
        if(l->size > 0) {
            Node* aux = NULL;
            Node* p = l->head;

            while(p != NULL) {
                aux = p;
                p = p->next;
            }

            if(p == NULL)
                return l;

            if(aux == NULL) {
                l->head = p->next;
            } else {
                aux->next = p->next;
            }

            free(p);
        }
    }while(l->head != NULL);
    return l;
}

List* listRemoveByCoord(List* l, int x, int y) {
    if(l->size > 0) {
        Node* aux = NULL;
        Node* p = l->head;
        while(p != NULL && (p->x != x && p->y != y)) {
            aux = p;
            p = p->next;
        }
        if(p == NULL)
            return l;

        if(aux == NULL) {
            l->head = p->next;
        } else {
            aux->next = p->next;
        }
        free(p);
        return l;
    }
    return l;
}

Node* atPos(List* l, int index) {
    if(index >= 0 && index < l->size) {
        Node* node = l->head;
        for(int i = 0; i < index; i++) {
            node = node->next;
        }
        return node;
    }
    return NULL;
}

int X(List* l, int index) { return atPos(l, index)->x; }

int Y(List* l, int index) { return atPos(l, index)->y; }

char symbol(List* l, int index) { return atPos(l, index)->symbol; }

List* addX(List* l, int index, int x) {
    if(index >= 0 && index < l->size) {
        Node* node = l->head;
        for(int i = 0; i < index; i++) {
            node = node->next;
        }
        node->x += x;
        return l;
    }
    return NULL;
}

List* addY(List* l, int index, int y) {
    if(index >= 0 && index < l->size) {
        Node* node = l->head;
        for(int i = 0; i < index; i++) {
            node = node->next;
        }
        node->y += y;
        return l;
    }
    return NULL;
}

List* defineX(List* l, int index, int x) {
        if(index >= 0 && index < l->size) {
        Node* node = l->head;
        for(int i = 0; i < index; i++) {
            node = node->next;
        }
        node->x = x;
        return l;
    }
    return NULL;
}

List* defineY(List* l, int index, int y) {
    if(index >= 0 && index < l->size) {
        Node* node = l->head;
        for(int i = 0; i < index; i++) {
            node = node->next;
        }
        node->y = y;
        return l;
    }
    return NULL;
}
