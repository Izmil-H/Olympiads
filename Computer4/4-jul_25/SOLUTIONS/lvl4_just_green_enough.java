import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), a[][] = new int[n+1][n+1];
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				a[i][j] = readInt();
		System.out.println( cntGrids(n, a, 100) - cntGrids(n, a, 101) );
	}
	static long cntGrids(int n, int a[][], int min) {
		int h[] = new int[n+1]; long ans = 0;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(a[i][j] >= min) h[j]++;
				else h[j] = 0;
			}
			for(int j=1; j<=n; j++) {
				int cur = h[j]; long cnt = h[j];
				for(int k=j-1; k>=1; k--) {
					cur = Math.min(cur, h[k]);
					cnt += cur;
				}
				ans += cnt;
			}
		}
		return ans;
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