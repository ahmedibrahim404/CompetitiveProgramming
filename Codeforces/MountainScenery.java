// CF218-D2-A

import java.util.Scanner;

public class MountainScenery {

	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);
		long n=input.nextInt(), k=input.nextInt();
		int i=1;
		int[] e = new int[(int) ((2*n)+1)];
		
		for(int j=0;j<(2*n)+1;j++) {
			e[j] = input.nextInt();
		}
		
		while(k>0 && i < (2*n)+1) {
			if(e[i] > e[i-1]+1 && e[i] > e[i + 1]+1) {
				e[i] = e[i] - 1;
				k--;
			}
			i+=2;
			
		}
		

		for(int l=0;l<(n*2)+1;l++) {
			System.out.print(e[l] + " ");
		}
		
	}

}
