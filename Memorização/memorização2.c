#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>

void nivel(char *string, int n)
{
int b;
n--;
    if(n>0){
    srand(time(NULL));
        for(int i=0;i<n;i++){
            b=rand() %9;
            sprintf((string+i),"%d",b);}
    }
    srand(time(NULL));
}

int resultado (char *string, char *str2, char *res1, char *res2)
{
	int resultado;
	// se igual a 0 continua ambos acertaram ou erraram, se 1, o primeiro ganhou , se 2 o segundo ganhou,
    if(((strcmp(string,res1)==0) && (strcmp(str2,res2)==0)) || ( (strcmp(string,res1)!=0) && (strcmp(str2,res2)!=0)))
        resultado=0;
    else if((strcmp(string,res1)==0) && (strcmp(str2,res2)!=0))
        resultado=1;
    else if ((strcmp(string,res1)!=0) && (strcmp(str2,res2)==0))
        resultado=2;

    return resultado;


}

int memorizacao2(int n)
{
	int a,b,cont=0,result,tempo=5000;
	char string[100],string2[100],res1[100],res2[100];
	bool VF=true;
    n--;
    srand(time(NULL));
    for(int i=0;i<=n;i++)
        {
        b=rand() %9;
        sprintf((string+i),"%d",b);
        *(string+i+1)='\0';
        a=rand() %9;
        sprintf((string2+i),"%d",a);
        *(string2+i+1)='\0';
        }
	do
	{
        b=rand() %9;
        sprintf((string+n),"%d",b);
        *(string+n+1)='\0';
        a=rand() %9;
        sprintf((string2+n),"%d",a);
        *(string2+n+1)='\0';
        printf("Memorize a seguinte sequencia jogador 1: %s\n",string);
        Sleep(tempo);
        system("cls");
        printf("Memorize a seguinte sequencia jogador 2: %s\n",string2);
        Sleep(tempo);
        system("cls");
        printf("Diga a sua sequencia jogador 1: ");
        scanf("%s",res1);
        Sleep(2000);
        system("cls");
        printf("Diga a sua sequencia jogador 2: ");
        scanf("%s",res2);
        Sleep(2000);
        system("cls");
        n++;
        tempo-=10;
        result=resultado(string,string2,res1,res2);

    if(result==0)
        {

        }
    else if (result==1)
    {
        VF=false;
        int tamanho=strlen(res1);
        printf("O ganhador foi o jogador 1\nEle memorizou %i casas decimais.",tamanho);
    }
    else if (result==2)
    {
        VF=false;
        int tamanho=strlen(res2);
        printf("O ganhador foi o jogador 2\nEle memorizou %i casa(s) decimais.",tamanho);
    }
	}
	while(VF);


}

int memorizacao1(int n)
{
    int b,cont=0,tempo=5000,acertos=0;
	char string[100],res1[100];
	bool VF=true;
    nivel(string,n);
    n--;
    do{
        srand(time(NULL));
        b=rand() %9;
        sprintf((string+n),"%d",b);
        *(string+n+1)='\0';
        printf("Memorize a seguinte sequencia: %s\n",string);
        Sleep(tempo);
        system("cls");
        printf("Diga a sua sequencia: ");
        scanf("%s",res1);
        system("cls");
        n++;
        tempo-=10;
        if(strcmp(res1,string)==0){
            acertos=strlen(string);
        }
        else if(strcmp(res1,string)!=0)
        {
            VF=false;
            printf("Voce memorizou %i casas decimais.",acertos);
        }
    }
    while(VF);
}

    int main()
{
    int escolha = 0,n=0;

    do{
        printf("--------------------------------------------");
        printf("\n-----------------Escolha--------------------");
        printf("\nOpcao 01 - - - Jogo de memorizacao 1 jogador");
        printf("\nOpcao 02 - - - Jogo de memorizacao 2 jogador");
        printf("\nOpcao 03 - - - Sair");
        printf("\n---------------------------------------------");
        printf("\n\nOpcao -> ");
        scanf("%i",&escolha);
        }
    while(escolha>3 || escolha==0);

    if(escolha==1)
    {
        do{
            printf("------------------------------------------");
            printf("\n------Em qual nivel deseja comecar: ---- ");
            printf("\nNivel ------------------------ 1 - Padrao");
            printf("\nNivel ------------------------ Entre 1-20 ");
            printf("\n------------------------------------------");
            printf("\nNivel -> ");
            scanf("%i",&n);}
        while(n>20 || n==0);
        memorizacao1(n);
    }
    else if(escolha==2)
    {
        do{
            printf("------------------------------------------");
            printf("\n------Em qual nivel deseja comecar: ---- ");
            printf("\nNivel ------------------------ 1 - Padrao");
            printf("\nNivel ------------------------ Entre 1-20 ");
            printf("\n------------------------------------------");
            printf("\nNivel -> ");
            scanf("%i",&n);}
        while(n>20 || n==0);
        memorizacao2(n);
    }
    else {
        if(escolha==3)
        {
            exit(0);
        }
}

}