import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), ans = 0, a[] = new int[n+2], pre[] = new int[n+2], suf[] = new int[n+2];
		for(int i=1; i<=n; i++) {
			a[i] = readInt();
			pre[i] = gcd(pre[i-1], a[i]);
		}
		for(int i=n; i>=1; i--) {
			suf[i] = gcd(suf[i+1], a[i]);
		}
		for(int i=1; i<=n; i++) {
			ans = Math.max(ans, gcd(pre[i-1], suf[i+1]));
		}
		System.out.println(ans);
	}
	static int gcd(int n, int m) {
		if(m == 0) return n;
		return gcd(m, n % m);
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