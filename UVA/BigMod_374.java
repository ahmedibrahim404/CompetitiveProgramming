// UVA 374

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BigMod_374 {

	public static void main(String[] args) throws IOException {
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		long n1, n2, n3;
        String s;
        
        while ((s=br.readLine())!=null) {
			
			n1 = Long.parseLong(s);
			n2 = Long.parseLong(br.readLine());
			n3 = Long.parseLong(br.readLine());
			System.out.println(power(n1, n2, n3));
			
			br.readLine();
			
		}
		
	}
	
	public static long power(long a, long b, long c) {
		
		if(b==0) return 1;
		
		long res = power(a, b/2, c);
		res = res * res;
		
		if(b%2==1)
			res = res * a;
		
		return res % c;
		
	}
	
}
