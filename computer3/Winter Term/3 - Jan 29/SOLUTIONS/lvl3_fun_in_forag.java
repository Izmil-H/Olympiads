import java.util.*;
import java.io.*;
public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static int N, M, A, B; static long C; static List<edge> adj[];
	public static void main(String[] args) throws IOException {
		N = readInt(); M = readInt(); adj = new ArrayList[N+1];
		for(int i=1; i<=N; i++) adj[i] = new ArrayList();
		for(int i=1; i<=M; i++) {
			int u = readInt(), v = readInt(), w = readInt();
			adj[u].add(new edge(v, w, i)); adj[v].add(new edge(u, w, i));
		}
		A = readInt(); B = readInt(); C = readLong();
		int lo = 1, hi = M, ans = -1;
		while(lo <= hi) {
			int mid = (lo + hi)/2;
			if(check(mid)) { ans = mid; hi = mid - 1; }
			else lo = mid + 1;
		}
		System.out.println(ans);
	}
	static boolean check(int lvl) {
		long dis[] = new long[N+1]; boolean vis[] = new boolean[N+1];
		Arrays.fill(dis, Long.MAX_VALUE);
		Queue<Integer> q = new LinkedList();
		dis[A] = 0; vis[A] = true; q.add(A);
		while(!q.isEmpty()) {
			int cur = q.poll(); vis[cur] = false;
			for(edge e: adj[cur]) {
				if(e.id > lvl) continue;
				if(dis[e.v] > dis[cur] + e.w) {
					dis[e.v] = dis[cur] + e.w;
					if(!vis[e.v]) { q.add(e.v); vis[e.v] = true; } 
				}
			}
		}
		return dis[B] < C;
	}
	static class edge implements Comparable<edge>{
		int v, w, id;
		edge(int v0, int w0, int i0){ v=v0; w=w0; id=i0;}
		public int compareTo(edge x) { return w - x.w; }
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