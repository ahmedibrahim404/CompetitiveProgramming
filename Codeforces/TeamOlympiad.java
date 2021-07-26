// CF490-D2-A

import java.util.Scanner;

public class TeamOlympiad {

	
	static Scanner input = new Scanner(System.in);
	
	public static void main(String[] args) {
		
		int gP=0, gM=0, gPE=0, n=input.nextInt();	
		int[][] arr = new int[4][5000];

		for(int i=0;i<n;i++) {

			switch(input.nextInt()) {
				case 1:
					arr[1][gP] = i+1;
					gP++;
					break;
				case 2:
					arr[2][gM] = i+1;
					gM++;
					break;
				case 3:
					arr[3][gPE] = i+1;
					gPE++;
					break;
			}
						
		}
		
		int numberOfTeams = Math.min(Math.min(gP, gM), gPE);
		
		System.out.println(numberOfTeams);
		
		for(int j=0;j<numberOfTeams;j++) {
			System.out.print(arr[1][j] + " ");
			System.out.print(arr[2][j] + " ");
			System.out.println(arr[3][j] + " ");
		}

		
	}

}
