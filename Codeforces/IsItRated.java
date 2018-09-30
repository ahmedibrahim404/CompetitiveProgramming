// CF807-D2-A

import java.util.Scanner;

public class IsItRated {
	
	static Scanner input = new Scanner(System.in);

	public static void main(String[] args) {
		
		int n = input.nextInt(), num_1, num_2;
		int[] a  = new int[n];
		int[] b  = new int[n];
		for(int i=0;i<n;i++) {
			num_1 = input.nextInt();
			num_2 = input.nextInt();
			a[i] = num_1;
			b[i] = num_2;
			if(num_1 != num_2) {
				System.out.println("rated");
				return;
			}
		}
		
		for(int j=1;j<n;j++) {
			if(a[j] > a[j-1]) {
				System.out.println("unrated");
				return;
			}
		}
		
		
		System.out.println("maybe");
		
	}

}
