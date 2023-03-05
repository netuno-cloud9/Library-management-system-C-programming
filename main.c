#include <stdio.h> 
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 
#include<locale.h> 
#include <unistd.h> 
#include <time.h> 

#define DEFAULT_PWD "iliad\n"
#define ADMIN_FPATH "restrito.txt"
#define RENTS_FPATH "Empréstimos.txt"
#define ACCOUNTS_FPATH "usuários.txt"
#define BOOKS_FPATH "livros.txt"
#define TEMPF_PATH "temp.tmp"
#define MAX_LEN 1024
#define MAX_PWDSIZE sizeof(DEFAULT_PWD)
#define MAX_RENTSNUM 30
#define MAX_ACCOUNTSNUM 10
#define MAX_BOOKSNUM 20

void new_user(void); 
void addRent(void);
void removeRent(void);
void showRent(void);
void removeAccounts(void);
void showAccounts(void);
void addBooks(void);
void removeBooks(void);
void showBooks(void);
void changePwd(void);
void loadAnima(); 
void vermelho (void);
void bege (void);
void branco (void);
void ciano(void);
void roxo (void);
void verde (void);
void azul (void);
void laranja (void);

int login()
{
    char pwdIn_file[MAX_LEN] = {'\0'};
    char inputPwd[MAX_LEN] = {'\0'};
    verde();
    printf("\nDigite a senha : ");
    int c = 0, ch;
    while ((ch = getch()) != '\r') {
        if (ch == '\b') {
            if (c > 0) {
                printf("\b \b");
                c--;
            }
        } else {
            inputPwd[c++] = ch;
	    ciano();
            printf("*");
        }
    }
    inputPwd[c] = '\0';

    FILE* pAdmin;
    if ((pAdmin = fopen(ADMIN_FPATH, "r")) == NULL || fgets(pwdIn_file, MAX_LEN, pAdmin) == NULL) {
        fclose(pAdmin);

        pAdmin = fopen(ADMIN_FPATH, "w");
        fprintf(pAdmin, DEFAULT_PWD); 
        fclose(pAdmin);

        pAdmin = fopen(ADMIN_FPATH, "r");
        fgets(pwdIn_file, MAX_LEN, pAdmin);
    } else {
        fclose(pAdmin);
    }

    char* newline = strchr(pwdIn_file, '\n');
    if (newline != NULL) {
        *newline = '\0';
    }

    if (strcmp(pwdIn_file, inputPwd) != 0) {
        vermelho();
        printf("\nAcesso Negado! Verifique os dados e tente Novamente");
        login();
    } else {
        return 1;
    }
};

void print_quote() {
 
     char *quotes[] = {
					  "Um livro é um sonho que você segura com as mãos. - Neil Gaiman",
					    
					  "Livros não mudam o mundo, quem muda o mundo são as pessoas. Os livros só mudam as pessoas. - Mário Quintana",
					
					  "Os livros não mudam o mundo, quem muda o mundo são as pessoas. Os livros só mudam as pessoas. - José Saramago",
						
					  "O livro é uma extensão da memória e da imaginação humana.- Jorge Luis Borges",
						
					  "Ler é viajar, é conhecer novos mundos, novas realidades, novas formas de pensar e de sentir. - Mia Couto",
						
				          "A leitura é uma fonte inesgotável de prazer, mas, por incrível que pareça, a quase totalidade não sente esta sede. - Carlos Drummond de Andrade",
						
					  "Livros são os mais silenciosos e constantes amigos; os mais acessíveis e sábios conselheiros; e os mais pacientes professores. - Charles W. Eliot",
						
					  "Ler é como viajar sem sair do lugar. É ver, sentir e experimentar o mundo através das palavras. - Cecília Meireles",
						
					  "Livros são tesouros que enriquecem a alma, a mente e o coração. - Rubem Alves",
						
					  "O livro é um objeto mágico capaz de mudar nossas vidas e nos transportar para outros universos. - José Eduardo Agualusa",

  };

char *colors[] = {
				    "\033[35m",
				    "\033[0;31m", 
				    "\033[0;32m", 
				    "\033[0;33m", 
				    "\033[0;34m", 
				    "\033[0;35m", 
				    "\033[0;36m", 
				    "\033[0;37m", 
				    
  };

  int num_quotes = sizeof(quotes) / sizeof(quotes[0]);
  int num_colors = sizeof(colors) / sizeof(colors[0]);
  int index = rand() % num_quotes;
  int color_index = rand() % num_colors;
  
  printf("\n\n\t\t%s%s\033[0m\n", colors[color_index], quotes[index]);

}

