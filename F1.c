//Nome:Gabriel Oliveira Santos / Matrícula: UC21100452
//Nome:GUSTAVO MAXWEL DE SOUSA OLIVEIRA  / Matrícula: UC21101257

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define MAX 450

struct Piloto{
	int idPiloto; 
	int idade;
	char nome[200]; 
	char pais[45];
	char sexo;
};

struct Piloto piloto;

 struct Circuito{
 	float tamanho;
 	int codigo;
 	int auxId;
	char tempo[20];
	char nome[200]; 
	char pais[50];
};

struct Circuito circuito;

struct Data{
	int dia;
	int mes;
	int ano;
};

struct Data data;

struct MelhorVolta{
	struct Piloto piloto;
	struct Circuito circuito;
	struct Data data;
	char equipePiloto[45];
	char bestLap[20];
	int auxCircuito; 
	int auxPiloto;
};

void le_valida_idPiloto(struct MelhorVolta f1[], int index);
void le_valida_idadePiloto(struct MelhorVolta f1[], int index);
void le_valida_nomePiloto(struct MelhorVolta f1[], int index);
void le_valida_sexoPiloto(struct MelhorVolta f1[], int index);
void le_valida_paisPilotoP(struct MelhorVolta f1[], int index);
void le_valida_tamCircuito(struct MelhorVolta f1[], int index);
void le_valida_codigoCircuito(struct MelhorVolta f1[], int index);
void le_valida_nomeCircuito(struct MelhorVolta f1[], int index);
void le_valida_paisCircuito(struct MelhorVolta f1[], int index);
void le_valida_tempoCircuito(struct MelhorVolta f1[], int index, int cont1);
void melhorVoltaCircuito(struct MelhorVolta f1[], int index, int cont1);
void le_valida_Equipe(struct MelhorVolta f1[], int index);
void le_valida_bestLap(struct MelhorVolta f1[], int cont1, int cont2, int cont3);
void consultaSimples(struct MelhorVolta f1[], int cont1, int cont2, int cont3);
void pesquisaPiloto(struct MelhorVolta f1[], int cont1);
void pesquisaCircuito(struct MelhorVolta f1[], int cont2);
void pesquisaTempo(struct MelhorVolta f1[], int cont3);

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	struct MelhorVolta F1[MAX];
	
	int opcao=0,opcao2=0, opcao3=0, cont=0, cont2=0, cont3=0;
	int codigoC;
	
	do{
	
		system("cls");
		
		printf("Cadastrar(Pilotos, Circuitos e Voltas)(0)\n");
		printf("Consulta simples sobre todos (Pilotos, Circuitos e Voltas)(1)\n");
		printf("Pesquisar pilotos pelo nome(2)\n");
		printf("Pesquisar um circuito e os dados relacionados ao mesmo(3)\n");
		printf("Pesquisar por tempo de volta(0.00.000)(4)\n");
		printf("Sair(5)\n");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 0:
				do{
					system("cls");
					printf("Digite 1 para cadastrar um piloto\n");
					printf("Digite 2 para cadastrar um circuito\n");
					printf("Digite 3 para registrar uma melhor volta de um piloto\n");
					printf("Digite 4 para retornar ao menu principal\n");
					scanf("%d", &opcao2);
					switch(opcao2){
						case 1:
							le_valida_idPiloto(&F1, cont);
							
							le_valida_idadePiloto(&F1, cont);
							
							le_valida_nomePiloto(&F1, cont);
							
							le_valida_paisPilotoP(&F1, cont);
							
							le_valida_sexoPiloto(&F1, cont);
				
							cont++;
							getch("");
						break;
					
						case 2:
							if(cont2>0){
								fflush(stdin);
								printf("\nDeseja recadastrar uma melhor volta?(s/n)");
								scanf("%c", &opcao3);
								switch(opcao3){						
									case's':
										melhorVoltaCircuito(&F1, cont2, cont);
										getch("");
									break;										
								}
							}
									system("cls");
									le_valida_codigoCircuito(&F1, cont2);
								
									le_valida_nomeCircuito(&F1, cont2);
								
									le_valida_paisCircuito(&F1, cont2);
								
									le_valida_tamCircuito(&F1, cont2);
	
									le_valida_tempoCircuito(&F1, cont2, cont);
								
									cont2++;								
									getch("");
						break;
						
						case 3:
							le_valida_Equipe(&F1, cont3);
							
							le_valida_bestLap(&F1,cont, cont2, cont3);
							
							cont3++;
						break;
						
						case 4:
							
						break;
					}
				}while(opcao2!=4);
			break;
			
			case 1:
				consultaSimples(&F1,cont, cont2, cont3);
			break;
			
			case 2:
				pesquisaPiloto(&F1,cont);
			break;
			
			case 3:
				pesquisaCircuito(&F1,cont3);
			break;
			
			case 4:
				pesquisaTempo(&F1, cont3);
			break;
			
			case 5:
				
			break;
		}
	}while(opcao!=5);
	
	return 0;
}

