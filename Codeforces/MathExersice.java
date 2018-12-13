import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class MathExersice {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		int T=Integer.parseInt(br.readLine());
		
		for(int t=1;t<=T;t++){
			int a=Integer.parseInt(br.readLine()), b=0;
			for(int i=1;i<=a;i++)
				if(a%i == 0)
					b+=i;
			
			System.out.println("Case "+(t)+": "+b);
		}
		
	}
	
}