void first_login(){
	
    srand(time(NULL));
	puts("");
	branco();
        printf("\t\t\t\t\t\t\t\t\t\t\t\t B");branco();printf("E" );ciano();printf("M" );roxo();printf(" " );
        printf("V");vermelho();printf("I");azul();printf("N");verde();printf("D");laranja();printf("O");
				printf("!\n");branco();
												
	puts("");			
        bege();
        printf("\t\t\t\t\t\t\t                           .--. .-...-.             .---.\n");
        branco();
	printf("\t\t\t\t\t\t\t                       .---|__||       |    .-.     |~~~|\n");
	bege();
	printf("\t\t\t\t\t\t\t                    .--|===|--||*******|    |_|     |~~~|--.\n");
	printf("\t\t\t\t\t\t\t                    |--|===|  ||*******|.---!~|...--|WAR|--|\n");
	branco();
	printf("\t\t\t\t\t\t\t                    |  |$$$|  ||       ||===| |--|  |ON |  |\n");
	printf("\t\t\t\t\t\t\t                    |  |   |  ||Art of ||   | |__|  |DRU|  |\n");
	printf("\t\t\t\t\t\t\t                    |  |   |  || Code *||===| |==|  | GS|++|\n");
	bege();
	printf("\t\t\t\t\t\t\t                    |  |   |__||_______||   |_|  |  |~~~|__|\n");
	printf("\t\t\t\t\t\t\t                    |--|===|--||       ||===|~|--|  |~~~|--|\n");
	branco();
	printf("\t\t\t\t\t\t\t                    `--^---'--'----------^-^--^--^---'--'---\n");	
        print_quote();
	
    if(login() == 0) return;
        puts("");
        loadAnima();  
}

int checkFile(FILE *pFile, char fPath[]);
int login(void);
int isA_validIc(char ic[]); 
int amountOf_inFile(FILE *pFile, char fPath[]);
char *removeSpecial_chars(char string[]);

FILE 
*pAdmin, 
*pRents,
*pAccounts,
*pBooks,
*pTemp;

struct rgAgora {
int dia, mes, ano;
int h, m, s;
};

typedef struct rentsInfo{
    char name[40],ic[10],
    title[40];
    int amountOf_daysRented; 
    float totalTo_pay;
} rent;

typedef struct accountsInfo{
    char name[40], ic[10], email[80], mobile[80];
    int amountOf_rents;
    float moneyTo_pay;
} account;

typedef struct booksInfo{
    char 
    title[40], 
    author[40],
    genres[15],
    date[12];
    float rentValue_perDay;
} book;

void head(){
    printf("\n\n");
    printf("\033[36m\t\t\t\t\t                                        \n");
    printf("\t\t\t\t\t                                              )\\ )        )      \n");
    printf("\t\t\t\t\t                                             (()/( (   ( /(  \n");
    printf("\t\t\t\t\t                                             (_)))\\  )\\())   \n");
    printf("\t\t\t\t\t                                             (_)) ((_)((_) ) \n");
    printf("\t\t\t\t\t                                             | |   (_)| |(_) \n");
    printf("\t\t\t\t\t                                             | |   (_)| |(_) \n");
    printf("\t\t\t\t\t                                             | |__ | || '_ \\ \n");
    printf("\t\t\t\t\t                                             |____||_||_.__/ \n");
    printf("\033[0m\n\n");
 
    printf("\033[1;32m\t\t\t\t\t\t\t              Sistema de gerenciamento de livros\n");
    printf("\t\t\t\t\t\t\t\t\t\t   Desenvolvido por Paulo Victor\n");
    printf("\033[0m\n\n");
    laranja();
    printf("\t\t\t\t\t\t\t              Contato: paulo95@ba.estudante.senai.br\n");
    printf("\n\n");
    verde();
    printf("\033[0;37m\t\t\t\t\t\t\t\t             Aperte [ENTER] p/ continuar... \033[0m");
    
    puts("");
    getchar();
};

