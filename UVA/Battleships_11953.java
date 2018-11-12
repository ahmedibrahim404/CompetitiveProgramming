import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Battleships_11953 {

	static boolean[][] visited;
	static char[][] nodes;

	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int t = Integer.parseInt(br.readLine());
		
		for(int k=1;k<=t;k++) {
			int f=0;
			int n = Integer.parseInt(br.readLine());
			visited = new boolean[n][n];
			nodes = new char[n][n];

			for(int a=0;a<n;a++) {
				String next = br.readLine();
				for(int b=0;b<n;b++)
					nodes[a][b] = next.charAt(b);
			}
			
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					
					if(nodes[i][j] == 'x' && !visited[i][j]) {
						
						DFS(i, j);
						f++;
						
					}
					
				}
			}
			
			System.out.println("Case " + k + ": " + f);
			
		}
		
	}
	
	public static void DFS(int x, int y) {
		
		if(!valid(x, y)) return;
		if(nodes[x][y] == '.') return;
		
		visited[x][y] = true;
		DFS(x+1, y);
		DFS(x-1, y);
		DFS(x, y+1);
		DFS(x, y-1);
		
	
		
	}
	
	public static boolean valid(int x, int y) {
		return x>=0 && y>=0 && x<nodes.length && y<nodes.length && !visited[x][y];
	}
	
}
