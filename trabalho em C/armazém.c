#include <stdio.h>

#define QTDPRODUTO 10
#define QTDARMAZEM 5

void mostrar_preco_produtos(float preco_produto[]){
  int i = 0;
  for(i=0;i<QTDPRODUTO;i++){
    printf("Produto %d custo %.2f\t  ",i+1,preco_produto[i]);
  }
  printf("\n\n");
}
void mostrar_armazens(int armazens[][QTDPRODUTO]){
  int i = 0;
  int j = 0;
  for(i = 0; i<QTDARMAZEM;i++){
    printf("Armazen %d: \n",i+1);
    for(j=0;j<QTDPRODUTO;j++){
      printf("Quantidade do produto %d: %d \t", j+1, armazens[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}
void mostrar_qtd_produtos_por_armazem(int qtd_produto_armazem[], int armazens[][QTDPRODUTO]){
  int acumulador = 0;
  int i = 0;
  int j=0;
  for(i = 0; i<QTDARMAZEM;i++){
    for(j=0;j<QTDPRODUTO;j++){
      acumulador += armazens[i][j];
    }
    qtd_produto_armazem[i] = acumulador;
    acumulador= 0;
    printf("No armazem %d tem %d produtos\n", i+1,qtd_produto_armazem[i] );
  }
  printf("\n");
}
void mostrar_qtd_total_por_produto(int qtd_produto_armazem[], int armazens[][QTDPRODUTO]){
  int acumulador = 0;
  int i = 0;
  int j=0;
  for(i = 0; i<QTDPRODUTO;i++){
    for(j=0;j<QTDARMAZEM;j++){
      acumulador += armazens[j][i];
    }
    qtd_produto_armazem[i] = acumulador;
    acumulador= 0;
    printf("Existem %d unidades do produto %d\n",qtd_produto_armazem[i], i+1);
  }
  printf("\n");
}
int produto_maior_estoque(int armazens[][QTDPRODUTO]){
  int maior_estoque_idx = 0;
  int maior_estoque_valor = armazens[0][0];
  int i = 0;
  int j = 0;
  for(i=0;i<QTDPRODUTO; i++){
    for(j=0; j<QTDARMAZEM; j++){
      if(armazens[j][i] < maior_estoque_valor){
        maior_estoque_valor = armazens[j][i];
        maior_estoque_idx = i;
      }
    }
  }
  return maior_estoque_idx;
}
int menor_estoque_armazenado(int armazens[][QTDPRODUTO]){
  int menor_estoque_idx = 0;
  int menor_estoque_valor = armazens[0][0];
  int i = 0;
  int j = 0;
  for(i=0;i<QTDPRODUTO; i++){
    for(j=0; j<QTDARMAZEM; j++){
      if(armazens[j][i] < menor_estoque_valor){
        menor_estoque_valor = armazens[j][i];
        menor_estoque_idx = i;
      }
    }
  }
  return menor_estoque_idx;
}
void custo_por_armazem(int armazens[][QTDPRODUTO],  float preco_produto[QTDPRODUTO] ){
  float custo = 0;
  int i = 0;
  int j = 0;
  for(i = 0; i<QTDARMAZEM;i++){
    for(j=0;j<QTDPRODUTO;j++){
      custo = armazens[i][j] * preco_produto[i];
    }
    printf("Armazem %d tem um custo de %.2f\n", i+1, custo);
    custo=0;
  }
  printf("\n");
}
int main(){
  float custo_armazem[QTDPRODUTO];
  int qtd_produto_armazem[QTDARMAZEM];
  int armazens[QTDARMAZEM][QTDPRODUTO];
  float preco_produto[QTDPRODUTO] ;
  int i = 0;
  int j = 0;
  	printf("\t\t\tPRECO DOS PRODUTOS\n\n\n");
  for(i=0;i<QTDPRODUTO;i++){
    printf("Informe o preco produto %d: ",i+1);
    scanf("%f", &preco_produto[i]);
  }
  printf("\n");

  printf("\t\t\tQUANTIDADE DE PRODUTOS ESTOCADOS EM CADA ARMAZEN\n\n\n");
  for(i = 0; i<QTDARMAZEM;i++){
    printf("Armazen %d: \n",i+1);
    for(j=0;j<QTDPRODUTO;j++){
      printf("Quantidade do produto %d: ",j+1);

      scanf("%d", &armazens[i][j]);
    }
  }
  mostrar_preco_produtos(preco_produto);
  mostrar_armazens(armazens);
  mostrar_qtd_produtos_por_armazem(qtd_produto_armazem, armazens);
  mostrar_qtd_total_por_produto(qtd_produto_armazem, armazens);
  int maior_estoque_idx = produto_maior_estoque(armazens);
  printf("O preco do produto com maior estoque eh: %.2f\n", preco_produto[maior_estoque_idx] );
  int menor_estoque_idx = menor_estoque_armazenado(armazens);
  printf("O produto com menor estoque eh: Produto %d\n\n",menor_estoque_idx+1 );
  custo_por_armazem(armazens,preco_produto);
	return 0 ;
  // esse codigo rendeu muita discurssão
}
