#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "nomes.h"

int main(int argc, char *argv[]) {

int quantidade=20;
FILE *bin=fopen(argv[1],"rb");
if(argc!=2 || bin==NULL){
printf("Erro na abertura do arquivo");
return 0;
}
Cliente *buffer = (Cliente *)calloc(quantidade, sizeof(Cliente));

for(int a=0;a<20;a++){
fread(&(buffer+a)->nome,sizeof(char)*30 ,1,bin);
fread(&(buffer+a)->num_conta,sizeof(int),1,bin);
fread(&(buffer+a)->taxa,sizeof(double),1,bin);
fread(&(buffer+a)->saldo,sizeof(float),1,bin);
fread(&(buffer+a)->tipo,sizeof(enum tipo_conta),1,bin);
}
setlocale(LC_ALL, "Portuguese");

//interagir com o usuario
int *conta;
printf("Bem-vindo ao Caixa 24 horas\nDigite o número da sua conta:\n");
scanf("%d",conta);

if(*conta>19 || *conta<0) {
  printf("Nùmero inválido\n");
  return 0;
}
printf("Ola %s\n",(buffer+*conta)->nome);
int parar=0;
int comando;
float valor;

do
{
int c=0;
printf("Caixa Eletrônico\n Digite: \n 1-Para depositar\n 2-Para sacar\n 3-Para ver o seu saldo\n 4-Sair\n");
scanf("%d",&comando);
switch (comando)
{
case 1:
  printf("Digite o valor:\n");
  scanf("%f",&valor);
  if(valor<=0){
      printf("Valor inválido");
      break;;
    }
    else{
    (buffer+*conta)->saldo=depositar((buffer+*conta)->saldo,valor);break;}
case 2:
  printf("Digite o valor:\n");
  scanf("%f",&valor);
  if(valor<=0 || valor>(buffer+*conta)->saldo){
      printf("Valor inválido");
      break;;
    }
    else{
     (buffer+*conta)->saldo=sacar((buffer+*conta)->saldo,valor);
    break;}
 
case 3:
saldo(buffer,conta);
break;

 case 4:
  printf("Operação finalizada\n");
  break;
default:
  printf("Comando inválido\n");
  break;
}
}
while (comando!=4);


//regravar em um txt
fclose(bin);

FILE *res=fopen("resultado.txt","w");

 for (int i = 0; i < quantidade; i++){
    fprintf(res,"%s",(buffer+i)->nome);
    fprintf(res, "%d", (buffer+ i)->num_conta);
    fprintf(res,"%lf", (buffer+ i)->taxa);
    fprintf(res,"%f",(buffer+ i)->saldo);
    fprintf(res,"%i\n",(buffer+ i)->tipo);
    
 }
return 0;
}