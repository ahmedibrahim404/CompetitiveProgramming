// CF236-D2-A

import java.util.Scanner;


public class BoyOrGirl {
	
	static Scanner input = new Scanner(System.in);

	public static void main(String[] args) {

		String name = input.next();
		String tempString = "";
		
		for(int i=0;i<name.length();i++) {
			if(! tempString.contains( String.valueOf(name.charAt(i)) ) ) {
				tempString += name.charAt(i);
			}
		}
		
		int m = tempString.length();
		
		switch( m % 2 ) {
			case 0:
				System.out.println("CHAT WITH HER!");
				break;
			case 1:
				System.out.println("IGNORE HIM!");
				break;
			default:
				break;
		}
		
		
	}

}
