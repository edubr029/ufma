programa
{
	inclua biblioteca Matematica --> m
	
	funcao inicio()
	{	
		const inteiro NUMERO_DE_CASAS_DECIMAIS = 3
		real resistencia, resistenciaEquivalente = 0.0, inversoDasResistencias = 0.0
		inteiro contagemDeIteracao = 0, numeroDeResistores
		
		escreva("Este programa irá calcular o valor da resistência equivalente (Req) em paralelo de N resistores.\n\n")
		
		faca
		{	
			escreva("Entre com a quantidade de resistores desejada:\n")
			leia(numeroDeResistores)

			se(numeroDeResistores < 2)
			{
				escreva("Entre com um valor válido (2 ou mais resistências)!\n\n")
			}
			
		}enquanto(numeroDeResistores < 2)

		faca
		{	
			contagemDeIteracao++
			escreva("Entre com o valor de R", contagemDeIteracao, ":\n")
			leia(resistencia)

			enquanto(resistencia <= 0)
			{	
				escreva("Valor inválido! Entre com um valor maior que zero.\n\n")
				escreva("Entre com o valor de R", contagemDeIteracao, ":\n")
				leia(resistencia)
			}
			
			inversoDasResistencias+= m.potencia(resistencia, -1.0)
			
		}enquanto(contagemDeIteracao <= numeroDeResistores)

		resistenciaEquivalente = m.potencia(inversoDasResistencias, -1.0)
		
		escreva("A resistencia equivalente de ", numeroDeResistores, " resistores é Req = ", m.arredondar(resistenciaEquivalente, NUMERO_DE_CASAS_DECIMAIS), "Ω")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 1302; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */