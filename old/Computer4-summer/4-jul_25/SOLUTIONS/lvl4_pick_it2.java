import java.util.*;
import java.io.*;
public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		int n = readInt(), k = readInt(), f = 0, r = 0, q[] = new int[n+1];
		long psa[] = new long[n+1], dp[][] = new long[n+1][2];
		for(int i=1; i<=n; i++){
			psa[i] = readLong(); psa[i] += psa[i-1];
			dp[i][0] = Math.max(dp[i-1][0], dp[i-1][1]);
			while(f <= r && q[f]<i-k) f++;
			dp[i][1] = dp[q[f]][0] + psa[i] - psa[q[f]];
			while(f <= r && dp[q[r]][0] < dp[i][0] - (psa[i] - psa[q[r]])) r--;
			q[++r] = i;
		}
		pr.println(Math.max(dp[n][0], dp[n][1])); pr.close();
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