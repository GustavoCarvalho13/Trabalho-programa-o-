#ifndef __TOOLS_H_
#define __TOOLS_H_

#define MAXOPERATION 6
#define MAXMAQUINAS 7
#define MAXTEMPO 60
// este ficheiro serve para fazer as assinaturas
//  entre os ficheiros
// este ficheiro so leva as assinaturas nada mais de logica

struct Job;
struct Operation;

typedef struct jp{
	int id;
	int operacao[7];
	struct jp *seguinte;
} Job;

typedef struct op{
	int id;
	int maquina[MAXMAQUINAS];
	int tempo[MAXTEMPO];
	struct op *seguinte;
} Operation;

//assinaturas

//JOBS
Job *inserirJobs(Job *jp, int id, int operacao[MAXOPERATION]);
void listarJobs(Job *jp);
int quantidadeJobs(Job *jp);
void guardarJobs(Job *jp);


//OPERAÇÔES
Operation *inserirOperacoes(Operation *op, int id, int maq[MAXMAQUINAS], int temp[MAXTEMPO]);
Operation* procuraOperacoes(Operation* op, int id);
Operation* removerOperacoes(Operation * op, int id);
Operation* alteraOperacao(Operation* op, int id,int* maq,int* temp);
void listarOperations(Operation *op);

//OUTROS
int menu();

#endif
