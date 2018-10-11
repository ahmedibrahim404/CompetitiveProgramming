// CF80-D2-A

import java.util.Scanner;

public class PanoramixsPrediction {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n1 = input.nextInt(), n2=input.nextInt();
		
		for(int i=n1+1; i<=n2;i++) {
			
			if( isPrime(i) == true ) {
				if(i == n2) {
					System.out.println("YES");
					return;
				} else {
					System.out.println("NO");
					return;
				}
			}
			
		}
		
		System.out.println("NO");

	}
	
	private static boolean isPrime(int num) {
        boolean isprime = true;
        for(int i = 2; i <= num / 2; i++) {
            if (num % i == 0) {
            	isprime = false;
                break; 
            }
        }
		return isprime;
	}

}
