programa
{
	inclua biblioteca Matematica --> m
	funcao inicio()
	{
		real entrada, aux1, saida
		inteiro casas, aux2
		
		escreva("Insira o número real na base 10: ")
		leia(entrada)
		escreva("\nQual o número de casas decimais desejadas?: ")
		leia(casas)
		
		aux1 = entrada * m.potencia(10, casas)
		aux2 = aux1 / 1
		saida = aux2 / m.potencia(10, casas)
		
		escreva("\nO número arredondado é: ",saida)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 81; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */