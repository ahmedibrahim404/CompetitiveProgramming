// CF281-D2-A

import java.util.Scanner;

public class WordCapitalization {

	static Scanner input = new Scanner(System.in);
	public static void main(String[] args) {
		
		String str = input.next();

		String strModified = str.substring(0, 1).toUpperCase() + str.substring(1);
		
		System.out.println(strModified);
		
	}

}
