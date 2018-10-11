// CF1-D12-A

import java.util.Scanner;

public class TheatreSquare {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		long n=input.nextLong(), m=input.nextLong(), a=input.nextLong();
		
		int p1 = n % a != 0 ? 1 : 0;
		int p2 = m % a != 0 ? 1 : 0;
		
		System.out.println( (( n / a ) + p1 ) * (( m / a ) + p2) );
		
	}

}
