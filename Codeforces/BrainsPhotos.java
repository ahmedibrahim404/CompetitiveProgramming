// CF707-D2-A

import java.util.Scanner;

public class BrainsPhotos {
	
	static Scanner input = new Scanner(System.in);
	public static void main(String[] args) {
		
		long n1 =input.nextInt(), n2=input.nextInt();
		
		for(long i=0;i<n1*n2;i++) {
			String c = input.next();
			if(c.equals("C") || c.equals("M") || c.equals("Y")) {
				System.out.println("#Color");
				return;
			}
		}
		
		System.out.println("#Black&White");

	}

}
