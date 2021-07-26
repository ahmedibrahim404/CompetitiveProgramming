// CF268-D2-A

import java.util.Scanner;

public class Games {

	static Scanner input = new Scanner(System.in);
	
	public static void main(String[] args) {
		
		int n = input.nextInt();
		int[] home = new int[n];
		int[] guest = new int[n];
		int e = 0;
		for(int i=0;i<n;i++) {
			home[i] = input.nextInt();
			guest[i] = input.nextInt();
		}
		
		for(int j=0;j<n;j++) {
			for(int k=0;k<n;k++) {
				if(home[j] == guest[k] && j != k) {
					e++;
				}
			}
		}
		
		System.out.println(e);
		
	}

}
