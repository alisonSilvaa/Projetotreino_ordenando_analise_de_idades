#include <stdio.h> 
#include <string.h>
#include <locale.h>
#include <unistd.h>

int main() {
	
	setlocale(LC_ALL, ""); 

	int config=0,idade[1000][config],i,aux,j,media,menu=0,res,fucionamento=0,qtd_bancos=0,fucionamento1;
	int media_geral[1000],maior_idade[1000],menor_idade[1000],qtd_acima[1000],qtd_abaixo[1000],soma_geral[1000]; 
	char rmenu[1], nome_banco[1000][99], busca_nome[1][99];  
	
	do {
		
		menu=0; 
		rmenu[0] = '_'; 
		
		printf("status do script \n");
		printf("qtd de bancos registrado: %d \n",qtd_bancos);  
		printf("\n");	
		
		printf("Ordenação e Analise de idades \n");
		printf("\n"); 
		
		printf(" 1 - Criar banco para analise \n"); 
		printf(" 2 - consultar \n");
		printf(" 3 - sair do programa \n"); 
		printf("\n"); 
		
		printf("digite o comando: ");
		scanf(" %d", &res); 
		printf("\n"); 
		
		switch (res) {
			
			case 1:
				
				do {
					
					fucionamento=0;
					menu=0; 
					
					// nome do banco
					
					printf("digite o nome do banco de dados: ");
					scanf(" %[^\n]", nome_banco[qtd_bancos]);  
					
					// configurar
							
					printf("configure a quantidade de idades a ser analisado: "); 
					scanf("%d", &config);
					printf("\n");
					
					// digita as idades
					
					for(i=0; i < config; i++) {
						printf("digite as idades: ");
						scanf("%d", &idade[qtd_bancos][i]);
					}
					
					// ordem crescente
					
					for(i=0; i < config; i++) {
						for(j=0; j < config; j++) {
							if(idade[qtd_bancos][j] > idade[qtd_bancos][i]) {
								aux = idade[qtd_bancos][j]; 
								idade[qtd_bancos][j] = idade[qtd_bancos][i];
								idade[qtd_bancos][i] = aux; 
							}
						}	
					}
					
					// mostrar
					
					printf("\n"); 
					
					for(i=0; i < config; i++) {
						printf(" %d",idade[qtd_bancos][i]);
					} 
					
					 printf("\n"); 
					 printf("\n");
						 
					 printf("Informações gerais: \n");
					 printf("\n");
					 
					 // media geral
					 
					 soma_geral[qtd_bancos] = 0; 
					 
					 for(i=0; i < config; i++) {
					 	soma_geral[qtd_bancos] += idade[qtd_bancos][i]; 
					 }
					 
					 media_geral[qtd_bancos] = soma_geral[qtd_bancos] / config; 
					 printf("A média geral de idade: %d \n",media_geral[qtd_bancos]);
					 
					 // maior idade && menor idade
					 
					 maior_idade[qtd_bancos] = idade[qtd_bancos][config - 1];
					 menor_idade[qtd_bancos] = idade[qtd_bancos][0];
					 
					 printf("a maior idade: %d \n",maior_idade[qtd_bancos]); 
					 printf("a menor idade: %d \n",menor_idade[qtd_bancos]);
					 
					 // qtd de acima e abaixo da media
					 
					 qtd_acima[qtd_bancos] = 0; 
					 qtd_abaixo[qtd_bancos] = 0;
					 
					 for(i=0; i < config; i++) {
					 	if(idade[qtd_bancos][i] > media_geral[qtd_bancos]) {
					 		qtd_acima[qtd_bancos]++;
						 } else if(idade[qtd_bancos][i] < media_geral[qtd_bancos]) {
						  	qtd_abaixo[qtd_bancos]++;
						   } 
					 }
					 
					printf("a quantidade de pessoas acima da média: %d \n",qtd_acima[qtd_bancos]); 
					printf("a quantidade de pessoas abaixo da média: %d \n",qtd_abaixo[qtd_bancos]);	
					printf("\n");
					 
					qtd_bancos++;
					
					// deseja continuar? 
					
					while(rmenu[0] != 's') {
						printf("deseja continuar? s|n: "); 
						scanf(" %c", &rmenu[0]);
					}
					
					// voltar ao menu
					
					printf("Voltando ao menu... \n"); 
					for(i=1; i <=5; i++) {
						printf("em %d... \n",i); 
						sleep(1);  
					}
					
					menu=1;
					fucionamento=0;   
					printf("\n");
					
				} while (fucionamento); 
				
			break;
			
			case 2:  
			
				printf("Consulta ao banco de dados sobre idade \n"); 
				printf("banco de dados disponiveis: \n"); 
				printf("\n");
				
				if(qtd_bancos == 0) {
					printf("nenhum banco de dados localizados \n"); 
					sleep(3);
					printf("voltando ao menu \n");
					for(i=1; i <= 5; i++) {
						printf("em %d \n",i);
						sleep(1); 		
					}
						menu=1;
						fucionamento=0;
						fucionamento1=0;
						printf("\n");  
					} else {
						fucionamento1=1;
					}
				
					
				while(fucionamento1) {
				
					do {
						
						fucionamento=0;
						menu=0; 
						
						// exibir banco de dados disponiveis. 
						
						for(i=0; i < qtd_bancos; i++) {
							printf("%s \n",nome_banco[i]); 
						}
						
						printf("\n");
						
						printf("Digite o banco escolhido: ");
						scanf(" %[^\n]", busca_nome[0]);
						printf("\n");
						for(i=0; i < qtd_bancos; i++) {
							if(strcmp(busca_nome[0], nome_banco[i]) == 0) {
								
								// exibir as informações salvas
								
								printf("Informações gerais: \n");
								printf("\n");
								
								printf("A média geral de idade: %d \n",media_geral[i]);
								printf("a maior idade: %d \n",maior_idade[i]); 
						 		printf("a menor idade: %d \n",menor_idade[i]);
						 		printf("a quantidade de pessoas acima da média: %d \n",qtd_acima[i]); 
								printf("a quantidade de pessoas abaixo da média: %d \n",qtd_abaixo[i]);
								printf("\n"); 	
									
							}
						} 
						
							int voltar=0; 
							
							// cambiarra do diabo pra fazer isso voltar ao menu
						
						do {
						    
							voltar = 0; 
						
						    printf("Deseja consultar outro banco de dados? s|n: "); 
						    scanf(" %c", &rmenu[0]);
						
						    if (rmenu[0] == 's') {
						        fucionamento=1;
						        fucionamento1=0;
								menu=0;
								voltar=0;
						        printf("\n");
						    } else {
						        printf("\nDeseja voltar ao menu? s|n: ");
						        scanf(" %c", &rmenu[0]);
						        if (rmenu[0] == 's') {
							        fucionamento=0;
							        fucionamento1=0;
							        menu=1;
							        voltar=0;
							        printf("\n");
						        } else {
							        fucionamento=0;
							        fucionamento1=0;
							        menu=0;
							        voltar=1;
									printf("\n");	
								}
						    }
						
						} while (voltar);

					} while(fucionamento);
				}
				
				break; 
				
				case 3:
					
					printf("finalizando programa... \n");
					for(i=1; i <=5; i++) {
						printf("em %d... \n",i); 
						sleep(1);  
					}
					
					menu=0; 
					
				break;
				
				default: 
				
					printf("Erro, tente novamente! \n"); 
					printf("\n");
					sleep(3); 
					
					menu=1;
				
				break; 
		} 
			
	} while(menu);	 
	
	
	
	return 0; 
	
}