void le_valida_idPiloto(struct MelhorVolta f1[], int index){
	
	int unId=0;
	
	do{
		printf("Identificação do piloto(100-500): ");
		scanf("%d", &f1[index].piloto.idPiloto);
		
		for(unId; unId<index; unId++){
			if(f1[index].piloto.idPiloto == f1[unId].piloto.idPiloto){
				do{
					printf("Esse número já está em uso!\n");
					printf("Identificação do piloto: ");
					scanf("%d", &f1[index].piloto.idPiloto);
				}while(f1[index].piloto.idPiloto == f1[unId].piloto.idPiloto);	
			}
		}	
	}while(f1[index].piloto.idPiloto<100 || f1[index].piloto.idPiloto>500);
}

void le_valida_idadePiloto(struct MelhorVolta f1[], int cont1){
	
	do{
		printf("Idade do piloto:");
		scanf("%d",&f1[cont1].piloto.idade);
		if(f1[cont1].piloto.idade<18){
			printf("Vai pra F2!(>18)\n");
		}else if(f1[cont1].piloto.idade>65){
					printf("\nAposenta!(<65)\n");
				}
	}while(f1[cont1].piloto.idade <18 || f1[cont1].piloto.idade>65);
}

void le_valida_nomePiloto(struct MelhorVolta f1[], int cont1){
		
	int tam, espaco, j=0;
	
	do{
		fflush(stdin);
		printf("Nome do piloto:");
		scanf("%[^\n]s",&f1[cont1].piloto.nome);
		fflush(stdin);
		
		tam=strlen(f1[cont1].piloto.nome);
		
		for(j; j<tam;j++){
				f1[cont1].piloto.nome[j] = tolower(f1[cont1].piloto.nome[j]);
			}
			
			f1[cont1].piloto.nome[0] = toupper(f1[cont1].piloto.nome[0]);
		for(j=0; j<tam; j++){
			if(f1[cont1].piloto.nome[j]==' '){
				espaco = j; 
				f1[cont1].piloto.nome[espaco+1] = toupper(f1[cont1].piloto.nome[espaco+1]);
			}
		}
		if(tam<1 || tam>200){
			printf("O nome não pode ser nulo\n");
		}
	}while(tam<1 || tam>200);
}

void le_valida_paisPilotoP(struct MelhorVolta f1[], int cont1){
	
	int tam, espaco, j=0, valido=0, r;
	char arqPaises[200][50];
	
	do{
		FILE *arq;
		
		arq = fopen("Paises.txt", "r");
		
		if(arq == NULL){
			printf("Erro ao abrir o arquivo!");
		}else{
				fflush(stdin);
				printf("País piloto:");
				fflush(stdin);
				scanf("%[^\n]s",&f1[cont1].piloto.pais);
				
				tam=strlen(f1[cont1].piloto.pais);
				
				for(j; j<tam;j++){
					f1[cont1].piloto.pais[j] = tolower(f1[cont1].piloto.pais[j]);
				}
					
				f1[cont1].piloto.pais[0] = toupper(f1[cont1].piloto.pais[0]);
				for(j=0; j<tam; j++){
					if(f1[cont1].piloto.pais[j]==' '){
						espaco = j; 
						f1[cont1].piloto.pais[espaco+1] = toupper(f1[cont1].piloto.pais[espaco+1]);
					}
				}
				
				valido=0;
				
				while(fscanf(arq,"%s",arqPaises)!=EOF){
					if(strcmp(arqPaises, f1[cont1].piloto.pais)==0){
						valido=1;
						printf("País Aceito!\n\n");
						break;
					}	
				}
		
				if(valido==0){
					printf("País Inexistente!\n");
				}
		}
		fclose(arq);
	}while(tam<1 || tam>45 || valido==0);
}


