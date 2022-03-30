import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static long memo[] ;
	public static void main(String[] args) throws IOException{	
		int n = readInt(); memo = new long[n+1];
		System.out.println(f(n));
	}
	static long f(int n) {
		if(memo[n] != 0) return memo[n];
		if(n <= 1) return memo[n] = 1;
		long ans = 1;
		for(int i=1; i<=n/2; i++) {
			ans += f(n-2*i);
		}
		return memo[n] = ans;
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