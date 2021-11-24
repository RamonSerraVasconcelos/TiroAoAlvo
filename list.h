typedef struct node Node;
typedef struct lists List;

List* createList();
List* push(List* l, char symbol, int x, int y);
void printList(List* l);
int listSize(List* l);
List* listFree(List* l);
List* listRemoveByCoord(List* l, int x, int y);
Node* atPos(List* l, int index);
int X(List* l, int index);
int Y(List* l, int index);
char symbol(List* l, int index);
List* addX(List* l, int index, int x);
List* addY(List* l, int index, int y);
List* defineX(List* l, int index, int x);
List* defineY(List* l, int index, int y);
