import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static boolean adj[][]; static int pre[], idx=0;
	public static void main(String[] args) throws IOException{	
		int n = readInt(), m = readInt(); List<String> city = new ArrayList<>();
		Map<String, Integer> map = new HashMap<>();
		adj = new boolean[26][26];
		for(int i=1; i<=n; i++) {
			String u = next(), v = next();
			if(!map.containsKey(u)) { city.add(u); map.put(u, idx++); }
			if(!map.containsKey(v)) { city.add(v); map.put(v, idx++); }
			int uidx = map.get(u), vidx = map.get(v);
			adj[uidx][vidx] = adj[vidx][uidx] = true;
		}
		pre = new int[idx];
		for(int i=1; i<=m; i++) {
			String st = next(), ed = next(), ans = "";
			bfs(map.get(st), map.get(ed));
			for(int u=map.get(ed); u!=-1; u=pre[u]) {
				ans += city.get(u).charAt(0);
			}
			System.out.println(new StringBuffer(ans).reverse());
		}
	}
	static void bfs(int st, int ed) {
		Queue<Integer> q = new LinkedList<>(); 
		boolean vis[] = new boolean[idx];
		Arrays.fill(pre, -1);
		q.add(st); vis[st]=true; 
		while(!q.isEmpty()) {
			int cur = q.poll();
			for(int nxt=0; nxt<idx; nxt++) {
				if(adj[cur][nxt] && !vis[nxt]) {
					q.add(nxt); vis[nxt]=true;  pre[nxt]=cur;
				}
			}
			if(vis[ed]) return;
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