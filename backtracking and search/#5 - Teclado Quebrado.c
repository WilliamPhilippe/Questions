#include <stdio.h>
#include <string.h>

void main(){

	char lendo[10000];
	char final[10000];
	char enquanto[10000];
	int i, j, status;

	while( scanf("%s", lendo) != EOF ){

		final[0] = '\0';
		enquanto[0] = '\0';

		for(i = 0, j = 0, status = 1; i <= strlen(lendo); i++){
			if(lendo[i] == '['){
				if(status){
					enquanto[j] = '\0';
					strcat(enquanto, final);
					strcpy(final, enquanto);
					j = 0;
					enquanto[j] = '\0';
				}
				else{
					enquanto[j] = '\0';
					strcat(final, enquanto);
					j = 0;
					enquanto[j] = '\0';
				}
				status = 1;
			}
			else if(lendo[i] == ']'){
				if(status){
					enquanto[j] = '\0';
					strcat(enquanto, final);
					strcpy(final, enquanto);
					j = 0;
					enquanto[j] = '\0';
				}
				else{
					enquanto[j] = '\0';
					strcat(final, enquanto);
					j = 0;
					enquanto[j] = '\0';
				}
				status = 0;
			}
			else if(i == strlen(lendo) ){
				if(status){
					enquanto[j] = '\0';
					strcat(enquanto, final);
					strcpy(final, enquanto);
					j = 0;
					enquanto[j] = '\0';
				}
				else{
					enquanto[j] = '\0';
					strcat(final, enquanto);
					j = 0;
					enquanto[j] = '\0';
				}
			}
			else{
				enquanto[j] = lendo[i];
				j++;
			}
		}

		printf("%s\n", final);

	}

}