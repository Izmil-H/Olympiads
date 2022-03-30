import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		int n = readInt(), h[] = new int[n+1], dp[] = new int[n+1];
		for(int i=1; i<=n; i++) h[i] = readInt();
		dp[2] = Math.abs(h[1] - h[2]);
		for(int i=3; i<=n; i++)
			dp[i] = Math.min(dp[i-1] + Math.abs(h[i]-h[i-1]), dp[i-2]+Math.abs(h[i] - h[i-2]));
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