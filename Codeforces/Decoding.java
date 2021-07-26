// CF746-D2-B

import java.util.Scanner;

public class Decoding {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		String s = input.next();
		String s2="";
		int curr=0, turn=0;
		
		while(n > 0) {
			
			if(turn == 0) {
				s2 = s2 + s.charAt(curr);
				turn=1;
			} else {
				s2 = s.charAt(curr) + s2;
				turn=0;
			}
			
			s = s.substring(1, s.length());
			
			n--;
			
		}
		
				
		if(s2.length() % 2 == 1) {
			System.out.println(s2);
		} else {
			System.out.println(new StringBuilder().append(s2).reverse());
		}
		
		

	}

}
