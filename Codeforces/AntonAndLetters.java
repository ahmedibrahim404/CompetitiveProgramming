// CF443-D2-A

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class AntonAndLetters {
	
	static Scanner input = new Scanner(System.in);
	
	public static void main(String[] args) {
		String fL = input.nextLine();
		
		if( fL.charAt(0) == '{' && fL.charAt(fL.length() - 1) == '}' ) {
			fL = fL.substring(1, fL.length() - 1);
			String [] chars = fL.split(", ");

			Set<String> set = new HashSet<String>();
			
			for(int j=0;j<chars.length;j++) {
				if(! (chars[j].equals("")) )
					set.add(chars[j]);
			}
			
			System.out.println(set.size());

		}

	}
	
}
