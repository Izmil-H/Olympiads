import java.util.*;
import java.io.*;
public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		int n = readInt(); long g = 0;
		for(int i=0; i<n; i++)
			g = gcd(g, readLong());
		if(g == 1) System.out.println("DNE");
		else {
			long mx = 0;
			for(int i=2, up=(int)Math.sqrt(g); i<=up && g!=1; i++) {
				while(g % i == 0) { g/=i; mx = i; }
			}
			if(g != 1) mx = Math.max(mx, g);
			System.out.println(mx);
		}
	}
	static long gcd(long x, long y) {
		if(y==0) return x;
		return gcd(y, x%y);
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