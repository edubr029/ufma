programa
{
	
	funcao inicio()
	{
		real consumo
		real salarioMinimo
		real percentual
		real valorDaConta
		real valorDaContaComDesconto

		escreva("Entre com o consumo de água, o valor do salário mínimo e o percentual de desconto de 0% à 100%\n")
		leia(consumo, salarioMinimo, percentual)

		valorDaConta = (0.02 * salarioMinimo * consumo) / 1000
		valorDaContaComDesconto = valorDaConta * (1 - percentual/100)

		escreva("O valor da conta SEM desconto é: ", valorDaConta, "\n")
		escreva("O valor da conta COM desconto é: ", valorDaContaComDesconto)
		
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 568; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {consumo, 6, 7, 7}-{salarioMinimo, 7, 7, 13}-{percentual, 8, 7, 10}-{valorDaConta, 9, 7, 12}-{valorDaContaComDesconto, 10, 7, 23};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */