## Problema 

Implemente a função int maior(TNo *raiz) que recebe um ponteiro para a raiz de uma árvore B armazenada em memória principal e retorna a maior chave que está armazenada na árvore. O percurso na árvore deve ser feito de forma a ser o mais otimizado possível. Sua função deve imprimir cada nó examinado, usando para isso a função void imprime\_no(TNo *a), fornecida no arquivo arvore\_b.c em anexo. Essa função faz a impressão usando a formatação esperada pelos casos de teste cadastrados no Run.Codes, por isso é importante que ela seja usada dentro da sua função.  

Use o arquivo fornecido nesse exercício, pois ele já contém o tratamento de entrada e saída. 

## Entrada: 
- Ordem da árvore B
- Árvore B a ser analisada. As chaves dos nós da árvore devem ser informadas separados por traço (sem espaço entre o valor da chave e o traço), na ordem em que devem ser inseridos na árvore (o esqueleto fornecido nesse exercício já realiza a inserção). 

## Saída:
- Inteiro que representa a maior chave armazenada na árvore
- Sua função deve imprimir cada nó examinado, usando para isso a função void imprime\_no(TNo *a), fornecida no arquivo arvore\_b.c em anexo. Essa função faz a impressão usando a formatação esperada pelos casos de teste cadastrados no Run.Codes, por isso é importante que ela seja usada dentro da sua função.

## Exemplo1:

|Entrada|Saída|
|---|---| 
|2<BR/>10-20-11-15-14-23-45-60-32|Nos examinados:<BR/>   14   23<BR/>   32   45   60<BR/>Maior chave: 60|
|4<BR/>400-300-150-200|Nos examinados:<BR/>  150  200  300  400<BR/>Maior chave: 400|

## Dicas Importantes:

- A entrada e a saída já são tratadas no arquivo fornecido para ler e imprimir os dados no formato esperado pela questão. Vocês devem APENAS implementar a função solicitada no problema
- Não use arquivos .h (coloque todas as definições de tipo no arquivo .c)
