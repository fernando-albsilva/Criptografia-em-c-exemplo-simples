/* Escreva uma função que receba como parâmetro um texto e um valor N e faz a criptografia do mesmo usando a seguinte regra.
 Para cada letra do texto,
  de acordo com sua posição em cada vetor atribua a ela a letra que estiver N posições depois do mesmo vetor.
   Imprima a frase criptografada na tela. Ela deve ser exibida em grupos de 5 letras. O último grupo deve ser completado com zeros ao final se contiver menos de 5 letras.
 Escreva outra função que exiba a frase descriptografada.
*/

/* Programa que faz uma simples crpitografia de um texto e a seguir descriptografa o mesmo,
   a criptografia é feita onde cada letra do texto digitado recebe a letra na posição que a constante "FATOR" tem seu valor.
   Ou seja casa seja a letra 'a' e o "FATOR" definido com valor 3. A  Resposta criptografada desta letra será 'd'.
*/

#include <stdio.h>
#include <ncurses.h>
void cripto(char*,int);
void descripto(char*,int);

/*Define o valor do fator */
#define FATOR 3

int main(void)
{
    char str[100];
    

    printf("\nDigite o texto : ");
    scanf("%s", str);
   
    cripto(&str[0],FATOR);

    return 0;
}


    
 void cripto(char*str,int n)  
 { 
    char *teste, aux,crip[100];
    int i = 0, k = 0, cont = 0; 
    teste = &str[0];
    while (*teste != '\0' || *teste == '\0')
    {
        if (*teste == '\0')
        {
            crip[k] = '\0';
            break;
        }
        else
        {
                aux=*teste;
               
                if ( (aux+n) > 'z')
                {   
                    for(i=1; i<=n ; i++)
                    {
                        aux++;
                        if(aux > 'z')
                        {
                            aux='a';
                        }
                        crip[cont]=aux;

                    }
                  
                }
                else
                {
                    crip[cont]=(aux+n);
                }
            
            
        }
        cont++;
        k++;
        teste++;
    }
    teste = &crip[0];
    cont=1;
     k=0;
     printf("\n--------------------------------------------\n");
     printf("\nMensagem criptografada : ");
     while(*teste != '\0')
     {
        printf("%c",crip[k]);
        if(cont%5==0  && cont!=0)
        {
            putchar(' ');
            
        }
        k++;
        teste++;
        cont++;
        if (cont==6)
        {
            cont=1;
        }
        if(*teste == '\0' && cont!=6)
        {
            while(cont !=6  )
            {
                putchar('0');
                cont++;
            }
        }
     }
    printf("\n--------------------------------------------\n");
    descripto(&crip[0],n);

 }


void descripto(char*crip,int n)
{
    char *teste, aux;
    int i = 0, k = 0, cont = 0; 
    teste=&crip[0];
    while (*teste != '\0' || *teste == '\0')
    {
        if (*teste == '\0')
        {
            crip[k] = '\0';
            break;
        }
        else
        {
                aux=*teste;
               
                if ( (aux-n) < 'a')
                {   
                    for(i=1; i<=n ; i++)
                    {
                        aux--;
                        if(aux < 'a')
                        {
                            aux='z';
                        }
                        crip[cont]=aux;

                    }
                  
                }
                else
                {
                    crip[cont]=(aux-n);
                }
            
            
        }
        cont++;
        k++;
        teste++;
    }
    teste = &crip[0];
    
     k=0;
     printf("\n--------------------------------------------\n");
     printf("\nMensagem descriptografada: ");
     
     while(*teste != '\0')
     {
        printf("%c",crip[k]);
        
        k++;
        teste++;
    
     }
     printf("\n--------------------------------------------\n");
}