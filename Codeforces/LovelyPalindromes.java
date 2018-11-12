// CF688-D2-B

import java.util.Scanner;

public class LovelyPalindromes {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		String n = input.next();
		
		System.out.println(n + "" + new StringBuilder(n).reverse().toString());

	}

}