int main(void){
    system("color 1");
    setlocale(LC_ALL,"portuguese");  
    int back, diadev, mesdev, anodev; 
    int option1, option2;
    bool backToOption1 = false;
    first_login();	
    head();    
    azul();
    puts("");
    bege(); 
    puts("");
    bege();
    do{
	
	
    printf("\n\t\t\t\t\t\t\t\t\t  ______________________________________ \n");
    ciano();
    printf("\n\t\t\t\t\t\t\t\t\t ¦         [*] MENU PRINCIPAL [*]       ¦\n");
    bege();
    printf("\n\t\t\t\t\t\t\t\t\t ¦--------------------------------------¦\n");
    printf("\n\t\t\t\t\t\t\t\t\t ¦ [1] Cadastrar novo cliente           ¦\n");
    printf("\n\t\t\t\t\t\t\t\t\t ¦ [2] Alugar livro                     ¦\n");
    printf("\n\t\t\t\t\t\t\t\t\t ¦ [3] Adicionar novo exemplar          ¦\n");
    printf("\n\t\t\t\t\t\t\t\t\t ¦ [4] Remover cadastro                 ¦\n");
    printf("\n\t\t\t\t\t\t\t\t\t ¦ [5] Remover exemplar                 ¦\n");
    printf("\n\t\t\t\t\t\t\t\t\t ¦ [6] Devolução de Exemplar            ¦\n");
    printf("\n\t\t\t\t\t\t\t\t\t ¦ [7] Exibir dados                     ¦\n");
    printf("\n\t\t\t\t\t\t\t\t\t ¦ [8] Configurações                    ¦\n");
    printf("\n\t\t\t\t\t\t\t\t\t ¦ [9] Encerrar sessão                  ¦\n");
    printf("\n\t\t\t\t\t\t\t\t\t  ______________________________________ \n");

   	
   	scanf("%d", &option1);
   	fflush(stdin);
	switch(option1){
	
   
                          case 1:	    
        new_user();
                          break;						    
                          case 2 :
        addRent();
     	                  break;     	                  
                          case 3 :
        addBooks();
     	                  break;     	                  
                          case 4 :
        removeAccounts();                  	
     	                  break;     	                  
                          case 5 :
        removeBooks();                  	
     	                  break;                          	  
                          case 6 :
        removeRent();                  	
                       	  break; 	  
                          case 7: {
													    								  
                                    while (!backToOption1){									    								                               
                                    printf("\n\t\t\t\t\t\t\t\t\t   ______________________________________ \n");
                                    ciano();
								    printf("\n\t\t\t\t\t\t\t\t\t           [*] MENU SECUNDÁRIO [*]        \n");
								    bege();
								    printf("\n\t\t\t\t\t\t\t\t\t ¦---------------------------------------¦\n");
								    printf("\n\t\t\t\t\t\t\t\t\t ¦ [1] Exibir detalhes de aluguel        ¦\n");
								    printf("\n\t\t\t\t\t\t\t\t\t ¦ [2] Exibir detalhes de contas         ¦\n");
								    printf("\n\t\t\t\t\t\t\t\t\t ¦ [3] Exibir detalhes de exemplares     ¦\n");
								    printf("\n\t\t\t\t\t\t\t\t\t ¦ [4] Retornar p/ menu principal        ¦\n");
								    printf("\n\t\t\t\t\t\t\t\t\t ¦---------------------------------------¦\n");
								    printf("\n\t\t\t\t\t\t\t\t\t         ***Escolha uma operação***       \n");
			                                            printf("\n\t\t\t\t\t\t\t\t\t  ______________________________________  \n");
								    scanf("%d",&option2);
								    fflush(stdin);
							            switch(option2){
										                      case 1:
	    
													        showRent();
													                          break;																			    
													                          case 2 :
													        showAccounts();
													     	                  break;													     	                  
													                          case 3 :
													        showBooks();
													     	                  break;													     	                  
													                          case 4 :
													                          														         
													 	printf("\nRetornando.. ");                	
														backToOption1 = true; 
														  	  
															          break;
															              	  
													                       	  default:
                                                                                                                printf("\nOpção Inválida");
                                                                          }
                                                                             
                                                         }
               
        system("timeout 2");
   	backToOption1 = false;                  	
}
                          break;
						  case 8:
        changePwd(); 	  
     	                  break;
                          case 9 :
                     	
		system("color 9e");
		printf("\n\n\t\t\t\t-------------<<<SAINDO>>>-------------\n\n");
		puts("Até Logo..");                              
		system("timeout 1");
		exit(0);                  			           
                                                  default:
                                                  printf("\nOpção Inválida");
                                                                          	   	      
}
     
  }while(option1!=9);  

}

int checkFile(FILE *pFile, char fPath[]){
    char buffer[1024] = {'\0'};
    char *firstLine; 

    pFile = fopen(fPath, "r");
    firstLine = fgets(buffer, 1024, pFile); 
    fclose(pFile);

    if(pFile == NULL){
        pFile = fopen(fPath, "w"); 
        fclose(pFile);

        return -1;
    }
	else if(firstLine == NULL){
        return 0; 
    }
    else{
        return 1;
    }
}

int isA_validIc(char ic[]){
    account existingAccount;

    if(checkFile(pAccounts, ACCOUNTS_FPATH) != -1){
        pAccounts = fopen(ACCOUNTS_FPATH, "r");

        while(fscanf(pAccounts, "%s %s %d %f", &existingAccount.name, &existingAccount.ic,&existingAccount.amountOf_rents, &existingAccount.moneyTo_pay) != EOF){
            if(strcmp(ic, existingAccount.ic) == 0){
                fclose(pAccounts);
                return 0;
            }   
        }

        fclose(pAccounts);
        return 1;
    }

    return 0;
}

int amountOf_inFile(FILE *pFile, char fPath[]){
    int amountOf_lines = 0;
    char line[MAX_LEN] = {'\0'};

    if(checkFile(pFile, fPath) == 1){
        pFile = fopen(fPath, "r");

    while(fgets(line, MAX_LEN, pFile) != NULL)
    amountOf_lines++;
    fclose(pFile);
    }

    return amountOf_lines;
}

char *removeSpecial_chars(char string[]){
    if(strchr(string, '\n') == NULL){
       char extraChar;
       while((extraChar = fgetc(stdin)) != '\n' && extraChar != EOF);
    }

    for(int i = 0; i < strlen(string) - 1; i++){
        if(string[i] == ' ')
        string[i] = '-';
    }

    string[strlen(string) - 1] = '\0';
    return string;
}    

