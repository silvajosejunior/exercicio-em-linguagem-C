#include<stdio.h>

int main(){
  float vendas,total;
    printf("qual o valor total das vendas");
      scanf("%f",&vendas);
      total=vendas+(vendas*10)/100;
        printf("o total das venda e: %.2f",total);
}
