import java.util.Scanner;

public class NearlyLuckyNumber {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String s = input.next();
		int t = 0;
		for(int i=0;i<s.length();i++) {
			if(s.charAt(i) == '4' || s.charAt(i) == '7') {
				t++;
			}
		}
		
		
		System.out.println(t == 7 || t == 4 ? "YES" : "NO");
	}

}