void new_user(void){
	int idade;
    account newAccount;

    system("cls");

    if(amountOf_inFile(pAccounts, ACCOUNTS_FPATH) == MAX_ACCOUNTSNUM){
        printf("\n\n Limite Máximo Atingido !(%d)", MAX_ACCOUNTSNUM);
        return;
    }

    printf("\nInforme a idade : ");
    scanf("%i",&idade);
    fflush(stdin);
    
    if(idade >= 18){
      
    printf("\nInforme um nome de usuário ");
    fgets(newAccount.name, sizeof(newAccount.name), stdin);
    strcpy(newAccount.name, removeSpecial_chars(newAccount.name));  

    printf("\nInforme o nº RG ou CPF ");
    fgets(newAccount.ic, sizeof(newAccount.ic), stdin);
    strcpy(newAccount.ic, removeSpecial_chars(newAccount.ic));
    
    printf("\nInforme o email p/ contato ");
    fgets(newAccount.email, sizeof(newAccount.email), stdin);
    strcpy(newAccount.email, removeSpecial_chars(newAccount.email));

    if(isA_validIc(newAccount.ic) != 1){
        printf("\nErro! Documento já cadastrado!");
        return;
    }

    newAccount.amountOf_rents = 0; 
    newAccount.moneyTo_pay = 0;
    checkFile(pAccounts, ACCOUNTS_FPATH); 
    pAccounts = fopen(ACCOUNTS_FPATH, "a");
    fprintf(pAccounts, "%s %s %d %.2f\n", newAccount.name, newAccount.ic, newAccount.email,
    newAccount.amountOf_rents, newAccount.moneyTo_pay);
    fclose(pAccounts);
    printf("\nRealizado com sucesso!!");

}else{
       	       vermelho();
               printf("Você é menor de idade\n");
               branco();
               system("timeout 3");
               exit(0);
  	       }
  	   }

