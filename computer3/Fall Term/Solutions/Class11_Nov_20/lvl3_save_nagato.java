import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int n, last; static List<Integer> adj[];
	public static void main(String[] args) throws IOException{
		n = readInt(); adj = new ArrayList[n+1];
		for(int i=1; i<=n; i++) adj[i] = new ArrayList();
		for(int i=1; i<n; i++) {
			int u = readInt(), v = readInt();
			adj[u].add(v); adj[v].add(u);
		}
		int dis1[] = new int[n+1], dis2[] = new int[n+1];
		bfs(1, dis1);  bfs(last, dis1);  bfs(last, dis2);
		for(int i=1; i<=n; i++) System.out.println(Math.max(dis1[i], dis2[i]));
	}
	static void bfs(int start, int dis[]) {
		int q[] = new int[n]; Arrays.fill(dis, -1);
		int f = 0, r = 0;
		q[r++]=start; dis[start] = 1;
		while(f < r) {
			int u = q[f++]; last = u;
			for(int v: adj[u]) {
				if(dis[v]==-1) { q[r++]=v; dis[v] = dis[u] + 1; }
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