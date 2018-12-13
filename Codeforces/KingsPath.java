// CF242-D2-C

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;

public class KingsPath {
	
	static Map<String, Integer> c;
	static Map<String, Integer> m;
	static int[] xs = {1, -1, 0, 0, 1, 1, -1, -1};
	static int[] ys = {0, 0, 1, -1, 1, -1, 1, -1};

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int x0=input.nextInt(), y0=input.nextInt(), x1=input.nextInt(), y1=input.nextInt();
		c = new HashMap<String, Integer>();
		m = new HashMap<String, Integer>();
		int n =input.nextInt();
		for(int i=0;i<n;i++) {
			int r = input.nextInt();
			int f = input.nextInt(), t = input.nextInt();
			for(int j=f;j<=t;j++) {
				c.put(r+"-"+j, 1);
			}
		}
		
		
		int a = BFS_Path(x0, y0, x1, y1);
		System.out.println(a);
		
		
	}
	
	public static int BFS_Path(int x, int y, int a, int b) {
		
		Queue<Integer> q = new LinkedList<Integer>();
		q.add(x);
		q.add(y);
		m.put(x+"-"+y, 0);
		while(!q.isEmpty()) {
			int v = q.remove();
			int l = q.remove();
			
			for(int i=0;i<8;i++) {
			
				int newx = v + xs[i];
				int newy = l + ys[i];
				
				if(newx > 0 && newy > 0) {
					
					if(c.containsKey(newx+"-"+newy)) {
						q.add(newx);
						q.add(newy);
						m.put(newx+"-"+newy, m.get(v+"-"+l)+1);
						c.remove(newx+"-"+newy);
					}
					
					if(newx == a && newy == b) {
						return m.get(newx+"-"+newy);
					}					
					
				}
				


			} 
				

		}
		
		return -1;
	}

	
}
