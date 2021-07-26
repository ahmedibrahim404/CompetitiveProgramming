// CF677-D2-A

import java.util.Scanner;

public class VanyaAndFence {
	
	static Scanner userinput = new Scanner(System.in);
	
	
	public static void main(String[] args) {
		String[] input_1 = userinput.nextLine().split(" ");
		String[] input_2 = userinput.nextLine().split(" ");
		
		int n = Integer.parseInt(input_1[0]);
		int m = Integer.parseInt(input_1[1]);
		int totalWidth = 0;
		
		for(int i=0;i<n;i++) {
			int userHeight = Integer.parseInt(input_2[i]);
			if( userHeight > m ) {
				totalWidth++;
			}
			totalWidth++;
		}
		
		System.out.println(totalWidth);
		

		
	}

}
