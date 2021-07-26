import java.util.Scanner;

public class GrowingMushrooms {
	static int[] a;
	static double[] b;
	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);
		
		int n=input.nextInt(), t1=input.nextInt(), t2=input.nextInt(), k=input.nextInt();
	
		a = new int[n];
		b=new double[n];
		
		for(int i=0;i<n;i++) {
		
			int v1=input.nextInt(), v2=input.nextInt();
			
			double ts1 = v1*t1 - (double) v1*t1*k/100 + v2*t2;
			double ts2 = v2*t1 - (double) v2*t1*k/100 + v1*t2;
			
			a[i] = i+1;
			b[i] = (double) Math.max(ts1, ts2);
			
		}
		
		for(int i=0;i<n;i++) {
			
			for(int j=i+1;j<n;j++){
				
				if(b[j] > b[i])
					swap(i, j);
				else
					if(b[j] == b[i])
						if(a[i] > a[j])
							swap(i, j);
						
				
			}
			
		}
		

		for(int i=0;i<n;i++)
			System.out.println(a[i] + " " + String.format("%.2f", b[i]));
		
		
		
	}
	
	public static void swap(int i, int j) {
		double tempj = b[j];
		int tempi = a[j];
		a[j] = a[i];
		b[j] = b[i];
		a[i] = tempi;
		b[i] = tempj;
		
	}

}
