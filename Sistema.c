#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <locale.h>

#define tam 1000

void menulogin();
void menuadmin();
void menualuno();
void menuacervo();

void adlivros();
void adalunos();

void editarlivro();
void excluirlivro();

void editaraluno();
void excluiraluno();

void adhistorico();

void limpar();
void aguardaEnter();
void logo();
void linha();
void tabulacao();
void ltl();
void opcaoinvalida();

char op;
int qtdl = 0, qtda = 0, qtdh = 0, ln, i = 0, c = 0, p = 0;
float custo = 0;
// livros    alunos    historico

//==========senha administraçao======

char usuarioAdmistrador[20], senhaAdministrador[9];

char usuario[20];
char senha[9]; //verificar se existe nos admins cadastrados

char nomeusuario[40], senhausuario[9]; // pertece a funcao  aluno;

//===================================
struct dadosLivros
{
	char titulo[50]; //linguagem c
	char autor[30];  //luiz damas
	char anopublicacao[6]; //97; 1997; 10; 800; 10000
	int  codigo;

	float custo; //R$ 50;

	//cadastrar informacoes
	//referentes aos livros : autor, titulo, assunto,
	//verificar se
};
struct dadosLivros dLivros[tam]; //dadoLivros;


struct dadosAlunos
{

	char nome[40], cpf[15], email[50], matricula[16],
		 usuarioAluno[16], senhaAluno[9];

};
struct dadosAlunos dAlunos[tam]; //dadosAluno


struct historico
{

	char titulolivro[50], data[12], matricula[16];

	//23/06/2018 // 23/6/18
};
struct historico hAluno[200000];  //historicoAluno

//login adimistrador
//logim aluno

int main()
{
	setlocale(LC_ALL, "Portuguese");
	ltl();
	printf("\nBEM VINDO  ADMIN :)");
	printf("\nConfigurando o sistema para primeiro uso....");
	printf("\nPor favor, a partir de agora configure um usuario e senha administrador");
	printf("\n\nNome de usuário: ");
	scanf (" %[^\n]s", usuarioAdmistrador);
	printf("\nSenha: ");
	scanf (" %[^\n]s", senhaAdministrador);

	printf("\nOlá, Bem vindo....");
	printf("Pressione enter para continuar...");
	getchar();
	getchar();

	//adlivros();
	//menulogin();
	//adalunos();

	menulogin();

	/*for(i=0; i<qtdh; i++)
	{
		linha();
		printf("%s %s %s\n", hAluno[i].titulolivro, hAluno[i].data, hAluno[i].matricula);
	}
	*/
	//adhistorico();
	//consultaMaterial();
	return 0;
}

void menulogin()
{
	do
	{

		ltl();
		printf("\n|1|-ALUNO\n\n|2|-ADMINISTRAÇÃO\n\n|3|-SOBRE\n\n|4|-SAIR\n");//adicionar
		printf("\n\n\\> ");                                                      //consultar acervo
		scanf(" %c", &op);                                                         //no menu aluno

		switch(op)
		{
		case '1':
			menualuno();
			break;
		case '2':
			menuadmin();
			break;
		case '3':
			printf("\nSistema BIBLIOTECA versão 0.0.0.1\nby João Carlos de Sousa fé com auxilio e supervisão do professor Leonardo Pereira de Sousa \n");
			aguardaEnter();
			break;
		case '4':
			break;
		default:
			opcaoinvalida();
			aguardaEnter();
		}

	}
	while(op != '4');
}

