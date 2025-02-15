#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por rigião
#include <string.h> //Biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//Início da criação das variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação das variáveis/strinng
	
	printf("Digite o CPF a ser cadastrado: \n"); //Coleta de informações do usuário
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo,cpf);  // Responsável por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //Salva o valor da variável
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa adicionar
	fprintf(file, ","); //adiciona virgula
	fclose(file); //%s refere-se a string
	
	printf("Digite o nome a ser cadastrado: \n"); //Coleta de informações do usuário
	scanf("%s",nome); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa adicionar
	fprintf(file,nome); //Salva o valor da variável
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa adicionar
	fprintf(file, ","); //adiciona virgula
	fclose(file); // Fecha o arquivo
	
	printf("Digite o Sobrenome a ser cadastrado: \n"); //Coleta de informações do usuário
	scanf("%s",sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa adicionar
	fprintf(file,sobrenome); //Salva o valor da variável
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa adicionar
	fprintf(file, ","); //adiciona virgula
	fclose(file); // Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: \n"); //Coleta de informações do usuário
	scanf("%s",cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa adicionar
	fprintf(file,cargo); //Salva o valor da variável
	fclose(file); // Fecha o arquivo
	
	system("pause"); // pausa o sistema
	
}

int consulta()
{
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
	//Início da criação das variáveis/string
	char cpf[40];
	char conteudo[200];
	//final da criação das variáveis/strinng
	
	printf("Digite o CPF a ser consultado: "); //Coleta de informações do usuário
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf,"r"); //Abre o arquivo e o "r" significa ler
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado.\n"); //Mensagem de retorno ao usuário
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: "); // mensagem de retorno ao usuário
		printf("%s", conteudo); //%s refere-se a string
		printf("\n\n"); //espaço 
	}
	
	system("pause"); //pausa o sistema
}

int deletar()
{
	//Início da criação das variáveis/string
	char cpf[40];
	//final da criação das variáveis/strinng
	
	printf("Digite o CPF do usuário a ser deletado: "); //Coleta de informações do usuário
	scanf("%s",cpf); //%s refere-se a string
	
	remove(cpf);
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf,"r"); //Abre o arquivo e o "r" significa ler
	{
		printf("O usuário foi deletado!!! \n"); // mensagem de retorno ao usuário
		system("pause"); //pausa o sistema
	}
	if(file == NULL )
	{
		printf("O usuário não se encontra no sistema!!! \n"); // mensagem de retorno ao usuário
		system("pause"); //pausa o sistema
	}
}

int main()
{
	int opcao=0;  //Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); //responsável por limpar a tela
	
		setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
		
		printf("### Cartório da EBAC ### \n \n"); //Início do Menu
		printf("Escolha a opção desejada do menu: \n \n  ");
		printf("\t1 - Registrar nomes \n  ");
		printf("\t2 - Consultar nomes \n  ");
		printf("\t3 - Deletar nomes \n  "); 
		printf("\t4 - Sair do Sistema \n");
		printf("\nOpção: "); // Fim do Menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
		system("cls"); //responsável por limpar a tela
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
				registro(); //chamada de funções
				break;
				
			case 2:
				consulta(); //chamada de funções
				break;
				
			case 3:
				deletar();	 //chamada de funções
				break;
			
			case 4:
				printf("Obrigado por utilizar o sistema!\n\n");
				return 0;
				break;
					
			default:
				printf("Esta opção não está disponível!!!\n"); //mensagem de retorno ao usuário
				system("pause"); //pausa o sistema
				break;
		} //fim da seleção
		
	}	
}
