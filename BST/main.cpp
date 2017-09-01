#include <stdio.h>
#include "functions.h"

int main(void){
	int op = 1, key;
	Node_t *tree = inicializa();

	while(op != 0){
		op = menu();
		switch(op){
			case 0: destroyTree(tree);
					break;
			case 1:	printf("Digite a chave: ");
					scanf("%d", &key);
					tree = insert(tree, key);
					break;
			case 2: printf("Chave para busca: ");
					scanf("%d", &key);
					search(tree, key);
					break;
			case 3: printPre(tree);
					break;
			case 4: printf("Chave para remover: ");
					scanf("%d", &key);
					tree = remove(tree, key);
					break;
			default : printf("Opcao invalida!\n");
		}
	}
	return 0;
}
