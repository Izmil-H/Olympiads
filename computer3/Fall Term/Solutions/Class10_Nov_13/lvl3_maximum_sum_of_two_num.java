import java.util.*;
import java.io.*;
public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
    public static void main(String [] args) throws IOException{
    	int n = readInt(), m = readInt(), a[] = new int[n], ans = 0;
    	for(int i=0; i<n; i++) a[i] = readInt();
    	Arrays.sort(a);
    	for(int i=1; i<n; i++){
    		int p = Arrays.binarySearch(a, 0, i, m-a[i]);
    		if(p < 0) p = -p - 2;
    		if(p >= 0) ans = Math.max(ans, a[i]+a[p]);
    	}
    	System.out.println(ans);
    }
	static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong () throws IOException {
		return Long.parseLong(next());
	}
	static int readInt () throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble () throws IOException {
		return Double.parseDouble(next());
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}