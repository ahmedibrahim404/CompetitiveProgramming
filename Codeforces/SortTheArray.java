import java.util.Arrays;
import java.util.Scanner;

public class SortTheArray {

	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);
		int n =input.nextInt();
		
		int[] a = new int[n], b = new int[n];
		
		for(int l=0;l<n;l++) {
			a[l] = input.nextInt();
			b[l] = a[l];
		}
		
		Arrays.sort(b);
		
		
		int start=-1, end=-1;
		
		for(int i=0;i<n;i++)
			if(a[i] != b[i]) {
				start = i;
				break;
			}
		
		for(int j=n-1;j>=0;j--)
			if(a[j] != b[j]) {
				end=j;
				break;
			}
		

		if( start == -1 && end == -1 ) {
			System.out.println("yes");
			System.out.println("1 1");
			return;
		}
		
		
		
		reverseOrder(a, start, end);
		
		for(int i=0;i<n;i++) {
			if(!(a[i] == b[i])) {
				System.out.println("no");
				return;
			}
		}
			
		System.out.println("yes");
		System.out.println((start+1) + " " + (end+1));
							

	}
	
	
	public static void reverseOrder(int[] a, int l, int r) {
        for(int i=l,j=r; i<=(l+r)/2; i++,j--) {
        	int b = a[i];
        	a[i] = a[j];
        	a[j] = b;
        }

        

		
	}

}