void menuadmin()
{
	//cadastrar informacoes mediante senha de acesso
	do
	{
		ltl();

		printf("\nUsuario Administrador: ");
		scanf (" %[^\n]s", usuario);

		printf("\nSenha Administrador: ");
		scanf (" %[^\n]s", senha);


		if(strcmp(senha, senhaAdministrador) != 0 || strcmp(usuario, usuarioAdmistrador) != 0)
		{
			printf("Usuario ou senha invalidos tente novamente....");
			c++;
			aguardaEnter();
		}
		else
		{
			do
			{
				c = 0;

				ltl();
				printf("\n|1|-REGISTRAR PEDIDO DE LIVRO\n\n");
				printf("|2|-ADICIONAR LIVRO (espaço alocado disponivel %d)\n|3|-EDITAR LIVRO\n|4|-REMOVER LIVRO\n", tam - qtdl);
				printf("\n|5|-ADCIONAR ALUNO NO SISTEMA (espaço alocado disponivel %d)\n|6|-EDITAR ALUNO\n|7|-REMOVER ALUNO DO SISTEMA\n\n|8|-EXIBIR TODOS OS ALUNOS\n|9|-EXIBIR TODO ACERVO\n\n|0|-SAIR\n\n", tam - qtda);
				linha();
				printf("\n\n\\> ");
				scanf(" %c", &op);

				switch(op)
				{
				case '1':
					// função adicionar Historico V
					adhistorico();

					break;

				case '2':
					// função acicionar livro V
					adlivros();
					break;

				case '3':
					//função editar livro F
					editarlivro();
					break;

				case '4':
					//função excluir livro
					excluirlivro();
					break;

				case '5':
					//função adicionar aluno
					adalunos();
					break;

				case '6':
					//função editar aluno
					editaraluno();
					break;

				case '7':
					// remover/desutorizar aluno
					excluiraluno();
					break;

				case '8':
					if (qtda == 0)
					{
						printf("\nNenhum aluno registrado ");
					}
					else
					{
						limpar();
						for(i = 0; i < qtda; i++)
						{
							linha();
							printf("ALUNO |%d|: %s\nCPF: %s\nE-MAIL: %s\nMATRICULA: %s\nUSUÁRIO: %s\nSENHA: %s\n", i + 1, dAlunos[i].nome, dAlunos[i].cpf, dAlunos[i].email, dAlunos[i].matricula, dAlunos[i].usuarioAluno, dAlunos[i].senhaAluno);
						}
					}
					aguardaEnter();
					break;

				case '9':
					menuacervo();
					aguardaEnter();
					break;

				case '0':
					return;

				default:
					opcaoinvalida();
					break;
				}
			}
			while(op != '0');
		}

		if(c == 3)
		{
			printf("Você Errou a senha muintas vezes. Tente novamente mais tarde...\n");
			return;//forcar sair da função. break so encerra loop ou condição;
		}

	}
	while(strcmp(senha, senhaAdministrador) != 0 || strcmp(usuario, usuarioAdmistrador) != 0);

}

