#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    char area[20]; 
    float valorTotal;
    char dataInicio[11]; 
    int duracaoMeses;
} Projeto;

void cadastrarProjeto(Projeto *projetos, int *totalProjetos);
void listarProjetos(Projeto *projetos, int totalProjetos);

int main() {
    Projeto projetos[100]; 
    int totalProjetos = 0; 
    int opcao;

    while(1) {
        printf("\nMenu de Opções:\n");
        printf("1. Cadastrar Projeto\n");
        printf("2. Listar Projetos\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); 

        switch(opcao) {
            case 1:
                cadastrarProjeto(projetos, &totalProjetos);
                break;
            case 2:
                listarProjetos(projetos, totalProjetos);
                break;
            case 3:
                printf("Saindo do programa...\n");
                return 0;
            default:
                printf("Opção inválida!\n");
        }
    }

    return 0;
}

void cadastrarProjeto(Projeto *projetos, int *totalProjetos) {
    if (*totalProjetos >= 100) {
        printf("Limite de projetos atingido!\n");
        return;
    }

    Projeto p;
    printf("Nome do Projeto: ");
    fgets(p.nome, 100, stdin);
    p.nome[strcspn(p.nome, "\n")] = 0; 

    printf("Área do Projeto (Marketing, Operacional, Inovação): ");
    fgets(p.area, 20, stdin);
    p.area[strcspn(p.area, "\n")] = 0; 

    printf("Valor Total: ");
    scanf("%f", &p.valorTotal);
    getchar(); 

    printf("Data de Início (DD/MM/AAAA): ");
    fgets(p.dataInicio, 11, stdin);
    p.dataInicio[strcspn(p.dataInicio, "\n")] = 0; 

    printf("Duração em Número de Meses: ");
    scanf("%d", &p.duracaoMeses);
    getchar(); 

    projetos[*totalProjetos] = p;
    (*totalProjetos)++;

    printf("Projeto cadastrado com sucesso!\n");
}

void listarProjetos(Projeto *projetos, int totalProjetos) {
    if (totalProjetos == 0) {
        printf("Nenhum projeto cadastrado.\n");
        return;
    }

    for (int i = 0; i < totalProjetos; i++) {
        printf("\nProjeto %d:\n", i + 1);
        printf("Nome: %s\n", projetos[i].nome);
        printf("Área: %s\n", projetos[i].area);
        printf("Valor Total: %.2f\n", projetos[i].valorTotal);
        printf("Data de Início: %s\n", projetos[i].dataInicio);
        printf("Duração: %d meses\n", projetos[i].duracaoMeses);
    }
}