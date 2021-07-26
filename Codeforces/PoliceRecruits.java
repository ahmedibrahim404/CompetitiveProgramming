// CF427-D2-A

import java.util.Scanner;

public class PoliceRecruits {
	
	static Scanner input = new Scanner(System.in);

	public static void main(String[] args) {
		
		int n = input.nextInt();
		int hired =0;
		int nextInt, crimes=0;
		for(int i=0;i<n;i++) {
			
			nextInt = input.nextInt();
			
			if(nextInt>0) {
				hired = hired + nextInt;
			} else {
				if(hired>0) {
					hired--;
				} else {
					crimes++;
				}
			}
			
		}
		
		System.out.println(crimes);
		
	}

}
