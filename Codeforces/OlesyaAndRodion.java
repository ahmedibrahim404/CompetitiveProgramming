// CF584-D2-A

import java.util.Scanner;

public class OlesyaAndRodion {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		int n=input.nextInt(), t=input.nextInt();
		
		if(n == 1 && t == 10) {
			System.out.println(-1);
			return;
		}
		
		System.out.print(t);

		if(n > 1 && t < 10) {
			System.out.print(0);
		}
		
		for(int i=1;i<n-1;i++) {
			System.out.print(0);
		}

	}

}
