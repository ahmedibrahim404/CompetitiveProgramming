// CF545-D2-C

import java.util.Scanner;

public class Woodcutters {

	static long[] cr;
	static long[] ln;
	static long[] ch;
	public static void main(String[] args) {
				
		Scanner input = new Scanner(System.in);
		int n=input.nextInt();
		cr = new long[n];
		ln = new long[n];
		ch = new long[n];
		
		ch[0] = -1;
		ch[ch.length-1] = 1;
		
		for(int i=0;i<n;i++) {
			cr[i] = input.nextLong();
			ln[i] = input.nextLong();
		}
		
		System.out.println(max(1)+(n > 1 ? 2 : 1));
		
	}
	
	public static int max(int i) {
		
		if(i >= cr.length-1) return 0;

		boolean done=false;
		int res=0;
		
		long x1, y1, x2, y2;
		
		x1 = cr[i]-ln[i];
		y1 = cr[i];
		
		if(ch[i-1] == -1) {
			x2=cr[i-1]-ln[i-1];
			y2=cr[i-1];
		} else if(ch[i-1] == 1) {
			x2=cr[i-1];
			y2=cr[i-1]+ln[i-1];
		} else {
			x2=cr[i-1];
			y2=cr[i-1];
		}
		
		if(!(x1 <= y2 && x2 <= y1)) {
			ch[i] = -1;
			res = Math.max(res, max(i+1)+1);
			done=true;
		} else {
			x1 = cr[i];
			y1 = cr[i]+ln[i];
			
			x2 = cr[i+1];
			y2 = cr[i+1];
			
			if(!(x1 <= y2 && x2 <= y1)) {
				ch[i] = 1;
				res = Math.max(res, max(i+1)+1);
				done=true;
			}
		}
		
				
		if(done==false)
			res = Math.max(res, max(i+1));
		
		return res;
		
	}


}
