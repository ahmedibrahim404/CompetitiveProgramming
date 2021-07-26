import java.util.Scanner;

public class Overlapping_460 {

	static Scanner input = new Scanner(System.in);
	public static void main(String[] args) {
		int n=input.nextInt();
		int x1,y1,x2,y2,x3,y3,x4,y4;
		for(int i=0;i<n;i++) {
			x1 = input.nextInt();
			y1 = input.nextInt();
			x2 = input.nextInt();
			y2 = input.nextInt();
			x3 = input.nextInt();
			y3 = input.nextInt();
			x4 = input.nextInt();
			y4 = input.nextInt();

			if(Math.abs(x4-x2) < Math.abs(x3-x4) && Math.abs(y4-y2) < Math.abs(y2-y1)) {
				System.out.println(Math.max(x1, x3) + " " + Math.max(y1, y3) + " " + Math.min(x2, x4) + " " + Math.min(y2, y4));
			} else {
				System.out.println("No Overlap");
			}
			
			
		}
		
	}
	
}
