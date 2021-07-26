// Brute Force - Try all possible possibilities
// CF66-D2-B

import java.util.Scanner;

public class PetyaAndCountryside {

	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);
		int n=input.nextInt();
		
		if(n == 1) {
			System.out.println("1");
			return;
		}
		
		int[] nNums = new int[n];
		int largest = 1;
		
		for(int k=0;k<n;k++) {
			nNums[k] = input.nextInt();
		}
		
		for(int i=0;i<nNums.length;i++) {

			// time for and time while So do not get bored :"DDD
			
			int PreviousN1=nNums[i], total1=0;
			for(int j=i;j>0;j--) {
				if(nNums[j-1] <= PreviousN1) {
					total1++;
					PreviousN1 = nNums[j-1];
				} else {
					break;
				}
			}
			
			
			
			int PreviousN2=nNums[i], total2=0;
			int j=i+1;
			while(j < nNums.length) {
				if(nNums[j] <= PreviousN2) {
					total2++;
					PreviousN2 = nNums[j];
				} else {
					break;
				}
				j++;
			}
			
			if(total1 + total2 > largest) {
				largest = total1 + total2;
			}

		}
		
		System.out.println(largest+1);
		
		
		
	}

}
