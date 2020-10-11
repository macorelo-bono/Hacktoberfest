#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>
int escolha;
int menu()
{
	system("cls");
	printf("Para mudar a string e substring, basta mudar o valor das variáveis no main.\n\n");
	int choice;
	printf("Comparação de caracteres, digite 1\nPelo strstr, digite 2\nPara sair, digite 3\nOpção: ");
	scanf("%d",&escolha);
	if(escolha==3) exit;
	return escolha;
}
void substring_comp(char *string, char *subs)
{
	system("cls");
	printf("Procurando \"%s\" em \"%s\"\n",subs,string);
	for(int i = 0; i < strlen(string); i++){
        for(int j = 0; j <= strlen(subs); j++){//usa dois laços for, para ir percorrendo caractere a caractere
			if(j == strlen(subs)){
                printf("\nPosicao: %d",i+1);//ao encontrar semelhança, retorna a posição original de contagem de vetor(início em 0)+1, para facilitar compreensão do usuário
				printf("\nEnter para continuar");
				getche();
				break;
            }
            if(subs[j] == string[i+j]){
                continue;
            }
            else{
                break;
            }
		}
	}
	if(subs=="")printf("\nSubstring não encontrada!");
	escolha=menu();
}
void comando(char *string, char *subs)
{
	system("cls");
	printf("Procurando \"%s\" em \"%s\"\n",subs,string);
	printf("-------------------------------------------------------\n");
	char *result=strstr(string,subs);//busca a string subs, em string
 	while (result!=NULL)//verificará o resultado do strstr até que este finalize a varredura da string
  	{
    	printf ("Ela está na posição %d ->%s\n",result-string+1,result);//mostra a exatam posição da letra (substring) e ela na frase, pelo resultado do strstr
    	result=strstr(result+1,subs);//refaz o processo pra continuar o while
  	}
  	if(result=="") {
	  	printf("Não foi encontrada!");
	  }
	  printf("\nEnter para continuar");
	  getche();
	  escolha=menu();
}

main()
{
	system("color 0a");
	setlocale(LC_ALL,"Portuguese");//permite uso de acentos
		printf("Ola! Sou o menu do Trabalho 02 de IC1, feito por Renan Barbieri Segamarchi e Marco Aurélio Chaim de Santis!\n\n");
	printf("O exercício 1, tema deste arquivo, foi desenvolvido por 2 métodos, via comparação manual de caracteres, \nretornando a posição de início do 1 caractere da substring, \ne pelo comando strstr, que conta também com a possibilidade de mostrar o mesmo resultado, mas mais facilmente. \nEscolha!\n");
	printf("\nAperte enter para começar");
	getche();
	escolha = menu();
	
	
	char string[] = "Usuário, prazer, esta é sua string!";
	char substring[] = "sua";
	
	
	while(escolha >4 || escolha<1){
		escolha = menu();	
	}
	while(escolha!=3){
	
		if(escolha==1)substring_comp(string,substring);
		else if(escolha==2) comando(string,substring);
		if(escolha==3)exit;
	}
}
