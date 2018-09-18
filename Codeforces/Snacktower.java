// CF767-D2-A

import java.util.Scanner;

public class Snacktower {

	static Scanner input = new Scanner(System.in);
	
	public static void main(String[] args) {
		
		int n = input.nextInt();
		int[] s = new int[n+1];
		boolean[] v = new boolean[n+1];
		for(int i=0;i<n;i++) {
			s[i] = input.nextInt();
		}
		int size = n;
		for(int j=0;j<=size;j++) {
			v[s[j]] = true;
			while(n > 0 && v[n] == true) {
				System.out.print(n + " ");
				n--;
			}
			System.out.println("");
		}
		
	}

}
