import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		String a = readLine().toLowerCase(), b = readLine().toLowerCase();
		int va = 0, vb = 0;
		for(int i=0; i<a.length(); i++) {
			va += pow(a.charAt(i)-'a'+1, i+1, 10);
		}
		for(int i=0; i<b.length(); i++) {
			vb += pow(b.charAt(i)-'a'+1, i+1, 10);
		}
		va %= 10;  vb %= 10;
		if(va == 0) va = 10;
		if(vb == 0) vb = 10;
		System.out.println(va + vb);
	}
	static int pow(int base, int exp, int mod) {
		if(exp == 0) return 1;
		int t = pow(base, exp/2, mod);
		t = t*t % mod;
		if(exp % 2 == 0) return t;
		return t*base % mod;
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