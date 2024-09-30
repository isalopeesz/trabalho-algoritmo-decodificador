#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int func_val(int x, int b) {
	

    // VALOR DE A
    
   double a0 = 186.752;
    double a1 = -148.235;
    double a2 = 34.5049;
    double a3 = -3.5091;
    double a4 = 0.183166;
    double a5 = -0.00513554;
    double a6 = 0.0000735464;
    double a7 = -4.22038e-7;

    double resultado = a0 + (a1 + b) * x + a2 * pow(x, 2) + a3 * pow(x, 3) 
                      + a4 * pow(x, 4) + a5 * pow(x, 5) 
                      + a6 * pow(x, 6) + a7 * pow(x, 7);

    // RETORNO DO RESULTADO DA FUNÇAO
    return (int)resultado;
}

int main() {
	
	int quantidade;
	int i;
	int j;
	int b;
	int decimal;
	int length;
	char hexadecimal[501];
	char dupla[3] = "00";
		
	
	printf("Quantidade de mensagens a decifrar: ");
    scanf("%d", &quantidade);

    for (i = 0; i < quantidade; i++) {
        
        printf("Coloque a mensagem hexadecimal a ser decodificada: ");
        scanf("%s", hexadecimal);

        // VALOR DA VARIAVEL B
        printf("Qual o valor b: ");
        scanf("%d", &b);

        length = strlen(hexadecimal);

        // INTERA PARES DA STRING HEXADECIMAL
        for (j = 0; j < length; j += 2) {
        	
            // NAO DEIXA ULTRAPASSAR O LIMITE DA STRING
            if (j + 1 < length) {
                dupla[0] = hexadecimal[j];
                dupla[1] = hexadecimal[j + 1];
                dupla[2] = '\0';  

                //HEXADECIMAL PARA DECIMAL
                decimal = strtol(dupla, NULL, 16);

                // CONFERIR RESULTADO DA FUNÇÃO PARA IMPRIMR 
                if (func_val((j / 2) + 1, b) != 0) {
                    printf("%c", decimal);
                }

                // PARAR CASO HOUVER 0 
                if (decimal == 0) {
                    break;
                }
            }
        }

        printf("\n\n"); 
    }

    return 0;
}
