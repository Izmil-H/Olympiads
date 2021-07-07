import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), m = readInt(), start = readInt(), end = readInt();
		List<Integer> adj[] = new ArrayList[n+1];
		for(int i=0; i<=n; i++) adj[i] = new ArrayList();
		for(int i=1; i<=m; i++) {
			int u = readInt(), v = readInt();
			adj[u].add(v); adj[v].add(u);
		}
		Queue<Integer> q = new LinkedList();
		int dis[] = new int[n+1], pre[] = new int[n+1]; boolean vis[] = new boolean[n+1];
		q.add(start); dis[start] = 0; vis[start]=true;  pre[start]=-1;
		while(!q.isEmpty()) {
			int cur = q.poll();
			for(int nxt: adj[cur]) {
				if(!vis[nxt]) {
					q.add(nxt); vis[nxt]=true; pre[nxt]=cur;
					dis[nxt] = dis[cur] + 1;
				}
			}
		}
		if(vis[end]) {
			System.out.println("GO SHAHIR!");
//			System.out.println("shortest dist: " + dis[end]);
//			for(int u=end; u!=-1; u=pre[u]) {
//				System.out.print(u + "<--");
//			}
		}else System.out.println("NO SHAHIR!");
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