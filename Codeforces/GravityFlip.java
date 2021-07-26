// CF405-D2-A

import java.util.Arrays;
import java.util.Scanner;

public class GravityFlip {

	static Scanner input = new Scanner(System.in);

	public static void main(String[] args) {
		int n = Integer.parseInt(input.nextLine());
		String[] cubes = input.nextLine().split(" ");
		int[] cubesI = new int[n];

		for(int j=0;j<cubes.length;j++) {
			cubesI[j] = Integer.parseInt(cubes[j]);
		}

		Arrays.sort(cubesI);
		
		for(int i=0;i<cubes.length;i++) {
			System.out.print(cubesI[i] + " ");
		}
	

	}

}
