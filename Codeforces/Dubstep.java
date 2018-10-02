// CF208-D2-A

import java.util.Scanner;

public class Dubstep {

	static Scanner input = new Scanner(System.in);
	
	public static void main(String[] args) {

		String t = input.nextLine();
		t = t.replaceAll("WUB", " ").trim();
		System.out.println(t);

	}

}
