// Prefix Sum

// CF363-D2-B
import java.util.Scanner;

public class Fence {

	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);
		int n =input.nextInt(), k=input.nextInt(), a=15000001, in=0;
		int[] ns = new int[n+1];
		for(int i=1;i<=n;i++) {
			int next = input.nextInt();
			ns[i] = ns[i-1] + next;
		}
		
		for(int i=k;i<=n;i++) {
			if(a > ns[i] - ns[i-k]) {
				a = ns[i] - ns[i-k];
				in = i;
			}
		}
		
		System.out.println(in - k + 1);
		
		

	}

}
