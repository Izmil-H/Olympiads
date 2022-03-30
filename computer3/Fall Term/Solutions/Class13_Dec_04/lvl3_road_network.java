import java.util.*;
import java.io.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		int n = readInt(), m = readInt();  List<edge> adj[] = new ArrayList[n+1];
		for(int i=1; i<=n; i++) adj[i] = new ArrayList<>();
		int x[] = new int[n+1], y[] = new int[n+1];
		for(int i=1; i<=n; i++) {
			x[i] = readInt(); y[i] = readInt();
			for(int j=1; j<i; j++) {
				double d = Math.sqrt((long)(x[i]-x[j])*(x[i]-x[j]) + (long)(y[i]-y[j])*(y[i]-y[j]));
				adj[i].add(new edge(j, d)); adj[j].add(new edge(i, d));
			}
		}
		for(int i=1; i<=m; i++) {
			int u = readInt(), v = readInt();
			adj[u].add(new edge(v, 0.0)); adj[v].add(new edge(u, 0.0));
		}
		double dis[] = new double[n+1]; boolean vis[] = new boolean[n+1];
		Arrays.fill(dis, 1e18);  
		PriorityQueue<edge> q = new PriorityQueue<>();
		dis[1] = 0; q.add(new edge(1, 0));
		while(!q.isEmpty()) {
			edge cur = q.poll(); int u = cur.v;
			if(vis[u]) continue;
			vis[u] = true;
			for(edge e : adj[u]) {
				int v = e.v; double w = e.w;
				if(!vis[v] && dis[v] > w) { dis[v] = w; q.add(new edge(v, w)); }
			}
		}
		double ans = 0;
		for(int i=1; i<=n; i++) ans += dis[i];
		System.out.printf("%.2f\n", ans);
	}
	static class edge implements Comparable<edge>{
		int v; double w;
		edge(int v0, double w0){ v = v0; w = w0; }
		public int compareTo(edge x) { return Double.compare(w, x.w); }
	}
	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong() throws IOException {
		return Long.parseLong(next());
	}
	static int readInt() throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}
	static char readCharacter () throws IOException {
		return next().charAt(0);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}