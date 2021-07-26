// CF463-D2-B

import java.util.Scanner;

public class CaisaAndPylons {

	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);
		int n=input.nextInt(), spent=0, res=0;
		int[] heights = new int[n+1];
		heights[0] = 0;
		for(int i=1;i<=n;i++) {
			heights[i] = input.nextInt();
			res += heights[i-1] - heights[i];
			if(res < 0) {
				spent -= res;
				res=0;
			}
		}

		System.out.println(spent);
		
	}

}