void addRent(void){
    int diadev, mesdev, anodev; 
	struct tm tempo;
    time_t tempoSeg;
    time(&tempoSeg);
    tempo = *localtime(&tempoSeg);

    struct rgAgora agora;
    agora.dia = tempo.tm_mday;
    agora.mes = tempo.tm_mon + 1;
    agora.ano = tempo.tm_year + 1900;
    agora.h = tempo.tm_hour;
    agora.m = tempo.tm_min;
    agora.s = tempo.tm_sec;   
    
    char ds[7][4] = {"dom", "seg", "ter", "qua", "qui", "sex", "sab"};
    
    rent newRent;
    account accountList;
    book bookList;

    int lineCounter = 0, accountNum_toRent = 0, bookNum_toRent = 0;
    char numInput[MAX_LEN] = {'\0'};

    system("cls");
    printf("\n\t\t\t\t\tEscolha um cliente");
    
    printf("\n\t\t\t************************************************");

    if (checkFile(pAccounts, ACCOUNTS_FPATH) != 1 || checkFile(pBooks, BOOKS_FPATH) != 1){
        printf("\n\nERRO! Cadastre um exemplar e/ou cliente !");
        return;
    }

    if(amountOf_inFile(pRents, RENTS_FPATH) == MAX_RENTSNUM){
        printf("\n\nLimite Máximo de Alugueis Atingido! (%d)", MAX_RENTSNUM);
        return;
    }

    pAccounts = fopen(ACCOUNTS_FPATH, "r");
    while(fscanf(pAccounts, "%s %s %d %f", &accountList.name, &accountList.ic, &accountList.amountOf_rents, &accountList.moneyTo_pay) != EOF){
        lineCounter++; 
        printf("\n\n\t\t\t\t%d) Nome: %s - Documento id: %s", lineCounter, accountList.name, 
        accountList.ic,accountList.email);
    }
    fclose(pAccounts);

    printf("\n\n Informe o nº do cliente que deseja alugar um exemplar: "); 
    fgets(numInput, MAX_LEN, stdin);
    if((accountNum_toRent = atoi(numInput)) == 0 || accountNum_toRent > lineCounter){
        printf("\nOpção Inválida!");
        return;
    }
  
    system("cls");
    printf("\n\t\t\t\t\tSelecione um exemplar");
    printf("\n\t\t\t________________________________________________");

    if(checkFile(pBooks, BOOKS_FPATH) != 1){
        printf("\nError!");
        return;
    }

    pBooks = fopen(BOOKS_FPATH, "r");
    lineCounter = 0;
    while(fscanf(pBooks, "%s %s %s %s %f", &bookList.title, &bookList.author, &bookList.genres, &bookList.date, &bookList.rentValue_perDay) != EOF){
        lineCounter++;        
        printf("\n\n\t\t%d) Título: %s - Autor: %s - Preço: R$%.2f", 
        lineCounter, bookList.title, bookList.author, bookList.rentValue_perDay);    
    }    
    fclose(pBooks);

    printf("\n\nInforme o nº do exemplar "); 
    fgets(numInput, MAX_LEN, stdin);
    if((bookNum_toRent = atoi(numInput)) == 0 || bookNum_toRent > lineCounter){
        printf("\nOpção Inválida!");
        return;
    }
  
    system("cls");
    printf("\n\t\t\t\t\tQuantidade de dias");
    printf("\n\t\t\t________________________________________________");

    printf("\n\nInforme a quantidade de dias que deseja alugar: ");
    fgets(numInput, MAX_LEN, stdin);
    if((newRent.amountOf_daysRented = atoi(numInput)) == 0){
        printf("\nOpção Inválida!");
        return;
    }

    if(checkFile(pAccounts, ACCOUNTS_FPATH) != 1 || checkFile(pBooks, BOOKS_FPATH) != 1 ){
        printf("\n\nError!");
        return;
    }

    pAccounts = fopen(ACCOUNTS_FPATH, "r");
    lineCounter = 0; 
    while(fscanf(pAccounts, "%s %s %d %f", &accountList.name, &accountList.ic, &accountList.amountOf_rents, &accountList.moneyTo_pay) != EOF){
        lineCounter++; 

        if(lineCounter == accountNum_toRent){
            strcpy(newRent.name, accountList.name);
            strcpy(newRent.ic, accountList.ic);
        }
    }
    fclose(pAccounts);

    pBooks = fopen(BOOKS_FPATH, "r");
    lineCounter = 0;
    while ( fscanf( pBooks, "%s %s %s %s %f", &bookList.title, &bookList.author, & bookList.genres, &bookList.date, &bookList.rentValue_perDay) != EOF){
        lineCounter++;      
        if(lineCounter == bookNum_toRent){
            strcpy(newRent.title, bookList.title);
            newRent.totalTo_pay = bookList.rentValue_perDay * newRent.amountOf_daysRented;
        }  
    }    
    fclose(pBooks);

    checkFile(pRents, RENTS_FPATH); 
    pRents = fopen(RENTS_FPATH, "a");
    fprintf(pRents, "%s %s %s %d %.2f\n", newRent.name, newRent.ic, newRent.title, 
    newRent.amountOf_daysRented, newRent.totalTo_pay);
    fclose(pRents);

    pAccounts = fopen(ACCOUNTS_FPATH, "r");
    pTemp = fopen(TEMPF_PATH, "w"); 
    lineCounter = 0; 

    while(fscanf(pAccounts, "%s %s %d %f", &accountList.name, &accountList.ic, &accountList.amountOf_rents, &accountList.moneyTo_pay) != EOF){
        lineCounter++; 
        if(lineCounter == accountNum_toRent){
            fprintf(pTemp, "%s %s %d %.2f\n", accountList.name, accountList.ic, 
            accountList.amountOf_rents + 1, accountList.moneyTo_pay + newRent.totalTo_pay);
        }
        else{
            fprintf(pTemp, "%s %s %d %.2f\n", accountList.name, accountList.ic, 
            accountList.amountOf_rents, accountList.moneyTo_pay);
        }
    }
                 			       
    fclose(pAccounts);
    fclose(pTemp);

    remove(ACCOUNTS_FPATH);
    rename(TEMPF_PATH, ACCOUNTS_FPATH);
    
        printf("\n\n\t\t\t\t ---------------------- RECIBO --------------------- \n\n");	                     						 
   	    printf("Data do empréstimo : %02d/%02d/%d (%s) as %02d:%02d:%02d horas.\n", agora.dia, agora.mes, agora.ano, ds[tempo.tm_wday], agora.h, agora.m, agora.s);
        printf("______________________________________________________________________");	
		printf("\nRealizado com sucesso!"); 
       
}

void addBooks(void){
    book newBook_toAdd;
    char inputStr[MAX_LEN] = {'\0'};

    system("cls");
    printf("\n\t\t\t\t\t  Adicionando Exemplares");
    printf("\n\t\t\t________________________________________________");

    if(amountOf_inFile(pBooks, BOOKS_FPATH) == MAX_BOOKSNUM){
        printf("\n\nLimite máximo de livros atingido ! (%d)", MAX_BOOKSNUM);
        return;
    }
     
    printf("\n\nInforme o Título do livro: ");
    fgets(newBook_toAdd.title, sizeof(newBook_toAdd.title), stdin);
    strcpy(newBook_toAdd.title, removeSpecial_chars(newBook_toAdd.title));
    strupr(newBook_toAdd.title); 

    printf("\nInforme o Autor : ");
    fgets(newBook_toAdd.author, sizeof(newBook_toAdd.author), stdin);
    strcpy(newBook_toAdd.author, removeSpecial_chars(newBook_toAdd.author));
    strupr(newBook_toAdd.author);
    
    printf("\nInforme o gênero: ");
    fgets(newBook_toAdd.genres, sizeof(newBook_toAdd.genres), stdin);
    strcpy(newBook_toAdd.genres, removeSpecial_chars(newBook_toAdd.genres));
    strupr(newBook_toAdd.genres);

    printf("\nInforme a data de lançamento (dd/mm/yyy): ");
    fgets(newBook_toAdd.date, sizeof(newBook_toAdd.date), stdin);
    strcpy(newBook_toAdd.date, removeSpecial_chars(newBook_toAdd.date));
    strupr(newBook_toAdd.date);
    
    printf("\nInforme o valor da diária: R$");
    fgets(inputStr, MAX_LEN, stdin);
    if((newBook_toAdd.rentValue_perDay = atof(inputStr)) <= 0)
    {
        printf("\nInvalid Input!");
        return;
    }

    checkFile(pBooks, BOOKS_FPATH); 
    pBooks = fopen(BOOKS_FPATH, "a");
    fprintf(pBooks, "%s %s %s %s %.2f\n", newBook_toAdd.title, newBook_toAdd.author, 
    newBook_toAdd.genres, newBook_toAdd.date, newBook_toAdd.rentValue_perDay);
    fclose(pBooks);

    printf("\nAdicionado com sucesso!");
}

