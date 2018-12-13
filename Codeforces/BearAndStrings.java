import java.util.Scanner;

public class BearAndStrings {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String s=input.next();
		int si = s.length();
		int t=0;
		for(int i=0;i<si-3;i++)
			for(int j=i;j<si-3;j++)
				if(s.charAt(j) == 'b' && s.charAt(j+1) == 'e' && s.charAt(j+2) == 'a' && s.charAt(j+3) == 'r') {
					t+=si-j-3;
					break;
				}
		
		System.out.println(t);
	}
	
}
