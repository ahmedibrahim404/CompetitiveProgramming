// CF265-D2-A

import java.util.Scanner;

public class ColorfulStones {

	static Scanner input = new Scanner(System.in);
	
	public static void main(String[] args) {
		
		String s = input.nextLine();
		String t = input.nextLine();
		
		int fP=0;
		
		for(int i=0;i<t.length();i++) {
			
			if( t.charAt(i) == s.charAt(fP) ) {
				fP++;
			}
			
		}
		
		System.out.println(fP + 1);
		
	}

}
