import java.util.Scanner;

public class DreamoonAndWifi {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		String s1=input.next(), s2=input.next();
		int n=0, st1=0, st2=0;
		for(int i=0;i<s1.length();i++) {
			
			if(s1.charAt(i) == '+')
				st1++;
			else
				st1--;
			
			if(s2.charAt(i) == '+')
				st2++;
			else if(s2.charAt(i) == '-')
				st2--;
			else
				n++;
			
		}
		
		double p=Math.pow(2, n);
		
		if(n == 0) {
			System.out.println(st1 == st2 ? 1 : 0);
			return;
		}
		
		int i = n + (st1 - st2);
		
		if(i % 2 == 0 && i/2 >= 0 && i/2 <= n)
			System.out.println(fact(n)/(fact(n-i/2) * fact(i/2))/p);
		else
			System.out.println(0);
		
		
	}
	
	public static int fact(int n) {
		
		if(n == 0 || n == 1)
			return 1;
		else
			return n*fact(n-1);
		
	}
	
}
