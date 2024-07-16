#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mom�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() // Fun��o responsavel por cadastrar os usu�rios no sistema
{

	//In�cio cria��o de vari�veis /string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char email[40];
	char telefone[40];
	//Final da cria��o de vari�veis/string
	
				//Coletando informa��es do Usu�rio
	
	//Cadastrando o CPF
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das string no nome do arquivo, ou seja, o CPF ser� o pr�prio nome do Arquivo!
	FILE *file; // Cria o arquivo no Banco de dados

	file = fopen(arquivo, "w"); // cria o arquivo "w" quer dizer escrever--- arquivo do tipo whitre
	fprintf(file,"CPF: ");
	fprintf(file,cpf); //Salvo o Valor da Vari�vel --- salvar no arquivo a vari�vel cpf
	fclose(file); // fecha o arquivo
	
	//Cadastrando o Nome
	
	file = fopen(arquivo, "a"); //abrindo o arquivo e atualizando ,"a" quer dizer atualizar
	fprintf(file,", \nNome:"); // separando os dados por virgula 
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome); //armazenando o nome digitado
	
	file = fopen(arquivo, "a"); //abrindo o arquivo e atualizando
	fprintf(file,nome);
	fclose(file); //fechando o arquivo
	
	//Cadastrando o Sobrenome
		
	file = fopen(arquivo, "a");
	fprintf(file,", \nSobrenome:");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	//Cadastrando o Cargo
	
	file = fopen(arquivo, "a");
	fprintf(file,", \nCargo:");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	//Cadastrando o e-mail

	file = fopen(arquivo, "a");
	fprintf(file,", \nemail:");
	fclose(file);
	
	printf("Digite o e-mail a ser cadastrado: ");
	scanf("%s",email);
	
	file = fopen(arquivo,"a");
	fprintf(file,email);
	fclose(file);

	//Cadastrando o Telefone
	
	file = fopen(arquivo, "a");
	fprintf(file,", \nTelefone:");
	fclose(file);
	
	printf("Digite o telefone a ser cadastrado: ");
	scanf("%s",telefone);
	
	file = fopen(arquivo,"a");
	fprintf(file,telefone);
	fclose(file);
	

	file = fopen(arquivo, "a");
	fprintf(file,".");
	fprintf(file,"\n\n");
	fclose(file);
	
	//Fim do Cadastro
	
	system("Pause");	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo Linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //Abre o aquivo e l� o que tem dentro
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!. \n");
	}	
	
	printf("Essas s�o as informa��es do usu�rio: \n\n");
	
	while(fgets(conteudo, 500, file)!= NULL)// Salvando na variavel conteudo  na string, os 200 caracteres dentro do arquivo
	{
		printf("%s", conteudo);
		//printf("\n");
	}
	
	system("pause");
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo Linguagem
	
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf); // Vai varrer tudo o que o usu�rio digitar e salvar onde a gente pedir
	
	remove(cpf);
	
	FILE *file;
	file = fopen (cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!. \n"); //Informa que o CPF n�o foi encontrado
		system("pause");
		return 0;
	}

	
}

int fechar() 
{
  //printf("Obrigado Ebacer! Clique Enter para Fechar Programa.\n");
  exit(0); // Fechando o Programa
  return 0;
}


int main()
{
	int opcao=0;// Definindo vari�veis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("Bem vindo ao Cart�rio da EBAC \n\n");
	printf("Login de Administrador! \n\nDigite a sua senha:");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao== 0)
	{	

		for(laco=1;laco=1;)
		{
			
			system("cls"); //removendo todo o texto e conte�do exibido anteriormente
		
	
			setlocale(LC_ALL, "Portuguese");// Definindo Linguagem
	
			printf("Cart�rio da EBAC \n\n");//in�cio do menu
			printf("Por Favor Escolha a op��o Desejada: \n\n");
			printf("\t 1 - Registrar nomes.\n");
			printf("\t 2 - Consultar nomes.\n");
			printf("\t 3 - Deletar nomes.\n");
			printf("\t 4 - Fechar Programa.\n\n");
			printf("Digite sua Op��o: ");// fim do menu
	
			scanf("%d", &opcao);// armazenando a escolha do usu�rio
	
			system("cls"); //removendo todo o texto e conte�do exibido anteriormente
		
				switch(opcao)
					{
					case 1:
					registro(); //chamada de fun��es
					break;
			
					case 2:
					consulta();
					break;
			
					case 3:
					deletar();
					break;
			
					case 4:
					fechar();
					break;
			
					default:
					printf("Esta op��o n�o est� dispon�vel!\n");
					system("Pause");
					break;	
				}
		}
	
	}
	
	else
		printf("\nSenha Incorreta!\n\nPor favor, tente Novamente!");
		system("Pause");

}
