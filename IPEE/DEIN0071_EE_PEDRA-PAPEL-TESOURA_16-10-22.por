programa
{
	inclua biblioteca Util
	
	funcao inicio()
	{
		inteiro jogador, computador, pedraPapelTesoura

		escreva("Pedra, Papel e Tesoura\n\n")
		escreva("\tEscolha Pedra (1), Papel (2) ou Tesoura (3)\n\n")
		leia(jogador)
		escreva("\n")

		computador = sorteia(1, 3)

		pedraPapelTesoura = jogador - computador

		escolha(pedraPapelTesoura)
		{
			//empate
			caso 0:
				escreva("O computador escolheu ", computador, ". Você empatou!\n")
			pare
			//vitoria
			caso 1:
				escreva("O computador escolheu ", computador, ". Você venceu!\n")
			pare
			caso -2:
				escreva("O computador escolheu ", computador, ". Você venceu!\n")
			pare
			//derrota
			caso 2:
				escreva("O computador escolheu", computador, "Você perdeu!\n")
			pare
			caso -1:
				escreva("O computador escolheu", computador, "Você perdeu!\n")
			pare
			//valor invalido
			caso contrario:
				escreva("Escolha um valor válido!\n")
				retorne
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 656; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */