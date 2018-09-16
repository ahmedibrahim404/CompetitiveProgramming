// CF294-D2-A

import java.util.Scanner;

public class ShaassAndOskols {

	static Scanner input = new Scanner(System.in);
	public static void main(String[] args) {
		int n=input.nextInt();
		int[] birds = new int[n];
		int nO;

		for(int i=0;i<n;i++) {
			nO = input.nextInt();
			birds[i] = nO;
		}
		
		int wire,bird,right,left;
		int times = input.nextInt();

		for(int j=0;j<times;j++) {
			wire = input.nextInt() - 1;
			bird = input.nextInt();
			right = birds[wire] - bird;
			left = bird - 1;
						
			if(wire >= 0 && wire < n) {
				
				if(wire > 0) 
					birds[wire-1] = birds[wire-1] + left;
				
				if(wire < n-1)
					birds[wire+1] = birds[wire+1] + right;

				birds[wire] = 0;
				
			}
	
			
		}
		
		for(int k=0;k<n;k++) {
			System.out.println(birds[k]);
		}

		
	}
	
}
