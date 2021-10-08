import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static int n, a[], t[], ans=0; static List<Integer> adj[];
	public static void main(String[] args) throws IOException {
		n = readInt(); a = new int[n+1];  t = new int[n+1]; adj = new ArrayList[n+1];
		for(int i=1; i<=n; i++) {
			a[i] = readInt(); adj[i] = new ArrayList();
		}
		for(int i=1; i<n; i++) {
			int u = readInt(), v = readInt();
			adj[u].add(v); adj[v].add(u);
		}
		for(int i=1; i<=n; i++) {
			Arrays.fill(t, 0); dfs(i, 0);
			if(t[i]==0 || t[i] == 1) ans++;
		}
		System.out.println(ans);
	}
	static void dfs(int u, int pa) {
		t[u] = a[u];
		for(int v: adj[u]) {
			if(v == pa) continue;
			dfs(v, u);
			t[u] = (t[u] + 12 - t[v])%12;
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