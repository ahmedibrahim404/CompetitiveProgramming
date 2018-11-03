// CF78-D2-B

import java.util.Scanner;

public class EasterEggs {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();	
		String colors = "ROYGBIV";
		char[] e = new char[n];
		for(int i=0;i<7; i++) {
			e[i] = colors.charAt(i);
		}
		
		
		
		for(int i=7;i<n;i++) {
			e[i] = getChar(e, i);
		}
		
		
		for(int j=0;j<n;j++) {
			System.out.print(e[j]);
		}

		
		
	}
	
	public static char getChar(char[] arr, int index) {
		
		String getFrom = "ROYGBIV";
		
			
		for(int j=0;j<7;j++) {
			if(getFrom.charAt(j) != arr[index-1] && getFrom.charAt(j) != arr[index-2] && getFrom.charAt(j) != arr[index-3]) {
				
				int next1 = isNext(arr, index+1);
				if(next1 != -1) {
					if(arr[next1] == getFrom.charAt(j)) {
						continue;
					}
				}
				
				int next2 = isNext(arr, index+2);
				if(next2 != -1) {
					if(arr[next2] == getFrom.charAt(j)) {
						continue;
					}
				}
				
				int next3 = isNext(arr, index+3);
				if(next3 != -1) {
					if(arr[next3] == getFrom.charAt(j)) {
						continue;
					}
				}
				
				return getFrom.charAt(j);
			}
		}
		
		return 0;
			
	}
	
	public static int isNext(char[] arr, int index) {
		if(index > arr.length-1)
			index = index - arr.length;
					
		if(index >= 0 && index < arr.length)
			if(arr[index] != 0)
				return index;
			else
				return -1;
		else
			return -1;
		
		
	}

}
