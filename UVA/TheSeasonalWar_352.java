import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class TheSeasonalWar_352 {
	static boolean seen[][];
	static char[][] grid;
	static int[] xs = { 0, 0, 1, -1, 1, -1, 1, -1 };
	static int[] ys = { 1, -1, 0, 0, -1, -1, 1, 1 };
	static int n;
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String s;
		int number=1;
		while ((s=br.readLine())!=null) {
			int cr=0;
			n = Integer.parseInt(s);
			grid = new char[n][n];
			seen = new boolean[n][n];
			for(int e=0;e<n;e++) {
				grid[e] = br.readLine().toCharArray();
			}

			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					if(!seen[i][j] && grid[i][j] == '1') {
						DFS(i, j);
						cr++;
					}
				}
			}
			
			System.out.println("Image number "+ number +" contains "+ cr +" war eagles.");
			number++;
			
		}	

	}
	
	public static void DFS(int i, int j) {
		seen[i][j] = true;
		for(int l=0;l<8;l++) {
			if(valid(i+xs[l], j+ys[l]) && grid[i][j] == grid[i+xs[l]][j+ys[l]]) {
				DFS(i+xs[l], j+ys[l]);
			}
		}
	}
	
	public static boolean valid(int i, int j) {
		return ( i >= 0 && j >= 0 && i < n && j < n && !seen[i][j] );
	}

}