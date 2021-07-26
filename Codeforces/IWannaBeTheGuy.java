// CF469-D2-A

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class IWannaBeTheGuy {
	
	static Scanner input = new Scanner(System.in);

	public static void main(String[] args) {

        Set<Integer> levels = new HashSet<Integer>(); 
        int n = input.nextInt();

        for(int k=1;k<=2;k++) {
        	int m = input.nextInt();
        	for(int i=0;i<m;i++) {
        		levels.add(input.nextInt());	
        	}
        	
    	}

        System.out.println(levels.size() == n ? "I become the guy." : "Oh, my keyboard!");

        

	}

}
