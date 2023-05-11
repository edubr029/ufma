programa
{
	funcao inicio()
	{
		real distanciaEmKm, gasolinaEmLitros, rendimentoKmPorLitro

		escreva("Escreva a quilometragem percorrida: \n")
		leia(distanciaEmKm)
		escreva("Escreva a quantidade abastecida em litros: \n")
		leia(gasolinaEmLitros)

		logico distanciaIncorreta = distanciaEmKm < 0
		logico gasolinaIncorreta = gasolinaEmLitros <= 0

		se(distanciaIncorreta)
		{
			escreva("O valor de distância não é válido, verifique novamente")
		}
		senao se(gasolinaIncorreta)
		{
			escreva("O valor em litros de gasolina não é válido, verifique novamente")
		}
		senao
		{
			rendimentoKmPorLitro = distanciaEmKm / gasolinaEmLitros

			escreva("O rendimento do carro é de ", rendimentoKmPorLitro, " km/l")
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 640; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */