// CF770-D2-A

import java.util.Scanner;

public class NewPassword {
	
	static char[] chars = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	static Scanner input = new Scanner(System.in);
	
	
	public static void main(String[] args) {
		int n = input.nextInt();
		int k = input.nextInt();
		String s="";
		for(int i=0;i<n;i++) {
			s += chars[i%k];
		}
		
		System.out.println(s);
		
	}

}
