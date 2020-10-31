#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _DIGITS 10 
void split_to_int(char src[], char delimiter[], int target[]);
void ranking(int src[], int tam, int src2);
void sort_array(int array[], int tam);
void copy_and_add(int src[], int taget[], int tam, int src2);


int main(int argc, char *argv[]){
	if(argc > 1){
		if (strcmp("start", argv[1])==0){

			int n,m;
			
			scanf("%d\n", &n);
			
			int scores[n];
			int scoresAux[n+1];
			char *str = malloc(_DIGITS*n*sizeof(char));

			fgets(str, _DIGITS*n, stdin); 
			
			split_to_int(str, " ", scores);
			free(str);

			scanf("%d\n", &m);
			int alice[m];
			str=malloc(_DIGITS*m*sizeof(char));
			fgets(str, _DIGITS*m, stdin);
			split_to_int(str, " ", alice);
			free(str);
			
			for(int i=0;i<m; i++){
				copy_and_add(scores, scoresAux, n+1, alice[i]);
				sort_array(scoresAux, n+1);
				ranking(scoresAux, n+2, alice[i]);
			}
			
		}else{
			printf("Algo salio mal\n");
			return 1;
		}
	}

return 0;
}

void split_to_int(char src[], char delimiter[], int target[]){
	char *token = strtok(src, delimiter);
			if(token != NULL){
				int i =0;
			while(token != NULL){
				target[i] = atoi(token);
				i++;
				token = strtok(NULL, delimiter);
			}
		}
}	

void ranking(int src[], int tam, int src2){
	int ranking[tam], rank=1;
	char state = 0;
	ranking[0]=rank;
	for(int i=1; i<tam; i++){
		if(src[i-1] == src[i]){
				ranking[i]=rank;
		}else{
			rank++;
			ranking[i]= rank;
		}
		if(src2==src[i-1] && state == 0){
			state=1;
			printf("%d\n", ranking[i-1]);
		}
	}
}

void sort_array(int src[], int tam){
	int temp;
	for (int i = 0;i < tam; i++){
		for (int j = 0; j< tam-1; j++){
			if (src[j] < src[j+1]){
			temp = src[j]; 
			src[j] = src[j+1]; 
			src[j+1] = temp;
			}
		}
	}
}
void copy_and_add(int src[],int target[], int tam, int src2){
	int i;
	for(i=0; i<tam-1; i++){
		target[i]= src[i];
	}
	target[i]=src2;
		
}