void menualuno()
{

	int acheiusuario = 0, p;
	char nomeusuario[16];
	char senhausuario[9];
	c = 2;
	limpar();
	do
	{
		if(qtda == 0)
		{
			printf("Nenhum Aluno Registrado no sistema !! contate o administrador... ");
			aguardaEnter();
			break;
		}
		else
		{
			ltl();
			printf("\nMenu aluno");
			printf("\nUsuario: ");
			scanf (" %[^\n]s", nomeusuario);
			printf("\nSenha: ");
			scanf (" %[^\n]s", senhausuario);

			for(i = 0; i < qtda; i++)
			{
				if(strcmp(nomeusuario, dAlunos[i].usuarioAluno) == 0 && strcmp(senhausuario, dAlunos[i].senhaAluno) == 0)
				{
					acheiusuario = 1;
					p = i; // varivel p recebe i para verificar se o aluno atual esta disponivel no historico
					break; //compara a matricula com todo o historico e onde encontrar, é exibido aquele historico
				}
			}
			if(acheiusuario == 0)
			{
				printf("Usuário não encontrado!! tentativas restantes = %d", c);
				aguardaEnter();
			}
			else
			{
				do
				{
					ltl();
					printf("\nUSUÁRIO: %s\n", nomeusuario);
					printf("\n|1|-Exibir meus dados");
					printf("\n|2|-Historico de livros requisitados\n\n|3|-Alterar meu usuario ou senha\n|4|-Todos os livros disponiveisn\n|5|-Pesquisar livro\n\n|6|-Sair\n");
					linha();
					printf("\n\n\\> ");
					scanf(" %c", &op);

					switch(op)
					{

					case '1':
						ltl();
						
						for(i = 0; i < qtda; i++) //atualizar a opção
						{
							if(strcmp(nomeusuario, dAlunos[i].usuarioAluno) == 0 && strcmp(senhausuario, dAlunos[i].senhaAluno) == 0)
							{
								break;
							}
						}

						printf("\nNome: %s\nE-mail: %s\nCPF: %s\nMatricula: %s\n", dAlunos[i].nome, dAlunos[i].email, dAlunos[i].cpf, dAlunos[i].matricula);
						printf("Nome de usuario: %s\nSenha: %s", dAlunos[i].usuarioAluno, dAlunos[i].senhaAluno);
						aguardaEnter();
						break;

					case '2':

						limpar();
						int acheihistorico = 0;
						for(i = 0; i < qtdh; i++)
						{
							if( strcmp(dAlunos[p].matricula, hAluno[i].matricula) == 0)
							{
								acheihistorico = 1;
								break;
							}
						}

						if(acheihistorico == 1)
						{
							printf("\nMostrando todo seu historico de requisições de livros...\n");
							linha();
							for(i = 0; i < qtdh; i++)
							{
								if( strcmp(dAlunos[p].matricula, hAluno[i].matricula) == 0)
								{

									printf("\nLivro: %s. Data de requisição: %s\n", hAluno[i].titulolivro, hAluno[i].data);
									linha();
								}
							}

						}
						else
						{
							printf("Você ainda não possui nenhuma requisição de livros...");
						}
						aguardaEnter();

						break;

					case '3' : //fazer alteração dos dados fora da struct
						do
						{

							ltl();
							printf("\n|1|-Alterar meu usuario\n|2|-alterar minha senha\n|3|-Sair\n");
							linha();
							printf("\n\n\\> ");
							scanf(" %c", &op);

							switch(op)
							{
							case '1':

								printf("\nUsuario atual: %s\nDigite seu novo usuario: ", nomeusuario);
								scanf (" %[^\n]s", nomeusuario);

								strcpy(dAlunos[i].usuarioAluno, nomeusuario);
								printf("Usuário alterado com sucesso !!\nSeu novo usuário: %s \n", dAlunos[i].usuarioAluno);
								printf("\nPor favor, refassa o login ");
								aguardaEnter();
								menualuno();
								break;

							case '2':

								printf("Senha atual: %s\nDigite sua nova senha: ", senhausuario);
								scanf (" %[^\n]s", senhausuario);
								strcpy(dAlunos[i].senhaAluno, senhausuario);
								printf("Senha alterada com sucesso !!\nSua nova senha: %s \n", dAlunos[i].senhaAluno);
								printf("\nPor favor, refassa o login ");
								aguardaEnter();
								menualuno();
								break;

							case '3':
								return ;
							}

						}
						while(op != '3');


					case '4' :
						menuacervo();
						aguardaEnter();
						break;
					case '5' :

						limpar();
						if(qtdl == 0)
						{
							printf("\nNenhum livro disponivel....");
							aguardaEnter();
							break;
						}
						else
						{
							int acheilivro = 0, t = 0;
							char templivro[50];
							printf("\nTitulo ou Autor: ");
							scanf (" %[^\n]s", templivro);
							for(i = 0; i < qtdl; i++)
							{
								if( strcmp(templivro, dLivros[i].titulo) == 0 || strcmp(templivro, dLivros[i].autor) == 0)
								{
									acheilivro = 1; //confirmação se achar algum dados
									break; //obter meu indice na struct
								}
							}

							if(acheilivro == 1) 
							{
								for(i = 0; i < qtdl; i++)
								{       //vai comparando e onde encontrar, é exibido
									if( strcmp(templivro, dLivros[i].titulo) == 0 || strcmp(templivro, dLivros[i].autor) == 0)
									{
										printf("\nTitulo: %s\nAutor: %s\nAno de publicação: %s\nCódigo: %d\n", dLivros[i].titulo, dLivros[i].autor, dLivros[i].anopublicacao, dLivros[i].codigo);
										t++;
										linha();
									}
								}
								printf("\n%d livros encontrados\n", t);
							}
							else
							{
								printf("\nNenhum livro encontrado...\n");
							}
						}
						aguardaEnter();
						break;
					case '6' :
						return;
					}
				}
				while(op != '6');
			}

			if (c == 0)
			{
				printf("\nMuitas tentativas detectadas !! contante o administrador..");
				aguardaEnter();
				return;
			}
			c--;
		}

	}
	while(acheiusuario == 0);

}



