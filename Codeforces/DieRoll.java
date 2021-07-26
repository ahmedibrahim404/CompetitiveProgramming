// CF9-D2-A

import java.util.Scanner;

public class DieRoll {

	static Scanner sc = new Scanner(System.in);
	
	public static void main(String[] args) {
		
		String[] role = { "1/6", "1/3", "1/2", "2/3", "5/6", "1/1" };

		int max = Math.max(sc.nextInt(), sc.nextInt());
		System.out.println( role[6-max] );

	}

}
