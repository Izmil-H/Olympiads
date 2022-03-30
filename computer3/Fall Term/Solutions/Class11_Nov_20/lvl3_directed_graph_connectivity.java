import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static int n, m; static boolean adj[][];
	public static void main(String[] args) throws IOException{	
		n = readInt(); m = readInt(); int u[] = new int[m], v[] = new int[m];
		adj = new boolean[n+1][n+1];
		for(int i=0; i<m; i++) {
			u[i] = readInt(); v[i] = readInt();
			adj[u[i]][v[i]] = true;
		}
		for(int i=0; i<m; i++) {
			adj[u[i]][v[i]] = false;
			if(bfs(1, n)) System.out.println("YES");
			else System.out.println("NO");
			adj[u[i]][v[i]] = true;
		}
	}
	static boolean bfs(int st, int ed) {
		Queue<Integer> q = new LinkedList<>(); 
		boolean vis[] = new boolean[n+1];
		q.add(st); vis[st]=true;
		while(!q.isEmpty()) {
			int u = q.poll();
			for(int v = 1; v <= n; v++) {
				if(adj[u][v] && !vis[v]) { q.add(v); vis[v]=true; }
			}
		}
		return vis[ed];
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