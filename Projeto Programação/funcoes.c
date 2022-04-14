#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <unistd.h>
#include "header.h"

//ligar ao header para tudo que eu fazer aqui 
//fica aqui ligado ao main 

int quantidadeJobs(Job * jp) {
  int soma = 0;
  while (jp != NULL) {
    jp = jp -> seguinte;
    soma++;
  }
  return (soma);
}

//INSERIR

Job* inserirJobs(Job * jp, int id, int* operacao){

  Job *jb = (Job*) malloc(sizeof(Job));

  if (jb!=NULL)
  {
    jb->id = id;
    //copiar array 
    int sizearrayoperacao=sizeof(operacao);
    for(int h=0;h<sizearrayoperacao;h++){
      jb->operacao[h] = operacao[h] ;
    }
    
    jb->seguinte = jp;
    return(jb);
  }
  else return(jp);
}


Operation* inserirOperacoes(Operation * op, int id, int* maq, int* temp){

  Operation *ot = (Operation*) malloc(sizeof(Operation));
  ot->id=id;
  int sizearraytemp= sizeof(temp);
  int sizearraymaq= sizeof(maq);
  // passa de um arrey para o outro /maquina/
  for(int i=0; i<sizearraymaq;i++){
    ot->maquina[i]=maq[i];
  }

  // passa de um arrey para o outro /tempo/
  for(int j=0; j<sizearraytemp;j++){
    ot->tempo[j]=temp[j];
  }
  ot->seguinte=NULL;
  if(op == NULL){
    op= ot;
  }else{
    Operation* lastnode = op;
    while(lastnode->seguinte != NULL){
      lastnode = lastnode->seguinte;
    }
    lastnode->seguinte = ot;
  }
  return op;
}



Operation* removerOperacoes(Operation * op, int id){
  
  if( op == NULL) return NULL;

  if(op->id == id){
    Operation* aux = op;
    op=op->seguinte;
    free(aux);
  }
  else{
    Operation *aux=op;
    Operation *auxAnt = aux;
    while(aux && aux->id != id){
      auxAnt=aux;
      aux = aux->seguinte;
    }
    if(aux != NULL){
      auxAnt->seguinte= aux->seguinte;
      free(aux);
    }

  }
  return op;
}

Operation* procuraOperacoes(Operation* op, int id){
  if(op==NULL) return NULL;
  else{
    Operation* aux = op;
    while(aux != NULL){
      if(aux->id == id){
        return aux;
      }
      aux= aux->seguinte;
    }
    return NULL;
  }
}



Operation* alteraOperacao(Operation* op, int id,int* maq,int* temp){
  Operation* aux = procuraOperacoes(op, id);
  if(aux != NULL){
    // insere as maquinas de novo
    int sizearraymaq= sizeof(maq);
    // passa de um arrey para o outro /maquina/
    for(int i=0; i<sizearraymaq;i++){
    aux->maquina[i]=maq[i];
    }

    //insere o tempo de novo 
    int sizearraytemp= sizeof(temp);
    // passa de um arrey para o outro /maquina/
    for(int i=0; i<sizearraytemp;i++){
    aux->tempo[i]=temp[i];
    }


  }
  return op;
}



//LISTAR

void listarJobs(Job *jp){
  while (jp!=NULL)
 {
    printf("Job n%d\n",jp->id );
    for(int j=0; j<7;j++){
      if(jp->operacao[j]==0) break;
      printf(" Lista de operacoes:%d\n", jp->operacao[j]);
      
    }
    jp = jp->seguinte;
 }


}


void listarOperations(Operation *op){
  while (op!=NULL)
 {
    printf("Operacao n%d\n",op->id );

    //lista as maquinas que se pode usar 
    printf(" Lista   de  Maquinas:(");
    for(int j=0; j<7;j++){  
      if(op->maquina[j+1]==0){
        printf("%d", op->maquina[j]);
        break;
      }else
          printf("%d,", op->maquina[j]); 
    }
    printf(")");

    //lista o tempo que cada maquina demora

    printf("\nTempo de cada Maquina:[");
    for(int j=0; j<7;j++){  
      if(op->tempo[j+1]==0){
        printf("%d", op->tempo[j]);
        break;
      }else
          printf("%d,", op->tempo[j]); 
    }
    printf("]\n");

    op = op->seguinte;
 }


}

//CALCULAR

int calculaTempJob(Job* jp, int id, int* op){
return (0);
}

//TODO: acabar o armazenamento  
//BUG: Nao guarda direito so guarda zeros
//ARMAZENAR JOBS
/*
  void guardarJobs(Job *jp){
    int fp;
    int cod, len;
    char buffer[16] = {0};
    fp = open("data.txt",O_WRONLY|O_CREAT);
    //verifica se criou o ficheiro 

    printf("Resultado do ficheiro: %d\n",fp);
    if(fp == -1){
      perror("Erro ficheiro:");
    }

    

    while (jp!=NULL){
      
    printf("Job n%d\n",jp->id );
    jp->id= cod;
    len= sizeof(cod);
    buff= &cod;
    write(fp,buff,len);
    
    jp = jp->seguinte;
 }



  close(fp);
 }
*/


//MENU
//funçao que retorna ao menu

int menu(){
    int opcao;
    do{
        printf("---------MENU-------\n");
        printf("1 - Inserir job com operacoes\n");
        printf("2 - Quantidade de jobs\n");
        printf("3 - Listar jobs\n");
        printf("4 - Remover operacao\n");
        printf("5-  Alterar operacao\n");
        printf("6-  Listar operacoes\n");
        printf("7- Guardar \n");
        printf("0 - Sair\n");
        printf("Opcao:");
        scanf("%d",&opcao); 
    }
    while ((opcao>12)||(opcao<0));
    return(opcao);
}
 

