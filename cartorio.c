#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string


int registro() //Função responsavel por cadastrar os usuários no sistema				
{
	   //Início ciração de variáveis/string
	   char arquivo[40];
       char cpf[40];
       char nome[40];
       char sobrenome[40];
       char cargo[40];
       //Final da criação das variáveis
       
       printf("\tDigite seu CPF a ser cadastrado: "); //Coletando informações 
       scanf("%s", cpf); //%s refere-se a string
       
       strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
       
       FILE *file; //Criar o arquivo
       file = fopen(arquivo, "w"); //Cria o arquivo
       fprintf(file,cpf); //Salvo o valor da variavel
       fclose(file); //Fecha o arquivo
       
       file = fopen(arquivo, "a"); //Abrir um arquivo para leitura
       fprintf(file,",");
       fclose(file);
       
       printf("\tDigite o nome a ser cadastrado: ");
       scanf("%s",nome);
       
       file = fopen(arquivo, "a");
       fprintf(file,nome);
       fclose(file);
       
       file = fopen(arquivo, "a");
       fprintf(file,",");
       fclose(file);
       
       printf("\tDigite o sobrenome a ser cadastrado: ");
       scanf("%s",sobrenome);
       
       file = fopen(arquivo, "a");
       fprintf(file,sobrenome);
       fclose(file);
       
       file = fopen(arquivo, "a");
       fprintf(file,",");
       fclose(file);
       
       
       printf("\tDigite o cargo a ser cadastrado: ");
       scanf("%s",cargo);
       
       file = fopen(arquivo, "a");
       fprintf(file,cargo);
       fclose(file);
       
       system("pause");
            
}

int consulta() //Função responsavel para consultar o registro
{
       char cpf[40];
       char conteudo[200];
       
       printf("Digite o CPF a ser consultado: ");
       scanf("%s",cpf);
       
       FILE *file;
       file = fopen(cpf,"r"); //"r" para ler o cpf do usuário
       
       if(file == NULL)
       {
            printf("Arquivo não localizado!\n");    
	   }
       
       while(fgets(conteudo, 200, file) != NULL)
       {
       	    printf("\nEssas são as informações do usuário: ");
       	    printf("%s", conteudo);
        	printf("\n\n");
	   }
	   
	   system("pause");
       
       
       
}

int deletar() //Função responsavel por deletar informação do usuário
{
       char cpf[40];
       
       printf("\t\tDigite o CPF para deletar: ");
       scanf("%s",cpf);
       
       remove(cpf);
       
       FILE *file;
       file = fopen(cpf,"r");
       
       if(file == NULL)
       {
       	    printf("\t\tO usuário não se encontra no sistema!.\n");
       	    system("pause");
	   }
}





int main()
{
	int opcao=0; //Definindo variáveis
	int abraco=1;
	
	for(abraco=1;abraco=1;)
	{
	    system("cls");	
	
        setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 
	
    	printf("\t\t\t\t\t\t### Cartório Eleitoral ### \n\n");//Inicio do Menu
    	printf("\tEscolha a opção desejada abaixo:\n\n");
    	printf("\t\t1 - Registrar nomes\n");
    	printf("\t\t2 - Consultar nomes\n");
    	printf("\t\t3 - Deletar nomes\n\n"); //Fim do Menu
    	printf("\t\t4 - Sair do sistema\n\n");
    	printf("\tColoque a numeração da opção desejada:"); //Visual para o usuário
	
    	scanf("%d" ,&opcao); //Armazenando escolhas do usuário
	
    	system("cls"); //Responsavel por limpar a tela
	
	switch(opcao) //Início de seleção 
	{
		case 1:
		registro();	//Chamada de funções 
	    break;
	    
	    case 2:
	    consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		case 4:
		printf("obrigado por utilizar o sistema!\n");
		return 0;
		break;	
		
		default:
		printf("\t\t\t\t\t\t*Essa opção não está disponível!*\n");
		system("pause");	
	    break;
	} //Fim de seleção
	
    
	
}
}
