#include <stdio.h>

int verificaDuplicidade(int vec[], int cod, int tam){
    int check = 1;
    for (int i = 0; i < tam;++i){
        if(cod == vec[i]) check = 0;
    }
    return check;
}

void cadastroInicial(int vec[], int quant[], int tam){
    int cod = 0, checkDuplicidade = 0;
    for (int i = 0; i < tam; ++i){
        do{
            printf("Digite o codigo do produto %d \n", i + 1);
            scanf("%d", &cod);
            checkDuplicidade = verificaDuplicidade(vec, cod, tam);
            if (!checkDuplicidade){
                printf("Codigo duplicado, favor digitar novamente. \n"); 
            } 
        }while(!checkDuplicidade);
        vec[i] = cod;
    }
}

void imprimirRelatorio(int codigos[], int quant[], int tam){
    for (int i = 0; i < tam; ++i){
        printf("%d unidades do item %d \n", quant[i], codigos[i]);
    }
}

void adicionaEstoque(int quant[], int indice, int qnt){
    quant[indice] += qnt;
}

void removerEstoque(int qnt, int quantidade[], int indice){
    quantidade[indice] -= qnt;
}

int buscaProduto(int cod, int codigos[], int tam){
    int indice = -1;
    for(int i = 0; i < tam; ++i){
        if (cod == codigos[i]) indice = i;
    }
    return indice;
}

int main(){
    int codigos[5], quantidade[5] = {0,0,0,0,0}, opc = 0, indice = -1, cod, tam = 5, quant;

    printf("Entre com os dados iniciais \n");
    cadastroInicial(codigos, quantidade, tam);
    do{
        printf("Digite a opcao desejada: \n");
        printf("1 - Buscar produto\n");
        printf("2 - Adicionar estoque\n");
        printf("3 - Remover estoque\n");
        printf("4 - Imprimir relatorio\n");
        printf("5 - Sair\n");
        scanf("%d", &opc);
        switch (opc){
        case 1:
            printf("Digite o codigo do produto buscado: ");
            scanf("%d", &cod);
            indice = buscaProduto(cod, codigos, tam);
            if (indice < 0){
                printf("Item %d nao localizado \n", cod);
            } else{
                printf("Item %d possui %d itens em estoque \n", cod, quantidade[indice]);
            }
            break;
        case 2:
            do{
                printf("Digite o produto que deseja adicionas estoque: \n");
                scanf("%d", &cod);
                indice = buscaProduto(cod, codigos, tam);
                if(indice < 0) printf("Codigo digitado invalido, digite novamente. \n");
            }while(indice < 0);
            printf("Digite a quantidade a ser adicionada: \n");
            scanf("%d", &quant);
            adicionaEstoque(quantidade, indice, quant);
            break;
        case 3:
            do{
                printf("Digite o produto que deseja remover estoque: \n");
                scanf("%d", &cod);
                indice = buscaProduto(cod, codigos, tam);
                if(indice < 0) printf("Codigo digitado invalido, digite novamente. \n");
            }while(indice < 0);
            do{
                printf("Digite a quantidade a ser removida: \n");
                scanf("%d", &quant);
                if(quant > quantidade[indice]) printf("Valor maior que o disponivel em estoque, digite novamente. \n");
            }while(quant > quantidade[indice]);
            removerEstoque(quant, quantidade, indice);
            break;
        case 4:
            imprimirRelatorio(codigos, quantidade, tam);
            break;
        case 5:
            printf("Aplicacao sera finalizada.\n");
            break;
        default:
        printf("Operacao invalida. Digite novamente. \n");
            break;
        }
    }while(opc != 5);
    return 0;
}