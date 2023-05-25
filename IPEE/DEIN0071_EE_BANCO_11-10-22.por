programa
{
	funcao inicio()
	{
		inteiro saque, notaDe10, restoDe10, notaDe20, restoDe20, notaDe50, restoDe50

		escreva("Insira o valor de saque \n")
		leia(saque)

		notaDe50 = saque / 50
		restoDe20 = saque % 50
		notaDe20 = restoDe20 / 20
		restoDe10 = restoDe20 % 20
		notaDe10 = restoDe10 / 10

		escreva("Você sacou: \n", notaDe50, " cédulas de R$50. \n", notaDe20, " cédulas de R$20. \n", notaDe10, " cédulas de R$10. \n")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 10; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */