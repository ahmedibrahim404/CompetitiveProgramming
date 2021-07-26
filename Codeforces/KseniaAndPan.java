// CF382-D2-A

import java.util.Scanner;

public class KseniaAndPan {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String[] r = input.next().split("");
		String c = input.next();
		
		for(int i=0;i<r.length;i++) {
			if(r[i].equals("|")) {
				r[i] = "!";
			}
		}
		
		String[] strArr = new String[2];
		String[] str = String.join("", r).split("!");
		
		for(int i=0;i<strArr.length;i++) {
			if(i < str.length) {
				strArr[i] = str[i];
			} else {
				strArr[i] = "";
			}
		}
		
		
		String c1=strArr[0], c2=strArr[1];
		
		for(int j=0;j<c.length();j++) {
			if(c1.length() > c2.length()) {
				
				c2 = c2 + c.charAt(j);
				
			} else {
				
				c1 = c1 + c.charAt(j);

				
			}
		}
		
		System.out.println(c1.length() == c2.length() ? c1 + "|" + c2 : "Impossible");

		
		
	}

}
