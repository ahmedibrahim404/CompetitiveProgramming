import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class AddingReversedNumbers_713 {

	public static void main(String[] args) throws NumberFormatException, IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());
		
		for(int i=0;i<n;i++) {
		
	    	StringTokenizer st = new StringTokenizer(br.readLine());
	    	BigInteger s1=new BigInteger(new StringBuffer(st.nextToken()).reverse().toString());
	    	BigInteger s2=new BigInteger(new StringBuffer(st.nextToken()).reverse().toString());
	    	
	    	BigInteger sum = s1.add(s2);
	    	
	    	System.out.println(new StringBuffer(sum.toString()).reverse().toString().replaceFirst("^0*", ""));
	    	
			
		}
		
	}

}
