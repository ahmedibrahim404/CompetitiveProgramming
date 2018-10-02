// CF118-D2-A

import java.util.Scanner;

public class StringTask {
	
	static Scanner input = new Scanner(System.in);

	public static void main(String[] args) {

		String str = input.next().toLowerCase();
		str= str.replaceAll("[aeiouy]", "");

		for(int i=0;i<str.length();i++) {
			str = str.substring(0, i) + "." + str.substring(i);
			i++;
		}
		
		System.out.println(str);

		
	}
	

}
