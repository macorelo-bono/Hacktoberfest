#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>
int escolha;
int menu()
{
	system("cls");
	printf("Para mudar a string e substring, basta mudar o valor das vari�veis no main.\n\n");
	int choice;
	printf("Compara��o de caracteres, digite 1\nPelo strstr, digite 2\nPara sair, digite 3\nOp��o: ");
	scanf("%d",&escolha);
	if(escolha==3) exit;
	return escolha;
}
void substring_comp(char *string, char *subs)
{
	system("cls");
	printf("Procurando \"%s\" em \"%s\"\n",subs,string);
	for(int i = 0; i < strlen(string); i++){
        for(int j = 0; j <= strlen(subs); j++){//usa dois la�os for, para ir percorrendo caractere a caractere
			if(j == strlen(subs)){
                printf("\nPosicao: %d",i+1);//ao encontrar semelhan�a, retorna a posi��o original de contagem de vetor(in�cio em 0)+1, para facilitar compreens�o do usu�rio
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
	if(subs=="")printf("\nSubstring n�o encontrada!");
	escolha=menu();
}
void comando(char *string, char *subs)
{
	system("cls");
	printf("Procurando \"%s\" em \"%s\"\n",subs,string);
	printf("-------------------------------------------------------\n");
	char *result=strstr(string,subs);//busca a string subs, em string
 	while (result!=NULL)//verificar� o resultado do strstr at� que este finalize a varredura da string
  	{
    	printf ("Ela est� na posi��o %d ->%s\n",result-string+1,result);//mostra a exatam posi��o da letra (substring) e ela na frase, pelo resultado do strstr
    	result=strstr(result+1,subs);//refaz o processo pra continuar o while
  	}
  	if(result=="") {
	  	printf("N�o foi encontrada!");
	  }
	  printf("\nEnter para continuar");
	  getche();
	  escolha=menu();
}

main()
{
	system("color 0a");
	setlocale(LC_ALL,"Portuguese");//permite uso de acentos
		printf("Ola! Sou o menu do Trabalho 02 de IC1, feito por Renan Barbieri Segamarchi e Marco Aur�lio Chaim de Santis!\n\n");
	printf("O exerc�cio 1, tema deste arquivo, foi desenvolvido por 2 m�todos, via compara��o manual de caracteres, \nretornando a posi��o de in�cio do 1 caractere da substring, \ne pelo comando strstr, que conta tamb�m com a possibilidade de mostrar o mesmo resultado, mas mais facilmente. \nEscolha!\n");
	printf("\nAperte enter para come�ar");
	getche();
	escolha = menu();
	
	
	char string[] = "Usu�rio, prazer, esta � sua string!";
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
