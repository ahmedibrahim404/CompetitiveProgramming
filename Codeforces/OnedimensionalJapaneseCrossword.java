import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class OnedimensionalJapaneseCrossword {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		int n=input.nextInt();
		String s= input.next();
		boolean iscurgroup = false;
		List<Integer> a = new ArrayList<Integer>();
		int ns=0;
		for(int i=0;i<n;i++) {

			if(s.charAt(i) == 'B') {
				
				if(iscurgroup)
					ns++;
				else {
					iscurgroup = true;
					ns++;
				}
				
			} else {
				if(ns > 0)
					a.add(ns);
				iscurgroup = false;
				ns = 0;
			}
			
		}
		
		if(ns > 0) {
			a.add(ns);
			ns = 0;
		}
		
		System.out.println(a.size());
		for(int i=0;i<a.size();i++) {
			System.out.print(a.get(i) + (i == a.size() ? "" : " "));
		}
		
	}

}
