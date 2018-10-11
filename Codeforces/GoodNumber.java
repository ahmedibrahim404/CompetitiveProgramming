// CF365-D2-A

import java.util.Scanner;

public class GoodNumber {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n=input.nextInt(), k=input.nextInt();
		String nums = "0123456789";
		int no=0;
		boolean isgood=true;
		for(int i=0;i<n;i++) {
			isgood=true;
			String s = input.next();
				for(int j=0;j<=k;j++) {
					if(s.indexOf(nums.charAt(j)) == -1) {
						isgood = false;
						break;
					} 
				}
			if(isgood == true) {
				no++;
			}
		}
		System.out.println(no);
	}
		
	
}
