#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void token(char str[], char delimitador[], int data[]);
void ranking(int scores[], int tam, int dato);
void sort_array(int array[], int tam);
void copy_and_add(int taget[], int src[], int tam, int dato);
void printArray(int arr[], int tam);


int main(int argc, char *argv[]){
	if(argc > 1){
		if (strcmp("start", argv[1])==0){
			int n,m;
			
			scanf("%d\n", &n);
			
			int scores[n];
			int scoresAux[n+1];
			char *str = malloc(4*n*sizeof(char));
			
			fgets(str, 4*n, stdin); 
			
			token(str, " ", scores);
			free(str);
			scanf("%d\n", &m);
			int alice[m];
			str=malloc(4*m*sizeof(char));
			fgets(str, 4*m, stdin);
			token(str, " ", alice);
			free(str);
			
			ranking(scores, n, 0);
			
			for(int i=0;i<m; i++){
				copy_and_add(scoresAux, scores, n+1, alice[i]);
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

void token(char str[], char delimitador[], int data[]){
	char *token = strtok(str, delimitador);
			if(token != NULL){
				int i =0;
			while(token != NULL){
	
				data[i] = atoi(token);

				i++;
				token = strtok(NULL, delimitador);
			}
		}
}	


void ranking(int score[], int tam, int dato){
	int ranking[tam];
	int i, ran=1;
	char state = 0;
	ranking[0]=ran;
	for(i=1; i<tam; i++){
		if(score[i-1] == score[i]){
				ranking[i]=ran;
		}else{
			ran++;
			ranking[i]= ran;
		}
		if(dato==score[i-1] && state == 0){
			state=1;
			printf("%d\n", ranking[i-1]);
		}
	}
}

void sort_array(int array[], int tam){
	int temporal;
	for (int i = 0;i < tam; i++){
		for (int j = 0; j< tam-1; j++){
			if (array[j] < array[j+1]){
			temporal = array[j]; 
			array[j] = array[j+1]; 
			array[j+1] = temporal;
			}
		}
	}
}
void copy_and_add(int target[], int src[], int tam, int dato){
	int i;
	for(i=0; i<tam-1; i++){
		target[i]= src[i];
	}
	target[i]=dato;
		
}

void printArray(int arr[], int tam){
	for(int i=0; i<tam; i++){
		printf("score: %d\n", arr[i]);
	}
}
