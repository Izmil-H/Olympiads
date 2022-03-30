import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static int n, p[], w[], d[];
	public static void main(String[] args) throws IOException{	
		n = readInt(); p = new int[n]; w = new int[n]; d = new int[n];
		for(int i=0; i<n; i++) {
			p[i] = readInt(); w[i] = readInt(); d[i] = readInt();
		}
		int lft = 0, rit = (int)1e9+1;
		while(lft < rit) {
			int mid = (lft + rit)/2;
			if(f(mid) < f(mid + 1)) rit = mid;
			else lft = mid+1;
		}
		System.out.println(f(lft));
	}
	static long f(int x) {
		long cost = 0;
		for(int i=0; i<n; i++) {
			if(x < p[i] - d[i]) cost += (long)(p[i] - d[i] - x) * w[i];
			if(x > p[i] + d[i]) cost += (long)(x - p[i] - d[i]) * w[i];
		}
		return cost;
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
	static char readCharacter () throws IOException {
		return next().charAt(0);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}