#include <stdio.h>  //biblioteca de comunica��o com o usario
#include <stdlib.h> //biblioteca de aloca��o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);
	
	FILE *file;
	file = fopen(arquivo, "w");
	fprintf(file,cpf);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	printf("\n\nDados cadastrados com sussesso!! \n");	
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //"r" quer dizer Ler o arquivo
	
	if(file == NULL)
	{
		printf("\nN�o foi possivel abrir o arquivo,n�o localizado! \n");
		system("pause");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //"while la�o de repeti��o enqunto // valida��o de ENquanto 
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser Deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\nO usu�rio n�o se encontra mais no sistema. \n");
		system("pause");
	}
	
}

int main()
	{
	int opcao=0; //definomos a variavel
	int laco=1;
		
	for(laco=1;laco=1;)
	{
		system("cls");
				
		setlocale(LC_ALL, "Portuguese"); //definimos a linguagem
		
		printf("\tCart�rio da EBAC\n"); //inicio do menu
		printf("Selecione uma op��o no menu\n\n");
		printf("\t1 - Cadastrar nome\n");
		printf("\t2 - Comsultar nome\n");
		printf("\t3 - Deletar nome\n\n");
		printf("\t4 - obrigado por usar o sistema!\n\n");
		printf("Op��o:"); //fim do menu
		
		scanf("%d",&opcao);  //armazenando a escolha do usuaruio
		
		system("cls");
		
		switch(opcao) //inicio da sele��o
		{
			case 1:
			registro();
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por usar o sistema!\n");
			return 0;
			
			default:
			printf("Op��o Indisponivel\n");
			system("pause");
			break;	
		}
		
    
	}
    
}
