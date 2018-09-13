// CF791-D2-A

import java.util.Scanner;

public class BearAndBigBrother {

	static Scanner userInput = new Scanner(System.in); 

	public static void main(String[] args) {
		String[] bearsWeight = userInput.nextLine().split(" ");
		int limakWeight = Integer.parseInt(bearsWeight[0]);
		int bobWeight = Integer.parseInt(bearsWeight[1]);
		int years = 0;
		while(bobWeight >= limakWeight) {
			bobWeight = bobWeight * 2;
			limakWeight = limakWeight * 3;
			years++;
		}
		
		System.out.println(years);
		
	}

}
