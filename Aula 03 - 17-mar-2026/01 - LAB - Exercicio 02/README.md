[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/eXFkX9hC)
# Alteração em Lista Encadeada

#### Problema 

No arquivo lista_encadeada.c, implemente a função **void altera(TLista* li, int vantigo, int vnovo)** que altera o valor do campo INFO de uma lista encadeada *li*, substituindo o valor *vantigo* pelo valor *vnovo* (ambos passados como parâmetro). Usar o arquivo lista-encadeada.c em anexo, que já possui essa função declarada e algumas funções de apoio. Caso *vantigo* não exista na lista, ela deve permanecer inalterada. Caso *vantigo* apareça mais de uma vez na lista, todas as ocorrências devem ser substituídas. 

#### Entrada: 
- lista de inteiros separados por traço, que representa a lista encadeada
- valor inteiro *vantigo* que representa o elemento a ser alterado
- valor inteiro *vnovo* que representa o novo valor do elemento *vantigo*

#### Saída:
- nova lista, impressa usando a função imprime lista

#### Exemplos:

|Entrada|Saída|
|-------|-----|
|1-2-3<BR/>2<BR/>5 | 1 5 3<BR/><BR/>| 
|1-5-2-7-3<BR/>1<BR/>99 | 99 5 2 7 3<BR/><BR/>|
|1-1-7<BR/>1<BR/>99 | 99 99 7<BR/><BR/>|

#### Dicas Importantes:

- A entrada e a saída já são tratadas no arquivo fornecido para ler e imprimir os dados no formato esperado pela questão. Vocês devem APENAS implementar a função solicitada no problema
