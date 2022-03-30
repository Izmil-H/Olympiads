import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static int N, M, Q; static List<edge> adj[];
	public static void main(String[] args) throws IOException {
		N=readInt(); M = readInt(); adj = new ArrayList[N+1];
		for(int i=1; i<=N; i++) adj[i] = new ArrayList<>();
		Map<String, Integer> map = new HashMap<>();
		int cnt = 0;
		for(int i=1; i<=M; i++) {
			String a = next(), b =next(); int t = readInt();
			if(!map.containsKey(a)) map.put(a, ++cnt);
			if(!map.containsKey(b)) map.put(b, ++cnt);
			adj[map.get(a)].add(new edge(map.get(b), (long)t));
		}
		for(Q = readInt(); Q>0; Q--) {
			String a = next(), b = next();
			long dis = dijkstra(map.get(a), map.get(b));
			System.out.println(dis>=1e15? "Roger" : dis);
		}
	}
	static long dijkstra(int st, int ed) {
		long dis[] = new long[N+1]; boolean vis[] = new boolean[N+1];
		PriorityQueue<edge> q = new PriorityQueue<>();
		Arrays.fill(dis, (long)1e15); dis[st] = 0; q.add(new edge(st, 0));
		while(!q.isEmpty()) {
			int u = q.poll().v;
			if(vis[u]) continue;
			vis[u] = true;
			for(edge e: adj[u]) {
				int v = e.v; long w = e.w;
				if(dis[v] > dis[u] + w) {
					dis[v] = dis[u]  + w; q.add(new edge(v, dis[v]));
				}
			}
		}
		return dis[ed];
	}
	static class edge implements Comparable<edge>{
		int v; long w;
		edge(int v0, long w0){ v = v0; w = w0; }
		public int compareTo(edge x) { return Long.compare(w, x.w); }
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
