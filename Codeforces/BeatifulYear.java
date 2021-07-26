import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class BeatifulYear {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int y = input.nextInt();
		Set s = new HashSet();
		while(1 == 1) {
			y++;
			String s1 = Integer.toString(y);
			for(int i=0;i<s1.length();i++) {
				s.add(s1.charAt(i));
			}
			
			if(s.size() == s1.length()) {
				System.out.println(s1);
				return;
			} else {
				s.clear();
			}
			
		}
		
	}
	
}
