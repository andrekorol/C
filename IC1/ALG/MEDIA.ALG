Algoritmo "troca"
// Disciplina   : [Introdu��o � Computa��o]
// Professor    : Ver�nica Di Grassi
// Descri��o   : Aqui voc� descreve o que o programa faz! (fun��o)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 16/3/2017
Var
nota1, nota2, nota3 :real
peso1, peso2, peso3, media: real

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc...
escreva("Entre com a primeira nota: ")
leia(nota1)
escreval("Entre com o peso da primeira nota: ")
leia(peso1)
escreval("Entre com a segunda nota: ")
leia(nota2)
escreval("Entre com o peso da segunda nota: ")
leia(peso2)
escreval("Entre com a terceira nota: ")
leia(nota3)
escreval("Entre com o peso da terceira nota: ")
leia(peso3)

nota1 <- nota1 * peso1
nota2 <- nota2 * peso2
nota3 <- nota3 * peso3

media <- nota1 + nota2 + nota3

escreva("A m�dia ponderada do aluno �: ", media)

Fimalgoritmo