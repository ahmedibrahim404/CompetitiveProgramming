import java.util.Scanner;

public class Steps {

	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);
		long n=input.nextLong(), m=input.nextLong();
		long x=input.nextLong(), y=input.nextLong();
		int t=input.nextInt();
		long totalsteps = 0;
		
		for(int i=0;i<t;i++) {
			long xs = input.nextInt(), ys=input.nextInt();
			long start=0, end=(long) Math.pow(10, 9);
			long mid;
			long steps = 0;
			while(start <= end) {
				mid = (start+end)/2;
				if(valid( x+(xs*mid), y+(ys*mid), n, m )) {
					steps = mid;
					start = mid + 1;
				} else
					end = mid - 1;

			}
						
			totalsteps += steps;
			x = (xs * steps) + x;
			y = (ys * steps) + y;

			
		}
		
		System.out.println(totalsteps);
		
		
	}
	
	public static boolean valid(long x,  long y, long n, long m) {
		return x > 0 && y > 0 && x <= n && y <= m;
	}
	
	

}
