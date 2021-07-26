// CF228-D2-A

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class IsYourHorsesheoOnTheOtherHoof {

	static Scanner input = new Scanner(System.in); 
	
	public static void main(String[] args) {
        Set<Integer> set = new HashSet<Integer>(); 

		for(int i=0;i<4;i++) {
	        set.add(input.nextInt()); 
		}
        
        
  
        System.out.println(4 - set.size()); 


	}

}
