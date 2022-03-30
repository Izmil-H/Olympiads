import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static boolean [][] adj;  static int n, vis[], dis[], cycle;
	public static void main(String[] args) throws IOException{
		for(int t=1; t<=5; t++) {
			n = readInt(); vis = new int[101]; dis = new int[101];
			adj = new boolean[101][101];
			for(int i=1; i<=n; i++) {
				int x = readInt(), y = readInt();
				adj[x][y] = true;
			}
			cycle = 0; dfs(1);
			System.out.println(cycle);
		}
	}
	static void dfs(int u) {
		if(cycle > 0) return;
		vis[u] = 1;
		for(int v=1; v<=100; v++) {
			if(adj[u][v]) {
				if(vis[v] == 1) {
					cycle = dis[u] - dis[v] + 1; return;
				}else if(vis[v] == 0) {
					dis[v] = dis[u]+1; dfs(v);
				}
			}
		}
		vis[u] = 2;
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