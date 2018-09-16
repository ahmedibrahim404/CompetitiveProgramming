// CF339-D2-A

import java.util.Arrays;
import java.util.Scanner;

public class HelpfulMaths {

	
	static Scanner input = new Scanner(System.in);
	
	public static void main(String[] args) {
		
		String s = input.nextLine();
				
		String[] n = s.split("");
		
		int[] nArr = new int[n.length];
		
		for(int i=0;i<n.length;i++) {
			if(! (n[i].equals("+")))
				nArr[i] = Integer.parseInt(n[i]);
		}
		
		Arrays.sort(nArr);
		
		String a = "";
		
		for(int j=0;j<nArr.length;j++) {
			if(!(nArr[j] == 0)) {
				if(j == nArr.length - 1) {
					a += nArr[j];
				} else {
					a += nArr[j] + "+";
				}
			}

			

		}
		
		System.out.println(a);
		
		
		
	}

}
