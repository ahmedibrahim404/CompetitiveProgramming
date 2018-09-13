// CF732-D2-A

import java.util.Scanner;

public class BuyAShovel {

	static Scanner input = new Scanner(System.in);
	
	public static void main(String[] args) {
	
		int p = input.nextInt();
		int r = input.nextInt();
		
		int n=0;
		
		while( true ) {
			n++;
			if(p * n % 10 == r || p * n % 10 == 0) {
				break;
			}
		}
		
		System.out.println(n);
		
	}

}
