// UVA 10368

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class EuclidsGame_10368 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s;
    	while((s=br.readLine())!=null) {
        	StringTokenizer st = new StringTokenizer(s);
        	long n1=Integer.parseInt(st.nextToken()), n2=Integer.parseInt(st.nextToken());
        	long n=0;
        	
        	if(n1 == 0 && n2 == 0)
        		return;
        	
        	while(n1 != 0 && n2 != 0) {
        		long i;
        		n++;
        		if(n1>n2) {
        			
        			for(i=1;i<5000;i++)
        				if(n2*i > n1)
        					break;
   
        			n1 -= n2 * (i-1);
        			
        		} else {
        			
        			for(i=1;i<5000;i++)
        				if(n1*i > n2)
        					break;

        			n2 -= n1 * (i-1);
        			
        		}
        		
        		if(i-1>1)
        			break;
      
        		        		
        	}
        	
        	System.out.println(n%2 == 1 ? "Stan wins" : "Ollie wins");
        	
    	}
    	
		
	}
	
}
