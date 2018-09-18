// CF768-D2-A

import java.util.Arrays;
import java.util.Scanner;

public class OathOfTheNightsWatch {

	static Scanner input = new Scanner(System.in);
	
	public static void main(String[] args) {

		int n = input.nextInt(), k=0;
		int[] stewards = new int[n];
		for(int i=0;i<n;i++) {
			stewards[i] = input.nextInt();
		}
		
		Arrays.sort(stewards);
		
		for(int j=0;j<stewards.length;j++) {
			if(stewards[j] > stewards[0] && stewards[j] < stewards[n-1]) {
				k++;
			}
		}
		
		System.out.println(k);
		
	}

}
