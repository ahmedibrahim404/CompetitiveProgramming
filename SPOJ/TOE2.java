import java.io.BufferedInputStream;
import java.util.Scanner;
import java.util.StringTokenizer;

public class TOE2 {

	public static void main(String[] args) {

        Scanner sc = new Scanner(new BufferedInputStream(System.in));
		char[][] ns = new char[3][3];
		String s;
		
        while ((s = sc.next())!=null) {
        	if(s.equals("end")) return;
        	        	
			int cntx=0, cnto=0;
			for(int i=0;i<3;i++) {
				ns[i] = s.substring(i*3, (i*3) + 3).toCharArray();
				for(int j=0;j<3;j++)
					if(ns[i][j] == 'X')
						cntx++;
					else if(ns[i][j] == 'O')
						cnto++;
			}
						
			

			
			boolean winx =checkWin(ns, 'X'), wino = checkWin(ns, 'O');
			boolean valid=true;
			
			if(cntx != cnto && cntx != cnto + 1)
				valid = false;
			if(winx && wino)
				valid = false;
			if(winx && (cnto >= cntx))
				valid = false;
			if(wino && (cntx != cnto))
				valid = false;
			if(!wino && !winx && (cntx + cnto != 9))
				valid = false;

			if(valid)
				System.out.println("valid");	
			else
				System.out.println("invalid");

			
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
