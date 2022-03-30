import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static int n, m, t, dis[][]; static List<Integer> adj[];
	public static void main(String[] args) throws IOException{	
		n = readInt(); m = readInt(); t = readInt(); adj = new ArrayList[n+1];
		dis = new int[n+1][n+1];
		for(int i=1; i<=n; i++) {
			adj[i] = new ArrayList<>(); 
			Arrays.fill(dis[i], -1);
		}
		for(int i=1; i<=m; i++) {
			int u = readInt(), v = readInt(); adj[u].add(v);
		}
		for(int i=1; i<=n; i++) bfs(i, dis[i]);
		for(int q=readInt(); q > 0; q--) {
			int u = readInt(), v = readInt();
			if(dis[u][v] != -1) System.out.println(dis[u][v] * t);
			else System.out.println("Not enough hallways!");
		}
	}
	static void bfs(int s, int dis[]) {
		Queue<Integer> q = new LinkedList<>();
		q.add(s); dis[s] = 0;
		while(!q.isEmpty()) {
			int u = q.poll();
			for(int v : adj[u]) {
				if(dis[v]==-1) { q.add(v); dis[v] = dis[u] + 1; }
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