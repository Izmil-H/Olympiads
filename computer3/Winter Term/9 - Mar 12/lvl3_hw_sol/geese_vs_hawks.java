import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		int n = readInt(), a[] = new int[n], b[] = new int[n];
		char s[] = readLine().toCharArray();
		for(int i=0; i<n; i++) a[i] = readInt();
		char t[] = readLine().toCharArray();
		for(int i=0; i<n; i++) b[i] = readInt();
		int dp[][] = new int[n+1][n+1];
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
				if((s[i-1]=='W' && t[j-1]=='L' && a[i-1] > b[j-1]) ||
					(s[i-1]=='L' && t[j-1]=='W' && a[i-1] < b[j-1]) )
					dp[i][j] = Math.max(dp[i][j], dp[i-1][j-1]+a[i-1]+b[j-1]);
			}
		}
		System.out.println(dp[n][n]);
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