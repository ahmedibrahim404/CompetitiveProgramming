// CF227-D2-B

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class EffectiveApproach {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		long n = input.nextInt();
		Map<Long, Long> nums = new HashMap<Long, Long>();
		for(long i=0;i<n;i++) {
			nums.put(input.nextLong(), i+1);
		}
		long m = input.nextLong();
		long[] vs = new long[2];
		vs[0]=0;
		vs[1]=0;
		
		for(long j=0;j<m;j++) {
			long e = input.nextLong();
			vs[0] += nums.get(e);
			vs[1] += n-nums.get(e) + 1;
		}
		
		System.out.println(vs[0] + " " + vs[1]);

		
	}
	
}
