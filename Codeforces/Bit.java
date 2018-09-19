// CF282-D2-A

import java.util.Scanner;

public class Bit {

	static Scanner input = new Scanner(System.in);
	
	public static void main(String[] args) {

		int n=input.nextInt();
		int x=0;
		for(int i=0;i<n;i++) {
			String str = input.next();
			if( str.indexOf("++") > -1 ) {
				x++;
			} else if(str.indexOf("--") > -1) {
				x--;
			}
		}
		
		System.out.println(x);

	}

}
