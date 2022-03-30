import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), m = readInt(); List<Edge> adj[] = new ArrayList[n+1];
		for(int i=0; i<=n; i++) adj[i] = new ArrayList();
		for(int i=1; i<=m; i++) {
			int u = readInt(), v = readInt(), w = readInt();
			adj[u].add(new Edge(v, w)); 
		}
		int dis1[] = new int[n+1], dis2[] = new int[n+1];
		boolean inq[] = new boolean[n+1]; Queue<Integer> q = new LinkedList();
		Arrays.fill(dis1, Integer.MAX_VALUE/2); Arrays.fill(dis2, Integer.MAX_VALUE/2);
		dis1[1] = 0; inq[1] = true; q.add(1);
		while(!q.isEmpty()) {
			int u = q.poll(); inq[u]=false;
			for(Edge e: adj[u]) {
				int v = e.v, w = e.w;
				if(dis1[v] > dis1[u] + w) {
					dis2[v] = dis1[v]; dis1[v] = dis1[u] + w;
					if(!inq[v]) { q.add(v); inq[v]=true;}
				}else if(dis1[v] != dis1[u] + w && dis2[v] > dis1[u] + w) {
					dis2[v] = dis1[u] + w;
					if(!inq[v]) { q.add(v); inq[v]=true;}
				}
				if(dis1[v] != dis2[u] + w && dis2[v] > dis2[u] + w) {
					dis2[v] = dis2[u] + w;
					if(!inq[v]) { q.add(v); inq[v]=true;}
				}
			}
		}
		System.out.println(dis2[n]==Integer.MAX_VALUE/2? -1:dis2[n]);
	}
	static class Edge {
		int v, w;
		Edge(int v0, int w0) { v = v0; w = w0; }
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