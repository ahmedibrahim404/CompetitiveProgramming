// CF492-D2-B

import java.util.Arrays;
import java.util.Scanner;

public class VenyaAndLanterns {

	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);
		int n = input.nextInt(), l=input.nextInt();
		int[] vs = new int[n];
		for(int i=0;i<n;i++)
			vs[i] = input.nextInt();
		
		Arrays.sort(vs);
		
		double large=0;
		
		for(int i=1;i<n;i++)
			large = (int) Math.max(large, (vs[i] - vs[i-1]));
		
		large = large/2;
		
		if(vs[0] != 0){
			large = Math.max((double) vs[0], large);
		}
		
		if(l != vs[vs.length -1]){
			large = Math.max(l - vs[vs.length - 1] , (double) large);
		}
		
		System.out.println((double) large);

	}

}
