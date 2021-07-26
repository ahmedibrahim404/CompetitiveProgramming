import java.util.Scanner;
import java.util.*;

public class Keyboard_88 {
	static List<int[]> shiftList;
	static int n, m, x;
	static char[][] ns;
	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);
		n=input.nextInt();
		m=input.nextInt();
		x=input.nextInt();
		ns = new char[n][m];
		Map<Character, String> ns2 = new HashMap<Character, String>();
	    shiftList = new ArrayList<int[]>();
		
		for(int i=0;i<n;i++) {
			char[] s = input.next().toCharArray();
			for(int j=0;j<m;j++) {
				ns2.put(s[j], i+"-"+j);
				ns[i][j] = s[j];
				if(s[j] == 'S') {
					shiftList.add(new int[] { i, j });
				}
			}
		}
		
		int q=input.nextInt();
		String s = input.next();
		int total = 0;
		for(int i=0;i<s.length();i++){
			if(ns2.containsKey(Character.toLowerCase(s.charAt(i)))) {
				double a = getPositionToNearest(s.charAt(i));
				if(a == -1) {
					System.out.println(-1);
					return;
				}
				
				if(a>x) {
					total++;
				}
			} else {
				System.out.println("-1");
				return;
			}
		}
		
		
		System.out.println(total);

	}
	
	public static double getPositionToNearest(char ss) {
		double lowest = 51;
		int index=-1;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(ns[i][j] == Character.toLowerCase(ss)) {
					index = i;
					if(Character.isUpperCase(ss)) {
						if(shiftList.isEmpty()) {
							return -1;
						}
						for(int k=0;k<shiftList.size();k++) {
							int c=shiftList.get(k)[0]+1, d=shiftList.get(k)[1]+1;
							double dis = Math.sqrt(Math.pow((i+1)-c, 2) + Math.pow((j+1)-d, 2));
							if(dis < lowest) {
								lowest = dis;
							}
						}
					} else {
						lowest = 0;
					}
				}
			}
		}
				
		if(index == -1) 
			return -1;
		
		
		return lowest;
	}
	
	

}
