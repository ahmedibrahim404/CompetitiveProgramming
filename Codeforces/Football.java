// CF43-D2-A

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Football {

	static Scanner input = new Scanner(System.in);
	public static void main(String[] args) {
		
		int n = input.nextInt();
		
        Map<String, Integer> map = new HashMap<String, Integer>();
        String tn;
		for(int i=0;i<n;i++) {
			tn = input.next();
			if(map.get(tn) != null) {
				map.put(tn,  map.get(tn) + 1);
			} else {
				map.put(tn,  1);
			}
		}
		
		String maxKey = null;
		for (String key : map.keySet())
		{
		    if (maxKey == null || map.get(key) > map.get(maxKey))
		    {
		        maxKey = key;
		    }
		}
		
		System.out.println(maxKey);
		
		
			    
		
	}
	
}
