import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class FilyaAndHomework {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		int n=input.nextInt();
		
		Set<Integer> ns = new HashSet<Integer>();
		
		for(int i=0;i<n;i++) {
			ns.add(input.nextInt());			
		}
		
		Object[] a = ns.toArray();
				
		if(a.length > 3)
			System.out.println("NO");
		else if(a.length == 1 || a.length == 2)
			System.out.println("YES");
		else {
			Arrays.sort(a);
			if((int) a[a.length - 1] - (int) a[a.length - 2] ==  (int) a[a.length - 2] - (int) a[a.length - 3] )
				System.out.println("YES");
			else
				System.out.println("NO");
		}
				
				
	}
	
}
