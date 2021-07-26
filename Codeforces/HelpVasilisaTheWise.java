// CF143-D2-A

import java.util.Scanner;

public class HelpVasilisaTheWise {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		int r1=input.nextInt(), r2=input.nextInt(),
				c1=input.nextInt(), c2=input.nextInt(),
				d1=input.nextInt(), d2=input.nextInt();
				
		int a = (r1+c1-d2)/2;
		int b = r1-a, c=c1-a, d=c2-b;
		
		
		
		if(checkIsTure(a,b,c,d, r1,r2,c1,c2,d1,d2) && isDifferentAndTrue(a,b,c,d)) {
			System.out.println(a + " " + b);
			System.out.println(c + " " + d);
		} else {
			System.out.println("-1");
			return;
		}


	}
	
	private static boolean isDifferentAndTrue(int a, int b, int c, int d) {
		return a > 0 && b > 0 && c > 0 && d > 0 && a != b && b != c && c != d && a != d && a != c && b != d && a < 10 && b < 10 && c < 10 && d < 10;
	}
	
	private static boolean checkIsTure(int a, int b, int c, int d, int r1, int r2, int c1, int c2, int d1, int d2) {
		return a + b == r1 && c + d == r2 && a + c == c1 && b + d == c2 && a + d == d1 && b + c == d2;
	}

}
