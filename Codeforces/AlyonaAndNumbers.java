// CF682-D2-A

import java.util.Scanner;

public class AlyonaAndNumbers {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		long n=input.nextInt(), m=input.nextInt();
		long[] x = new long[5], y=new long[5];
		
		int no=0;
		for(int i=1;i<=n;i++) {
			x[i%5]++;
		}
		
		for(int j=1;j<=m;j++) {
			y[j%5]++;
		}
		

		System.out.println( x[0]*y[0] + x[1]*y[4] + x[2]*y[3] + x[3]*y[2] + x[4]*y[1] );
		
	}

}
