// CF225-D2-A

import java.util.Scanner;

public class DiceTower {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n=input.nextInt(), x=input.nextInt();
		for(int i=0;i<n;i++) {
			int a1=input.nextInt(), a2=input.nextInt();
			if(x==a1 || x==a2 || x==7-a1 || x==7-a2) {
				System.out.println("NO");
				return;
			}
		}
		System.out.println("YES");
	}
	
}
