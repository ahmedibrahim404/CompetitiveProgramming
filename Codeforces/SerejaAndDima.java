// CF381-D2-A

import java.util.Scanner;

public class SerejaAndDima {

	static Scanner input = new Scanner(System.in);;

	public static void main(String[] args) {
				
		int n = input.nextInt();
		
		int[] arr = new int[n];
		
		for(int i=0;i<n;i++) {
			if(input.hasNextInt()) {
				arr[i] = input.nextInt();
			}
		}
		
		int min=0, max=n-1, role, val;
		int s=0,d=0;
		
		for(int j=0;j<n;j++) {
			
			role = j % 2;
		
			if(arr[min] > arr[max]) {
				val = arr[min];
				min++;
			} else {
				val = arr[max];
				max--;
			}
			
			if(role == 0) 
				s+=val;
			else 
				d+=val;
		
		}
		
		System.out.println(s + " " + d);
		
		
	}

}
