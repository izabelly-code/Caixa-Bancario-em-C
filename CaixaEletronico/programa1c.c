#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nomes.h"

FILE *dados;
int main(int argc, char *argv[]) {
 if(armazenar(argc,argv[1],dados)==NULL){
  return 0;}
 else{dados=armazenar(argc,argv[1],dados);}
  int quantidade=20;
  fscanf(dados, "%d", &quantidade);
  Cliente *c = (Cliente *)calloc(quantidade, sizeof(Cliente));
  gravar_array(c,quantidade,dados);
  gravar_bin(c,quantidade);
  fclose(dados);
return 0;
}
