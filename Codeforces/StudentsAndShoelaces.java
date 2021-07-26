import java.util.ArrayList;
import java.util.Scanner;

public class StudentsAndShoelaces {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		int n=input.nextInt(), m=input.nextInt(), groups=0;
		
		boolean[][] ns = new boolean[n+1][n+1];
		int[] as = new int[n+1];
		
		for(int l=0;l<m;l++) {
			int a=input.nextInt(), b=input.nextInt();
			ns[a][b] = true;
			ns[b][a] = true;
			as[a]++;
			as[b]++;
		}
		
		int kl = 0;
		while(as.length > 0) {
			kl++;
	        ArrayList<Integer> removed = new ArrayList<Integer>(n); 
			
			int toremove = 0;
			
			for(int i=1;i<=n;i++) {
				
				if(as[i] == 1) {
				
					removed.add(i);
					
				}
				
			}
			
			for(int i=0;i<removed.size();i++) {
				int item = removed.get(i);
				as[item] = 0;

				toremove++;
				
				for(int j=1;j<=n;j++) {
					
					if(ns[item][j] == true || ns[j][item] == true) {
					
						as[j]--;
						as[item]--;
						
						ns[item][j] = false;
						ns[j][item] = false;

					}
					
				}
				
			}

			if(toremove > 0)
				groups++;
			else
				break;
			
		}
		
		System.out.println(groups);
		
		
	}
	
}
