import java.util.Scanner;

public class CarrotCakes {
	
	static Scanner input = new Scanner(System.in);
	
	public static void main(String[] args) {
		int n = input.nextInt(),
			t = input.nextInt(),
			k = input.nextInt(),
			d = input.nextInt();
		
		int times = (int) Math.ceil( n/k );
		int t1 = 0, t2 = d;
		
		for(int i=0;i<times;i++) {
			if( t1 > t2 ) {
				t2 += t;
			} else {
				t1 += t;
			}
		}
		
		if(times*t < Math.max(t1,t2)) {
			System.out.println("NO");
		} else {
			System.out.println("YES");
		}
		
	}

}
