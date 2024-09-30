#include <stdio.h>

int main() {
    float n1, n2, n3 = 0.0, eu = 0.0, ppd, total = 0.0;
    int flag, flag2;

    // VALIDACAO DAS NOTAS N1, N2 e PPD
    do {
    	
        printf("Digite a nota de sua N1 (0 a 4,5):\n");
        scanf("%f", &n1);
        
        printf("Digite a nota de sua N2 (0 a 4,5):\n");
        scanf("%f", &n2);
        
        printf("Digite a nota de seu PPD (0 a 1):\n");
        scanf("%f", &ppd);
        
        if((n1 < 0) || (n1 > 4.5) || (n2 < 0) || (n2 > 4.5) || (ppd < 0) || (ppd > 1)) {
        	
            printf("Codigo de erro: 3\nValor invalido.\n");
        }
        
    } while((n1 < 0) || (n1 > 4.5) || (n2 < 0) || (n2 > 4.5) || (ppd < 0) || (ppd > 1));

    // VERIFICAÇÃO DO EXAME UNIFICADO (EU)
    do {
    	
        printf("O aluno fez o Exame Unificado (EU)?\n1(sim) 0(nao)\n");
        scanf("%d", &flag);

        if(flag == 1) {
            do {
            	
                printf("Digite a nota do Exame Unificado (0 a 1):\n");
                scanf("%f", &eu);
                
                if((eu < 0) || (eu > 1)) {
                	
                    printf("Codigo de erro: 3\nValor invalido.\n");
                    
                }
            } while((eu < 0) || (eu > 1));
            
        } else if(flag != 0) {
        	
            printf("Digite novamente com um valor valido (0 ou 1)\n");
            
        }
    } while((flag != 1) && (flag != 0));

    // VERIFICAÇÃO N3
    do {
    	
        printf("O aluno fez a N3?\n1(sim) 0(nao)\n");
        scanf("%d", &flag2);

        if(flag2 == 1) {
            do {
            	
                printf("Digite a nota da N3 (0 a 4,5):\n");
                scanf("%f", &n3);
                
                if((n3 < 0) || (n3 > 4.5)) {
                	
                    printf("Codigo de erro: 3\nValor invalido.\n");
                    
                }
            } while((n3 < 0) || (n3 > 4.5));
            
        } else if(flag2 != 0) {
        	
            printf("Digite novamente com um valor valido (0 ou 1)\n");
            
        }
    } while((flag2 != 1) && (flag2 != 0));

    // SUBISTUIÇÃO DA MENOR NOTA DA N1 E N2, SE N3 FOR MAIOR
    if((n1 < n2) && (n1 < n3)) {
        n1 = n3;
    } else if((n2 < n1) && (n2 < n3)) {
        n2 = n3;
    }

    // CALCULO DA NOTA FINAL
    total = n1 + n2 + ppd + eu;

    // LIMITAR A NOTA PARA 10
    if(total > 10) {
        total = 10;
    }

    // EXIBIR O RESULTADO FINAL
    if(total < 7) {
    	
        printf("Aluno reprovado com nota %.2f\n", total);
        
    } else {
    	
        printf("Aluno aprovado com nota %.2f\n", total);
    }

    return 0;
}
