programa
{
	
	funcao inicio()
	{
		real salario, salarioReajustado, percentualDeReajuste

		escreva("Qual é o salário? \n")
		leia(salario)
		
		se(salario < 500)
		{
			percentualDeReajuste = 0.15
		}
		senao se(salario < 1000)
		{
			percentualDeReajuste = 0.1
		}
		senao
		{
			percentualDeReajuste = 0.05
		}

		salarioReajustado = salario * (1 + percentualDeReajuste)

		escreva("O salário reajustado é de: R$", salarioReajustado)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 449; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */