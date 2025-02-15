#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por rigi�o
#include <string.h> //Biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//In�cio da cria��o das vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o das vari�veis/strinng
	
	printf("Digite o CPF a ser cadastrado: \n"); //Coleta de informa��es do usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo,cpf);  // Respons�vel por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //Salva o valor da vari�vel
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa adicionar
	fprintf(file, ","); //adiciona virgula
	fclose(file); //%s refere-se a string
	
	printf("Digite o nome a ser cadastrado: \n"); //Coleta de informa��es do usu�rio
	scanf("%s",nome); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa adicionar
	fprintf(file,nome); //Salva o valor da vari�vel
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa adicionar
	fprintf(file, ","); //adiciona virgula
	fclose(file); // Fecha o arquivo
	
	printf("Digite o Sobrenome a ser cadastrado: \n"); //Coleta de informa��es do usu�rio
	scanf("%s",sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa adicionar
	fprintf(file,sobrenome); //Salva o valor da vari�vel
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa adicionar
	fprintf(file, ","); //adiciona virgula
	fclose(file); // Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: \n"); //Coleta de informa��es do usu�rio
	scanf("%s",cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa adicionar
	fprintf(file,cargo); //Salva o valor da vari�vel
	fclose(file); // Fecha o arquivo
	
	system("pause"); // pausa o sistema
	
}

int consulta()
{
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
	//In�cio da cria��o das vari�veis/string
	char cpf[40];
	char conteudo[200];
	//final da cria��o das vari�veis/strinng
	
	printf("Digite o CPF a ser consultado: "); //Coleta de informa��es do usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf,"r"); //Abre o arquivo e o "r" significa ler
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado.\n"); //Mensagem de retorno ao usu�rio
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); // mensagem de retorno ao usu�rio
		printf("%s", conteudo); //%s refere-se a string
		printf("\n\n"); //espa�o 
	}
	
	system("pause"); //pausa o sistema
}

int deletar()
{
	//In�cio da cria��o das vari�veis/string
	char cpf[40];
	//final da cria��o das vari�veis/strinng
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //Coleta de informa��es do usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	remove(cpf);
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf,"r"); //Abre o arquivo e o "r" significa ler
	{
		printf("O usu�rio foi deletado!!! \n"); // mensagem de retorno ao usu�rio
		system("pause"); //pausa o sistema
	}
	if(file == NULL )
	{
		printf("O usu�rio n�o se encontra no sistema!!! \n"); // mensagem de retorno ao usu�rio
		system("pause"); //pausa o sistema
	}
}

int main()
{
	int opcao=0;  //Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); //respons�vel por limpar a tela
	
		setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
		
		printf("### Cart�rio da EBAC ### \n \n"); //In�cio do Menu
		printf("Escolha a op��o desejada do menu: \n \n  ");
		printf("\t1 - Registrar nomes \n  ");
		printf("\t2 - Consultar nomes \n  ");
		printf("\t3 - Deletar nomes \n  "); 
		printf("\t4 - Sair do Sistema \n");
		printf("\nOp��o: "); // Fim do Menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
		system("cls"); //respons�vel por limpar a tela
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
				registro(); //chamada de fun��es
				break;
				
			case 2:
				consulta(); //chamada de fun��es
				break;
				
			case 3:
				deletar();	 //chamada de fun��es
				break;
			
			case 4:
				printf("Obrigado por utilizar o sistema!\n\n");
				return 0;
				break;
					
			default:
				printf("Esta op��o n�o est� dispon�vel!!!\n"); //mensagem de retorno ao usu�rio
				system("pause"); //pausa o sistema
				break;
		} //fim da sele��o
		
	}	
}
