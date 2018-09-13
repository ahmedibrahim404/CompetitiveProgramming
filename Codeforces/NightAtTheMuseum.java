// CF731-D2-A

import java.util.Scanner;

public class NightAtTheMuseum {
	
	static Scanner input = new Scanner(System.in);

	public static void main(String[] args) {
		
		String chars = "abcdefghijklmnopqrstuvwxyz";
		String s = input.next();	
		int current =0;
		int moves=0;
		int move1, move2;
		for(int i=0;i<s.length();i++) {
			
			int index = chars.indexOf(s.charAt(i));
			if(index < current) {
				
				move1 = current-index;
				move2 = 25-(current-index) + 1;				
	
			} else {
				
				move1 = index-current;
				move2 = 26-(index-current);
	
			}
			
			if(move1>move2) {
				moves+=move2;
			} else {
				moves+=move1;
			}
			
			current = index;

			
		}
		
		System.out.println(moves);
		
		
		
	}

}
