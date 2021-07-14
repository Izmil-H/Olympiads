import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), m = readInt(), k = readInt(), dif[][] = new int[n+2][m+2];
		long psa[][] = new long[n+2][m+2];
		for(int i=1; i<=k; i++) {
			int r1 = readInt(), c1 = readInt(), r2 = readInt()+1, c2 = readInt()+1;
			dif[r1][c1]++; dif[r1][c2]--; dif[r2][c1]--; dif[r2][c2]++;
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				dif[i][j] += dif[i-1][j] + dif[i][j-1] - dif[i-1][j-1];
				psa[i][j] = psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1] + dif[i][j];
			}
		}
		for(int q = readInt(); q > 0 ; q--) {
			int r1 = readInt() - 1, c1 = readInt()-1, r2 = readInt(), c2 = readInt();
			System.out.println(psa[r2][c2] - psa[r1][c2] - psa[r2][c1] + psa[r1][c1]);
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