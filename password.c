#include <stdio.h>   
#include <stdlib.h>  
#include <time.h> 
#include <string.h>  

void gerarSenha(int tamanho, int incluirMaiusculas, int incluirNumeros, int incluirSimbolos, char *senhaGerada) {
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
    
    for(int i = 0; i < tamanho; i++) {
        int indice = rand() % conjuntoLength;
        senhaGerada[i] = conjunto[indice];
    }
    senhaGerada[tamanho] = '\0';
    
    printf("\nSenha gerada: %s\n", senhaGerada);
}

void salvarSenha(char *senha, int tamanho, int maiusc, int nums, int simb) {
    FILE *arquivo;
    char nomeArquivo[100];
    
    time_t agora = time(NULL);
    struct tm *dataHora = localtime(&agora);
    
    sprintf(nomeArquivo, "senha_%02d-%02d-%04d_%02d-%02d-%02d.txt",
            dataHora->tm_mday,
            dataHora->tm_mon + 1,
            dataHora->tm_year + 1900,
            dataHora->tm_hour,
            dataHora->tm_min,
            dataHora->tm_sec);
    
    arquivo = fopen(nomeArquivo, "w");
    
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return;
    }
    
    fprintf(arquivo, "================================\n");
    fprintf(arquivo, "SENHA GERADA\n");
    fprintf(arquivo, "================================\n\n");
    fprintf(arquivo, "Data/Hora: %02d/%02d/%04d %02d:%02d:%02d\n", 
            dataHora->tm_mday, 
            dataHora->tm_mon + 1, 
            dataHora->tm_year + 1900,
            dataHora->tm_hour, 
            dataHora->tm_min, 
            dataHora->tm_sec);
    fprintf(arquivo, "Senha: %s\n", senha);
    fprintf(arquivo, "Tamanho: %d caracteres\n", tamanho);
    fprintf(arquivo, "Maiusculas: %s\n", maiusc ? "Sim" : "Nao");
    fprintf(arquivo, "Numeros: %s\n", nums ? "Sim" : "Nao");
    fprintf(arquivo, "Simbolos: %s\n", simb ? "Sim" : "Nao");
    fprintf(arquivo, "\n================================\n");
    
    fclose(arquivo);
    
    printf("Senha salva com sucesso no arquivo '%s'!\n", nomeArquivo);
}

int main(){
    srand(time(NULL));
    int tamanho, incluirMaiusculas, incluirNumeros, incluirSimbolos;
    char continuar;
    char senha[200];
    
    do {
        printf("Digite o tamanho da senha: ");
        scanf("%d", &tamanho);  
        
        printf("Incluir letras maiusculas? (1-Sim / 0-Nao): ");
        scanf("%d", &incluirMaiusculas);  
        
        printf("Incluir numeros? (1-Sim / 0-Nao): ");
        scanf("%d", &incluirNumeros);  
        
        printf("Incluir simbolos? (1-Sim / 0-Nao): ");
        scanf("%d", &incluirSimbolos);
        
        gerarSenha(tamanho, incluirMaiusculas, incluirNumeros, incluirSimbolos, senha);
        
        salvarSenha(senha, tamanho, incluirMaiusculas, incluirNumeros, incluirSimbolos);
        
        printf("\nDeseja gerar outra senha? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');
    
    return 0;
}