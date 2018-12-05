#include <stdio.h>
#include <string.h>

int arvore[1000][3];
int pais[10000] = {0};

void verificar(int no, int pai){
    if(no == -1){
       if(arvore[pai][0] == -1 && arvore[pai][1] == -1) pais[  arvore[pai][2]   ] = 1;
        return;
    }
    else{
        verificar(arvore[no][0], no);
        verificar(arvore[no][1], no);
    }
}

int main(){
    int n, i;
    scanf("%d", &n);
    
    for(i = 0; i < n; i++){
        scanf("%d %d\n", &arvore[i][0], &arvore[i][1]);
        arvore[(arvore[i][0])][2] = i;
        arvore[(arvore[i][1])][2] = i;
    }
    
    verificar(0, 0);
    
    for(i = 0; i < 1000; i++){
        if(pais[i]) printf("%d\n", i);
    }
    
	return 0;
}
