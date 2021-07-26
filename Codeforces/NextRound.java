// CF158-D12-A

import java.util.Scanner;

public class NextRound {

	static Scanner input = new Scanner(System.in);
	
	public static void main(String[] args) {

		int n = input.nextInt();
		int k = input.nextInt();
		int[] a = new int[n];
		
		for(int i=0;i<n;i++) {
			a[i] = input.nextInt();
		}
		
		int m=a[k-1];
		int c=0;
		for(int j=0;j<n;j++) {
			if(a[j] >= m && a[j] != 0) {
				c++;
			}
		}
		
		System.out.println(c);
		
	}

}
