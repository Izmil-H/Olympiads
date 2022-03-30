import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), m = readInt(); List<Integer> adj[] = new ArrayList[n+1];
		for(int i=1; i<=n; i++) adj[i] = new ArrayList<>();
		for(int i=1; i<=m; i++) {
			int u = readInt(), v = readInt();
			adj[u].add(v); adj[v].add(u);
		}
		int w = readInt(), dis[] = new int[n+1]; //run Ants BFS
		Queue<Integer> q = new LinkedList<>();  boolean vis[] = new boolean[n+1];
		for(int i=1; i<=w; i++) {
			int x = readInt(); q.add(x); vis[x]=true; 
		}
		while(!q.isEmpty()) {
			int cur = q.poll();
			for(int nxt : adj[cur]) {
				if(!vis[nxt]) { q.add(nxt); vis[nxt]=true; dis[nxt] = dis[cur] + 4; }
			}
		}
		Arrays.fill(vis, false);
		int human[] = new int[n+1];
		q.add(1); vis[1] = true;  
		while(!q.isEmpty()) {
			int cur = q.poll();
			for(int nxt : adj[cur]) {
				if(!vis[nxt] && human[cur] + 1 < dis[nxt]) {
					q.add(nxt); vis[nxt]=true; human[nxt]=human[cur] + 1;
				}
			}
		}
		if(vis[n]) System.out.println(human[n]);
		else System.out.println("sacrifice bobhob314");
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