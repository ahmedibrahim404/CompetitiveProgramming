// CF766-D2-B

import java.util.Arrays;
import java.util.Scanner;

public class MahmoudAndATriangle {

	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);
		int n=input.nextInt();
		int[] ns = new int[n];
		
		for(int i=0;i<n;i++)
			ns[i] = input.nextInt();
		
		Arrays.sort(ns);
		for(int i = 0; i < ns.length / 2; i++){
		    int temp = ns[i];
		    ns[i] = ns[ns.length - i - 1];
		    ns[ns.length - i - 1] = temp;
		}

		
		for(int i=0;i<n-2;i++) {
			
			for(int j=i+1;j<n-1;j++) {
								
				if(ns[i] < ns[j] + ns[j+1]) {
					System.out.println("YES");
					return;
				}
				
			}
			
		}
		
		System.out.println("NO");
		
	}

}
