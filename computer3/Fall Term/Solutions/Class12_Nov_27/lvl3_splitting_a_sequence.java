import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static int n, m, a[];
	public static void main(String[] args) throws IOException{
		n = readInt(); m = readInt(); a = new int[n];
		long lo = 0, hi = 0, ans = Integer.MAX_VALUE;
		for(int i=0; i<n; i++) {
			a[i] = readInt(); 
			lo = Math.max(lo, a[i]); hi += a[i];
		}
		while(lo <= hi) {
			long mid = (lo + hi)/2;
			if(check(mid)) { ans = mid; hi = mid - 1; }
			else lo = mid + 1;
		}
		System.out.println(ans);
	}
	static boolean check(long limit) {
		long sum = a[0]; int cnt = 1;
		for(int i=1; i<a.length; i++) {
			if(sum + a[i] <= limit) sum += a[i];
			else { cnt++; sum = a[i]; }
		}
		return cnt <= m;
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