void le_valida_sexoPiloto(struct MelhorVolta f1[], int cont1){
	
	do{
		fflush(stdin);
		printf("Sexo(M/F):");
		scanf("%c",&f1[cont1].piloto.sexo);
		fflush(stdin);
		
		f1[cont1].piloto.sexo = toupper(f1[cont1].piloto.sexo);
		
		if(f1[cont1].piloto.sexo!='M' && f1[cont1].piloto.sexo!='F'){
			printf("(M/F)!\n");
		}
	}while(f1[cont1].piloto.sexo!='M' && f1[cont1].piloto.sexo!='F');
}

void le_valida_codigoCircuito(struct MelhorVolta f1[], int cont1){
	
		f1[cont1].circuito.codigo=cont1+1;
		printf("Codigo do circuito:%d",f1[cont1].circuito.codigo);	
}

void le_valida_nomeCircuito(struct MelhorVolta f1[], int cont2){
	
	int tam=0, f=0;
	
	do{
		fflush(stdin);
		printf("\nNome do circuito:");
		scanf("%[^\n]s",&f1[cont2].circuito.nome);
		
		for(f; f<cont2; f++){
			if(stricmp(f1[cont2].circuito.nome, f1[f].circuito.nome)==0){
				printf("\n O nome do circuito não pode ser o mesmo!");
				do{
					printf("\n\nNome do circuito:");
					scanf("%[^\n]s",&f1[cont2].circuito.nome);
				}while(stricmp(f1[cont2].circuito.nome, f1[f].circuito.nome)==0);
			}
		}
		
		tam=strlen(f1[cont2].circuito.nome);
		
		if(tam>200){
			printf("Muito grande!(<200)\n");
		}else if(tam<1){
					printf("O nome não pode ser nulo!(>5)\n");
				}
	}while(tam>200|| tam<1);
}

void le_valida_tamCircuito(struct MelhorVolta f1[], int cont2){
	
	do{
		fflush(stdin);
		printf("\nTamanho do circuito(Km):");
		scanf("%f",&f1[cont2].circuito.tamanho);
		if(f1[cont2].circuito.tamanho>10){
			printf("Muito grande!(<10)\n");
		}else if(f1[cont2].circuito.tamanho<5){
					printf("\nMuito pequeno!(>5)\n");
				}
	}while(f1[cont2].circuito.tamanho <5 || f1[cont2].circuito.tamanho>10);
}

void le_valida_paisCircuito(struct MelhorVolta f1[], int cont2){
	
	int tam, espaco, j=0, valido=0;
	char arqPaises[200][50];
	
	do{
		FILE *arq;
		
		arq = fopen("PaisesCircuito.txt", "r");
		
		if(arq == NULL){
			printf("Erro ao abrir o arquivo!");
		}else{
				fflush(stdin);
				printf("\nPaís do circuito:");
				scanf("%[^\n]s",&f1[cont2].circuito.pais);
				
				tam=strlen(f1[cont2].circuito.pais);
				
				for(j; j<tam;j++){
					f1[cont2].circuito.pais[j] = tolower(f1[cont2].circuito.pais[j]);
				}
					
				f1[cont2].circuito.pais[0] = toupper(f1[cont2].circuito.pais[0]);
				for(j=0; j<tam; j++){
					if(f1[cont2].circuito.pais[j]==' '){
						espaco = j; 
						f1[cont2].circuito.pais[espaco+1] = toupper(f1[cont2].circuito.pais[espaco+1]);
					}
				}
				
				valido=0;
				
				while(fscanf(arq,"%s",arqPaises)!=EOF){
					if(strcmp(arqPaises, f1[cont2].circuito.pais)==0){
						valido=1;
						printf("País Aceito!\n");
						break;
					}	
				}
		
				if(valido==0){
					printf("País Inexistente!\n Apenas os países pertencentes ao calendário da F1 são permitidos");
				}				
		}
		fclose(arq);
	}while(tam<1 || tam>45 || valido==0);
}

