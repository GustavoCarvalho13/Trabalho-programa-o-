#include <stdio.h>
#include <stdlib.h>

#include "header.h"

int main()
{
    Job *jobs = NULL;
    Operation * operacoes = NULL; 
     //cria as listas das operaçoes e dos jobs

    int option;
    int aa[MAXOPERATION]={1,2,3,};
    int bb[5]={4,5};
    int cc[5]={2,8};
    int rr[5]={2,6};
    int tt[5]={6,5};
    int kk[5]={3,7};
    int ii[5]={5,2};
    int hh[3]={6,6};
    int qt,qt2=0;
    int idOp=0;

    do{
        option = menu();
        switch(option){
            case 1:
                //inserir Job
                printf("Inserindo jobs...\n");
                jobs=inserirJobs(jobs,1,aa);
               /* //inserir 
                printf("Insira aquantidade de operaçoes:");
                scanf("%d",&qt);
                //ciclo para introduzir as operaçoes
                for(int i=0; i<qt;i++){
                    idOp++;
                    printf("###OPERACAO %d###\n",i+1);
                    printf("Insere a quantidade de maquinas:");
                    scanf("%d",&qt2);
                    int maquinas[qt2];
                    int tempos[qt2];
                    for(int j=0;j<qt2;j++){
                        printf("Insere as maquinas:");
                        scanf("%d",&maquinas[j]);
                    }
                    //inserir tempo
                     for(int j=0;j<qt2;j++){
                        printf("Insere tempo da maquina %d:",j+1);
                        scanf("%d",&tempos[j]);
                    }
                    operacoes=inserirOperacoes(operacoes,idOp,maquinas,tempos);
                    qt2=0;
                }*/

                operacoes= inserirOperacoes(operacoes,1,bb,cc);
                operacoes= inserirOperacoes(operacoes,2,rr,tt);   
                operacoes= inserirOperacoes(operacoes,3,kk,ii); 
                //operaçoes é a lista para adicionar
                break; 
            case 2:
                printf("Quantidade: %d\n", quantidadeJobs(jobs));
                break;
            case 3:
                listarJobs(jobs);
                break;
            case 4:
                printf("###### remover operacao #####\n\n");
                removerOperacoes(operacoes,2);
                break;
            case 5:
                printf("###### Alterar Operacao #####\n\n");
                alteraOperacao(operacoes,3,hh,ii);
                break;
            case 6:
                //insere e depois lista
                //tenho de passar arrays no parametros para maquinas e tempo 
                listarOperations(operacoes);
                break;
            case 7:
                //guardar ainda nao fiz
                //TODO:Ainda não fiz e nao funciona
                //
                break;
            default:
                break;
        }
    }while(option != 0);

    return 0;
}
