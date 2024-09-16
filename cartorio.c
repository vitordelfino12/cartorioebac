#include <stdio.h> // bibilioteca de comunicação com usuario
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável por cuidar das strings

int registro() // Função responsável por cadastrar os usuários no sistema
{
	// inicio da criação de variaveis
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	//final da criação de variaveis
	
	printf ("Digite o CPF a ser cadastrado: \n"); //coletando informações do usuário
	scanf("%s", cpf); // %s usado para armazenar o valor digitado na string "cpf"
	
	strcpy(arquivo, cpf); // copia o valor da variavel "cpf" para o nome do arquivo de texto criado
	FILE *file; // utiliza uma função "FILE" para criar o "file"
	
	file = fopen(arquivo, "w"); // cria o arquivo com a função "w, write"
	fprintf(file,cpf); //salva o valor do "cpf" dentro do arquivo"
	fclose(file); //fecha o arquivo
	
	file = fopen (arquivo, "a"); // "a" serve para atualizar o arquivo com o dado vindo do fprintf
	fprintf(file, ", "); // virgula para separar os dados no file
	fclose(file);
	
	printf ("Digite o nome a ser cadastrado: \n");  //cadastro do nome
	scanf ("%s",nome);
	file = fopen (arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen (arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf ("Digite o sobrenome a ser cadastrado: \n"); //cadastro do sobrenome
	scanf ("%s", sobrenome);
	file = fopen (arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	system ("pause");
}

int consulta() // Inicio função consulta de usuario
{
	char cpf [40];
	char conteudo [200];
	
	printf ("Digite o CPF a ser consultado: ");
	scanf ("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf ("\nNão foi possivel localizar o CPF informado.\n\n");
	}
	
	while (fgets (conteudo, 200, file) != NULL)
	{
		printf ("\nEssas são as informações do usuário: ");
		printf ("%s \n\n", conteudo);
	}
	system ("pause");
}

int deletar () // Inicio função deletar usuario
{
	char cpf[40];
	printf ("Digite o CPF a ser deletado: ");
	scanf ("%s", cpf);
	
	FILE *file;
	file = fopen (cpf, "r");
	fclose(file);
	
	if (file == NULL)
	{
		printf ("\nO usuário não se encontra no sistema! \n\n");
		system ("pause");
	}
	else
	{
		remove(cpf);
		printf ("\nUsuário deletado com sucesso! \n\n");
		system ("pause");
	}
}	

int main()
{
	int opcao=0;
	int x=1;
	char senhadigitada[10]= "a";
	
	while (x==1)
	{
		printf("### Cartorio da EBAC ###\n");
		printf("\nLogin de administrador!\n\nDigite a sua senha:");
		scanf("%s", senhadigitada);
		
		if(strcmp(senhadigitada, "admin") == 0) // comparação de senha digitada para validar se esta correta
		{
			printf ("\nAcesso permitido!\n\n");
			system("pause");
			break;
		}
		else
		{
			printf("\nSenha incorreta! Tente novamente\n\n");
			system("pause");
			system("cls");
		}
	}
	
	for (x=1; x=1;)
	{
		setlocale (LC_ALL, "Portuguese"); //definindo a linguagem
		system("cls");
		printf("# Cartório da EBAC # \n\n");
		printf("Escolha a opção desejeada no menu: \n\n");
		printf("\t1 - Registro de nomes. \n");
		printf("\t2 - Consulta de nomes. \n");
		printf("\t3 - Deletar nomes. \n");
		printf ("\t4 - Sair do sistema. \n\n");
		printf("Opção: ");
		scanf("%d", &opcao); // "%d" usado para receber oque usuário digitou e "&opcao" usado para armazenar o valor na variavel "opcao"
		system("cls"); // usado para limpar a tela
		
		switch (opcao) // Inicio da seleção de menu
		{
			case 1:
			registro(); // chamada de função
			break;
				
			case 2:
			consulta(); // chamada de função
			break;
				
			case 3:
			deletar(); // chamada de função
			break;
				
			case 4:
			printf ("\nObrigado por utilizar o sistema. \n");
			return 0;
			break;
				
			default:
			printf ("Opção não está disponivel \n\n");
			system ("pause");
			break;
		} //fim da seleção
	}
}
