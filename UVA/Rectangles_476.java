// UVA 476

import java.util.Scanner;

public class Rectangles_476 {
	static Scanner input = new Scanner(System.in);
	public static void main(String[] args) {
		
		float[][] rects = new float[10][4];
		int i;
		float x,y;
		for(i=0;i<10;i++) {
			
			if(input.next().equals("r")) {
				
				for(int k=0;k<4;k++) {
					rects[i][k] = input.nextFloat();
				}
				
			} else {				
				break;
			}
		}
		

		int n=1;
		boolean isIn=false;
		while(input.hasNext()) {
			x=Float.parseFloat(input.next());
			y=Float.parseFloat(input.next());

			if((int) x == 9999) {
				return;
			}
			isIn=false;
			for(int j=0;j<i;j++) {
				float minX=Math.min(rects[j][0], rects[j][2]), maxX=Math.max(rects[j][0], rects[j][2]);
				float minY=Math.min(rects[j][1], rects[j][3]), maxY=Math.max(rects[j][1], rects[j][3]);

				if(x > minX && x < maxX && y > minY && y < maxY) {
					isIn=true;
					System.out.println("Point " + n + " is contained in figure "+ (j+1));
				}
								
			}
			if(isIn == false) {
				System.out.println("Point " + n + "  is not contained in any figure");
			}
			n++;

		}
		
		

	
	
	}
	
}
