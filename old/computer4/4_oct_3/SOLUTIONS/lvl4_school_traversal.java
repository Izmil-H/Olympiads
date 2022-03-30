import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static int N, Q, LOG, dep[], anc[][]; static long dis[]; static List<edge> adj[];
	public static void main(String[] args) throws IOException{
		N = readInt(); dep = new int[N+1]; dis = new long[N+1]; adj = new ArrayList[N+1];
		LOG = 31 - Integer.numberOfLeadingZeros(N);  anc = new int[LOG+1][N+1];
		for(int i=1; i<=N; i++) adj[i] = new ArrayList();
		for(int i=1; i<N; i++) {
			int u = readInt() + 1, v = readInt() + 1, w = readInt();
			adj[u].add(new edge(v, w)); adj[v].add(new edge(u, w));
		}
		dfs(1, 0);  Q = readInt();
		for(int i=1; i<=Q; i++) {
			int u = readInt() + 1, v = readInt() + 1 ;
			System.out.println(dis[u] + dis[v] - 2*dis[LCA(u, v)]);
		}
	}
	static void dfs(int u, int pa) {
		dep[u] = dep[pa]+1; anc[0][u] = pa;
		for(int i=1; i<=LOG; i++) anc[i][u] = anc[i-1][anc[i-1][u]];
		for(edge e: adj[u]) {
			int v = e.v, w = e.w;
			if(v == pa) continue;
			dis[v] = dis[u] + w;  dfs(v, u);
		}
	}
	static int LCA(int u, int v) {
		if(dep[u] < dep[v]) { int tmp = u; u = v; v = tmp; }
		for(int k=LOG; k>=0; k--)
			if(dep[anc[k][u]] >= dep[v]) u = anc[k][u];
		if(u == v) return u;
		for(int k=LOG; k>=0; k--)
			if(anc[k][u] != anc[k][v]) { u = anc[k][u]; v = anc[k][v]; }
		return anc[0][u];
	}
	static class edge {
		int v, w;
		edge(int v0, int w0) { v = v0; w = w0; }
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