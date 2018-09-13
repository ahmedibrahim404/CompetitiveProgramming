// CF263-D2-A

import java.util.Scanner;

public class BeautifulMatrix {
	static Scanner input = new Scanner(System.in);
	static int[] numbers;
	static int j=0;
	public static void main(String[] args) {
		String[] line = input.nextLine().split(" ");
	    for(int i=0;i<25;i++){
	    	if(i % 5 == 0 && i != 0) {
	    		if(input.hasNextLine()) {
		    		line = input.nextLine().split(" ");
		    		j = 0;
	    		} else {
	    			break;
	    		}
	    	}
	    	j++;

	    	if(Integer.parseInt(line[j-1]) == 1) {
	    		System.out.println(12-i);
	    	}

	    }
	}
}
