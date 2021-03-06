#include <stdio.h>
#include <stdlib.h>

typedef struct Node_a{
	int number;
	Node_a *right, *left;
} Node_t;

Node_t* inicializa(){
	return NULL;
}

Node_t* insert(Node_t *root, int key){
	Node_t *r = root;

	if(r == NULL){
		Node_t* newer = (Node_t*) malloc(sizeof(Node_t));
		newer->number = key;
		newer->right = NULL;
		newer->left = NULL;
		return newer;
	}
	else if(r->number == key){
		printf("The key is already inserted!\n");
		return r;
	}
	else if(r->number > key) r->left = insert(r->left, key);
	else if(r->number < key) r->right = insert(r->right, key);
	return root;
}

void printPre(Node_t *root){
	Node_t *r = root;
	if(r != NULL){
		printf("%d ", r->number);
		if(r->left != NULL) printPre(r->left);
		if(r->right != NULL) printPre(r->right);
	}else{printf("Empty tree!\n");}
}

void printIn(Node_t *root){
	Node_t *r = root;
	if(r != NULL){
		if(r->left != NULL) printIn(r->left);
		printf("%d ", r->number);
		if(r->right != NULL) printIn(r->right);
	}else{printf("Empty tree!\n");}
}

void printPos(Node_t *root){
	Node_t *r = root;
	if(r != NULL){
		if(r->left != NULL) printPos(r->left);
		if(r->right != NULL) printPos(r->right);
		printf("%d ", r->number);
	}else{printf("Empty tree!\n");}
}

void search(Node_t *root, Node_t *run, int key){
	Node_t *r = run;
	Node_t *aux = root;
	if(r == NULL) printf("Key not found!\n");
	else if(r->number == key){
		printf("The key was found!\n");
		while(aux != r){
			printf("%d ", aux->number);
			if(r->number > aux->number) aux = aux->right;
			else if(r->number < aux->number) aux = aux->left;
		}
		printf("( %d )\n", aux->number);
	}
	else if(r->number < key) search(root, r->right, key);
	else if(r->number > key) search(root, r->left, key);
}

void destroyTree(Node_t *root){
	if(root != NULL){
		if(root->left != NULL) destroyTree(root->left);
		if(root->right != NULL) destroyTree(root->right);
		free(root);
	}
}

Node_t* remove(Node_t *root, int key){
	Node_t *r = root;
	Node_t *aux, *dad;
	int value;

	if(r == NULL){
		printf("Key not found!\n");
		return root;
	}
	else if(r->number == key){
		if(r->left != NULL){
			aux = r->left;
			if(aux->right != NULL){
				while(aux->right != NULL) aux = aux->right;
				dad = r->left;
				while(dad->right != aux) dad = dad->right;
				value = aux->number;
				free(aux);
				dad->right = NULL;
				r->number = value;
				return r;
			}else{
				r->number = aux->number;
				r->left = aux->left;
				free(aux);
				return r;
			}
		} 
		else if(r->right != NULL){
			aux = r->right;
			if(aux->left != NULL){
				while(aux->left != NULL) aux = aux->left;
				dad = r->right;
				while(dad->left != aux) dad = dad->left;
				value = aux->number;
				free(aux);
				dad->left = NULL;
				r->number = value;
				return r;
			}else{
				r->number = aux->number;
				r->right = aux->right;
				free(aux);
				return r;
			}
		}else{
			free(r);
			return NULL;
		}
	}
	else if(r->number > key) r->left = remove(r->left, key);
	else if(r->number < key) r->right = remove(r->right, key);
	return root;
}

int menu(){
	int op;
	printf("|-----------------|\n");
	printf("|-0 Exit\n");
	printf("|-1 Insert\n");
	printf("|-2 Search\n");
	printf("|-3 Print PreOrder\n");
	printf("|-4 Print InOrder\n");
	printf("|-5 Print PosOrder\n");
	printf("|-6 Remove\n");
	printf("|-----------------|\n");
	scanf("%d", &op);
	return op;
}
