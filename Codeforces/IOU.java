import java.util.Scanner;

public class IOU {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		int n=input.nextInt(), m=input.nextInt();
		int[][] depts = new int[n+1][2];
		int total = 0;
		
		
		for(int i=0;i<m;i++) {
			int a=input.nextInt(), b=input.nextInt(), c=input.nextInt();
			depts[a][0] += c;
			depts[b][1] += c;
			
			
		}
		
		
	
		for(int i=1;i<=n;i++) {
			if(depts[i][0] > depts[i][1])
				total += depts[i][0] - depts[i][1];
		}
		System.out.println(total);
		
		
	}
	
}
