#include <stdio.h>
#include <stdlib.h>

/*
------------------------------------------------------------------------------------------------------------
Aluno(a):Fabricio Braga
RA: 196645
------------------------------------------------------------------------------------------------------------
*/


/*
------------------------------------------------------------------------------------------------------------
void ordena(int *conj, int tam);


Esta funcao deve ordenar um conjunto dado como parametro.

Parametros:

- conj -> Ponteiro para o conjunto;
- tam -> Quantidade de elementos do conjunto;

------------------------------------------------------------------------------------------------------------
*/

void ordena(int *conj, int tam) {
 	int i, j;
	char aux;

	for (i = tam - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if ((conj[j]) > conj[j + 1]) {
				aux = conj[j];
				conj[j] = conj[j + 1];
				conj[j + 1] = aux;
			}
		}
	}
}


/*
------------------------------------------------------------------------------------------------------------
int pertence(int *conj, int tam, int elemento);


Esta funcao deve verificar se um elemento esta presente no conjunto.

Parametros:

- conj -> Ponteiro para o conjunto;
- tam -> Quantidade de elementos do conjunto;
- elemento -> Elemento no qual deve ser ser verificado se esta presente no conjunto;

Retorno

- 1 Caso o elemento PERTENCA conjunto;
- 0 Caso o elemento NAO PERTENCA ao conjunto;

------------------------------------------------------------------------------------------------------------
*/

int pertence(int *conj, int tam, int elemento) {
//int pertence(char conj[], int tam, char letra){
    int i;
    
    for(i = 0; i < tam; i++){
        if(conj[i] == elemento)
            return 1;
    }
    return 0;
}

/*
------------------------------------------------------------------------------------------------------------
int contido(int *conj_A, int *conj_B, int tam_A, int tam_B);


Esta funcao deve verificar se o conjunto A esta contido no conjunto B.

Parametros:
- conj_A -> Ponteiro para o conjunto A;
- conj_B -> Ponteiro para o conjunto B;
- tam_A -> Quantidade de elementos do conjunto A;
- tam_B -> Quantidade de elementos do conjunto B;

Retorno

- 1 Caso o conjunto A ESTEJA CONTIDO no conjunto B;
- 0 Caso o conjunto A NAO ESTEJA CONTIDO no conjunto B;

------------------------------------------------------------------------------------------------------------
*/

int contido(int *conj_A, int *conj_B, int tam_A, int tam_B) {
//int contido(char conj1[], char conj2[], int tam1, int tam2){
  int i;
  
  for(i = 0; i < tam_A; i++){
        if (!pertence(conj_B, tam_B, conj_A[i]))
            return 0;
  }
    return 1;
}

/*
------------------------------------------------------------------------------------------------------------
int* init(int *tam, int *cap);


Esta funcao deve inicializar um vetor(conjunto).

Parametros:
- tam -> Ponteiro para a quantidade de elementos do conjunto;
- cap -> Ponteiro para a capacidade de elementos do conjunto;

OBS:
- A capacidade inicial do vetor(conjunto) deve ser 2.
- A quantidade inicial de elementos no vetor(conjunto) deve ser zero.
- Nao confundir capacidade com quantidade de elementos.

Retorno

- Ponteiro para o conjunto;

------------------------------------------------------------------------------------------------------------
*/

int* init(int *tam, int *cap) {
	*tam = 0;
	*cap = 2;
	int *ponte = malloc(*cap*sizeof(int));
  return ponte;
}

/*
------------------------------------------------------------------------------------------------------------
int* adicao(int *conj, int *tam, int *cap, int elemento);


Esta funcao deve adicionar um novo elemento no conjunto, ou seja, se o elemento ja pertence ao 
conjunto o mesmo NAO deve ser adicionado.

Parametros:
- conj -> Ponteiro para o conjunto;
- tam -> Ponteiro para a quantidade de elementos do conjunto;
- cap -> Ponteiro para a capacidade de elementos do conjunto;
- elemento -> Elementos para ser adicionado;

OBS:
- Ao adicionar um novo elemento o tamanho atual do conjunto devera ser atualizado;
- Caso o ponteiro para o conjunto seja NULL, o conjunto devera ser alocado com uma capacidade de dois (02) 
e a atualizacao da capacidade deverar ser feita;
- Caso a quantidade de elementos do conjunto seja igual a capacidade do conjunto e um novo elemento tenha que 
ser inserido, então o conjunto tera de ser realocado com o dobro da capacidade e a capcidade do conjunto 
devera ser atualizada;

Retorno

- Ponteiro para o conjunto;

------------------------------------------------------------------------------------------------------------
*/

int* adicao(int *conj, int *tam, int *cap, int elemento) {

	if(conj == NULL)
		conj = init(tam, cap);

	if (!pertence(conj, *tam, elemento)){
		if(*tam >= *cap){	
			conj = realloc(conj,*cap*2*sizeof(int));
			*cap = *cap*2;
		}

    conj[*tam] = elemento;
    *tam = *tam + 1;
  }

  return conj;
}

/*
------------------------------------------------------------------------------------------------------------
int* subtracao(int *conj, int *tam, int *cap, int elemento);


Esta funcao deve remover um elemento no conjunto caso ele exista.

Parametros:
- conj -> Ponteiro para o conjunto;
- tam -> Ponteiro para a quantidade de elementos do conjunto;
- cap -> Ponteiro para a capacidade de elementos do conjunto;
- elemento -> Elementos para ser removido;

OBS:
- Ao remover um elemento o tamanho atual do conjunto devera ser atualizado;
- Caso a capacidade seja maior que dois (02) e a quantidade de elementos do conjunto seja menor ou igual que 1/4 da capacidade do conjunto, então 
o conjunto tera de ser realocado com a metade da capacidade e a capacidade do conjunto devera ser atualizada.

Retorno

- Ponteiro para o conjunto;

------------------------------------------------------------------------------------------------------------
*/

