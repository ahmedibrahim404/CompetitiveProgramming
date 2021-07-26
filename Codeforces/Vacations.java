import java.util.Scanner;

public class Vacations {

	static int[] na;
	
	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);
		int n=input.nextInt();
		na = new int[n];
		
		for(int i=0;i<n;i++) na[i] = input.nextInt();
		
		System.out.println(DP(0, 0));
		
	}
	
	public static int DP(int i, int prev) {
		
		if(i >= na.length) return 0;
		
		int v = (int) 1e6;
		boolean done=false;


		if(prev != 1 && (na[i] == 1 || na[i] == 3) ) {
			v = Math.min(v,DP(i+1, 1));
			done = true;
		}
		
		if(prev != 2 && (na[i] == 2 || na[i] == 3)) {
			v = Math.min(v,DP(i+1, 2));
			done = true;
		}
		
		
		if(done == false)
			v= Math.min(v, DP(i+1, 0)+1);

		return v;
	}

}
