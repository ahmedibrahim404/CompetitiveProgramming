import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class ThePlayboyChimp_10611 {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] talls=new int[n];
    	StringTokenizer st = new StringTokenizer(br.readLine());
    	for(int i=0;i<n;i++) {
    		talls[i]=Integer.parseInt(st.nextToken());
    	}
    	
    	int m = Integer.parseInt(br.readLine());
    	StringTokenizer st2 = new StringTokenizer(br.readLine());
    	for(int j=0;j<m;j++) {
    		int number = Integer.parseInt(st2.nextToken());
    		int low = (int) lowVal(talls, number, 0, talls.length);
    		int high = (int) highVal(talls, number, 0, talls.length);
    		System.out.println((low != -1 ? low : "X") + " " + (high == -1 ? "X" : high));
    	}
    	
	}
	
	public static Object highVal(int[] arr, int target, int low, int high) {
		int mid = Math.round((low + high) /2);
		if(target > arr[arr.length - 1]) return -1;
		if(target < arr[0]) return arr[0];
		if(target == arr[mid]) return arr[mid+1];
		
		if(target < arr[mid] && target >= arr[mid-1])
			return arr[mid];
		
		if(arr[mid] > target)
			return highVal(arr, target, low, mid);
		else
			return highVal(arr, target, mid, high);
		
	}
	
	public static Object lowVal(int[] arr, int target, int low, int high) {
		int mid = Math.round((low + high) /2);
		if(target > arr[arr.length - 1]) return arr[arr.length - 1];
		if(target < arr[0]) return -1;
		if(target == arr[mid]) return arr[mid-1];

		if(target > arr[mid] && target <= arr[mid+1]) {
			return arr[mid];
		}
		
		if(arr[mid] > target) {
			return lowVal(arr, target, low, mid);
		} else {
			return lowVal(arr, target, mid, high);
		}
		
	}

}
