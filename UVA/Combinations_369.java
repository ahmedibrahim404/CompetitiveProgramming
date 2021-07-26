import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Combinations_369 {

	static long[][] a = new long[101][101];
	
	public static void main(String[] args) throws NumberFormatException, IOException {
				

		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String s;
        
        while ((s=br.readLine())!=null) {
        	
        	StringTokenizer st = new StringTokenizer(s);
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			
			if(n==0&&m==0)
				return;
			
			System.out.println(n + " things taken " + m + " at a time is " + C(n, m) + " exactly.");
			
		}

	}
	
	public static long C(int n, int m) {
		if(m==0) return 1;
		if(n==m) return 1;
		
		if(a[n][m] != 0) return a[n][m];
		
		a[n][m] = C(n-1, m-1) + C(n-1, m);
		return a[n][m];
	}
	
}
