import java.util.*;
import java.io.*;
public class usaco_loan_repayment {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static long n, k, m;
	public static void main(String[] args) throws IOException {
		n = readLong(); k = readLong(); m = readLong();
		long lo = 1, hi = n, ans = 0;
		while(lo <= hi) {
			long mid = (lo + hi)/2;
			if(check(mid)) { ans = mid; lo = mid + 1; }
			else hi = mid - 1;
		}
		System.out.println(ans);
	}
	static boolean check(long x) {
		long g = 0;
		for(long day=0; day<k; ) {
			long y = (n - g)/x;
			if(y <= m) { g += (k - day)*m; break; }
			long len = Math.min((n - g - x*y)/y + 1, k-day);
			g += len * y; day += len;
		}
		return g >= n;
	}
	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}

	static long readLong() throws IOException {
		return Long.parseLong(next());
	}

	static int readInt() throws IOException {
		return Integer.parseInt(next());
	}

	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static char readCharacter() throws IOException {
		return next().charAt(0);
	}

	static String readLine() throws IOException {
		return br.readLine().trim();
	}
}