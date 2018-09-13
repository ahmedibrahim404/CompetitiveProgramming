// CF231-D2-A

import java.util.Scanner;

public class Team {
	
	static Scanner input = new Scanner(System.in);

	public static void main(String[] args) {
		
		int nProblems = Integer.parseInt(input.nextLine());
		int problemsT = 0;
		
		for(int i=0;i<nProblems;i++) {
			String[] results = input.nextLine().split(" ");
			int answeredO=0;
			for(int j=0;j<results.length;j++) {
				if(Integer.parseInt(results[j] ) == 1) {
					answeredO++;
				}
			}
			if(answeredO>1) {
				problemsT++;
			}
		}
		
		System.out.println(problemsT);

	}

}