void le_valida_tempoCircuito(struct MelhorVolta f1[], int cont2, int cont1){
	
	int tam=0, f=0, a=0;
	
	do{
		fflush(stdin);
		printf("\nMelhor volta do circuito(0.00.000):");
		scanf("%[^\n]s",&f1[cont2].circuito.tempo);
		
		tam=strlen(f1[cont2].circuito.tempo);
	
		printf("\nIdentificação do piloto:");
		scanf("%d",&f1[cont2].circuito.auxId);
		
		for(f; f<cont1; f++){
			if(f1[cont2].circuito.auxId == f1[f].piloto.idPiloto){
				printf("\nPiloto:%s", f1[f].piloto.nome);
				a=1;
			}
		}
		
		if(a==0){
			printf("\nId inexistente!");
		}
		
	}while(tam!=8 || a==0);
}

void melhorVoltaCircuito(struct MelhorVolta f1[], int cont2, int cont1){
		
		int f=0,a=0, auxCodigo=0, tam=0;
		char op, menorT[20];
		
		do{
				printf("Digite o codigo do circuito que deseja alterar a melhor volta:");
				scanf("%d", &auxCodigo);
		
				for(f; f<cont2; f++){
					if(auxCodigo==f1[f].circuito.codigo){
						printf("\nCircuito:%s", f1[f].circuito.nome);
						printf("\nPais:%s", f1[f].circuito.pais);
						printf("\nTamanho:%.2f", f1[f].circuito.tamanho);
						printf("\nMenor tempo cadastrado:%s", f1[f].circuito.tempo);
						a=1;
						getch("");
					}
				}
		
				if(a==0){
					printf("\nCircuito inexistente!");
				}else{
					fflush(stdin);
					printf("\nDigite o novo melhor tempo(0.00.000):");
					scanf("%[^\n]s", &menorT);
					
					f=0;
					for(f; f<cont2; f++){
						if(strcmp(menorT, f1[auxCodigo-1].circuito.tempo)<0){
							strcpy(f1[auxCodigo-1].circuito.tempo, menorT);
						}
					}
					strcpy(f1[auxCodigo-1].circuito.tempo, menorT);
					printf("Melhor tempo de %s: %s", f1[auxCodigo-1].circuito.nome, f1[auxCodigo-1].circuito.tempo);
					
					tam=strlen(f1[auxCodigo-1].circuito.tempo);
				}
		}while(a==0||tam!=8);						
}

void le_valida_Equipe(struct MelhorVolta f1[], int cont3){
	
	int tam=0;
	
	do{
		fflush(stdin);
		printf("Digite o nome da equipe do piloto:");
		scanf("%[^\n]s", &f1[cont3].equipePiloto);
		
		tam=strlen(f1[cont3].equipePiloto);
		
		if(tam<1 || tam>45){
			printf("\nA equipe não pode ser nula e nem maior que 45 caracteres!\n");
		}
	}while(tam<1 || tam>45);
}

