programa
{
	inclua biblioteca Matematica --> m	
	funcao inicio()
	{
		inteiro binario, digito1, digito2, digito3, decimal

		escreva("Entre com um número binário de 3 digitos: \n")
		leia(binario)

		digito1 = binario / 100
		digito2 = (binario / 10) % 10
		digito3 = binario % 10		

		decimal = (digito3 * m.potencia(2.0, 2.0)) +  (digito2 * m.potencia(2.0, 1.0)) + (digito1 * m.potencia(2.0, 0.0))

		escreva("O valor em decimal é: \n", decimal)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 450; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {digito1, 6, 19, 7}-{digito2, 6, 28, 7}-{digito3, 6, 37, 7}-{decimal, 6, 46, 7};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */