// CF69-D2-A

import java.util.Scanner;

public class YoungPhysicist {

	static Scanner input = new Scanner(System.in);
	
	public static void main(String[] args) {

		int n = input.nextInt(), x=0,y=0,z=0;
		for(int i=0;i<n;i++) {
			x+= input.nextInt();
			y+= input.nextInt();
			z+= input.nextInt();
		}
		
		System.out.println(( x == 0 && y == 0 && z == 0 ) ? "YES" : "NO");
		
	}

}
