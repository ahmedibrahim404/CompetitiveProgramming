// CF344-D2-A

import java.util.Scanner;

public class Magnets {

	static Scanner input = new Scanner(System.in);
	
	public static void main(String[] args) {
		
		int n = input.nextInt();
		int last = 0, current;
		int groups=0;
		for(int i=0;i<n;i++) {

			current = input.nextInt();
			
			if(last != current) {
				groups++;
				last = current;
			}
			
			
		}
		
		System.out.println(groups);

	}

}
