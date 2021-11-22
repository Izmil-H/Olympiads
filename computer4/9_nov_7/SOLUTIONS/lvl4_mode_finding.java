import java.io.*;
import java.util.*;
public class homework {
    public static void main(String[] args) {
    	Scanner in = new Scanner(System.in);
    	int n = in.nextInt(); TreeMap<Integer, Integer> mp = new TreeMap<Integer, Integer>();
    	for(int i=0; i<n; i++){
    		int x =in.nextInt(); mp.put(x,  mp.getOrDefault(x, 0)+1);
    	}
    	int cnt = 0, ans = 0;
    	for(int x: mp.keySet())
    		if(mp.get(x) > cnt){ cnt=mp.get(x); ans = x; }
    	System.out.println(ans);
    }
}