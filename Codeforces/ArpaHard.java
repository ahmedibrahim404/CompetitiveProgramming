// CF742-D2-A

import java.util.Scanner;

public class ArpaHard {

	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		int[] digits = { 8,4,2,6 };
		
		if(n == 0)
			System.out.println(1);
		else if(n%4 ==0)
			System.out.println(digits[3]);
		else
			System.out.println(digits[(n%4) - 1]);

	}

}
