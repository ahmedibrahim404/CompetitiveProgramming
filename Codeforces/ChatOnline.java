import java.util.Scanner;

public class ChatOnline {

	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);
		int p=input.nextInt(), q=input.nextInt(), l=input.nextInt(), r=input.nextInt();
		int[] xs = new int[p], ys=new int[p];
		boolean[] v = new boolean[1004];
		int t = 0;
		for(int i=0;i<p;i++) {
			xs[i] = input.nextInt();
			ys[i] = input.nextInt();
		}
		
		
		for(int i=0;i<q;i++) {
			
			int c=input.nextInt(), d=input.nextInt();
			
			for(int j=0;j<p;j++) {
				
				int x = xs[j]-c, y=ys[j]-d;
				// 11, 16
				if(l>y || x>r)
					continue;
				
				for(int k=Math.max(x, l);k<=Math.min(y, r);k++) {
					if(!v[k]) {
						v[k] = true;
						t++;
					}
				}
								
			}
			
		}
		
		System.out.println(t);

	
		
	}
	
}
