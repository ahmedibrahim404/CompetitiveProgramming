// CF785-D2-A

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class AntonAndPolyhedrons {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		Map<String, Integer> map = new HashMap<String, Integer>();
		map.put("Tetrahedron", 4);
		map.put("Cube", 6);
		map.put("Octahedron", 8);
		map.put("Dodecahedron", 12);
		map.put("Icosahedron", 20);
		long sum=0;
		
		for(int i=0;i<n;i++) {
			sum+=map.get(input.next());
		}
		
		System.out.println(sum);
		
	}

}
