// CF160-D2-A

import java.util.Arrays;
import java.util.Scanner;

public class Twins {

	
	static Scanner input = new Scanner(System.in);
	
	public static void main(String[] args) {

		int n = input.nextInt();
		int total=0;
		int[] coins= new int[n];
		
		
		for(int i=0;i<n;i++) {
			int coin = input.nextInt();
			total += coin;
			coins[i] = coin;
		}
		
		Arrays.sort(coins);

		
		int totake = 0, constTaken=0;
		for(int j=coins.length-1;j>=0;j--) {
			constTaken += coins[j];
			total -= coins[j];
			totake++;
			if(constTaken > total) {
				break;
			} else {
				continue;
			}
			
		}
		
		System.out.println(totake);

	}

}
