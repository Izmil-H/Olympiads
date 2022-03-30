import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{	
		int n = readInt(), m = readInt(), dif[][] = new int[17][n+2], st[][] = new int[18][n+1];
		int [] x = new int[m+1], y = new int[m+1], z = new int[m+1];
		for(int i=1; i<=m; i++) {
			x[i] = readInt(); y[i] = readInt(); z[i] = readInt();
			dif[z[i]][x[i]]++; dif[z[i]][y[i]+1]--;
		}
		for(int i=1; i<=n; i++) {
			st[0][i] = 1;
			for(int j=1; j<=16; j++) {
				dif[j][i] += dif[j][i-1];
				if(dif[j][i] > 0) st[0][i] = st[0][i] * j / gcd(st[0][i], j);
			}
		}
		for(int k=1; k<st.length; k++)
			for(int i=1; i+(1<<k)-1 <= n; i++)
				st[k][i] = gcd(st[k-1][i], st[k-1][i+(1<<k-1)]);
		for(int i=1; i<=m; i++) {
			int g = query(x[i], y[i], st);
			if(g != z[i]) { System.out.println("Impossible"); return; }
		}
		for(int i=1; i<=n; i++) System.out.print(st[0][i] + " ");
	}
	static int gcd(int x, int y) {
		return y==0? x : gcd(y, x%y);
	}
	static int query(int x, int y, int [][]st) {
		int k = 31 - Integer.numberOfLeadingZeros(y-x+1);
		return gcd(st[k][x], st[k][y-(1<<k)+1]);
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