	#include <stdio.h>
	#include <string.h>
	#include <ctype.h>

	struct caminhao
	{
		int c_itens[1000];
		int c_fim, c_peso, c_max;	
	};

	struct gal
	{
		int g_itens[1000];
		int g_ini, g_fim, g_peso;
	};

	void iniciar(struct caminhao *caminhoes, int nc, struct gal *galpao){
		int i, j;

		for(i = 0; i < nc; i++){
			memset( (caminhoes + i)->c_itens, 0, sizeof((caminhoes + i)->c_itens) );
			(caminhoes + i)->c_fim = 0;
			(caminhoes + i)->c_peso = 0;
			(caminhoes + i)->c_max = 0;
		}

		memset( galpao->g_itens, 0, sizeof(galpao->g_itens));
		galpao->g_ini = 0;
		galpao->g_fim = 0;
		galpao->g_peso = 0;
	}


	void main(){

		int nc, param, i;
		char comando[3], lixo;

		while( scanf("%d\n", &nc) != EOF ){
		
			struct caminhao caminhoes[nc];
			struct gal galpao;

			iniciar(caminhoes, nc, &galpao);

			for(i = 0; i < nc; i++){
				scanf("%d\n", &caminhoes[i].c_max);
			}

			while( scanf("%c", &comando[0]) != EOF ){
		
				if( comando[0] < 65 || comando[0] > 90 ) break;

				scanf("%c%c", &comando[1], &comando[2]);
				scanf("%d\n", &param);

				if(comando[0] == 'A'){
					//add(&galpao, param);
				}
				else if(comando[0] == 'L'){
					//loa(&galpao, param, caminhoes);
				}
				else if(comando[0] == 'D'){
					//del(caminhoes, param);
				}
				else if(comando[0] == 'I'){
					//inf(caminhoes, param);
				}
			}

		}
	}
