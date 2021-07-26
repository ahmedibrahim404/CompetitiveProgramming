// CF112-D2-A

import java.util.ArrayList;
import java.util.Scanner;

public class PetyaAndStrings {
	
	static char[] chars = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	static Scanner input = new Scanner(System.in);

	public static void main(String[] args) {
		ArrayList<Character> list = new ArrayList<Character>();
		
		for(int i=0;i<chars.length;i++) {
			
			list.add(chars[i]);
			
		}

		String str_1 = input.nextLine().toLowerCase();
		String str_2 = input.nextLine().toLowerCase();
		int n = str_1.compareTo(str_2);


		System.out.println(n == 0 ? "0" : n > 0 ? "1" : n < 0 ? "-1" : null);
		
		
	}

}
