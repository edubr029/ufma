
programa
{
	funcao inicio()
	{
		real a, b, c, d, aux

		escreva("Escreva o valor de A: \n")
		leia(a)

		escreva("Escreva o valor de B: \n")
		leia(b)

		escreva("Escreva o valor de C: \n")
		leia(c)

		escreva("Escreva o valor de D: \n")
		leia(d)

		se(a < b)
		{
			aux = a
			a = b
			b = aux
		}
		
		se(a < c)
		{
			aux = a
			a = c
			c = aux
		}

		se(a < d)
		{
			aux = a
			a = d
			d = aux
		}
		
		se(b < c)
		{
			aux = c
			c = b
			b = aux
		}
		
		se(b < d)
		{
			aux = d
			d = b
			b = aux
		}

		se(c < d)
		{
			aux = d
			d = c
			c = aux
		}
		
		escreva("Os valores em ordem decrescente são: \n A = ", a, "\n B = ", b, "\n C = ", c, "\n D = ", d)
		
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 677; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */