#include <stdio.h> // bibilioteca de comunica��o com usuario
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings

int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	// inicio da cria��o de variaveis
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	//final da cria��o de variaveis
	
	printf ("Digite o CPF a ser cadastrado: \n"); //coletando informa��es do usu�rio
	scanf("%s", cpf); // %s usado para armazenar o valor digitado na string "cpf"
	
	strcpy(arquivo, cpf); // copia o valor da variavel "cpf" para o nome do arquivo de texto criado
	FILE *file; // utiliza uma fun��o "FILE" para criar o "file"
	
	file = fopen(arquivo, "w"); // cria o arquivo com a fun��o "w, write"
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

int consulta() // Inicio fun��o consulta de usuario
{
	char cpf [40];
	char conteudo [200];
	
	printf ("Digite o CPF a ser consultado: ");
	scanf ("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf ("\nN�o foi possivel localizar o CPF informado.\n\n");
	}
	
	while (fgets (conteudo, 200, file) != NULL)
	{
		printf ("\nEssas s�o as informa��es do usu�rio: ");
		printf ("%s \n\n", conteudo);
	}
	system ("pause");
}

int deletar () // Inicio fun��o deletar usuario
{
	char cpf[40];
	printf ("Digite o CPF a ser deletado: ");
	scanf ("%s", cpf);
	
	FILE *file;
	file = fopen (cpf, "r");
	fclose(file);
	
	if (file == NULL)
	{
		printf ("\nO usu�rio n�o se encontra no sistema! \n\n");
		system ("pause");
	}
	else
	{
		remove(cpf);
		printf ("\nUsu�rio deletado com sucesso! \n\n");
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
		
		if(strcmp(senhadigitada, "admin") == 0) // compara��o de senha digitada para validar se esta correta
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
		printf("# Cart�rio da EBAC # \n\n");
		printf("Escolha a op��o desejeada no menu: \n\n");
		printf("\t1 - Registro de nomes. \n");
		printf("\t2 - Consulta de nomes. \n");
		printf("\t3 - Deletar nomes. \n");
		printf ("\t4 - Sair do sistema. \n\n");
		printf("Op��o: ");
		scanf("%d", &opcao); // "%d" usado para receber oque usu�rio digitou e "&opcao" usado para armazenar o valor na variavel "opcao"
		system("cls"); // usado para limpar a tela
		
		switch (opcao) // Inicio da sele��o de menu
		{
			case 1:
			registro(); // chamada de fun��o
			break;
				
			case 2:
			consulta(); // chamada de fun��o
			break;
				
			case 3:
			deletar(); // chamada de fun��o
			break;
				
			case 4:
			printf ("\nObrigado por utilizar o sistema. \n");
			return 0;
			break;
				
			default:
			printf ("Op��o n�o est� disponivel \n\n");
			system ("pause");
			break;
		} //fim da sele��o
	}
}
