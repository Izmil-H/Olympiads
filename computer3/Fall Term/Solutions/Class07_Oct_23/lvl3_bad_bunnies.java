import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static int n, m; static List<Integer> adj[];
	public static void main(String[] args) throws IOException{
		n = readInt(); m = readInt(); adj = new ArrayList[n+1];
		for(int i=1; i<=n; i++) adj[i] = new ArrayList();
		for(int i=1; i<n; i++) {
			int u = readInt(), v = readInt();
			adj[u].add(v); adj[v].add(u);
		}
		int dis[] = new int[n+1]; boolean vis[] = new boolean[n+1];
		Queue<Integer> q = new LinkedList<>();
		for(int i=1; i<=m; i++) {
			int x = readInt(); q.add(x); vis[x]=true; dis[x] = 0;
		}
		while(!q.isEmpty()) {
			int cur = q.poll();
			for(int nxt : adj[cur]) {
				if(!vis[nxt]) { q.add(nxt); vis[nxt]=true; dis[nxt] = dis[cur]+1;}
			}
		}
		int x = readInt(), y = readInt(), prev[] = new int[n+1]; //carrot bfs
		Arrays.fill(vis, false);
		q.add(x); vis[x]=true; prev[x] = -1;
		while(!q.isEmpty()) {
			int cur= q.poll();
			for(int nxt : adj[cur]) {
				if(!vis[nxt]) { q.add(nxt); vis[nxt]=true; prev[nxt] = cur; }
			}
		}
		int ans = Integer.MAX_VALUE, cur = y;
		for ( ; cur!=-1; cur=prev[cur]) ans = Math.min(ans, dis[cur]);
		System.out.println(ans);
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