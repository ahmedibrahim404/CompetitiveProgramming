// CF6-D2-B

import java.util.Scanner;

public class PresidentsOffice {
	static char[][] ns;
	static char[][] took;
	static int[] xs = { -1, 1, 0, 0 };
	static int[] ys = { 0, 0, 1, -1 };
	static char presch;
	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);
		int n=input.nextInt(), m=input.nextInt(), a=0;
		presch = input.next().charAt(0);
		boolean[][] pres = new boolean[n][m];
		ns = new char[n][m];
		took = new char[n][m];

		
		for(int i=0;i<n;i++){
			String l = input.next();
			for(int j=0;j<m;j++){
				ns[i][j] = l.charAt(j);
				if(ns[i][j] == presch)
					pres[i][j] = true;
			}
		}
		
		for(int k=0;k<n;k++) {
			for(int l=0;l<m;l++) {
				if(pres[k][l] == true)
					a += getAmmount(k, l);
			}
		}
		
		System.out.println(a);
		
	}
	
	public static int getAmmount(int i, int j) {
		int n=0;
		for(int k=0;k<4;k++) {
			
			int x=i+xs[k], y=j+ys[k];
			if(isTrue(x, y) && ns[x][y] != '.' && ns[x][y] != presch) {
				n++;
				took[x][y] = ns[x][y];
			}
			
			
		}
		return n;
		
	}
	
	public static boolean isTrue(int i, int j) {
		
		for(int k=0;k<ns.length;k++) {
			for(int l=0;l<ns[0].length;l++) {
				if( i >= 0 && j >= 0 && i < took.length && j < took[0].length && took[k][l] == ns[i][j])
					return false;
			}
		}
		
		return ( i >= 0 && j >= 0 && i < ns.length && j < ns[0].length );
		
	}

}
