import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		int n = readInt(), m = readInt(); List<pair> adj[]=new ArrayList[n+1];
		for(int i=1; i<=n; i++) adj[i] = new ArrayList<>();
		for(int i=1; i<=m; i++) {
			int u = readInt(), v = readInt(), w = readInt();
			adj[u].add(new pair(v, w)); adj[v].add(new pair(u, w));
		}
		pair dis[] = new pair[n+1]; boolean vis[] = new boolean[n+1];
		for(int i=1; i<=n; i++) dis[i] = new pair(m+1, m+1);
		dis[1] = new pair(0, 0);
		PriorityQueue<edge> q = new PriorityQueue<>(); q.add(new edge(dis[1], 1));
		while(!q.isEmpty()) {
			edge cur = q.poll();
			if(vis[cur.u]) continue;
			vis[cur.u] = true; int dan = cur.road.dan, cnt= cur.road.cnt;
			for(pair e : adj[cur.u]) {
				int v = e.dan, w = e.cnt;   pair tmp = new pair(dan+w, cnt+1);
				if(dis[v].compareTo(tmp) > 0) {
					dis[v] = tmp; q.add(new edge(dis[v], v));
				}
			}
		}
		if(!vis[n]) System.out.println(-1);
		else System.out.println(dis[n].dan + " " + dis[n].cnt);
	}
	static class pair implements Comparable<pair>{
		int dan, cnt;
		pair(int d, int c){dan = d; cnt = c;}
		public int compareTo(pair x) { 
			if(dan != x.dan) return Integer.compare(dan, x.dan);
			return Integer.compare(cnt, x.cnt);
		}
	}
	static class edge implements Comparable<edge>{
		pair road; int u;
		edge(pair x, int y){ road = x; u = y; }
		public int compareTo(edge x) { return road.compareTo(x.road);}
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