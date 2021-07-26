import java.util.Arrays;
import java.util.Scanner;

public class RomaAndChangingSings {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		int n=input.nextInt(), k=input.nextInt();
		long sum=0;
		int[] sq = new int[n];
		for(int i=0;i<n;i++) {
			int num=input.nextInt();
			if(num < 0 && k > 0) {
				sq[i] = num*-1;
				k--;
			} else
				sq[i] = num;
		}
		
		Arrays.sort(sq);
		
		if(k%2 == 1)
			sq[0] *= -1;
		
		for(int i=0;i<n;i++)
			sum += sq[i];
		
		System.out.println(sum);
		
	}
	
}
