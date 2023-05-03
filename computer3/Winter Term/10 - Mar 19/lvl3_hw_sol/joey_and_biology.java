import java.util.*;
import java.io.*;
import java.time.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		int n = readInt(), m = readInt(), dp[][] = new int[n+1][m+1];
		char a[] = readLine().toCharArray(), b[] = readLine().toCharArray();
		for(int i=0; i<=n; i++) {
			for(int j=0; j<=m; j++) {
				if(i==0 && j == 0) dp[i][j] = 0;
				else if(i == 0) dp[i][j] = (j+2)/3;
				else if(j == 0) dp[i][j] = (i+2)/3;
				else {
					if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
					else dp[i][j] = dp[i-1][j-1] + 1;
					for(int k=1; k<=3; k++) {
						if(j>=k) dp[i][j] = Math.min(dp[i][j], dp[i][j-k]+1);
						if(i>=k) dp[i][j] = Math.min(dp[i][j], dp[i-k][j]+1);
					}
				}
			}
		}
		System.out.println(dp[n][m]);
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