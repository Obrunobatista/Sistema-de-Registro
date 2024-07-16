#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em momória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() // Função responsavel por cadastrar os usuários no sistema
{

	//Início criação de variáveis /string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char email[40];
	char telefone[40];
	//Final da criação de variáveis/string
	
				//Coletando informações do Usuário
	
	//Cadastrando o CPF
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das string no nome do arquivo, ou seja, o CPF será o próprio nome do Arquivo!
	FILE *file; // Cria o arquivo no Banco de dados

	file = fopen(arquivo, "w"); // cria o arquivo "w" quer dizer escrever--- arquivo do tipo whitre
	fprintf(file,"CPF: ");
	fprintf(file,cpf); //Salvo o Valor da Variável --- salvar no arquivo a variável cpf
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
	file = fopen(cpf, "r"); //Abre o aquivo e lê o que tem dentro
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!. \n");
	}	
	
	printf("Essas são as informações do usuário: \n\n");
	
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
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf); // Vai varrer tudo o que o usuário digitar e salvar onde a gente pedir
	
	remove(cpf);
	
	FILE *file;
	file = fopen (cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!. \n"); //Informa que o CPF não foi encontrado
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
	int opcao=0;// Definindo variáveis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("Bem vindo ao Cartório da EBAC \n\n");
	printf("Login de Administrador! \n\nDigite a sua senha:");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao== 0)
	{	

		for(laco=1;laco=1;)
		{
			
			system("cls"); //removendo todo o texto e conteúdo exibido anteriormente
		
	
			setlocale(LC_ALL, "Portuguese");// Definindo Linguagem
	
			printf("Cartório da EBAC \n\n");//início do menu
			printf("Por Favor Escolha a opção Desejada: \n\n");
			printf("\t 1 - Registrar nomes.\n");
			printf("\t 2 - Consultar nomes.\n");
			printf("\t 3 - Deletar nomes.\n");
			printf("\t 4 - Fechar Programa.\n\n");
			printf("Digite sua Opção: ");// fim do menu
	
			scanf("%d", &opcao);// armazenando a escolha do usuário
	
			system("cls"); //removendo todo o texto e conteúdo exibido anteriormente
		
				switch(opcao)
					{
					case 1:
					registro(); //chamada de funções
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
					printf("Esta opção não está disponível!\n");
					system("Pause");
					break;	
				}
		}
	
	}
	
	else
		printf("\nSenha Incorreta!\n\nPor favor, tente Novamente!");
		system("Pause");

}
