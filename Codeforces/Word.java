// CF59-D2-A

import java.util.Scanner;

public class Word {
	
	static Scanner input = new Scanner(System.in);
	
	public static void main(String[] args) {
		
		String wordChars = input.next();
		int m=0;
		for(int i=0;i<wordChars.length();i++) {
			if(Character.isLowerCase(wordChars.charAt(i)) == true) {
				m--;
			} else {
				m++;
			}
		}
		
		if(m>0) {
			System.out.println(wordChars.toUpperCase());
		} else {
			System.out.println(wordChars.toLowerCase());
		}
		
	}

}
