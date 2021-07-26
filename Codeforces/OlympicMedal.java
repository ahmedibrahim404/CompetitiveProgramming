import java.util.Scanner;

public class OlympicMedal {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		int n=input.nextInt();
		int r1=0;
		for(int i=0;i<n;i++) {
			r1 = Math.max(r1, input.nextInt());
		}
		
		int m=input.nextInt();
		int p1=0;
		for(int i=0;i<m;i++) {
			p1 = Math.max(p1, input.nextInt());
		}
		
		int z=input.nextInt();
		int p2=-1;
		for(int i=0;i<z;i++) {
			if(p2==-1)
				p2 = input.nextInt();
			else
				p2 = Math.min(p2, input.nextInt());
		}
				
		double A=input.nextInt(), B=input.nextInt();
		double res = Math.sqrt( (B*p1*r1*r1) /  (A*p2 + B*p1));
		System.out.println(res);
		
		
	}
	
}
