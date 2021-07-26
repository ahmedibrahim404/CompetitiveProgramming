// CF734-D2-A

import java.util.Scanner;

public class AntonAndDanik {

	static Scanner userInput = new Scanner(System.in); 
	
	public static void main(String[] args) {
		int n = Integer.parseInt(userInput.nextLine());
		String s = userInput.nextLine();
		int antonS = 0;
		int danikS = 0;
		
		for(int i=0;i<n;i++) {
			if(s.charAt(i) == 'A') {
				antonS++;
			} else {
				danikS++;
			}
		}
		
		if(antonS > danikS) {
			System.out.println("Anton");
		} else if ( danikS > antonS ) {
			System.out.println("Danik");
		} else {
			System.out.println("Friendship");
		}

	}

}
