// CF520-D2-A

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Pangram {

	
	static Scanner input = new Scanner(System.in);
	
	public static void main(String[] args) {
		
		int n= input.nextInt();

		String[] word = input.next().toLowerCase().split("");
		
        Set<String> setS = new HashSet<String>(); 

        for(int i=0;i<word.length;i++) {
        	setS.add(word[i]);
        }
        
        System.out.println(setS.size() == 26 ? "YES" : "NO");
        

	}

}
