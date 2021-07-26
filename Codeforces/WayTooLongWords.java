// CF71-D2-A

import java.util.Scanner;

public class WayTooLongWords {

	static Scanner input = new Scanner(System.in);
	
	public static void main(String[] args) {

		int n = input.nextInt();
		String w;
		for(int i=0;i<n;i++) {
			
			w = input.next();
			
			if(w.length() > 10) {
				System.out.println(w.charAt(0) + "" + (w.length() - 2) + "" + w.charAt(w.length()-1));
			} else {
				System.out.println(w);
			}
			
		}

	}

}
