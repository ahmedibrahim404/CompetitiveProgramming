// CF16-D2-B

import java.util.Scanner;

public class BurglarAndMatches {

	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);
		int n =input.nextInt(), m=input.nextInt(), totalFi=0;
		int[] n1 = new int[m];
		int[] n2 = new int[m];
		
		for(int i=0;i<m;i++) {
			int fi = input.nextInt();
			totalFi+=fi;
			n1[i] = fi;
			n2[i] = input.nextInt();
		}
		
		int total=0, current=getLargest(n2, n1);
		
		if(totalFi < n)
			n=totalFi;

		while(n>0) {			
			if(n1[current] > 0) {
				if(n1[current] > n)
					n1[current] = n;
			
				total += n1[current] * n2[current];
				n -= n1[current];
				n1[current]=0;
			} else {
				current = getLargest(n2, n1);
				if(current == -1) {
					break;
				}
			}
		}
		
		System.out.println(total);
		
	}
	
	public static int getLargest(int[] arr1, int[] arr2) {
		
		int largest=-1, largestN=0;
		for(int i=0;i<arr1.length;i++) {
			if(arr2[i] > 0 && arr1[i] > largestN) {
				largest=i;
				largestN=arr1[i];
			}
		}
		
		return largest;
		
	}

	
}