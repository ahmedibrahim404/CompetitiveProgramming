// CF47-D2-B

import java.util.Scanner;

public class Coins {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		int[] n = new int[3];
		for(int j=0;j<3;j++)
			n[j]=0;
		
		for(int i=0;i<3;i++) {
			String[] c = input.next().split("");
			switch(c[1]) {
				case "<":
					n[getNum(c[2])-1]++;
					break;
				case ">":
					n[getNum(c[0])-1]++;
					break;
				default:
					break;
			}
		}
		
		if(n[0] == n[1] && n[1] == n[2])
		{
			System.out.println("Impossible");
			return;
		}
		
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				if(n[j] == i) System.out.print(getChar(j));
		
	}
	
	public static int getNum(String e) {
		switch(e) {
			case "A":
				return 1;
			case "B":
				return 2;
			case "C":
				return 3;
		}
		return -1;
	}
	
	public static String getChar(int e) {
		switch(e) {
		case 0:
			return "A";
		case 1:
			return "B";
		case 2:
			return "C";
	}
	return "";

	}
	


	
}
