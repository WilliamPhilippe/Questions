#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct nodeTree nodeTree;

struct nodeTree
{
	int value;
	nodeTree *left, *right;
};

nodeTree *CreateRoot(int x){
	nodeTree *newNode = (nodeTree *) malloc(sizeof(nodeTree));
	newNode->value = x;
	newNode->right = NULL;
	newNode->left = NULL;

	return newNode;
}

void Insert(nodeTree **node, int n){
	if(*node == NULL){
		*node = CreateRoot(n);
	}
	else{
		if(n >= (*node)->value ) Insert( &((*node)->right), n);
		else Insert(  &((*node)->left), n);
	}
}

void PrintTree(nodeTree *node){
	if (node == NULL)
	{
		return;
	}
	else{
		printf(" %d\n", node->value);
		PrintTree(node->left);
		PrintTree(node->right);
	}
}

void searchTree(nodeTree *node, int num, int *comp){

	if(node->value == num){
		(*comp) ++;
		return;
	}

	(*comp) ++;

	if( num > node->value ){
		searchTree(node->right, num, comp);
	}
	else if(num < node->value){
		searchTree(node->left, num, comp);
	}

}

void main(){

	int n, i, node;
	nodeTree *root = NULL;

	scanf("%d", &n);
	int array[n];

	for(i = 0; i < n; i++){
		scanf("%d", &node);
		array[i] = node;
		Insert(&root, node);
	}

	int num;
	while( scanf("%d", &num) != EOF){
		int compTree = 0, compArray = 0;

		for(i = 0; i < n; i++){
			if(array[i] == num){
				compArray++;
				break;
			}
			else compArray++;
		}

		searchTree(root, num, &compTree);
		printf("%d %d\n", compArray, compTree);
	}
}