int* subtracao(int *conj, int *tam, int *cap, int elemento) {
  int i;
  
	if(conj == NULL)
		conj = init(tam, cap);
  
  if (pertence(conj, *tam, elemento)){
      for(i = 0; i < *tam; i++){
          if(elemento == conj[i]){
              conj[i] = conj[*tam-1];
              *tam = *tam-1;

              if (*tam <= (1/4)*(*cap)){
              	conj = realloc(conj, *cap/2*sizeof(int));
              	*cap = *cap/2;
              }

              return conj;
          }
      }
  }
  return conj;
}



/*
------------------------------------------------------------------------------------------------------------
int* uniao(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C);


Esta funcao deve computar a uniao entre os conjuntos A e B. O resultado dessa uniao deve ser armazenado em 
um novo conjunto C.

Parametros:
- conj_A -> Ponteiro para o conjunto A;
- conj_b -> Ponteiro para o conjunto B;
- tam_A -> Quantidade de elementos do conjunto A;
- tam_B -> Quantidade de elementos do conjunto B;
- tam_C -> Ponteiro para a quantidade de elementos do conjunto resultante;
- cap_C -> Ponteiro para a capacidade de elementos do conjunto resultante;
- elemento -> Elementos para ser removido;

OBS:
- O tamanho atual e a capacidade do conjunto resultante C devera seguir a logica apresentada nas funcoes 
init e adicao.
- Os valores de quantidade de elementos e capacidade do conjunto resultante C devem ser atualizados 
respectivamente nos parametros tam_C e cap_C.

Retorno

- Ponteiro para o conjunto C;

------------------------------------------------------------------------------------------------------------
*/

int* uniao(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C) {
  int i, *conj;

  *tam_C = tam_A;

	if(conj == NULL)
		conj = init(tam_C, cap_C);

	for (i=0; i<tam_A; i++){
		conj[i] = conj_A[i];
	}
	for (; i<(tam_B + tam_A); i++){
		conj = adicao(conj, tam_C, cap_C, conj_B[i]);
	}

	return conj;
}

/*
------------------------------------------------------------------------------------------------------------
int* intersecao(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C);


Esta funcao deve computar a intersecao entre os conjuntos A e B. O resultado dessa intersecao deve ser 
armazenada em um novo conjunto C.

Parametros:
- conj_A -> Ponteiro para o conjunto A;
- conj_b -> Ponteiro para o conjunto B;
- tam_A -> Quantidade de elementos do conjunto A;
- tam_B -> Quantidade de elementos do conjunto B;
- tam_C -> Ponteiro para a quantidade de elementos do conjunto resultante;
- cap_C -> Ponteiro para a capacidade de elementos do conjunto resultante;
- elemento -> Elementos para ser removido;

OBS:
- O tamanho atual e a capacidade do conjunto resultante C devera seguir a logica apresentada nas funcoes 
init e adicao.
- Os valores de quantidade de elementos e capacidade do conjunto resultante C devem ser atualizados 
respectivamente nos parametros tam_C e cap_C.

Retorno

- Ponteiro para o conjunto C;

------------------------------------------------------------------------------------------------------------
*/

int* intersecao(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C) {
  int *conj, i, j, k;

	if(conj == NULL)
		conj = init(tam_C, cap_C);

	for (i=0; i<tam_A; i++){
		for (j=0; j<tam_B; j++){
			if(conj_A[i] == conj_B[i]){
				conj[k] = conj_A[i];
				k++;
			}
		}
	}

	*tam_C = k;
	*cap_C = k*2;

	return conj;
}

/*
------------------------------------------------------------------------------------------------------------
int* diferenca(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C);


Esta funcao deve computar a diferenca entre os conjuntos A e B. O resultado dessa diferenca deve ser 
armazenada em um novo conjunto C.

Parametros:
- conj_A -> Ponteiro para o conjunto A;
- conj_b -> Ponteiro para o conjunto B;
- tam_A -> Quantidade de elementos do conjunto A;
- tam_B -> Quantidade de elementos do conjunto B;
- tam_C -> Ponteiro para a quantidade de elementos do conjunto resultante;
- cap_C -> Ponteiro para a capacidade de elementos do conjunto resultante;
- elemento -> Elementos para ser removido;

OBS:
- O tamanho atual e a capacidade do conjunto resultante C devera seguir a logica apresentada nas funcoes 
init e adicao.
- Os valores de quantidade de elementos e capacidade do conjunto resultante C devem ser atualizados 
respectivamente nos parametros tam_C e cap_C.

Retorno

- Ponteiro para o conjunto C;

------------------------------------------------------------------------------------------------------------
*/

int* diferenca(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C) {
	int *conj, i, j, k;

	if(conj == NULL)
	conj = init(tam_C, cap_C);

	for (i=0; i<tam_A; i++){
		for (j=0; j<tam_B; j++){
			if(conj_A[i] != conj_B[i]){
				conj[k] = conj_A[i];
				k++;
			}
		}
	}
	*tam_C = k;
	*cap_C = k*2;

	return conj;
}