//========== mensagens do sistema ===========
void opcaoinvalida()
{
	printf("\n!! opção invalida !!");
}

void aguardaEnter()
{
	printf("\npressione enter para continuar ou sair... ");
	getchar();
	getchar();
}

//========= gravação/exibição dos dados

void menuacervo() //exibir todo acervo
{
	ltl();
	limpar();
	if(qtdl == 0)
	{
		printf("!! Nenhum livro registrado no acervo...!!");
	}
	else
	{
		limpar();
		printf("                                                        EXIBINDO TODO ACERVO...\n");
		linha();
		for(i = 0; i < qtdl; i++)
		{
			linha();
			printf("TITULO |%d|: %s\nAUTOR: %s\nANO DE PUBLICAÇÃO: %s\nCUSTO: R$%.2f\nCÓDIGO: %d\n", i + 1, dLivros[i].titulo, dLivros[i].autor, dLivros[i].anopublicacao , dLivros[i].custo, dLivros[i].codigo);
		}
	}

}
  
void adlivros() //adicionar livro
{

	do
	{
		ltl();//linha tabulação linha
		printf("\n|%d| ADICIONAR LIVRO", qtdl + 1);
		printf("\n\nTitulo: ");
		scanf (" %[^\n]s", dLivros[qtdl].titulo);

		printf("\nAutor: ");
		scanf (" %[^\n]s", dLivros[qtdl].autor);

		printf("\nAno de publicação: ");
		scanf (" %[^\n]s", dLivros[qtdl].anopublicacao);

		printf("\nID numérico do livro: ");
		scanf("%d", &dLivros[qtdl].codigo);


		printf("\nCusto pra biblioteca:R$ ");
		scanf ("%f", &dLivros[qtdl].custo);
		custo += dLivros[qtdl].custo;

		qtdl++;

		printf("\ndeseja adicionar mais dados sobre mais um livro? S/N: ");
		scanf(" %c", &op);

	}
	while(op == 's' || op == 'S');

	/*	int i;

	for(i = 0; i < qtdl; i++)
	{
		printf("\nTitulo: %s", dLivros[i].titulo );
		printf("\nAutor: %s", dLivros[i].autor);
		printf("\nAno de publicação: %s", dLivros[i].anopublicacao);
		printf("\nCusto: R$%.2f", dLivros[i].custo);
	}
	*/

}

void adalunos() //adicionar alunos
{

	do
	{
		ltl();
		printf("|%d| ADICIONAR ALUNO\n", qtda + 1);
		printf("\nNome: ");
		scanf (" %[^\n]s", dAlunos[qtda].nome);

		printf("\nCPF (000.000.000-00): ");
		scanf (" %[^\n]s", dAlunos[qtda].cpf);

		printf("\nE-mail: ");
		scanf (" %[^\n]s", dAlunos[qtda].email);

		printf("\nNumero da matricula: ");
		scanf (" %[^\n]s", dAlunos[qtda].matricula);

		printf("\nNome de usuario: ");
		scanf (" %[^\n]s", dAlunos[qtda].usuarioAluno);

		printf("\nSenha: ");
		scanf (" %[^\n]s", dAlunos[qtda].senhaAluno);

		printf("\ndeseja adicionar mais um aluno? S/N: ");
		scanf(" %c", &op);

		qtda++;

	}
	while(op == 's' || op == 's');

	/*
	for(i = 0; i < qtda; i++)
	{
		printf("\nNome: %s", dAlunos[i].nome);
		printf("\nCPF: %s", dAlunos[i].cpf);
		printf("\nE-mail: %s", dAlunos[i].email);
		printf("\nMatricula: %s", dAlunos[i].matricula);
		printf("\nNome de usuario: %s", dAlunos[i].usuarioAluno);
		printf("\nSenha: %s", dAlunos[i].senhaAluno);

	}
	*/

}

