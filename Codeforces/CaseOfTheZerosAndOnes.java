// CF556-D2-A

import java.util.Scanner;

public class CaseOfTheZerosAndOnes {
	static Scanner input = new Scanner(System.in);

	public static void main(String[] args) {
		
		int n = input.nextInt();
		String s = input.next();
		int ones=0, zeros=0;
		
		for(int i=0;i<s.length();i++) {
			if(s.charAt(i) == '1')
				ones++;
			else
				zeros++;
		}
		
		System.out.println(n-Math.min(ones, zeros)*2);
		

	}
	
}
