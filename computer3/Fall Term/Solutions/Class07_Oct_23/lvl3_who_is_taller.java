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
		for(int i=1; i<=m; i++) {
			int x = readInt(), y = readInt();
			adj[x].add(y);
		}
		int p = readInt(), q = readInt();
		if(bfs(p, q)) System.out.println("yes");
		else if(bfs(q, p)) System.out.println("no");
		else System.out.println("unknown");
	}
	static boolean bfs(int st, int ed) {
		Queue<Integer> q = new LinkedList();
		boolean vis[] = new boolean[n+1];
		q.add(st); vis[st]=true;
		while(!q.isEmpty()) {
			int cur = q.poll();
			for(int nxt : adj[cur]) {
				if(!vis[nxt]) {
					q.add(nxt); vis[nxt]=true;
				}
			}
			if(vis[ed]) return true;
		}
		return false;
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