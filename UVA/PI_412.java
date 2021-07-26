import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.DecimalFormat;

public class PI_412 {

	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String s;
        
        while ((s=br.readLine())!=null) {
        	
        	int n = Integer.parseInt(s), num=0;
			int total=n*(n-1) / 2;
        	
        	if(n==0)
        		return;
        	
        	int[] a = new int[n]; 
        	for(int i=0;i<n;i++)
        		a[i] = Integer.parseInt(br.readLine());
    
        
        	for(int i=0;i<n-1;i++)
        		for(int j=i+1;j<n;j++) {
        			if(GCD(a[i], a[j]) == 1)
        				num++;
        		}
        			
        		
        	if(num == 0)
        		System.out.println("No estimate for this data set.");
        	else {
        		DecimalFormat numberFormat = new DecimalFormat("#.######");
        		System.out.println(numberFormat.format(Math.sqrt(6*total / num)));
        	}
			
		}

	}
	
	public static int GCD(int a, int b) {
		if (b==0)
			return a;
		return GCD(b, a%b);
	}
	
}
