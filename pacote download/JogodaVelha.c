#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <stdbool.h>

int local, contador = 1, l, c, retorno = -1;
char velha[3][3];

void imprimirExemplo(void), teste(void), verificando(int i, int j);

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	
	char jogador1[20], jogador2[20], resp;
	bool ganhou;
	int vitoria1 = 0, vitoria2 = 0, empate = 0;
	
	printf("\n");
	printf("********************************************************\n");
	printf("                     JOGO DA VELHA                      \n");
	printf("********************************************************\n");
	printf(" Inicie o jogo informando os seus respectivos nomes.\n Apenas digite n�meros de 1 a 9. \n");
	printf(" Não é permitido digitar letras.\n Se divirta!!!\n");
	printf("\n Jogador 1: O ");
	printf("\n Jogador 2: X\n");
	
	imprimirExemplo();
	
	printf("\n--------------------------------------------------------");
	printf("\nJogador 1, informe o seu nome: ");
	gets(jogador1);
	fflush(stdin);
	
	printf("Jogador 2, informe o seu nome: ");
	gets(jogador2);
	fflush(stdin);
	printf("\n--------------------------------------------------------");
	
	do{
		for(l = 0; l < 3;l++){  
			for(c = 0; c < 3; c++){
					velha[l][c] = ' ';
			}
		}
		
		while(contador <= 9 && ganhou == false){
			ganhou = false; 
			contador++; 
			
			if(contador % 2 == 0){
				printf("\n\t\tJOGADOR 1 (%s) --> O\n", jogador1); 
			}else{
				printf("\n\t\tJOGADOR 2 (%s) --> X\n", jogador2);
			}
			
			printf("\nDigite o local que deseja inserir: ");
			retorno = scanf("%d", &local);
			fflush(stdin);
			
			if(retorno == 0){
				contador--;
				printf("ERRO! Digite apenas os números corretos [1 até 9]!!");
			}else{
				teste();
			}
		
			printf("\n");
			for(l = 0; l < 3; l++){
				printf("\t             ");
				for(c = 0; c < 3; c++){
					printf(" %c ", velha[l][c]);
					if(c < 2){
						printf("|");
					}
				}
				if(l < 2){
					printf("\n\t             ---+---+---");
					printf("\n");		
				}
			}
			printf("\n\n");
		
			if(velha[0][0] == velha[0][1] && velha [0][0] == velha[0][2] && velha[0][0] != ' ' && velha[0][1] != ' ' && velha[0][2] != ' '
			|| velha[0][0] == velha[1][0] && velha [0][0] == velha[2][0] && velha[0][0] != ' ' && velha[1][0] != ' ' && velha[2][0] != ' '
			|| velha[0][0] == velha[1][1] && velha [0][0] == velha[2][2] && velha[0][0] != ' ' && velha[1][1] != ' ' && velha[2][2] != ' '
			|| velha[1][0] == velha[1][1] && velha [1][0] == velha[1][2] && velha[1][0] != ' ' && velha[1][1] != ' ' && velha[1][2] != ' '
			|| velha[2][0] == velha[2][1] && velha [2][0] == velha[2][2] && velha[2][0] != ' ' && velha[2][1] != ' ' && velha[2][2] != ' '
			|| velha[2][0] == velha[1][1] && velha [2][0] == velha[0][2] && velha[2][0] != ' ' && velha[1][1] != ' ' && velha[0][2] != ' '
			|| velha[0][1] == velha[1][1] && velha [0][1] == velha[2][1] && velha[0][1] != ' ' && velha[1][1] != ' ' && velha[2][1] != ' '
			|| velha[0][2] == velha[1][2] && velha [0][2] == velha[2][2] && velha[0][2] != ' ' && velha[1][2] != ' ' && velha[2][2] != ' '){
				ganhou = true;
			}
			if(ganhou == true && contador % 2 == 0){ 
				printf("Parabéns, %s!! ", jogador1);
				printf("Venceu!!!\n");
				printf("\n%s você perdeu :( \nTente novamente ;)\n", jogador2);
				vitoria1++;
			}else if(ganhou == true && contador % 2 != 0){
				printf("Venceu!!!");
				printf("Parabéns, %s!!", jogador2);
				printf("\n%s você perdeu :( \nTente novamente ;)\n", jogador1);
				vitoria2++;
			}else if(contador > 9){
				printf("Empate!! \nTente novamente ;)");
				empate++;
			}
		printf("\n--------------------------------------------------------\n");
		}
		
		
		printf("Vitórias do jogador 1 (%s): %d\n\n", jogador1, vitoria1);
		printf("Vitórias do jogador 2 (%s): %d\n\n", jogador2, vitoria2);
		printf("Empates: %d\n", empate);
		printf("--------------------------------------------------------\n");
		
		printf("Deseja continuar jogando[s/n]? ");
		scanf("%c", &resp);
	
		if(resp != 'n' && resp != 'N'){ 
			system("cls");
			contador = 1;
			ganhou = false;
			printf("\n--------------------------------------------------------\n");
			imprimirExemplo();
			printf("\n--------------------------------------------------------\n");
			for(l = 0; l < 3;l++){  
				for(c = 0; c < 3; c++){
						velha[l][c] = ' ';
				}
			}
		}else{	
			printf("Encerrando...");	
			printf("\n--------------------------------------------------------\n");
		}

	}while(resp != 'n' && resp != 'N');

}

void imprimirExemplo(void){ //Para mostar exemplo
	printf("                            \n");
	printf("\t\t      1 | 2 | 3         \n");
	printf("\t\t     ---+---+--- 	    \n");
	printf("\t\t      4 | 5 | 6  	    \n");
	printf("\t\t     ---+---+--- 	    \n");
	printf("\t\t      7 | 8 | 9  	    \n");
}

void teste(void){
	void verificando(int i, int j);
	switch(local){
		case 1:
			verificando(0,0);
			break;	
		
		case 2:
			verificando(0,1);
			break;	
		
		case 3:
			verificando(0,2);
			break;	
		
		case 4:
			verificando(1,0);
			break;	
		
		case 5:
			verificando(1,1);
			break;	
		
		case 6:
			verificando(1,2);
			break;
		
		case 7:
			verificando(2,0);
			break;	
			
		case 8:
			verificando(2,1);
			break;	
			
		case 9:
			verificando(2,2);
			break;
			
		default:
			contador--;  
			printf("ERRO! Digite apenas os números corretos [1 até 9]!!");
	}
}

void verificando(int i, int j){ 
	if(velha[i][j] == 'O' || velha[i][j] == 'X'){
		printf("ERRO! Local já ocupado! Tente um novo número!\n");
		contador--;
	}else if(contador % 2 == 0){
		velha[i][j] = 'O';
	}else{
		velha[i][j] = 'X';
	}
}

