import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		int n = readInt(), base=131, ans=0; Map<Long, Integer> map = new HashMap();
		for(int i=1; i<=n; i++) {
			String s = readLine(); long pre = 0, suf = 0, pw = 1; int best = 0;
			for(int j=0; j<s.length(); j++) {
				int m = s.length();
				pre = pre*base + s.charAt(j);
				suf = s.charAt(m - j - 1)*pw + suf;  pw *= base;
				if(pre == suf) {
					best = Math.max(best, map.getOrDefault(pre, 0));
				}
			}
			ans = Math.max(ans, best+1); map.put(pre, best+1);
		}
		System.out.println(ans);
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