import java.util.Scanner;

public class FindTheBone {

	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);
		int n=input.nextInt(), m=input.nextInt(), k=input.nextInt();
		int currentpos = 1;
		
		boolean[] holes = new boolean[n+1];
		
		for(int i=0;i<m;i++)
			holes[input.nextInt()] = true;
		
		
		for(int i=0;i<k;i++) {
			int n1=input.nextInt(), n2=input.nextInt();
			
			if(holes[currentpos]) {
				System.out.println(currentpos);
				return;
			}
			
			if(currentpos == n1) {
				currentpos = n2;
				continue;
			}
			
			if(currentpos == n2) {
				currentpos = n1;
				continue;
			}
			
		}
		
		System.out.println(currentpos);
		

	}

}
