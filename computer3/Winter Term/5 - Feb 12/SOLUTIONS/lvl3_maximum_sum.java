import java.util.*;
import java.io.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException, InterruptedException {
		int n = readInt(), a[] = new int[n+1], dp[] = new int[n+1];
		for(int i=1; i<=n; i++) a[i] = readInt();
		dp[1] = a[1];
		for(int i=2; i<=n; i++)
			dp[i] = Math.max(dp[i-2] + a[i], dp[i-1]);
		System.out.println(dp[n]);
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