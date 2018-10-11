// CF514-D2-A

import java.util.Scanner;

public class CAndNumber {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		String[] x = input.next().split("");
        
        if(x.length > 1) {
            for(int i=0;i<x.length;i++) {
            	if(Integer.parseInt(x[i]) > 4) {
            		x[i] = Integer.toString(9 - Integer.parseInt(x[i]));
            	}
            	if(i==0 && x[i].equals("0")) {
            		x[i]="9";
            	}
            }
        }
        
        for(int j=0;j<x.length;j++) {
        	System.out.print(x[j]);
        }
        
	}
	
}
