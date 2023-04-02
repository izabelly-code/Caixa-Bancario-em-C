#ifndef nomes
#define nomes

#include <stdio.h>
enum tipo_conta { CORRENTE, POUPANCA, SALARIO };
typedef struct {

  char nome[30];
  int num_conta;
  double taxa;
  float saldo;
  enum tipo_conta tipo;
} Cliente;
FILE* armazenar(int a,char*text,FILE*dados);
void gravar_array(Cliente*buffer,int quantidade,FILE *dados);
void gravar_bin(Cliente*buffer,int quantidade);
float depositar(float ,float);
float sacar(float,float );
void saldo(Cliente*space ,int *conta );

#endif /*nomes*/