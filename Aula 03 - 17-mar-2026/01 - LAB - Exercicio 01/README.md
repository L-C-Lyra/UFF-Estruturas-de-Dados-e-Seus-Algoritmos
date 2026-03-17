[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/vX_yV35u)
#### Problema 

Implemente a função **TLista* exclui(TLista* li, int valor)** que exclui o nó com campo INFO=*valor* de uma lista encadeada *li*. Usar o arquivo lista-encadeada.c em anexo, que já possui essa função declarada e algumas funções de apoio. Caso *valor* não exista na lista, ela deve permanecer inalterada. 

#### Entrada: 
- lista de inteiros separados por traço, que representa a lista encadeada
- valor inteiro *valor* que representa o elemento a ser excluído

#### Saída:
- nova lista, impressa usando a função imprime lista

#### Exemplos:

|Entrada|Saída|
|-------|-----|
|1-2-3<BR/>2 | 1 3<BR/>| 
|1-5-2-7-3<BR/>9 | 1 5 2 7 3<BR/><BR/>|

#### Dicas Importantes:

- A entrada e a saída já são tratadas no arquivo fornecido para ler e imprimir os dados no formato esperado pela questão. Vocês devem APENAS implementar a função solicitada no problema
- Não use arquivos .h (coloque todas as definições de tipo no arquivo .c)
