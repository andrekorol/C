Algoritmo "triangulo"

// Disciplina   : [Linguagem e L�gica de Programa��o] 
// Professor    : Antonio Carlos Nicolodi 
// Descri��o   : Aqui voc� descreve o que o programa faz! (fun��o)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 16/3/2017
Var
// Se��o de Declara��es das vari�veis 
base, altura, area,polegadas, jardas, milhas :real

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
escreva("Entre o valor da base do tri�ngulo, em p�s")
leia(base)
escreval("Agora entre o valor da altura do tri�ngulo, em p�s")
leia(altura)
area <- (base * altura) / 2
escreval("A �rea do tri�ngulo � igual a: ")
escreval(area, "p�s")

polegadas <- area * 12
jardas <- (1.0 / 3.0) * pes
milhas <- (1.0 / 1760) * jardas

escreval(polegadas, "polegadas")
escreval(jardas, "jardas")
escreval(milhas, "milhas")

Fimalgoritmo