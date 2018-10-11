// CF456-D2-A

import java.util.Scanner;

public class Laptops {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		for(int i=0;i<n;i++) {
			if(input.nextInt() != input.nextInt()) {
				System.out.println("Happy Alex");
				return;
			}
		}
		System.out.println("Poor Alex");
		
	}

}