void adhistorico() //adcionar historico
{

	char tempmatricula[16], c = 2;
	int acheiusuario, tempcodigo, acheilivro = 0;

	if(qtdl == 0)
	{
		printf("O sistema não possui alunos registrados..Imposivel fazer qualquer registro");
		aguardaEnter();
	}
	else
	{
		limpar();
		printf("\nMatricula do aluno: ");
		scanf (" %[^\n]s", tempmatricula);

		for(i = 0; i < qtda; i++)
		{
			if( strcmp(tempmatricula, dAlunos[i].matricula) == 0)
			{
				acheiusuario = 1;
				break;
			}
		}

		if(acheiusuario == 1)
		{

			limpar();
			printf("Aluno: %s CPF: %s Matricula: %s\n", dAlunos[i].nome, dAlunos[i].cpf, dAlunos[i].matricula);
			linha();
			do
			{
				printf("\nCodigo do livro: ");
				scanf("%d", &tempcodigo);

				for(i = 0; i < qtdl; i++)
				{
					if(tempcodigo == dLivros[i].codigo)
					{
						acheilivro = 1;
						break;
					}
				}

				if(acheilivro == 1)
				{
					printf("\nLivro encontrado !!");
					printf("\n\nTitulo:%s\nAutor: %s\nAno de publicação: %s\n", dLivros[i].titulo, dLivros[i].autor, dLivros[i].anopublicacao);

					printf("\nData de requisição(dd//mm/aa): ");
					scanf (" %[^\n]s", hAluno[qtdh].data);

					strcpy(hAluno[qtdh].titulolivro, dLivros[i].titulo);
					strcpy(hAluno[qtdh].matricula, tempmatricula);

					printf("\nrequisição salva com sucesso !!!");
					printf("\nAluno: %s\nData de requisição: %s ", dAlunos[i].nome, hAluno[qtdh].data);
					printf("\nLivro: %s \nmatricula: %s", hAluno[qtdh].titulolivro, hAluno[qtdh].matricula);
					qtdh++;
					aguardaEnter();
				}
				else
				{
					printf("Livro não encontrado no acervo!! tente novamente");
					aguardaEnter();
					return;
				}

				if(c == 0)
				{
					c = 2;
					return;
				}
				c++;

			}
			while(acheilivro == 0);

		}
		else
		{
			printf("\nAluno não disponivel..tente novamente ");
			aguardaEnter();
		}
	}


}

void editarlivro()
{
	int tempcodigo = 0, acheilivro = 0;

	limpar();
	if(qtdl == 0)
	{
		printf("\nNão existe nenhum livro no acervo para edição :( ");
	}
	else
	{
		printf("Código do livro: ");
		scanf("%d", &tempcodigo);

		for(i = 0; i < qtdl; i++)
		{
			if(tempcodigo == dLivros[i].codigo)
			{
				acheilivro = 1;
				break;  	//para o laço e em seguida obtem-se o indice do dado na struct
			}
		}
		if(acheilivro == 1)
		{
			limpar();
			printf("\nLivro encontrado...");
			printf("\n\nLivro: %s\nAutor: %s\nAno de publicação: %s\nCodigo: %d\nCusto: %.2f", dLivros[i].titulo, dLivros[i].autor, dLivros[i].anopublicacao, dLivros[i].codigo, dLivros[i].custo);
			printf("\n\nDeseja prosseguir com alteração? S/N: ");
			scanf(" %c", &op);
			if(op == 'S' || op == 's')
			{
				printf("\n\nNovos dados\nTitulo: ");
				scanf (" %[^\n]s", dLivros[i].titulo);

				printf("\nAutor: ");
				scanf (" %[^\n]s", dLivros[i].autor);

				printf("\nAno de publicação: ");
				scanf (" %[^\n]s", dLivros[i].anopublicacao);

				printf("\nID numérico do livro: ");
				scanf("%d", &dLivros[i].codigo);


				printf("\nCusto pra biblioteca:R$ ");
				scanf ("%f", &dLivros[i].custo);

				printf("\nDados alterados com sucesso !!!");
				printf("\n\nLivro: %s\nAutor: %s\nAno de publicação: %s\nCodigo: %d\nCusto: %.2f", dLivros[i].titulo, dLivros[i].autor, dLivros[i].anopublicacao, dLivros[i].codigo, dLivros[i].custo);

			}
			else
			{
				printf("Você não alterou nenhum dado....");
			}
		}
		else
		{
			printf("\nLivro não encontrado....");

		}

	}
	aguardaEnter();
}