void le_valida_bestLap(struct MelhorVolta f1[], int cont1, int cont2, int cont3){
	
	int tam=0, f=0, g=0, a=0, b=0, c=0, i=0;
	
	do{
		printf("Digite o codigo do circuito:");
		scanf("%d", &f1[cont3].auxCircuito);
		
		for(f; f<cont2; f++){
			if(f1[cont3].auxCircuito==f1[f].circuito.codigo){
				printf("\nCircuito:%s", f1[f].circuito.nome);
				a=1;
			}
		}
		if(a==0){
			printf("*Circuito Inexistente!*");
		}
		
		printf("\n\nIdentificação do piloto:");
		scanf("%d",&f1[cont3].auxPiloto);
		
		for(g; g<cont1; g++){
			if(f1[cont3].auxPiloto == f1[g].piloto.idPiloto){
				printf("\nPiloto:%s", f1[g].piloto.nome);
				b=1;
			}
		}
		
		if(b==0){
			printf("\n*Id inexistente!*");
		}
		
		do{	
			printf("\n\nDigite o dia:");
			scanf("%d", &f1[cont3].data.dia);
			if(f1[cont3].data.dia<1 || f1[cont3].data.dia>31){
				printf("\nO dia não pode ser nulo e nem maior que 31!\n");
				printf("Digite o dia:");
				scanf("%d", &f1[cont3].data.dia);
			}
			
			printf("Digite o mês:");
			scanf("%d", &f1[cont3].data.mes);
			if(f1[cont3].data.mes<1 || f1[cont3].data.mes>12){
				printf("\nO mês não pode ser nulo e nem maior que 12!!\n");
				printf("Digite o mês:");
				scanf("%d", &f1[cont3].data.mes);
			}
			printf("Digite o ano:");
			scanf("%d", &f1[cont3].data.ano);
		 	if(f1[cont3].data.ano<1 ||f1[cont3].data.ano>2022){
				printf("\nO ano não pode ser nulo e nem maior que 2022(Ainda não existe viagem no tempo)!!!\n");
				printf("Digite o ano:");
				scanf("%d", &f1[cont3].data.ano);
			}	
		}while(f1[cont3].data.dia<1 || f1[cont3].data.dia>31 || f1[cont3].data.mes<1 || f1[cont3].data.mes>12 || f1[cont3].data.ano<1 ||f1[cont3].data.ano>2022);
		
		for(i=0; i<cont3; i++){
			if(f1[cont3].auxCircuito==f1[i].auxCircuito && f1[cont3].auxPiloto==f1[i].auxPiloto && 
			f1[cont3].data.dia==f1[i].data.dia && f1[cont3].data.mes==f1[i].data.mes && 
			f1[cont3].data.ano==f1[i].data.ano){
				printf("***Deve existir um único registro para um piloto em um circuito em uma data.****");
				c=1;
				break;
			}
		} 
		
		if(c==1){
			system("cls");
			printf("\n\nDigite o codigo do circuito:");
			scanf("%d", &f1[cont3].auxCircuito);
		
			for(f; f<cont2; f++){
				if(f1[cont3].auxCircuito==f1[f].circuito.codigo){
					printf("\nCircuito:%s", f1[f].circuito.nome);
					a=1;
				}
			}
			
			if(a==0){
				printf("Circuito Inexistente!");
				break;
			}
			
			printf("\nIdentificação do piloto:");
			scanf("%d",&f1[cont3].auxPiloto);
			
			for(g; g<cont1; g++){
				if(f1[cont3].auxPiloto == f1[g].piloto.idPiloto){
					b=1;
				}
			}
			
			if(b==0){
				printf("\nId inexistente!");
			}	
		}else{
			fflush(stdin);
			printf("\nInforme a melhor volta(0.00.000):");
			scanf("%[^\n]s",&f1[cont3].bestLap);
			
			tam=strlen(f1[cont3].bestLap);
		}
	}while(tam!=8 || a==0 || b==0);
}

void consultaSimples(struct MelhorVolta f1[], int cont1, int cont2, int cont3){
	int i=0, j=0, g=0;
	
	printf("\nPILOTOS:\n");
	for(i; i<cont1; i++){
		printf("\nIdentificação do piloto:%d", f1[i].piloto.idPiloto);
		printf("\nNome do piloto:%s", f1[i].piloto.nome);
		printf("\nIdade do piloto:%d", f1[i].piloto.idade);
		printf("\nPaís do piloto:%s", f1[i].piloto.pais);
		printf("\nSexo:%c", f1[i].piloto.sexo);
	}
	
		printf("\n\nCIRCUITOS:\n");
		for(j; j<cont2; j++){
			printf("\nIdentificação do circuito:%d", f1[j].circuito.codigo);
			printf("\nNome do circuito:%s", f1[j].circuito.nome);
			printf("\nTamanho do circuito:%2.f", f1[j].circuito.tamanho);
			printf("\nPaís do circuito:%s", f1[j].circuito.pais);
			printf("\nMenor tempo do circuito:%s", f1[j].circuito.tempo);
		}
		
		
		printf("\n\nVOLTAS:\n");
		for(g; g<cont3; g++){
			printf("\nIdentificação do piloto:%d", f1[g].auxPiloto);
			printf("\nIdentificação do circuito:%d", f1[g].auxCircuito);
			printf("\nEquipe do piloto:%s", f1[g].equipePiloto);
			printf("\nData da melhor volta:%d/%d/%d", f1[g].data.dia, f1[g].data.mes, f1[g].data.ano);
			printf("\nMelhor volta:%s", f1[g].bestLap);
		}	
	getch("");
}

