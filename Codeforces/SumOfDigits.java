// CF102-D2-B

import java.util.Scanner;

public class SumOfDigits {

	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);
		String n = input.next();
		int sum=0;
		int times=0;
		if(n.length() < 2) {
			System.out.println(0);
			return;
		} else {
			
			while(n.length() >= 2) {
				for(int i=0;i<n.length();i++) {
					sum += Character.getNumericValue(n.charAt(i));
				}
				times++;
				n = Integer.toString(sum);
				sum=0;
			}
			
		}
		
		System.out.println(times);

	}

}
