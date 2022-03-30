import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static int n, counter = 0;
	public static void main(String[] args) throws IOException{
		n = readInt();
		for(int i=1; i<=n/2; i++) {
			fun(i, i, n + "=" + i);
		}
		System.out.println("total="+counter);
	}
	static void fun(int pre, int sum, String ans) {
		if(sum == n) {
			System.out.println(ans);
			counter++; return;
		}
		for(int i=pre; i+sum <= n; i++) {
			fun(i, sum+i, ans + "+" + i);
		}
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