void pesquisaPiloto(struct MelhorVolta f1[], int cont1){
	
	int i=0,tam=0, g=0;
	char pesquisaPiloto[200];
	
	do{
		fflush(stdin);
		printf("Digite o nome do piloto que quer pesquisar:");
		scanf("%[^\n]s", &pesquisaPiloto);
		
		tam=strlen(pesquisaPiloto);
	}while(tam<1 || tam>200);
	
	for(i; i<cont1; i++){
		if(stricmp(pesquisaPiloto, f1[i].piloto.nome)==0){
			printf("\nIdentificação do piloto:%d", f1[i].piloto.idPiloto);
			printf("\nNome do piloto:%s", f1[i].piloto.nome);
			printf("\nIdade do piloto:%d", f1[i].piloto.idade);
			printf("\nPaís do piloto:%s", f1[i].piloto.pais);
			printf("\nSexo:%c", f1[i].piloto.sexo);
			getch("");
			g=1;
		}		
	}
	if(g==0){
		printf("Piloto não cadastrado!");
		getch("");				
	}
	
}

void pesquisaCircuito(struct MelhorVolta f1[], int cont3){
	
	int f=0, a=0, g=0;
	int pesquisaCircuito;
	
		fflush(stdin);
		printf("Digite o codigo do circuito que quer pesquisar:");
		scanf("%d", &pesquisaCircuito);
		
		for(f; f<cont3; f++){
			if(pesquisaCircuito==f1[f].auxCircuito && pesquisaCircuito==f1[f].circuito.codigo){//Tem que existir um codigo e ter uma melhor colta no mesmo circuito
				printf("\nCircuito:%s", f1[f].circuito.nome);
				printf("\nCodigo do circuito:%d", f1[f].auxCircuito);
				printf("\nTamanho do circuito:%.2f", f1[f].circuito.tamanho);
				printf("\nPaís do circuito:%s", f1[f].circuito.pais);
				for(g; g<cont3; g++){
					if(pesquisaCircuito==f1[g].auxCircuito && pesquisaCircuito==f1[g].circuito.codigo){
						printf("\n\nNome do piloto:%s", f1[g].piloto.nome);
						printf("\nIdentificação do piloto:%d", f1[g].auxPiloto);
						printf("\nEquipe do piloto:%s", f1[g].equipePiloto);
						printf("\nData da melhor volta:%d/%d/%d", f1[g].data.dia, f1[g].data.mes, f1[g].data.ano);
						printf("\nMelhor tempo de %d em %s:%s",f1[g].auxPiloto ,f1[g].circuito.nome, f1[g].bestLap);
					}	
				}
				a=1;
				getch("");
			}
		}
		if(a==0){
			printf("\nCircuito não cadastrado/Não há voltas rapidas cadastradas nesse circuito!");
		}
		
}

void pesquisaTempo(struct MelhorVolta f1[], int cont3){
	
	int f=0, a=0, g=0, j=0;
	int pesquisaTempo[20];
	
		fflush(stdin);
		printf("Digite o tempo que quer pesquisar:");
		scanf("%s", &pesquisaTempo);
		
		for(f; f<cont3; f++){
			if(strcmp(pesquisaTempo, f1[f].bestLap)<0 || strcmp(pesquisaTempo, f1[f].bestLap)==0){
				for(g; g<cont3; g++){
					if(strcmp(pesquisaTempo, f1[g].bestLap)<0 || strcmp(pesquisaTempo, f1[g].bestLap)==0){
						printf("\nPiloto:%s", f1[g].piloto.nome);
						printf("\nIdentificação do piloto:%d", f1[g].auxPiloto);
						printf("\nEquipe do piloto:%s", f1[g].equipePiloto);
						printf("\n\nIdentificação do circuito:%d", f1[g].auxCircuito);
						printf("\nNome do circuito:%s", f1[g].circuito.nome);	
					}	
				}
				a=1;
				getch("");
			}
		}
		if(a==0){
			printf("\nNão encontrado!");
		}
}
