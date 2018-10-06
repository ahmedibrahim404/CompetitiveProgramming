// CF404-D2-A

import java.util.Scanner;

public class ValeraAndX {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		char main = 0, second = 0;
		boolean isTrue=true;
		for(int i=0;i<n;i++) {
			String l = input.next();
			if(i==0) {
				main=l.charAt(0);
				second = l.charAt(1);
				if(main == second) {
					System.out.println("NO");
					return;
				}
			}
			
			for(int j=0;j<l.length();j++) {
				if(j==i || l.length()-1-j == i) {
					if(l.charAt(l.length()-1-j) == main && l.charAt(0+j) == main) {
						isTrue=true;
					} else {
						isTrue=false;
						System.out.println("NO");
						return;
					}
				} else {
					if(l.charAt(j) == second) {
						isTrue=true;
					} else {
						System.out.println("NO");
						isTrue=false;
						return;
					}
				}
			}
			
		}
		
		if(isTrue==true) {
			System.out.println("YES");
		}
		
	}

}
