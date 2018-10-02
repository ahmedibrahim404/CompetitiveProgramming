// CF41-D2-A

import java.util.Scanner;

public class Translation {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		String str1 = input.nextLine(), str2 = input.nextLine();
		
		StringBuilder strReverse = new StringBuilder();
		strReverse.append(str1).reverse();
	

		if(strReverse.toString().equals(str2)) 
			System.out.println("YES");
		else
			System.out.println("NO");
		
		
		
	}

}
