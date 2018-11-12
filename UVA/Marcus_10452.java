import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Marcus_10452 {
	static String path = "IEHOVA#";

	static int[] xs = { -1, 0, 0 };
	static int[] ys = { 0, 1, -1 };
	static String[] ways = { "forth", "right", "left" };
	static char[][] nodes;

	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		int[] start = new int[2];
		
		for(int k=0;k<t;k++) {
			nodes = new char[8][8];
			StringTokenizer st = new StringTokenizer(br.readLine());

			int n=Integer.parseInt(st.nextToken()), m=Integer.parseInt(st.nextToken());
			
			for(int i=0;i<n;i++) {
				String l = br.readLine();
				for(int j=0;j<m;j++) {
					nodes[i][j] = l.charAt(j);
					if(nodes[i][j] == '@') {
						start[0]=i;
						start[1]=j;
					}
				}
			}
			
			next(start[0], start[1], 0);
			
			
		}
		
	}
	
	public static void next(int i, int j, int next) {
		
		for(int k=0;k<3;k++) {
			int x=i+xs[k], y=j+ys[k];
			if(valid(x,y)) {
				
				if(nodes[x][y] == path.charAt(next)) {
					if(next == 6) 
						System.out.print(ways[k] + "\n");
					else 
						System.out.print(ways[k] + " ");
					
					if(nodes[x][y] == '#')
						break;
					
					next(x, y, next+1);
				}
				
			}
		}
				
	}
	
	public static boolean valid(int i, int j) {
		
		if(i >=0  && j >= 0 && i < nodes.length && j < nodes[0].length) {
			return true;
		}
		
		return false;
		
	}
	
}
