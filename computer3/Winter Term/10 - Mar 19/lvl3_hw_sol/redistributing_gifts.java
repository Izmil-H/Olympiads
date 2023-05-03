import java.util.*;
import java.io.*;
import java.time.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		int n = readInt(), a[][] = new int[n+1][n+1]; 
		boolean adj[][] = new boolean [n+1][n+1];
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++)
				a[i][j] = readInt();
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				adj[i][a[i][j]] = true;
				if(a[i][j] == i) break;
			}
		}
		for(int k=1; k<=n; k++) {
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=n; j++) {
					if(adj[i][k] && adj[k][j]) adj[i][j] = true;
				}
			}
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(adj[i][a[i][j]] && adj[a[i][j]][i]) {
					System.out.println(a[i][j]); break;
				}
			}
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