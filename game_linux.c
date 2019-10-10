#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int main(){

    srand(time(NULL));

    char tabuleiro[10][5], pecas[]="ABCDEFGHIJKLMNOPQRSTUVWXYABCDEFGHIJKLMNOPQRSTUVWXY"; //50
    int i, j;

    // Preenchendo matriz(tabuleiro) com valor de comparação
    for(i=0; i<10; i++){
        for(j=0; j<5; j++){
            tabuleiro[i][j]= ' ';
        }
    }

    // Atribuindo peças aleatóriamente no tabuleiro, gera-se valores aleatórios para "i" e  "j", onde indicará a posição da matriz tabuleiro[][] que receberá a peça do vetor pecas[]
    int posicaoPeca=0, controleWhile=0;
    while(controleWhile<50){
        i= rand()%10; // Número aleatório entre 0 e 9
        j= rand()%5;
        if(tabuleiro[i][j] == ' '){
            tabuleiro[i][j]= pecas[posicaoPeca];
            posicaoPeca++;
            controleWhile++;
        }
    }

    // Segundo tabuleiro, o qual o usuário irá visualizar
    char acertos[10][5];
    int contadorIndice_x=0, contadorIndice_y=0;
    // preencher matriz acertos[][] com '-' para facilitar a visualização
    for(i=0; i<10; i++){
        for(j=0; j<5; j++){
            acertos[i][j]= '-';
        }
    }

    // LAÇO DE REPETÇÃO PRINCIPAL DO JOGO
    controleWhile=0;
    int peca1X, peca1Y, peca2X, peca2Y, indiceVertical;
    while(controleWhile<25){
        peca1X=0;
        peca1Y=0;
        peca2X=0;
        peca2Y=0;
        indiceVertical=0;

        // Cola para visualizar as peças
        /*for(i=0; i<10; i++){
            for(j=0; j<5; j++){
                printf(" %c\t", tabuleiro[i][j]);
            }
            printf("\n\n");
        }*/

        // Texto "JOGO DA  MEMÓRIA" em ASCIIart
        printf("\n     ___  _______  _______  _______    ______   _______ \n    |   ||       ||       ||       |  |      | |   _   |\n    |   ||   _   ||    ___||   _   |  |  _    ||  |_|  |\n    |   ||  | |  ||   | __ |  | |  |  | | |   ||       |\n ___|   ||  |_|  ||   ||  ||  |_|  |  | |_|   ||       |\n|       ||       ||   |_| ||       |  |       ||   _   |\n|_______||_______||_______||_______|  |______| |__| |__|\n __   __  _______  __   __  _______  ______    ___   _______\n|  |_|  ||       ||  |_|  ||       ||    _ |  |   | |   _   |\n|       ||    ___||       ||   _   ||   | ||  |   | |  |_|  |\n|       ||   |___ |       ||  | |  ||   |_||_ |   | |       |\n|       ||    ___||       ||  |_|  ||    __  ||   | |       |\n| ||_|| ||   |___ | ||_|| ||       ||   |  | ||   | |   _   |\n|_|   |_||_______||_|   |_||_______||___|  |_||___| |__| |__|\n\n\n\n");

        // Print visão jogador
        printf("\t 0\t 1\t 2\t 3\t 4\n\n\n\n"); // indice horizontal
        for(i=0; i<10; i++){
            printf("%d\t", indiceVertical);
            indiceVertical++;
            for(j=0; j<5; j++){
                printf(" %c\t", acertos[i][j]);
            }
            printf("\n\n");
        }
        // número de acertos
        printf("Acertos: %d\n", controleWhile);
        // Input jogador
        printf("\nInforme a coluna para a peça 1: ");
        scanf("%d", &peca1Y);
        printf("Informe a linha para a peça 1: ");
        scanf("%d", &peca1X);
        printf("\nInforme a coluna para a peça 2: ");
        scanf("%d", &peca2Y);
        printf("Informe a linha para a peça 2: ");
        scanf("%d", &peca2X);

        system("clear");

        // Mostrar as peças conforme o input do jogador
        // Texto "JOGO DA  MEMÓRIA" em ASCIIart
        printf("\n     ___  _______  _______  _______    ______   _______ \n    |   ||       ||       ||       |  |      | |   _   |\n    |   ||   _   ||    ___||   _   |  |  _    ||  |_|  |\n    |   ||  | |  ||   | __ |  | |  |  | | |   ||       |\n ___|   ||  |_|  ||   ||  ||  |_|  |  | |_|   ||       |\n|       ||       ||   |_| ||       |  |       ||   _   |\n|_______||_______||_______||_______|  |______| |__| |__|\n __   __  _______  __   __  _______  ______    ___   _______\n|  |_|  ||       ||  |_|  ||       ||    _ |  |   | |   _   |\n|       ||    ___||       ||   _   ||   | ||  |   | |  |_|  |\n|       ||   |___ |       ||  | |  ||   |_||_ |   | |       |\n|       ||    ___||       ||  |_|  ||    __  ||   | |       |\n| ||_|| ||   |___ | ||_|| ||       ||   |  | ||   | |   _   |\n|_|   |_||_______||_|   |_||_______||___|  |_||___| |__| |__|\n\n\n\n");

        printf("\t 0\t 1\t 2\t 3\t 4\n\n\n\n"); // indice horizontal
        indiceVertical=0;
        for(i=0; i<10; i++){
            printf("%d\t", indiceVertical);
            indiceVertical++;
            for(j=0; j<5; j++){
                if(i == peca1X && j == peca1Y){
                    printf(" %c\t", tabuleiro[i][j]);
                } else if(i == peca2X && j == peca2Y){
                    printf(" %c\t", tabuleiro[i][j]);
                } else{
                    printf(" %c\t", acertos[i][j]);
                }
            }
            printf("\n\n");
        }

        // Comaparação se as peças são iguais, e restrições
        if(tabuleiro[peca1X][peca1Y] == tabuleiro[peca2X][peca2Y] && (peca1X!=peca2X || peca1Y!=peca2Y) && (acertos[peca1X][peca1Y] == '-' && acertos[peca2X][peca2Y] == '-')){
            acertos[peca1X][peca1Y]= tabuleiro[peca1X][peca1Y];
            acertos[peca2X][peca2Y]= tabuleiro[peca2X][peca2Y];
            controleWhile++;
        } else{
            (sleep(5));
        }
        system("clear");
    }

    system("clear");
    // texto "PARABÊNS" executado após o término do jogo
    printf("\n _______  _______  ______    _______  _______  _______  __    _  _______\n|       ||   _   ||    _ |  |   _   ||  _    ||       ||  |  | ||       |\n|    _  ||  |_|  ||   | ||  |  |_|  || |_|   ||    ___||   |_| ||  _____|\n|   |_| ||       ||   |_||_ |       ||       ||   |___ |       || |_____ \n|    ___||       ||    __  ||       ||  _   | |    ___||  _    ||_____  |\n|   |    |   _   ||   |  | ||   _   || |_|   ||   |___ | | |   | _____| |\n|___|    |__| |__||___|  |_||__| |__||_______||_______||_|  |__||_______|\n\n");

    return 0;
}
