// CF266-D2-A

import java.util.Scanner;

public class StonesOnTheTable {

	static Scanner input = new Scanner(System.in);
	
	public static void main(String[] args) {
		
		int n = Integer.parseInt(input.nextLine());
		
		String colors = input.nextLine();
		
		int minStones=0;
		
		for(int i=1;i<n;i++) {
			
			if(colors.charAt(i) == colors.charAt(i-1)) {
				minStones++;
			}
			
		}
		
		System.out.println(minStones);
		
	}

}
