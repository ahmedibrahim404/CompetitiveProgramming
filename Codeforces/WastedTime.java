// CF127-D2-A
// Computational Geometry

import java.util.Scanner;

public class WastedTime {

	static Scanner input = new Scanner(System.in);
	public static void main(String[] args) {
		
		int n=input.nextInt(), k=input.nextInt();
		float len=0;

		int[][] coordinates = new int[n][2];
		
		
		for(int i=0;i<n;i++) {
			coordinates[i][0] = input.nextInt();
			coordinates[i][1] = input.nextInt();
		}
		
		for(int j=1;j<coordinates.length;j++) {
			float x = (float) Math.pow(coordinates[j][0]-coordinates[j-1][0], 2);
			float y = (float) Math.pow(coordinates[j][1]-coordinates[j-1][1], 2);
			len += (float) Math.sqrt(x+y);
		}

		
		System.out.println((float) ((float) len*k) / 50);
		
		
	}
	
}
