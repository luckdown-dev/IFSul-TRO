import java.util.Scanner;

public class Exemplo01
{
	public static void main(String[] args) {
	    int numb1, numb2, soma;
	    
	    Scanner teclado = new Scanner(System.in);
	    
		System.out.print("Informe o primeiro valor: ");
		numb1 = teclado.nextInt();
		
		System.out.print("Informe o segundo valor: ");
		numb2 = teclado.nextInt();
		
		soma = numb1 + numb2;
		
		System.out.print("O resultado e: " + soma);
	}
}
