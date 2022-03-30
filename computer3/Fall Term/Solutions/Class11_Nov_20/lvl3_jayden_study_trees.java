import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static int n, len, far; static List<Integer> adj[];
	public static void main(String[] args) throws IOException{	
		n = readInt(); adj = new ArrayList[n+1];
		for(int i=1; i<=n; i++) adj[i] = new ArrayList<>();
		for(int i=1; i<n; i++) {
			int u = readInt(), v = readInt();
			adj[u].add(v); adj[v].add(u);
		}
		dfs(1, -1, 0);  len=0; dfs(far, -1, 0);
		System.out.println(len);
	}
	static void dfs(int cur, int pre, int dis) {
		if(dis > len) { far = cur; len = dis; }
		for(int nxt : adj[cur]){
			if(nxt != pre) dfs(nxt, cur, dis+1);
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