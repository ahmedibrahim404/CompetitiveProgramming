// CF136-D2-A

import java.util.Scanner;

public class Presents {

	static Scanner input = new Scanner(System.in);
	
	public static void main(String[] args) {

		int n = input.nextInt();
		int[] nGift = new int[n];
		
		for(int i=0;i<n;i++) {
			int p = input.nextInt();
			nGift[p-1] = i+1;
		}
		
		
		for(int j=0;j<n;j++) {
			int e = nGift[j];
			System.out.println(e);
		}
		
		

	}

}
