
#include "nomes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


float depositar(float saldo,float valor){
    
    saldo+=valor;
    printf("Operação realizada com sucesso\n");
    return saldo;
}
float sacar(float saldo,float valor){

    saldo-=valor;
    printf("Operação realizada com sucesso\n");
   return saldo;
  
}
void saldo(Cliente*space,int *conta){

  printf("Seu saldo é de %.2f\n",(space+*conta)->saldo);
}
FILE* armazenar(int a,char*text,FILE*dados){
  dados = fopen(text, "r");
  if(a!=2 || dados==NULL){
  printf("Erro na abertura do arquivo");
  return NULL;
  }
  else{
   return dados;
  }}

void gravar_array(Cliente*buffer,int quantidade,FILE*dados){
for (int i = 0; i < quantidade; i++) {
    fscanf(dados,"%s",(buffer+i)->nome);
    fscanf(dados, "%d", &(buffer + i)->num_conta);
    fscanf(dados,"%lf", &(buffer + i)->taxa);
    fscanf(dados,"%f",&(buffer + i)->saldo);
    fscanf(dados,"%d",&(buffer + i)->tipo);
  }

}
void gravar_bin(Cliente*buffer,int quantidade){
FILE*bin=fopen("binario.bin","ab");
for (int i = 0; i < quantidade; i++){
fwrite(&(buffer+i)->nome,sizeof(char),30,bin);
fwrite(&(buffer+i)->num_conta,sizeof(int),1,bin);
fwrite(&(buffer+i)->taxa,sizeof(double),1,bin);
fwrite(&(buffer+i)->saldo,sizeof(float),1,bin);
fwrite(&(buffer+i)->tipo,sizeof(enum tipo_conta),1,bin);
}
fclose(bin);
}