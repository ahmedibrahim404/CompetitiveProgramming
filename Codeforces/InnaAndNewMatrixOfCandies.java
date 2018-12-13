import java.util.Arrays;
import java.util.Scanner;

public class InnaAndNewMatrixOfCandies {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		int n=input.nextInt(), m=input.nextInt();
		
		int[] distance = new int[n];
		int t=0;
		boolean big=false;
		for(int i=0;i<n;i++) {
			
			String s =input.next();
			int gs = -1, ss =-1;
			for(int j=0;j<m;j++) {
				
				if(s.charAt(j) == 'G')
					gs =  j;
				
				if(s.charAt(j) == 'S')
					ss = j;
				
			}
			
			if(gs > ss)
				big=true;
			
			distance[i] = ss - gs > 0 ? ss - gs : 0;
			
		}
		
		while(1 == 1 && big == false) {
			Arrays.sort(distance);
			
			int moves = 0;
			for(int i=0;i<distance.length;i++)
				if(distance[i] > 0) {
					moves = distance[i];
					break;
				}
			
			
			if(moves == 0) {
				break;
			}
			
			t++;
			
			for(int i=0;i<distance.length;i++) {
				if(distance[i] > 0)
					distance[i] -= moves;
			}
				
			
			
			
		}
		
		System.out.println(big == true ? -1 : t);

		
		
	}
	
}
