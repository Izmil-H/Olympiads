import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static int mod = (int)1e9+7;
	public static void main(String[] args) throws IOException{
		for(int T = readInt(); T > 0; T--) {
			long a = readLong(), b = readLong(), c = readLong(), k = readLong();
			if(b - a == c - b) 
				System.out.println( (a + (b-a)*(k-1)%mod)%mod );
			else 
				System.out.println( a * pow(b/a, k-1, mod)%mod );
		}
	}
	static long pow(long x, long exp, long mod) {
		if(exp == 0) return 1;
		long t = pow(x, exp/2, mod);
		t = t*t % mod;
		if(exp % 2 == 0) return t;
		return t*x % mod;
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