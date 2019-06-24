#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int matrix[101][101];
int visitados[101] = {0};
int n, p, x, y;

typedef struct SetQueue SetQueue;
typedef struct node node;

struct node
{
	int value;
	node *next, *previous;
};

struct SetQueue
{
	int size;
	node *head;
	node *back;
};

SetQueue *CreateQueue(){
	SetQueue *newpointer = (SetQueue *) malloc(sizeof(SetQueue));
	newpointer->head = NULL;
	newpointer->back = NULL;
	newpointer->size = 0;
	return newpointer;
}

int pushItem( SetQueue *fila, int x, int command ){
	node *newpointer = (node *) malloc(sizeof(node));
	if(newpointer == NULL) return 0;
	newpointer->value = x;

	if(fila->head == NULL){
		newpointer->next == NULL;
		newpointer->previous = NULL;
		fila->head = newpointer;
		fila->back = newpointer;
	}
	else if(command == 1){
		newpointer->previous == NULL;
		newpointer->next = fila->head;
		fila->head->previous = newpointer;
		fila->head = newpointer;
	}
	else if(command == 2){
		newpointer->next = NULL;
		newpointer->previous = fila->back;
		fila->back->next = newpointer;
		fila->back = newpointer;
	}

	fila->size ++;

	return 1;
}

void zerarMatrix(){
	int i, j;

	for(i = 0; i < 101; i++){
		for(j = 0; j < 101; j++){
			matrix[i][j] = 0;
		}
	}

}

void dfs(int node, SetQueue *queue){
	if(visitados[node] == 1 || visitados[node] == 0) return;
	visitados[node] = 1;

	pushItem(queue, node, 2);

	int i;
	for(i = 1; i <= p; i++){
		if(matrix[node][i]){
			dfs(i, queue);
		}
	}
}

int printQueue(SetQueue *fila){
	if(fila->head == NULL) return 0;
	
	node *current = fila->head;
	printf("%d", current->value);
	current = current->next;
	
	while(current != NULL){
		printf(" %d", current->value);
		current = current->next;
	}

	return 1;
}

void main(){

	scanf("%d %d", &n, &p);

	int i, j;

	for(i = 0; i < n; i++){
		scanf("%d %d", &x, &y);

		matrix[x][y] = 1;
		matrix[y][x] = 1;
		visitados[x] = visitados[y] = -1;
	}

	int galaxy = 0;
	SetQueue *queue = NULL;

	for(i = 1; i <= p; i++){
		if (visitados[i] == -1)
		{	
			SetQueue *newQueue = CreateQueue();
			dfs(i, newQueue);
			galaxy++;

			printQueue(newQueue);
			printf("\n");
			// if(queue == NULL) queue = newQueue;
			// else if(newQueue->size > queue->size) queue = newQueue;
		} 
	}

	printf("%d\n", galaxy);
	// printQueue(queue);


}