void excluirlivro()
{
	//com o meu indice obtido a partir do 1º break
	//o livro a ser excluido é "sobrescrito" com as
	//informações do livro seguinte.
	//exemplo :
	// 0 : "portugues"
	// 1 : "matematica"
	// 2 : "historia"
	// 3 : "geografia"
	// 4 : "redes"
	//quero exclui o livro "historia"..
	//obtenho o inde do livro, nesse caso '2'
	//e em seguida, esse indice é sobrescrito com a informação
	//seguinte. indice 2 recebe o conteudo do indice 3
	// e o indice 3 recebe o conteudo do indice 4 :
	// 0 : "portugues"
	// 1 : "matematica"
	// 2 : "historia"  <--|
	// 3 : "geografia" ----
	// 4 : "redes"
	//resultado:
	// 0 : "portugues"
	// 1 : "matematica"
	// 2 : "geografia"
	// 3 : "redes"
	// 4 : "vazio" : nesse caso, diminui a qtd de livro em -1
	// na hora de mostrar os dados:
	// 0 : "portugues"
	// 1 : "matematica"
	// 2 : "geografia"
	// 3 : "redes"
	int tempcodigo = 0, acheilivro = 0, j;

	limpar();
	if(qtdl == 0)
	{
		printf("\nNão existe nenhum livro no acervo para excluisão :( ");
	}
	else
	{
		printf("Código do livro: ");
		scanf("%d", &tempcodigo);

		for(i = 0; i < qtdl; i++)
		{
			if(tempcodigo == dLivros[i].codigo)
			{
				acheilivro = 1;
				break;
			}
		}

		if(acheilivro == 1)
		{

			limpar();
			printf("\nLivro encontrado...");
			printf("\n\nLivro: %s\nAutor: %s\nAno de publicação: %s\nCodigo: %d\nCusto: %.2f", dLivros[i].titulo, dLivros[i].autor, dLivros[i].anopublicacao, dLivros[i].codigo, dLivros[i].custo);
			printf("\n\nDeseja prosseguir com a exclusão? S/N: ");
			scanf(" %c", &op);

			if(op == 'S' || op == 's')
			{
				for(j = i; j < qtdl; j++)//com o meu indice obtido a partir do 1º break
				{
					strcpy(dLivros[j].titulo, dLivros[j + 1].titulo);
					strcpy(dLivros[j].autor, dLivros[j + 1].autor);
					strcpy(dLivros[j].anopublicacao, dLivros[j + 1].anopublicacao);
					dLivros[j].codigo = dLivros[j + 1].codigo;
					dLivros[j].custo = dLivros[j + 1].custo;
				}
				qtdl--;
				printf("\nLivro excluido com sucesso...");
			}
			else
			{
				printf("\nExclusão cancelada...");

			}
		}
		else
		{
			printf("\nLivro não encontrado... ");
		}

	}
	aguardaEnter();
}

