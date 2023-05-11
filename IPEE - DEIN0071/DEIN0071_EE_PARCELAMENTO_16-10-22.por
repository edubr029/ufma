programa
{
	inclua biblioteca Matematica --> m
	
	funcao inicio()
	{
		real valorDoProduto, valorComJuros
		inteiro numeroDeParcelas
		
		escreva("Seja bem vindo(a) ao simulador de carrinho de compras\n")
		escreva("Aqui você terá um calculo de juros das parcerlas de compra.\n\n")
		escreva("Insira a baixo o valor do produto escolhido:\n R$")
		leia(valorDoProduto)

		se (valorDoProduto > 0)
		{			
			escreva("\nAbaixo está listado a quantidade de parcelas e seus respectivos valores de juros\n")
			escreva("\n\tx1 - Sem juros \n\tx2 - 1.1% de juros \n\tx3 - 2.7% de juros \n\tx4 - 4.2% de juros \n\tx5 - 5.9% de juros\n")
			escreva("\nEscolha a quantidade de parcelas (em até x5) que você deseja:\n x")
			leia(numeroDeParcelas)
			escreva("\n")
		}
		senao
		{
			escreva("O Valor do protudo não é válido.")
			retorne
		}

		se (numeroDeParcelas == 1)
		{
			escreva("O valor do produto a vista é de R$", m.arredondar(valorDoProduto, 2))
		}
		senao se (numeroDeParcelas == 2)
		{
			valorComJuros = ((valorDoProduto * 0.011) + valorDoProduto) / 2
			escreva("O valor da parcela com juros do produto em x2 é R$", m.arredondar(valorComJuros, 2),"\n")
		}
		senao se (numeroDeParcelas == 3)
		{
			valorComJuros = ((valorDoProduto * 0.027) + valorDoProduto) / 3
			escreva("O valor da parcela com juros do produto em x3 é R$", m.arredondar(valorComJuros, 2),"\n")
		}
		senao se (numeroDeParcelas == 4)
		{
			valorComJuros = ((valorDoProduto * 0.042) + valorDoProduto) / 4
			escreva("O valor da parcela com juros do produto em x4 é R$", m.arredondar(valorComJuros, 2),"\n")
		}
		senao se (numeroDeParcelas == 5)
		{
			valorComJuros = ((valorDoProduto * 0.059) + valorDoProduto) / 5
			escreva("O valor da parcela com juros do produto em x5 é R$", m.arredondar(valorComJuros, 2),"\n")
		}
		senao
		{
			escreva("O valor de parcela não é válido.")
			retorne 
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 1878; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */