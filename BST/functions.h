#include "functions.cpp"

Node_t* inicializa();
Node_t* insert(Node_t *root, int key);
void printPre(Node_t *root);
void printIn(Node_t *root);
void printPos(Node_t *root);
void search(Node_t *root, Node_t *run, int key);
void destroyTree(Node_t *root);
Node_t* remove(Node_t *root, int key);
int menu();
