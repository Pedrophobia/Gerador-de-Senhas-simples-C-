#include <stdio.h>   
#include <stdlib.h>  
#include <time.h> 
#include <string.h>  

void gerarSenha(int tamanho, int incluirMaiusculas, int incluirNumeros, int incluirSimbolos) {
    char maiusculas[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char minusculas[] = "abcdefghijklmnopqrstuvwxyz";
    char numeros[] = "0123456789";
    char simbolos[] = "!@#$%^&*()_+-=.<>?";

    char conjunto[100] = "";
    strcat(conjunto, minusculas);
    if (incluirMaiusculas) {
        strcat(conjunto, maiusculas);
    }
    if (incluirNumeros) {
        strcat(conjunto, numeros);
    }
    if (incluirSimbolos) {
        strcat(conjunto, simbolos);
    }
     int conjuntoLength = strlen(conjunto);
     printf("\nSenha gerada: ");
     
     for(int i = 0; i < tamanho; i++) {
        int indice = rand() % conjuntoLength;
        printf("%c", conjunto[indice]);
    }
    printf("\n");
}
int main(){
    srand(time(NULL));
    int tamanho, incluirMaiusculas, incluirNumeros, incluirSimbolos;
    char continuar;
    do {
        printf("Digite o tamanho da senha: ");
        scanf("%d", &tamanho);  
        
        printf("Incluir letras maiúsculas? (1-Sim / 0-Não): ");
        scanf("%d", &incluirMaiusculas);  
        
        printf("Incluir números? (1-Sim / 0-Não): ");
        scanf("%d", &incluirNumeros);  
        
        printf("Incluir símbolos? (1-Sim / 0-Não): ");
        scanf("%d", &incluirSimbolos);

        gerarSenha(tamanho, incluirMaiusculas, incluirNumeros, incluirSimbolos);
        printf("Deseja gerar outra senha? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    
    return 0;
}