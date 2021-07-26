// CF766-D2-A 

import java.util.Scanner;

public class MahmoudAndLongestUncommonSubsequence {

	static Scanner input = new Scanner(System.in);
	public static void main(String[] args) {
		
		String str_1 = input.nextLine();
		String str_2 = input.nextLine();
		
		if(str_1.equals(str_2)) {
			System.out.println("-1");
		} else if(str_1.length() > str_2.length()) {
			System.out.println(str_1.length());
		} else {
			System.out.println(str_2.length());
		}

	}

}