void removeRent(void){
    rent inFile;
    account accountIn_file;

    int lineCounter = 0, rentNum_toDelete = 0;
    char numInput[MAX_LEN] = {'\0'}, accountIc_toUpdte[10] = {'\0'};
    float accountMoney_toUpdte = 0; 

    system("cls");
    printf("\n\t\t\t\t\t   Efetuar devolução");
    printf("\n\t\t\t________________________________________________");
    
    if(checkFile(pRents, RENTS_FPATH) != 1){
        printf("\n\nNada por aqui..");
        return;
    }

    pRents = fopen(RENTS_FPATH, "r");
    while(fscanf(pRents, "%s %s %s %d %f", &inFile.name, &inFile.ic, &inFile.title, &inFile.amountOf_daysRented, &inFile.totalTo_pay) != EOF){
        lineCounter++;
        printf("\n\n\t\t%d) Name: %s - IC: %s - Título: %s", lineCounter, inFile.name, 
        inFile.ic, inFile.title);
    }
    fclose(pRents);

    printf("\n\nInforme um n de aluguel ");
    fgets(numInput, MAX_LEN, stdin);
    if((rentNum_toDelete = atoi(numInput)) == 0 || rentNum_toDelete > lineCounter){
        printf("\nOpção inválida!");
        return;
    }

    if(checkFile(pRents, RENTS_FPATH) != 1){
        printf("\nError!!");
        return;
    }

    pRents = fopen(RENTS_FPATH, "r");
    pTemp = fopen(TEMPF_PATH, "w");
    lineCounter = 0; 

    while(fscanf(pRents, "%s %s %s %d %f", &inFile.name, &inFile.ic, &inFile.title, &inFile.amountOf_daysRented, &inFile.totalTo_pay) != EOF){
        lineCounter++; 
        
        if(lineCounter != rentNum_toDelete){   
            fprintf(pTemp, "%s %s %s %d %.2f\n", inFile.name, inFile.ic, inFile.title, 
            inFile.amountOf_daysRented, inFile.totalTo_pay);
        } else{
            strcpy(accountIc_toUpdte, inFile.ic);
            accountMoney_toUpdte = inFile.totalTo_pay;
        }
    }    

    fclose(pRents);
    fclose(pTemp);

    remove(RENTS_FPATH);
    rename(TEMPF_PATH, RENTS_FPATH);

    pAccounts = fopen(ACCOUNTS_FPATH, "r");
    pTemp = fopen(TEMPF_PATH, "w");

    while(fscanf(pAccounts, "%s %s %d %f", &accountIn_file.name, &accountIn_file.ic, &accountIn_file.amountOf_rents, &accountIn_file.moneyTo_pay) != EOF){
        
        if(strcmp(accountIc_toUpdte, accountIn_file.ic) == 0){
            fprintf(pTemp, "%s %s %d %.2f\n", accountIn_file.name, accountIn_file.ic, 
            accountIn_file.amountOf_rents - 1, 
            accountIn_file.moneyTo_pay - accountMoney_toUpdte);
        } else{
            fprintf(pTemp, "%s %s %d %.2f\n", accountIn_file.name, accountIn_file.ic, 
            accountIn_file.amountOf_rents, accountIn_file.moneyTo_pay);
        }
    }

    fclose(pAccounts);
    fclose(pTemp);

    remove(ACCOUNTS_FPATH);
    rename(TEMPF_PATH, ACCOUNTS_FPATH);

    printf("\nRealizado com sucesso!");
}

void showRent(void){
    rent inFile;
    int lineCounter = 0;
    int diadev, mesdev, anodev; 
    char ds[7][4] = {"dom", "seg", "ter", "qua", "qui", "sex", "sab"};
    
    struct tm tempo;
    time_t tempoSeg;
    time(&tempoSeg);
    tempo = *localtime(&tempoSeg);

    struct rgAgora agora;
    agora.dia = tempo.tm_mday;
    agora.mes = tempo.tm_mon + 1;
    agora.ano = tempo.tm_year + 1900;
    agora.h = tempo.tm_hour;
    agora.m = tempo.tm_min;
    agora.s = tempo.tm_sec;   

    system("cls");
    printf("\n\t\t\t\t\t       Empréstimos");
    printf("\n\t\t\t________________________________________________");

    printf("\n %02d/%02d/%d (%s) as %02d:%02d:%02d horas.\n", agora.dia, agora.mes, agora.ano, ds[tempo.tm_wday], agora.h, agora.m, agora.s);
    
    if(checkFile(pRents, RENTS_FPATH) != 1){
        printf("\n\nNada por aqui.. :/");
        return;
    }

    pRents = fopen(RENTS_FPATH, "r");
    while ( fscanf(pRents, "%s %s %s %d %f", &inFile.name, &inFile.ic, &inFile.title, &inFile.amountOf_daysRented, &inFile.totalTo_pay) != EOF ){
        lineCounter++;
    printf("\n\n\t%d) Nome: %s - Documento id: %s - Título: %s - Dias: %d - Total á pagar: R$%.2f",
    lineCounter, inFile.name, inFile.ic, inFile.title, inFile.amountOf_daysRented, 
    inFile.totalTo_pay);               
    }
    fclose(pRents);

    printf("\n\nPressione [ENTER] p/ continuar..");
    getchar();
}
    
void removeAccounts(void){
    account inFile;
    char numInput[MAX_LEN] = {'\0'};
    int lineCounter = 0, accountNum_toDelete = 0;

    system("cls");
    printf("\n\t\t\t\t\tRemova uma conta");
    
    printf("\n\t\t\t________________________________________________");

    if(checkFile(pAccounts, ACCOUNTS_FPATH) != 1){
        printf("\n\nCadastre uma conta p/ continuar..");
        return;
    }

    pAccounts = fopen(ACCOUNTS_FPATH, "r");
    while ( fscanf(pAccounts, "%s %s %d %f", &inFile.name, &inFile.ic, &inFile.amountOf_rents, &inFile.moneyTo_pay) != EOF
    )
    {
        lineCounter++; 
         printf("\n\n\t\t\t\t%d) Name: %s - Ic: %s", lineCounter, inFile.name, inFile.ic);
    }
    fclose(pAccounts);

    printf("\n\nInforme o nº da conta que deseja remover: ");
    fgets(numInput, MAX_LEN, stdin);
    if((accountNum_toDelete = atoi(numInput)) == 0 || accountNum_toDelete > lineCounter){
        printf("\nOpção Inválida!");
        return;
    }
    
    if(checkFile(pAccounts, ACCOUNTS_FPATH) != 1){
        printf("\nError!!");
        return;
    }

    pTemp = fopen(TEMPF_PATH, "w");
    pAccounts = fopen(ACCOUNTS_FPATH, "r");
    lineCounter = 0; 

    while(fscanf(pAccounts, "%s %s %d %f", &inFile.name, &inFile.ic, &inFile.amountOf_rents, &inFile.moneyTo_pay) != EOF){
        lineCounter++;
        
        if(lineCounter != accountNum_toDelete){
            fprintf(pTemp, "%s %s %d %.2f\n", inFile.name, inFile.ic, 
            inFile.amountOf_rents, inFile.moneyTo_pay);
        }
        else if(inFile.amountOf_rents != 0){
            printf("\nNão foi possível remover conta.");
            printf("\nCertifique-se de remover todos os alugueis antes de faze-lo.");
            
            fclose(pAccounts);
            fclose(pTemp);

            remove(TEMPF_PATH);
            return;
        }
    }

    fclose(pAccounts);
    fclose(pTemp); 

    remove(ACCOUNTS_FPATH);
    rename(TEMPF_PATH, ACCOUNTS_FPATH);

    printf("\nRealizado com sucesso!");
}

void showAccounts(void){
    account inFile;
    int lineCounter = 0;
    system("cls");
    printf("\n\t\t\t\t\t    Clientes");
    printf("\n\t\t\t________________________________________________");

    if(checkFile(pAccounts, ACCOUNTS_FPATH) != 1){
        printf("\n\nNão Registrado! Cadastre um novo cliente/");
        return;
    }

    pAccounts = fopen(ACCOUNTS_FPATH, "r");
    while(fscanf(pAccounts, "%s %s %d %f", &inFile.name, &inFile.ic, &inFile.amountOf_rents, &inFile.moneyTo_pay) != EOF){
        lineCounter++;

     printf("\n\n\t\t%d) Nome: %s - Documento Id: %s - Alugueis: %d - Valor Total á pagar: R$%.2f", 
     lineCounter, inFile.name, inFile.ic, inFile.amountOf_rents, inFile.moneyTo_pay);
    }
    fclose(pAccounts);
    printf("\n\nPressione [ENTER] p/ continuar...");
}

