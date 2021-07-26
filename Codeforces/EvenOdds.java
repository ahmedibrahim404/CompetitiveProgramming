// CF318-D2-A

import java.util.Scanner;

public class EvenOdds {
	
	static Scanner input = new Scanner(System.in);

	public static void main(String[] args) {
	

		long n=input.nextLong(), k=input.nextLong();

		
		if(n%2 == 1) {
			n++;
		} 
		
		
		if(k>n/2) {
			System.out.println((k-n/2) * 2);
		} else {
			System.out.println(k*2 - 1);
		}
		
	}

}
