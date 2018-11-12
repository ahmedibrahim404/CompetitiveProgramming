import java.util.Scanner;

public class FancyFence {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		int n = input.nextInt();
		for(int i=0;i<n;i++) {
			
			int a = input.nextInt();

			if((float) 360 / (180-a) == (int)(360 / (180-a))) {
				System.out.println("YES");
			} else {
				System.out.println("NO");
			}
			
		}
		
	}
	
}
