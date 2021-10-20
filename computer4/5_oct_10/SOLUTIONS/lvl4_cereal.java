import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static int n, m, f[], s[], cereal[], ans[], cnt = 0;
	public static void main(String[] args) throws IOException {
		n = readInt(); m = readInt();
		f = new int[n+1]; s = new int[n+1]; cereal = new int[m+1]; ans = new int[n+1];
		for(int i=1; i<=n; i++) {
			f[i] = readInt(); s[i] = readInt();
		}
		for(int i=n; i>=1; i--) {
			fun(i, f[i]);  ans[i] = cnt;
		}
		for(int i=1; i<=n; i++) System.out.println(ans[i]);
	}
	static void fun(int cow, int flavor) {
		if(cereal[flavor] == 0) {
			cnt ++; cereal[flavor] = cow;
		}else if(cereal[flavor] > cow) {
			int tmp = cereal[flavor]; cereal[flavor] = cow;
			if(flavor != s[tmp]) fun(tmp, s[tmp]);
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