#include <stdio.h>

#define TAMANHO 10

int main() {
    char linha[TAMANHO] = {'A','B','C','D','E','F','G','H','I','J'}; //Linha de referência
    int coluna[TAMANHO] = {1,2,3,4,5,6,7,8,9,10}; //Coluna de referência
    int tabuleiro[TAMANHO][TAMANHO];  // Declaração de uma matriz 10x10 do tabuleiro
    int a,b,c; // Linhas e colunas onde se encontram os navios 
    // Definindo as armas (cone, cruz e octaedro como 3x5)
    int cone_x,cone_y; // Variavéis de localização da origem das armas
    int cruz_x,cruz_y; // Variavéis de localização da origem das armas
    int octa_x,octa_y; // Variavéis de localização da origem das armas
 
     
    //1. Inicializando o tabuleiro com água (água=0)
    //2. Apresentando o tabuleiro vazio ao usuário
    printf("TABULEIRO DE BATALHA NAVAL (VAZIO)\n");
    printf("   ");
    for(int i=0; i < TAMANHO; i++){
        printf("%c ",linha[i]); 
    }
    printf("\n"); 
    for(int i=0; i < TAMANHO; i++){
    printf("%-2d ",coluna[i]);  // Alinhando a direita a coluna de referência
        for(int j=0; j < TAMANHO; j++){
            tabuleiro[i][j]=0; // Inicializando o tabuleiro 
            printf("%d ",tabuleiro[i][j]);
        }  
        printf("\n");
    }

    //3. O usuário pode informar onde deseja posicionar os navios
    //   Nessa primeira implementação vamos posiconar 2 navios em posições fixas
    printf("\n");
    printf("Posicionando um navio horizontal...\n");
    a=2; //Linha 2, Colunas 5 a 7 (E,F,G)
    for(int j=5; j <=7; j++){
       tabuleiro[a-1][j-1] += 3;
    }
    printf("Posicionando um navio vertical...\n");
    b=8; //Coluna H, Linhas 7 a 9 (7,8,9)
    for(int j=7; j <=9; j++){
       tabuleiro[j-1][b-1] += 3;
    }
    printf("Posicionando um navio na diagonal principal...\n");
    for(int i=2; i <=4; i++){
        tabuleiro[i][i] += 3;
    }
    printf("Posicionando um navio na diagonal secundária...\n");
    for(int i=7; i <=9; i++){
        tabuleiro[i][TAMANHO-1-i] += 3;
    }
    
    printf("Posicionando um navio em outra diagonal qualquer...\n");
    c=2;
    for(int i=7; i <=9; i++){
        tabuleiro[i][c-i] += 3;
    }

    //4. Checando sobreposição dos navios...
    for(int i=0; i < TAMANHO; i++){
        for(int j=0; j< TAMANHO; j++){
        (tabuleiro[i][j] > 3) ? 
        printf("ATENÇÃO!!HOUVE SOBREPOSIÇÃO DE NAVIOS!!\n") : 0;
        }
    }


    //5. Apresentando o tabuleiro com os navios ao usuário
    printf("\n");
    printf("TABULEIRO DE BATALHA NAVAL (NAVIOS POSICIONADOS)\n");
    printf("\n");
    for(int i=0; i <TAMANHO; i++){
        printf("%c ",linha[i]); 
    }
    printf("\n"); 
    for(int i=0; i <TAMANHO; i++){
    printf("%-2d ",coluna[i]);  // Alinhando a direita a coluna de referência
        for(int j=0; j <TAMANHO; j++){
            printf("%d ",tabuleiro[i][j]);
        }  
        printf("\n");
    }   
    
    
    //6. Criando as armas... CONE, CRUZ E OCTAEDRO
    printf("\n");
    printf("Projéteis disponíveis: Cone, Cruz e Octaedro 3x5)\n");
    printf("\n");

    //Cone (7) com origem no índice (3,4). Pode ser posteriormente escolhido pelo usuário
    cone_x=3;
    cone_y=4;
    // A lógica de desenhar o cone desenvolvida foi usar que para cada linha p=-1,0,+1, temos
    // valores de q como (0),(-1,0,+1) e (-2,-1,0,+1,+2) formando a base triangular

    for(int i=0; i<TAMANHO; i++){
        for(int j=0; j <10; j++){
            for(int p=-1; p < +2;p++) { //p variável para desenhar o cone horizontalmente
                for(int q=-(p+1);q<=(p+1);q++) { // q variável para desenhar o cone verticalmente
                    tabuleiro[cone_x+p][cone_y+q]=7;
                }  
            }
        }  
    }  

    //Cruz (4) com origem no índice (7,3). Pode ser posteriormente escolhido pelo usuário
    //Não foi encontrada uma lógica específica para desenhar as linhas da cruz, uma vez que altena
    //entre (0), (-2,-1,0,+1,+2) e (0).
    cruz_x=7;
    cruz_y=3;
    
    for(int i=0; i<TAMANHO; i++){
        for(int j=0; j <10; j++){
            for(int p=-1; p < +2;p++) { //p variável para desenhar a cruz horizontalmente
                if(p==-1){
                    tabuleiro[cruz_x+p][cruz_y+0]=4;
                } else if (p==0) {
                    for(int q=-2; q<3;q++){
                        tabuleiro[cruz_x+p][cruz_y+q]=4; // q variável para desenhar o cone verticalmente   
                    }
                } else {
                    tabuleiro[cruz_x+p][cruz_y+0]=4;
                }                  
            }
        }  
    } 

    //Octaedro (8) com origem no índice (6,7). Pode ser posteriormente escolhido pelo usuário
    //Não foi encontrada uma lógica específica para desenhar as linhas do octeedro, uma vez que altena
    //entre (0), (-1,0,+1) e (0).
    octa_x=6;
    octa_y=7;
    
    for(int i=0; i<TAMANHO; i++){
        for(int j=0; j <10; j++){
            for(int p=-1; p < +2;p++) { //p variável para desenhar o octaedro horizontalmente
                if(p==-1){
                    tabuleiro[octa_x+p][octa_y+0]=8;
                } else if (p==0) {
                    for(int q=-1; q<2;q++){
                        tabuleiro[octa_x+p][octa_y+q]=8; // q variável para desenhar o octaedro verticalmente   
                    }
                } else {
                    tabuleiro[octa_x+p][octa_y+0]=8;
                }                  
            }
        }  
    } 
    
    printf("TABULEIRO DE BATALHA NAVAL (NAVIOS/ARMAS)\n");
    printf("   ");
    for(int i=0; i <TAMANHO; i++){
        printf("%c ",linha[i]); 
    }
    printf("\n"); 
    for(int i=0; i <TAMANHO; i++){
    printf("%-2d ",coluna[i]);  // Alinhando a direita a coluna de referência
        for(int j=0; j <TAMANHO; j++){
            printf("%d ",tabuleiro[i][j]);
        }  
        printf("\n");
    }  
    printf("\n");

    printf("0-Água não atingida pela arma\n");
    printf("3-Parte de navio não atingido pela arma\n");
    printf("7-Local atingido pelo cone\n");
    printf("4-Local atingido pela cruz\n");
    printf("8-Local atingido pelo octaedro\n");

    return 0;
}