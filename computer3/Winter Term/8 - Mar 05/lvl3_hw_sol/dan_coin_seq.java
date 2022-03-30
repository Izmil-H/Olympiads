import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		for(int T=readInt(); T>0; T--) {
			int n = readInt(), a[] = new int[n], ans = 0, max = 0;
			for(int i=0; i<n; i++) {
				a[i] = readInt(); max = Math.max(a[i], max);
			}
			Arrays.sort(a);
			boolean dp[] = new boolean[max+1]; dp[0] = true;
			for(int i=0; i<n; i++) {
				if(!dp[a[i]]) {
					ans++;  int val = a[i];
					for(int j=val; j<=max; j++)
						if(dp[j-val]) dp[j] = true;
				}
			}
			System.out.println(ans);
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