programa
{
	funcao inicio()
	{
		real a, b, c, aux

		escreva("Escreva o valor de A: \n")
		leia(a)

		escreva("Escreva o valor de B: \n")
		leia(b)

		escreva("Escreva o valor de C: \n")
		leia(c)
		
		aux = a

		se(b < aux)
		{
			aux = b
		}
		se(c < aux)
		{
			aux = c
		}

		escreva("O menor valor é: ", aux)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 265; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */