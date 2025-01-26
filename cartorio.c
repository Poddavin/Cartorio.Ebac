#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string


int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema				
{
	   //In�cio cira��o de vari�veis/string
	   char arquivo[40];
       char cpf[40];
       char nome[40];
       char sobrenome[40];
       char cargo[40];
       //Final da cria��o das vari�veis
       
       printf("\tDigite seu CPF a ser cadastrado: "); //Coletando informa��es 
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

int consulta() //Fun��o responsavel para consultar o registro
{
       char cpf[40];
       char conteudo[200];
       
       printf("Digite o CPF a ser consultado: ");
       scanf("%s",cpf);
       
       FILE *file;
       file = fopen(cpf,"r"); //"r" para ler o cpf do usu�rio
       
       if(file == NULL)
       {
            printf("Arquivo n�o localizado!\n");    
	   }
       
       while(fgets(conteudo, 200, file) != NULL)
       {
       	    printf("\nEssas s�o as informa��es do usu�rio: ");
       	    printf("%s", conteudo);
        	printf("\n\n");
	   }
	   
	   system("pause");
       
       
       
}

int deletar() //Fun��o responsavel por deletar informa��o do usu�rio
{
       char cpf[40];
       
       printf("\t\tDigite o CPF para deletar: ");
       scanf("%s",cpf);
       
       remove(cpf);
       
       FILE *file;
       file = fopen(cpf,"r");
       
       if(file == NULL)
       {
       	    printf("\t\tO usu�rio n�o se encontra no sistema!.\n");
       	    system("pause");
	   }
}





int main()
{
	int opcao=0; //Definindo vari�veis
	int abraco=1;
	
	for(abraco=1;abraco=1;)
	{
	    system("cls");	
	
        setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 
	
    	printf("\t\t\t\t\t\t### Cart�rio Eleitoral ### \n\n");//Inicio do Menu
    	printf("\tEscolha a op��o desejada abaixo:\n\n");
    	printf("\t\t1 - Registrar nomes\n");
    	printf("\t\t2 - Consultar nomes\n");
    	printf("\t\t3 - Deletar nomes\n\n"); //Fim do Menu
    	printf("\t\t4 - Sair do sistema\n\n");
    	printf("\tColoque a numera��o da op��o desejada:"); //Visual para o usu�rio
	
    	scanf("%d" ,&opcao); //Armazenando escolhas do usu�rio
	
    	system("cls"); //Responsavel por limpar a tela
	
	switch(opcao) //In�cio de sele��o 
	{
		case 1:
		registro();	//Chamada de fun��es 
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
		printf("\t\t\t\t\t\t*Essa op��o n�o est� dispon�vel!*\n");
		system("pause");	
	    break;
	} //Fim de sele��o
	
    
	
}
}
