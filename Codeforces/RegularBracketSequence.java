import java.util.Scanner;

public class RegularBracketSequence {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String s = input.next();
		
		int open= 0;
		int trueBrackets=0;
		for(int i=0;i<s.length();i++) {
			
			if(s.charAt(i) == '(') {
				open++;
				trueBrackets++;
			} else if(s.charAt(i) == ')') {
				if(open > 0) {
					open--;
					trueBrackets++;
				}
			}
			
			
			
		}
				
		System.out.println(trueBrackets-open);
		
	}
	
}
