programa
{
	
	inclua biblioteca Matematica --> m
	funcao inicio()
	{
		const real E = 2.718 //281828459045235360287
		real a, b, c, k, x, y, z, v, g, f, i, j, teta

		escreva("Entre com o valor de A, B e C respectivamente para encontrar o valor de Z \n")
		leia(a, b, c)
		escreva("Entre com o valor de V, G e F respectivamente para encontrar o valor de Z \n")
		leia(v, g, f)
		
		z = m.potencia(E, m.potencia((m.potencia((b - c), v) + a * b / f), g))
		
		escreva("Entre com o valor de A, B e C respectivamente para encontrar o valor de Y \n")
		leia(a, b, c)

		y = m.logaritmo(((-b + m.potencia(b, 2) - 4 * a * c) / (2 * a)), E)

		escreva("Entre com o valor de i e j respectivamente para encontrar o valor de K \n")
		leia(i, j)	
		escreva("Entre com o valor do angulo teta para encontrar o valor de K \n")
		leia(teta)
		
		k = m.raiz((m.potencia(i, 2) + m.potencia(j, 2) - 2 * i * j * m.cosseno(teta)), 2)
		
		escreva("\n Valor de Z: ", z)
		escreva("\n Valor de Y: ", y)
		escreva("\n Valor de K: ", k)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 1016; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */