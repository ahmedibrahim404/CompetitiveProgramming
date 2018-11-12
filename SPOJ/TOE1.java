import java.io.BufferedInputStream;
import java.util.Scanner;

public class TOE1 {

	public static void main(String[] args) {

        Scanner sc = new Scanner(new BufferedInputStream(System.in));
		int T = sc.nextInt();
		char[][] ns = new char[3][3];
		while(T-- > 0) {
			int xs=0, os=0;
			for(int i=0;i<3;i++) {
				String s = sc.next();
				ns[i] = s.toCharArray();
				for(int j=0;j<3;j++) {
					if(ns[i][j] == 'X')
						xs++;
					else if(ns[i][j] == 'O')
						os++;
				}
				
			}
						
			
			if(os > xs || xs-os > 1) {
				System.out.print("no");
				return;
			}
			
			boolean wonX =checkWin(ns, 'X'), wonO = checkWin(ns, 'O');
						
			if(wonX && xs == os) {
				System.out.print("no");
				return;
			}
			
			if(wonO && xs > os) {
				System.out.print("no");
				return;
			}
			
			
			if(wonX && wonO) {
				System.out.print("no");
				return;
			}
			
			System.out.print("yes");	
			System.out.print("\n");
			
			
		}

	}
	
	public static boolean checkWin(char[][] a, char t) {
	  if(a[0][0]==t&&a[0][1]==t&&a[0][2]==t)
		    return true;
		  if(a[1][0]==t&&a[1][1]==t&&a[1][2]==t)
		    return true;
		  if(a[2][0]==t&&a[2][1]==t&&a[2][2]==t)
		    return true;
		  if(a[0][0]==t&&a[1][0]==t&&a[2][0]==t)
		    return true;
		  if(a[0][1]==t&&a[1][1]==t&&a[2][1]==t)
		    return true;
		  if(a[0][2]==t&&a[1][2]==t&&a[2][2]==t)
		    return true;
		  if(a[0][0]==t&&a[1][1]==t&&a[2][2]==t)
		    return true;
		  if(a[2][0]==t&&a[1][1]==t&&a[0][2]==t)
		    return true;
		  return false;
		
	}

}