void editaraluno()
{
	limpar();
	int acheialuno = 0;
	char tempmatricula[16];
	if(qtda == 0)
	{
		printf("\nNenhum aluno registrado no sistema....");
	}
	else
	{
		printf("\nNumero de matricula do aluno: ");
		scanf (" %[^\n]s", tempmatricula);

		for(i = 0; i < qtda; i++)
		{
			if( strcmp(tempmatricula, dAlunos[i].matricula) == 0)
			{
				acheialuno = 1;
				break;
			}

		}

		if (acheialuno == 1)
		{
			printf("\nAluno encontrado !!!");
			printf("\nALUNO: %s\nCPF: %s\nE-MAIL: %s\nMATRICULA: %s\nUSUÁRIO: %s\nSENHA: %s\n", dAlunos[i].nome, dAlunos[i].cpf, dAlunos[i].email, dAlunos[i].matricula, dAlunos[i].usuarioAluno, dAlunos[i].senhaAluno);

			printf("\n\nDeseja proseguir com  a alteração? S/N: ");
			scanf(" %c", &op);

			if(op == 's' || op == 'S')
			{
				limpar();
				printf("\nAlterar dados do aluno %s...", dAlunos[i].nome);
				printf("\nNome: ");
				scanf (" %[^\n]s", dAlunos[i].nome);

				printf("\nCPF (000.000.000-00): ");
				scanf (" %[^\n]s", dAlunos[i].cpf);

				printf("\nE-mail: ");
				scanf (" %[^\n]s", dAlunos[i].email);

				printf("\nMatricula: ");
				scanf (" %[^\n]s", dAlunos[i].matricula);

				printf("\nNome de usuario: ");
				scanf (" %[^\n]s", dAlunos[i].usuarioAluno);

				printf("\nSenha: ");
				scanf (" %[^\n]s", dAlunos[i].senhaAluno);

				printf("\nDados alterado com sucesso !!!");
				printf("\nALUNO: %s\nCPF: %s\nE-MAIL: %s\nMATRICULA: %s\nUSUÁRIO: %s\nSENHA: %s\n", dAlunos[i].nome, dAlunos[i].cpf, dAlunos[i].email, dAlunos[i].matricula, dAlunos[i].usuarioAluno, dAlunos[i].senhaAluno);

			}
			else
			{
				printf("\nVoçê não alterou nenhum dado...");
			}

		}
		else
		{
			printf("\nAluno não encontrado...");
		}

	}
	aguardaEnter();
}

void excluiraluno()
{
	limpar();
	int acheialuno = 0, j;
	char tempmatricula[16];

	if(qtda == 0)
	{
		printf("\nNenhum aluno registrado no sistema....");
	}
	else
	{
		printf("\nNumero de matricula do aluno: ");
		scanf (" %[^\n]s", tempmatricula);

		for(i = 0; i < qtda; i++)
		{
			if( strcmp(tempmatricula, dAlunos[i].matricula) == 0)
			{
				acheialuno = 1;
				break; //obter meu indice
			}
		}
		if (acheialuno == 1)
		{
			printf("\nAluno encontrado !!!");
			printf("\nALUNO: %s\nCPF: %s\nE-MAIL: %s\nMATRICULA: %s\nUSUÁRIO: %s\nSENHA: %s\n", dAlunos[i].nome, dAlunos[i].cpf, dAlunos[i].email, dAlunos[i].matricula, dAlunos[i].usuarioAluno, dAlunos[i].senhaAluno);
			printf("\n\nDeseja proseguir com  a exclusão? S/N: ");
			scanf(" %c", &op);

			if(op == 'S' || op == 's')
			{
				for(j = i; j < qtdl; j++)
				{
					strcpy(dAlunos[j].nome, dAlunos[j + 1].nome);
					strcpy(dAlunos[j].cpf, dAlunos[j + 1].cpf);
					strcpy(dAlunos[j].email, dAlunos[j + 1].email);
					strcpy(dAlunos[j].matricula, dAlunos[j + 1].matricula);
					strcpy(dAlunos[j].usuarioAluno, dAlunos[j + 1].usuarioAluno);
					strcpy(dAlunos[j].senhaAluno, dAlunos[j + 1].senhaAluno);

				}
				qtda--;
				printf("\nAluno excluido/removido do sistema com sucesso...");
			}
			else
			{
				printf("\nExclusão cancelada...");

			}
		}
		else
		{
			printf("\nAluno não encontrado...");
		}

	}
	aguardaEnter();
}

//=================== design ===============
void limpar()
{
	system("cls");
}

void linha()
{

	for(ln = 0; ln < 134; ln++)
	{
		printf("_");
	}
	printf("\n");

}

void tabulacao()
{
	for(ln = 0; ln < 7; ln++)
	{
		printf("\n");
	}
}

void ltl()
{
	limpar();
	tabulacao();
	linha();
}
