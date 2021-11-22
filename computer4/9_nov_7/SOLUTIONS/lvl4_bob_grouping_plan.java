import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), m = 1;
		while(m*(m-1)<2*n) m++;
		if(m * (m-1) == 2*n) {
			System.out.println("Yes\n" + m);
			List<Integer> adj[] = new ArrayList[m+1];
			for(int i=1; i<=m; i++) adj[i] = new ArrayList<>();
			int edge = 0;
			for(int u=1; u<=m; u++) {
				for(int v=u+1; v<=m; v++) {
					edge++; adj[u].add(edge); adj[v].add(edge);
				}
			}
			for(int u=1; u<=m; u++) {
				System.out.print(m-1 + " ");
				for(int x : adj[u]) System.out.print(x + " ");
				System.out.println();
			}
		}else {
			System.out.println("No");
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