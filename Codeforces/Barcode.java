import java.util.Arrays;
import java.util.Scanner;

public class Barcode {

	static int[] arr;
	static int n, m, x, y;
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		n=input.nextInt();
		m=input.nextInt();
		x=input.nextInt();
		y=input.nextInt();
		arr = new int[m];
		for(int i=0;i<n;i++) {
			String s =input.next();
			for(int j=0;j<m;j++)
				arr[j] += s.charAt(j) == '#' ? 1 : 0;
		}
		
		System.out.println(minimum(0, -1, 2));
	}
	
	public static int minimum(int i, int prev, int prevn) {
				
		if(i >= arr.length) {
			if(prevn < x || prevn > y)
				return 100000;
			return 0;	
		}

		
		int sol = (int) 1e6;
		int hs = arr[i];

		if(i == 0 || ( prev == 0 && prevn+1 <= y ) || (prev == 1 && prevn >= x))
			sol = Math.min(sol, minimum(i+1, 0, prev == 0 ? prevn+1 : 1) + n-hs);
		
		if(i == 0 || ( prev == 1 && prevn+1 <= y ) || (prev == 0 && prevn >= x))
			sol = Math.min(sol, minimum(i+1, 1, prev == 1 ? prevn+1 : 1) + hs);
		
		return sol == (int) 1e6 ? 0 : sol;
		
	}
	
}
