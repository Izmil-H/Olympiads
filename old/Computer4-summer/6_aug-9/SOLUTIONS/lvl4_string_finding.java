import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static long [] hsh, pw; static long mod = (long)1e9+7;
	public static void main(String[] args) throws IOException{
		String s = readLine(), t = readLine();
		hsh = new long[s.length()+1]; pw = new long[s.length()+1];
		long hshT = 0, base = 131;
		hsh[0] = 0; pw[0] = 1;
		for(int i=1; i<=s.length(); i++) {
			hsh[i] = (hsh[i-1]*base + s.charAt(i-1))%mod;
			pw[i] = pw[i-1]*base%mod;
		}
		for(int i=0; i<t.length(); i++) {
			hshT = (hshT * base + t.charAt(i))%mod;
		}
		for(int i=0; i+t.length()<=s.length(); i++) {
			if(getSubStringHash(i+1, i+t.length()) == hshT) {
				System.out.println(i); return;
			}
		}
		System.out.println(-1);
	}
	static long getSubStringHash(int L, int R) { return (hsh[R] - hsh[L-1]*pw[R-L+1]%mod + mod)%mod; }
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