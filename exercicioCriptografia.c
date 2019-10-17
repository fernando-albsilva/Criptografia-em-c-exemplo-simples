/* Escreva uma função que receba como parâmetro um texto e um valor N e faz a criptografia do mesmo usando a seguinte regra.
 Para cada letra do texto,
  de acordo com sua posição em cada vetor atribua a ela a letra que estiver N posições depois do mesmo vetor.
   Imprima a frase criptografada na tela. Ela deve ser exibida em grupos de 5 letras. O último grupo deve ser completado com zeros ao final se contiver menos de 5 letras.
 Escreva outra função que exiba a frase descriptografada.
*/

#include <stdio.h>
#include <ncurses.h>
void cripto(char*,int);
int main(void)
{
    char str[100];
    int n;

    printf("\nDigite o texto : ");
    scanf("%s", str);
    printf("\nDigite um valor : ");
    scanf("%d", &n);
    cripto(&str[0],n);

    return 0;
}


    
 void cripto(char*str,int n)  
 { 
    char *teste, *reset, aux,crip[100];
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


 }










    /*
    reset = &str[0];

    teste = reset;
    
    while (*teste != '\0' || *teste == '\0')
    {
        if (*teste == '\0')
        {
            crip[k] = '\0';
            break;
        }
        else
        {
            
            aux = teste;
            for (i = 0 ; i <= n; i++)
            {
                if (str[cont] == '\0')
                {
                    aux = reset;
                    cont=0;
                    crip[k]=*aux;
                    cont++;
                    aux++;
                }
                else
                {
                    crip[k] = *aux;
                    aux++;
                    cont++;
                }
            }
            cont=k;
            k++;
            teste++;
        }
    }
    teste = reset;

    printf("\n\n%c\n\n", crip[0]);
*/