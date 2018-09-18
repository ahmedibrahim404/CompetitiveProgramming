// CF567-D2-A

import java.util.Scanner;

public class LinelandMail {

	static Scanner input = new Scanner(System.in);
	
	public static void main(String[] args) {
		
		int n = input.nextInt();
		int[] x = new int[n];
		for(int j=0;j<n;j++) {
			x[j] = input.nextInt();
		}
		
		for(int i=0;i<n;i++) {
			int minimum;
			if((i+1 < x.length && i+1>=0) && (i-1 < x.length&& i+-1>=0) ) {
				minimum = Math.min(Math.abs(x[i] - x[i+1]), Math.abs(x[i] - x[i-1]));
			} else if ( (i+1 < x.length && i+1>=0) ) {
				minimum = Math.abs(x[i] - x[i+1]);
			} else {
				minimum = Math.abs(x[i] - x[i-1]);
			}
			
			int maximum = Math.max(Math.abs( x[i] - x[n-1] ), Math.abs( x[i] - x[0] ));
			
			System.out.println(minimum + " " + maximum);
			
		}

	}

}
