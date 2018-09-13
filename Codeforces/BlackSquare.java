// CF431-D2-A

import java.util.Scanner;

public class BlackSquare {

	static Scanner input = new Scanner(System.in);
	
	public static void main(String[] args) {
		int[] strips = new int[4];
		for(int i=0;i<4;i++) {
//			System.out.println(input.nextInt());
			strips[i] = input.nextInt();
		}
		
		String s = input.next();
		int strip, cals=0;
		for(int j=0;j<s.length();j++) {
			strip = Integer.parseInt(Character.toString(s.charAt(j)));
			
			cals+=strips[strip-1];
			
		}
		
		System.out.println(cals);
				
	}

}
