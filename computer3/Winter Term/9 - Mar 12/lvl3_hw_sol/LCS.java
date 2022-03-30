import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		char s[] = readLine().toCharArray(), t[] = readLine().toCharArray();
		int n = s.length, m = t.length, dp[][] = new int[n+1][m+1];
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
				else dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
			}
		}
		String ans = "";
		for(int i=n, j=m; i>=0 && j>=0 && dp[i][j]!=0; ) {
			if(dp[i][j] == dp[i-1][j]) i--;
			else if(dp[i][j] == dp[i][j-1]) j--;
			else { ans += s[i-1]; i--; j--; }
		}
		for(int i=ans.length()-1; i>=0; i--) 
			System.out.print(ans.charAt(i));
		System.out.println();
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