import java.io.*;
import java.util.*;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
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

	public static void main(String[] args) throws IOException {
		int n = readInt(), q = readInt(), arr[] = new int[n+1], mv = (int)1e6;
		int freq[] = new int[2*mv];
		long psa[][] = new long[n+1][n+1];
		for (int i = 1; i <= n; i++) arr[i] = readInt();
		for (int i = 1; i <= n; i++)  {
			for (int k = i+1; k <= n; k++)  {
				int v = -(arr[i]+arr[k]) + mv;
				if (v >= 0 && v < 2*mv) psa[i][k] += freq[v];
				freq[arr[k]+mv]++;
			}
			for (int k = i+1; k <= n; k++) freq[arr[k]+mv] = 0;
		}
		for (int i = 1; i <= n; i++)  {
			for (int j = 1; j <= n; j++)  {
				psa[i][j] += psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
			}
		}
		for (int i = 1; i <= q; i++)  {
			int a = readInt(), b = readInt();
			System.out.println(psa[b][b] - psa[b][a-1] - psa[a-1][b] + psa[a-1][a-1]);
		}
	}
}