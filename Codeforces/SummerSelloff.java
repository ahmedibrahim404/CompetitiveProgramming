import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;
import java.util.Set;

public class SummerSelloff {

	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);
		int n=input.nextInt(), k=input.nextInt();
		int[] as = new int[n];
		long total =0;
		
		for(int i=0;i<n;i++) {
			
			int a=input.nextInt(), b=input.nextInt();
			
			total += Math.min(a, b);
			
			as[i] = a > b ? 0 : Math.min(a*2, b) - Math.min(a, b);
			
		}
		
		Arrays.sort(as);
		for(int i = 0; i < as.length / 2; i++)
		{
		    int temp = as[i];
		    as[i] = as[as.length - i - 1];
		    as[as.length - i - 1] = temp;
		}

		for(int i=0;i<k;i++) {
			total += as[i];
		}
		
		System.out.println(total);
        
	}

}
