// CF686-D2-A


import java.util.Scanner;

public class FreeIceCream {

	static Scanner input = new Scanner(System.in);
	
	public static void main(String[] args) {
		
		int n = input.nextInt();
		long x = input.nextInt();
		int distressed=0;
		for(int i=0;i<n;i++) {
			
			String o = input.next();
			int d = input.nextInt();
			
			if(o.equals("+")) {
				x += d;
			} else {
				if( x >= d ) {
					x -= d;
				} else {
					distressed++;
				}
				
			}
			

			
		}
		
		System.out.println(x + " " + distressed);
		
	}

}
