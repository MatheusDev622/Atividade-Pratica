#include <stdio.h>
#include <stdlib.h>

#define TAM 1024

// palavras a serem censuradas
char *plvr_cen[] = {"kanal", "libertadores", "ovo"};
int plvr_len[] = {5, 12, 3};  // tamanho de cada palavra censurada
int num_palavras = 4;


void censura(char str[TAM]) {
    for (int i = 0; str[i] != '\0'; i++) {
        for (int k = 0; k < num_palavras; k++) {
            int len = plvr_len[k];

            int igual = 1;
            for (int j = 0; j < len; j++) {
                if (str[i + j] == '\0' || str[i + j] != plvr_cen[k][j]) {
                    igual = 0;
                    break;
                }
            }

            if (igual) {
                for (int j = 0; j < len; j++) {
                    str[i + j] = '*';
                }
                i += len - 1; 
            }
        }
    }
}

int main() {
    char str[TAM];

    puts("Digite um texto de até 1024 caracteres:");
    fgets(str, sizeof(str), stdin);

    censura(str);

    printf("Texto censurado:\n%s", str);
    return 0;
}
