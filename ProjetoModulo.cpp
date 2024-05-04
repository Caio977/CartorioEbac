#include<stdio.h> // biblioteca comunicacao com usuario
#include<stdlib.h> // biblioteca aloca�ao espa�o em memoria
#include<locale.h> //biblioteca de aloca�ao de texto por regiao
#include<string.h> //biblioteca responsavel por cuidar das strings


int registro()
{
     char arquivo[40];	//criar variavel string arquivo
	 char cpf[40]; //criar variavel string cpf
	 char nome[40]; //criar variavel sring nome
	 char sobrenome[40]; // criar variavel string sobrenome
	 char cargo[40]; //criar variavel string cargo
	 
	 printf("Digite o cpf a ser cadastrado: "); //pergunta ao usuario
	 scanf("%s", cpf); //salva as informacoes q usuario digitar na string cpf
	 
	 strcpy(arquivo, cpf);//responsavel por copiar os valores da string
	 
	 FILE *file; //cria o arquivo
	 file = fopen(arquivo, "w"); //cria o arquivo w=novo
	 fprintf(file,cpf); //salvo o valor da variavel cpf
	 fclose(file); //fecha o arquivo
	 
	 file = fopen(arquivo,"a"); //incluir em um arquivo ja existente 'a'
	 fprintf(file,","); //cria a virgula entre as informa�oes
	 fclose(file); //fecha o arquivo
	 
	 printf("Digite o nome a ser cadastrado: "); //pergunta ao usuario o nome a ser cadastrado  
	 scanf("%s",nome); //salva as informa�oes na string nome
	 
	 file = fopen(arquivo,"a"); //incluir em um arquivo ja existente 'a'
	 fprintf(file,nome); // salva o valor na variavel nome
	 fclose(file); //fecha o arquivo
	 
     file = fopen(arquivo,"a"); //incluir em um arquivo ja existente 'a'
	 fprintf(file,","); //cria a virgula entre as informa�oes
	 fclose(file); //fecha o arquivo
	 
	 printf("Digite o sobrenome a ser cadastrado: "); //pergunta sobrenome a ser cadastrado
	 scanf("%s",sobrenome); //salva as informa�oes na string sobrenome
	 
	 file = fopen(arquivo,"a"); //incluir um arquivo ja existente
	 fprintf(file,sobrenome); //salva o valor na variavel sobrenome
	 fclose(file); //fecha o arquivo
	 
	 file = fopen(arquivo,"a"); //incluir um arquivo ja existente'a'
	 fprintf(file,","); // cria uma virgula
	 fclose(file); //fecha o arquivo
	 
	 printf("Digite o cargo a ser cadastrado: "); //pergunta ao usuario sobre o cargo
	 scanf("%s", cargo); // salva as informa�oes na string cargo
	 file = fopen(arquivo,"a"); // incluir em um arquivo ja existente 'a'
	 fprintf(file,cargo); // salva o valor na variavel cargo
	 fclose(file); //fecha o arquivo
	 
	 system("pause"); //pausa o sistema
}
int consulta()
{
	setlocale	(LC_ALL, "Portuguese"); //definindo a linguagem
	char cpf[40]; //criar o arquivo cpf na string
	char conteudo[200]; //criar variavel string conteudo
	
	printf("Digite o cpf a ser consultado: "); //pergunta ao usuario sobre o cpf consultado
	scanf("%s",cpf); // salva as informa�oes dentro da string cpf
	
	FILE *file; //acesse o arquivo file
	file = fopen(cpf,"r"); //abre o arquivo ja existente no modo leitura
	
	if(file == NULL) // se o cpf for inexistente
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!\n"); //msg de cpf nao localizado
	}
	while(fgets(conteudo, 200, file)!= NULL) // enquanto tiver conteudo dentro do file ele continua armazenando
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //resposta a pesquisa do usuario
		printf("%s", conteudo);  // mostra conteudo da string conteudo
		printf("\n\n");
	}
	system("pause");
	fclose(file);
}
int deletar()
{
    char cpf[40]; //string cpf
    printf("Digite o cpf do usu�rio a ser deletado: "); // msg ao usuario
    scanf("%s",cpf); // armazena o valor digitado na string
    
	FILE *file;
	file = fopen(cpf,"r"); // abrir o file no modo leitura
	fclose(file);
	
	if(file == NULL) //se cpf nao existir 
	{
		printf("O usuario n�o se encontra no sistema!\n"); // msg ao usuario
	}
	else // se existir...
	{
		remove(cpf); // remove o cpf
		printf("O usu�rio foi deletado com sucesso! \n\n"); // e manda msg de confirma��o
	}
	system("pause");
}
int main()
{
    int opcao=0; //definindo as vari�veis
    int laco=1;
	
	for(laco=1;laco=1;)//variavel la�o para sempre voltar ao menu
{
        system("cls"); //fun�ao de apagar as op�oes ap�s digitar 

    setlocale	(LC_ALL, "Portuguese"); //definindo a linguagem
    
        printf("\t###Cart�rio da EBAC###\n\n"); //inicio do menu
        printf("\tEscolha a op��o desejada no menu:\n\n");
        printf("\t1 Registrar nomes\n");
        printf("\t2 Consultar nomes\n");
        printf("\t3 Deletar nomes\n");
        printf("\t4 Sair do sistema\n\n");
        printf("Op��o: "); // escolha da op�ao e fim do menu
        
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
    
        system("cls"); //fun�ao de apagar as opcoes ap�s digitar o numero
    
    switch(opcao) // opc�ao  de decis�o switch case 
    {
    	case 1:
        registro();
		break;
		
		case 2:
	    consulta();
		break;
		
		case 3:	
		deletar();
		break;
		
		case 4:
		printf("Obrigado por utilizar o sistema!");	
		return 0;
		break;
		
		default:
		printf("Essa op��o n�o est� dispon�vel!\n"); //fim da sele�ao
	    system("pause");
	    break;
	    
	}
    
   
}
}
