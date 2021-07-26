// CF287-D2-A

import java.util.Scanner;

public class IQTest {

	public static void main(String[] args) {
		String[][] ch = new String[4][4];
		Scanner input = new Scanner(System.in);
		for(int k=0;k<4;k++) {
			String[] e = input.next().split("");
			for(int l=0;l<4;l++) {
				ch[k][l] = e[l];
			}
		}
		
		for(int i=0;i<4;i++) {
			for(int j=0;j<4;j++) {
				String first;
				if(isSquare(i,j, ch)) {
					System.out.println("YES");
					return;
				} else {
					first = ch[i][j];
					if(ch[i][j].equals("#")) {
						ch[i][j] = ".";
					} else {
						ch[i][j] = "#";
					}
					if(isSquare(i,j, ch)) {
						System.out.println("YES");
						return;
					}
					ch[i][j] = first;
				}
			}
		}
		System.out.println("NO");

	}
	
	public static boolean isSquare(int i, int j, String[][] ch) {
		if(i+1==4 || j+1==4) {
			return false;
		}
		return (ch[i][j].equals(ch[i][j+1])  && ch[i][j].equals(ch[i+1][j])  && ch[i][j].equals(ch[i+1][j+1])
				|| ( j == 1 && ch[i][j].equals(ch[i][j-1])  && ch[i][j].equals(ch[i+1][j])  && ch[i][j].equals(ch[i+1][j-1]) ) );
	}


}