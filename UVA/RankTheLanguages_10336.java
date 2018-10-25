import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.StringTokenizer;

// Change to Main when Uploading to UVA 
public class RankTheLanguages_10336 {

	static int n,m;
	static int[] xs = { 0, 0, 1, -1 };
	static int[] ys = { 1, -1, 0, 0 };
	static boolean[][] seen;
	static char[][] list;
	static int times = 0;
	public static void main(String[] args) throws NumberFormatException, IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int tc = Integer.parseInt(br.readLine());
		for(int a=0;a<tc;a++) {
			Map<Character, Integer> cts = new HashMap<Character, Integer>();
	    	StringTokenizer st = new StringTokenizer(br.readLine());
	    	n = Integer.parseInt(st.nextToken());
	    	m = Integer.parseInt(st.nextToken());
	    	list = new char[n][m];
	    	seen = new boolean[n][m];
	    	for(int e=0;e<n;e++) {
	    		String t = br.readLine();
	    		list[e] = t.toCharArray();
	    	}
	    	
	    	for(int i=0;i<n;i++) {
	    		for(int j=0;j<m;j++) {
	    			if(!seen[i][j]) {
	    				cts.put(list[i][j], cts.containsKey(list[i][j]) ? cts.get(list[i][j]) + 1 : 1);
	    				DFS(i, j);
	    			}
	    		}
	    	}
	    
			cts = sortByValue(cts);

			System.out.println("World #" + (a+1));
	        for (Character key : cts.keySet()){
	            System.out.println(key+": "+cts.get(key));
	        }
		}
	    		    	
		
		
		

	}
	
	public static void DFS(int i, int j) {
		seen[i][j] = true;
		for(int l=0;l<4;l++) {
			if(valid(i+xs[l], j+ys[l]) && list[i][j] == list[i+xs[l]][j+ys[l]]) {
				DFS(i+xs[l], j+ys[l]);
			}
		}
	}
	
	public static boolean valid(int i, int j) {
		return ( i >= 0 && j >= 0 && i < n && j < m && !seen[i][j] );
	}
	
	private static <K, V> Map<K, V> sortByValue(Map<K, V> map) {
	    List<Entry<K, V>> list = new LinkedList<>(map.entrySet());
	    Collections.sort(list, new Comparator<Object>() {
	        @SuppressWarnings("unchecked")
	        public int compare(Object o1, Object o2) {
	            return ((Comparable<V>) ((Map.Entry<K, V>) (o2)).getValue()).compareTo(((Map.Entry<K, V>) (o1)).getValue());
	        }
	    });

	    Map<K, V> result = new LinkedHashMap<>();
	    for (Iterator<Entry<K, V>> it = list.iterator(); it.hasNext();) {
	        Map.Entry<K, V> entry = (Map.Entry<K, V>) it.next();
	        result.put(entry.getKey(), entry.getValue());
	    }

	    return result;
	}
	
	

}
