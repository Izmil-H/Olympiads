import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		int n = readInt(), m = readInt(), d = readInt(); // n: num of vertices, m: num of edges
		List<Edge> adj[] = new ArrayList[n+1];
		for(int i=1; i<=n; i++) adj[i] = new ArrayList();
		for(int i=1; i<=m; i++) { // edge input: u v w  an bidirectional edge from u to v with cost w
			int u = readInt(), v = readInt(), w = readInt();
			adj[u].add(new Edge(v, w)); adj[v].add(new Edge(u, w));
		}
		boolean des[] = new boolean[n+1];
		for(int i=1; i<=d; i++) des[readInt()] = true;
		int dis[] = new int[n+1];  PriorityQueue<Edge> q = new PriorityQueue(); 
		dis[1] = (int)1e9; q.add(new Edge(1, dis[1]));
		while(!q.isEmpty()) {
			Edge cur = q.poll();
			if(cur.w < dis[cur.v]) continue;
			for(Edge e: adj[cur.v]) {
				int v = e.v, w = e.w;
				if(dis[v] < w) { dis[v] = w; q.add(new Edge(v, dis[v])); }
			}
		}
		int ans = Integer.MAX_VALUE;
		for(int i=1; i<=n; i++)
			if(des[i]) ans = Math.min(ans, dis[i]);
		System.out.println(ans);
	}
	static class Edge implements Comparable<Edge>{
		int v, w;
		Edge(int v0, int w0){ v = v0; w = w0; }
		public int compareTo(Edge x) { return -Integer.compare(w, x.w); }
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
	static char readCharacter() throws IOException {
		return next().charAt(0);
	}
	static String readLine() throws IOException {
		return br.readLine().trim();
	}
}