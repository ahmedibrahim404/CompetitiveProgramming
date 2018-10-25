// CF680-D2-B

import java.util.Scanner;

public class BearAndFindingCriminals {

	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);
		int n = input.nextInt(), a=input.nextInt()-1, num=0;
		int[] x = new int[n];
		for(int j=0;j<n;j++) {
			x[j] = input.nextInt();
		}
		
		for(int i=0;i<n;i++) {
			if(x[i] == 1) {
				int e = Math.abs(a-i);
				if(!valid(a+e, x.length) || !valid(a-e, x.length)) {
					num++;
					continue;
				}
				if(x[a+e] == x[a-e] && x[a+e] == 1) {
					num++;
				}
			}
		}
		
		System.out.println(num);
		
	}
	
	public static boolean valid(int a, int b) {
		return a < b && a >= 0;
	}

}