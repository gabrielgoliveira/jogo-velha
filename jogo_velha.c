#include <stdio.h>
#include <stdlib.h> /*responsavel pelo system*/

void iniciarTabuleiro(char [][3]);
void imprimirTabuleiro(char [][3]);
int inserirTabuleiro(char [][3], int, int, char);
char verificarJogada(int);
void ganhador(char tabuleiro[][3], int *ganhou);

int main(){
    int ganhou=0, l, c, cont_vez=0, verificacao=0;
    char tabuleiro[3][3], jogador1[20], jogador2[20];
    iniciarTabuleiro(tabuleiro);
    printf("---------------- JOGO DA VELHA ----------------\n");
    printf("By: Gabriel Oliveira\n\n");
    printf("Digite o seu nome Player 1: ");
    scanf("%19[^\n]s", jogador1);
    printf("Digite o seu nome Player 2: ");
    scanf(" %19[^\n]s", jogador2);

    while(ganhou!=1){
        system("cls");
        /*Caso a jogada não for realizada, imprimir no inicio*/
        if(verificacao == 1){
            printf("-------------- JOGADA NAO PERMITIDA BUNDAO --------------------- \n");
            printf("Jogue Novamente \n\n");
        }
        /*Mostrar Nome do Jogador*/
        if(verificarJogada(cont_vez) == 'X'){
            printf("Jogador %s\n", jogador1);
        }else {
            printf("Jogador %s\n\n", jogador2);
        }

        printf("------- Vez de %c --------- \n", verificarJogada(cont_vez));
        imprimirTabuleiro(tabuleiro);
        printf("Digite as coordenadas no formato: X Y: ");
        scanf("%d %d", &l, &c);
        
        verificacao = inserirTabuleiro(tabuleiro, l, c, verificarJogada(cont_vez));
        /*Passa a vez para o proximo jogador, caso a jogada for realizada*/
        if(verificacao == 0){
            cont_vez++;
        }     
       
        ganhador(tabuleiro, &ganhou);
        
    }
    return 0;
}

void iniciarTabuleiro(char tabuleiro[][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            tabuleiro[i][j] = ' ';
        }
    }
}


void imprimirTabuleiro(char tabuleiro[][3]){
    printf("+|1 2 3\n");
    for(int i=0;i<3;i++){
        printf("%d|", i+1);
        for(int j=0;j<3;j++){
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int inserirTabuleiro(char tabuleiro[][3], int x, int y, char jogada){
    if(tabuleiro[x-1][y-1]== ' ' || x>10){
        tabuleiro[x-1][y-1] = jogada;
        return 0;
    } else {
        return 1;
    }
}


char verificarJogada(int num){
    if(num%2 == 0){
        return 'X';
    } else {
        return 'O';
    }
}

void ganhador(char tabuleiro[][3], int *ganhou){
    int i, j, p1=-1, p2=-1;
    /*Verificar Linhas*/
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(tabuleiro[i][j] == 'X'){
                p1++;
            }
            if(tabuleiro[i][j] == 'O'){
                p2++;
            }
            if(p1 == 2){
                printf("\n------ X Ganhou ------- \n");
                *ganhou = 1;
                break;
            }
            if(p2 == 2){
                printf("\n------ O Ganhou ------- \n");
                *ganhou = 1;
                break;
            }
        }
        p1=-1;
        p2=-1;
    }
    
    /*Verificar Colunas*/
    for(j=0;j<3;j++){
        for(i=0;i<3;i++){
            if(tabuleiro[i][j] == 'X'){
                p1++;
            }
            if(tabuleiro[i][j] == 'O'){
                p2++;
            }
            if(p1 == 2){
                printf("\n------ X Ganhou ------- \n");
                *ganhou = 1;
                break;
            }
            if(p2 == 2){
                printf("\n------ O Ganhou ------- \n");
                *ganhou = 1;
                break;
            }
        }
        p1=-1;
        p2=-1;
    }
    
    /*Verificar Diagonal Principal*/
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(i == j){
                if(tabuleiro[i][j] == 'X'){
                    p1++;
                }
                if(tabuleiro[i][j] == 'O'){
                    p2++;
                }
                if(p1 == 2){
                    printf("\n------ X Ganhou ------- \n");
                    *ganhou = 1;
                    break;
                }
                if(p2 == 2){
                    printf("\n------ O Ganhou ------- \n");
                    *ganhou = 1;
                    break;
                }
        
            }
        }
    }
    p1=-1;
    p2=-1;
    
    /*Verificar Diagonal Segundaria*/
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(i + j == 2){
                if(tabuleiro[i][j] == 'X'){
                    p1++;
                }
                if(tabuleiro[i][j] == 'O'){
                    p2++;
                }
                if(p1 == 2){
                    printf("\n------ X Ganhou ------- \n");
                    *ganhou = 1;
                    break;
                }
                if(p2 == 2){
                    printf("\n------ O Ganhou ------- \n");
                    *ganhou = 1;
                    break;
                }
        
            }
        }        
    }
    p1=-1;
    p2=-1;
}