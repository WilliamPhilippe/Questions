#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct dados
{
	int n;
	int there;
	struct dados *next;
};

typedef struct dados stdd;

void ordenar(int *array, int n_r){

	int i, j;

	for(i = 0; i < n_r; i++){
		for(j = i; j < n_r; j++){
			if(array[i] > array[j]){
				int aux;
				aux = array[j];
				array[j] = array[i];
				array[i] = aux;
			}
		}
	}

}

void main(){

	stdd v_one[20], v_two[20];
	int array[20] = {0};
	int n_r = 0;

	stdd *gancho1; stdd *gancho2;

	gancho1 = &v_one[0]; gancho2 = &v_two[0];

	int i;


	for(i = 0; i < 20; i++){
		if(i != 19){
			v_one[i].next = &v_one[i + 1];
			v_two[i].next = &v_two[i + 1];
		}
		else{
			v_one[i].next = (stdd *)0;
			v_two[i].next = (stdd *)0;
		}
	}

	while(gancho1 != (stdd *)0){
		gancho1->there = 0;
		scanf("%d", &gancho1->n);
		gancho1 = gancho1->next;
	}

	while(gancho2 != (stdd *)0){
		gancho2->there = 0;
		scanf("%d", &gancho2->n);
		gancho2 = gancho2->next;
	}

	gancho1 = &v_one[0]; gancho2 = &v_two[0];

	for(i = 0; i<20; i++){
		array[i] = 999999;
	}


	while(gancho1 != (stdd *)0){

		while( gancho2 != (stdd *)0 && gancho1->there == 0){

			if( gancho1->n == gancho2->n ){

				array[n_r] = gancho1->n;
				n_r++;
				

				gancho1->there = 1;
				gancho2 = &v_two[0];
				break;

			}

			gancho2 = gancho2->next;

		}
		
		gancho2 = &v_two[0];
		gancho1 = gancho1->next;
	}

	ordenar(array, n_r);

	if(n_r == 0){
		printf("VAZIO\n");
		return;
	}

	for(i = 0; i < n_r; i++){
		printf("%d\n", array[i] );
	}

}