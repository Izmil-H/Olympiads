import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		int N = readInt(), M = readInt(), W = readInt();
		long dp[] = new long[W+1]; 
		int p[] = new int[N+1], s[] = new int[N+1];
		for(int i=1; i<=N; i++) {
			p[i] = readInt(); s[i] = readInt();
			for(int j=p[i]; j<=W; j++)
				dp[j] = Math.max(dp[j], dp[j-p[i]] + s[i]);
		}
		for(int i=1; i<=M; i++) {
			int q = readInt(), t = readInt(), d = readInt(), amt = readInt();
			for(int k=1; k<=amt; k*=2) {
				int cost = k*d; long value = (long)k*q*s[t];
				for(int j=W; j>=cost; j--)
					dp[j] = Math.max(dp[j], dp[j-cost] + value);
				amt -= k;
			}
			if(amt > 0) {
				int cost = amt*d; long value = (long)amt*q*s[t];
				for(int j=W; j>=cost; j--)
					dp[j] = Math.max(dp[j], dp[j-cost] + value);				
			}
		}
		System.out.println(dp[W]);
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