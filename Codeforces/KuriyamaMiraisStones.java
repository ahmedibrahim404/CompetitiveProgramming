import java.util.Arrays;
import java.util.Scanner;

public class KuriyamaMiraisStones {

	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);
		int n =input.nextInt();
		
		long[] v = new long[(int) (n+1)];
		v[0] = 0;
		
		for(int j=1;j<n+1;j++)
			v[j] = input.nextLong();
		
		
		long[] u = v.clone();
		Arrays.sort(u);

		for(int i=1;i<v.length;i++)
			v[i] += i == 0 ? 0 : v[(i-1)];
		
		for(int i=1;i<u.length;i++)
			u[i] += i == 0 ? 0 : u[i-1];
	
		int m = input.nextInt();
		
		while(m-->0) {
			
			int type = input.nextInt();
			long[] arr;
			if(type==1)
				arr=v;
			else
				arr=u;
			
			int n1=input.nextInt(), n2=input.nextInt();
			System.out.println(arr[n2] - arr[(n1-1)]);
			
		}
		

	}

}