void removeBooks(void){
    book inFile;
    char numInput[MAX_LEN] = {'\0'};
    int lineCounter = 0, bookNum_toDelete = 0;

    system("cls");
    printf("\n\t\t\t\t\t Remover exemplar");
    printf("\n\t\t\t________________________________________________");

    if(checkFile(pBooks, BOOKS_FPATH) != 1){
        printf("\n\nAdicione um exemplar!!!/");
        return;
    }

    pBooks = fopen(BOOKS_FPATH, "r");
    while(fscanf(pBooks, "%s %s %s %s %f", &inFile.title, &inFile.author,&inFile.genres, &inFile.date, &inFile.rentValue_perDay) != EOF){
        lineCounter++;        
        printf("\n\n\t\t\t%d) Título: %s - Autor: %s", lineCounter, inFile.title, inFile.author);    
    }   
	
    fclose(pBooks);
    printf("\n\nInforme o n do Exemplar: ");    
    fgets(numInput, MAX_LEN, stdin);
    if((bookNum_toDelete = atoi(numInput)) == 0 || bookNum_toDelete > lineCounter){        
        printf("\nopção inválida!");        
        return;    
    }

    if(checkFile(pBooks, BOOKS_FPATH) != 1){
        printf("\nError!");
        return;
    }
  
    pBooks = fopen(BOOKS_FPATH, "r");
    pTemp = fopen(TEMPF_PATH, "w");
    lineCounter = 0; 
    while(fscanf(pBooks, "%s %s %s %s %f", &inFile.title, &inFile.author, &inFile.genres, &inFile.date, &inFile.rentValue_perDay) != EOF){
        lineCounter++; 
        
        if(lineCounter != bookNum_toDelete)       
        {   
            fprintf(pTemp, "%s %s %s %s %.2f\n",  inFile.title, inFile.author, 
            inFile.genres, inFile.date, inFile.rentValue_perDay);
        }
    }    
    fclose(pBooks);
    fclose(pTemp);
    remove(BOOKS_FPATH);
    rename(TEMPF_PATH, BOOKS_FPATH);
    printf("\nRealizado com sucesso!!");
}

void showBooks(void){
    book inFile;
    int lineCounter = 0;

    system("cls");
    printf("\n\t\t\t\t\t     Exemplares");
    printf("\n\t\t\t________________________________________________");

    if(checkFile(pBooks, BOOKS_FPATH) != 1){
        printf("\n\nAdicione um exemplar!!!/");
        return;
    }

    pBooks = fopen(BOOKS_FPATH, "r");
    while(fscanf(pBooks, "%s %s %s %s %f", &inFile.title, &inFile.author, &inFile.genres, &inFile.date, &inFile.rentValue_perDay) != EOF){
    lineCounter++;
    printf("\n\n%d) Título: %s - Autor: %s - Gênero: %s - Data: %s - Aluguel: R$%.2f", 
    lineCounter, inFile.title, inFile.author, inFile.genres, inFile.date, 
    inFile.rentValue_perDay);
    }
    fclose(pBooks);
    printf("\n\nPressione [ENTER] p/ continuar.");
}

void changePwd(void)
{
    char newPwd1[MAX_LEN], newPwd2[MAX_LEN];

    if(login() == 0) return;

    printf("\n\t\t\t\t\tAlterando a senha de acesso !");
    printf("\n\t\t\t------------------------------------------------");

    printf("\n\nNova senha de Acesso - MAX %d Characters: ", MAX_PWDSIZE - 1); 
    fgets(newPwd1, MAX_LEN, stdin);
    printf("\nDigite a senha novamente: ");
    fgets(newPwd2, MAX_LEN, stdin);

    if (strlen(newPwd1) >= MAX_PWDSIZE || strlen(newPwd2) >= MAX_PWDSIZE || strcmp(newPwd1, newPwd2) != 0){
        printf("\nOpção inválida!");
        return;
    }

    pTemp = fopen(TEMPF_PATH, "w");
    fprintf(pTemp, newPwd1);
    fclose(pTemp);
    
    remove(ADMIN_FPATH);
    rename(TEMPF_PATH, ADMIN_FPATH);

    printf("\nrealizado com sucesso!");
}

void loadAnima() {
  printf("Carregando");
  puts("");
  sleep(1);
  int i, j;

  for (i = 1; i <= 40; i++) {
    for (j = 1; j <= i; j++) {
      // Choose a random color
      int color = rand() % 6 + 1;

      switch (color) {
        case 1:
          vermelho();
          break;
        case 2:
          verde();
          break;
        case 3:
          laranja();
          break;
        case 4:
          azul();
          break;
        case 5:
          bege();
          break;
        case 6:
          roxo();
          break;
        default:
          branco();
          break;
      }
      printf("~");
      printf("* * * * * * * * ~ . ");
      branco();
      printf(".");
      azul();
      printf("_");
    }
    usleep(10000); // Pause for 500 milliseconds
    system("cls");
  }
}

void bege (void){
	
	printf("\033[1;33m");
};

void vermelho (void)
{
	printf("\033[31m");	
};

void branco (void)
{
	printf("\033[0;37m"); 	
};

void ciano (void)
{
	 printf("\033[36m");	
};

void roxo (void)
{
     printf("\033[35m");	
};

void verde (void)
{
     printf("\033[32m");	
};

void azul (void)
{
     printf("\033[34m");	
};

void laranja (void)
{
     printf("\033[33m");	
};
