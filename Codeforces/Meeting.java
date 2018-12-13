import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Scanner;

public class Meeting {
	static int[] xs;
	static int[] ys;
	static int[] rs;
	static int n;
	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);
		int x1=input.nextInt(), y1=input.nextInt(), x2=input.nextInt(), y2=input.nextInt();
		n=input.nextInt();
		xs = new int [1009];
		ys = new int [1009];
		rs = new int [1009];
		
		int total=0;
		for(int i=0;i<n;i++) {
			xs[i]=input.nextInt();
			ys[i]=input.nextInt();
			rs[i]=input.nextInt();
		}
		
		for(int i=Math.min(y1, y2)+1;i< Math.max(y1, y2);i++)
			total += isNeed(x1, i) + isNeed(x2, i);

		
		for(int i=Math.min(x1, x2);i<=Math.max(x1, x2);i++) 
			total += isNeed(i, y1) + isNeed(i, y2) ;
			
		
		
		System.out.println(total);

	}
	
	public static int isNeed(int x, int y) {
	    
	    for(int i=0;i<n;i++) {
	    
	    	int x2 = xs[i], y2=ys[i], disv=rs[i];
	        int dis =  (x - x2)*(x - x2) + (y - y2)*(y - y2);
	        if(dis <= disv*disv) {
	        	return 0;
	        }

	    }
	    	    
	    return 1;
	}

}
