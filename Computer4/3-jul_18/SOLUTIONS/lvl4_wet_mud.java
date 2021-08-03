import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		int n = readInt(), m = readInt(), jump = readInt();
		if(jump > n) { System.out.println(0); return; }
		int t[] = new int[n+1];  Arrays.fill(t, Integer.MAX_VALUE);
		for(int i=0; i<m; i++) t[readInt()] = readInt();
		int l = 0, r = 0, q[] = new int[n+1], ans[] = new int[n+1], sol = Integer.MAX_VALUE;
		for(int i=1; i<=n; i++) { // [i-jump, i]
			while(l <= r && i - q[l] > jump) l++;
			ans[i] = Math.max(ans[q[l]], t[i]);
			while(l <= r && ans[q[r]] >= ans[i]) r--;
			q[++r] = i;
			if(i + jump > n) sol = Math.min(sol, ans[i]);
		}
		System.out.println(sol==Integer.MAX_VALUE? -1: sol);
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