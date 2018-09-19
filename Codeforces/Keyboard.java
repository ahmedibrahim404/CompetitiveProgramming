// CF474-D2-A

import java.util.Scanner;

public class Keyboard {

	static Scanner input = new Scanner(System.in);
	
	public static void main(String[] args) {

		char[] chars = {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l',';','z','x','c','v','b','n','m',',','.','/'	};
		int d = input.nextLine().equals("R") ? -1 : 1;
				
		char[] w = input.next().toCharArray();

		for(int i=0;i<w.length;i++) {
			for(int j=0;j<chars.length;j++) {
				if(chars[j] == w[i]) {
					w[i] = chars[j+d];
					break;
				}
			}
		}
		
		System.out.println(String.valueOf(w));
		
	}

}
