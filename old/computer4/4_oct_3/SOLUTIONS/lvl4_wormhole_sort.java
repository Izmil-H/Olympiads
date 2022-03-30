import java.util.*;

import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int n, m, p[], a[]; 
	public static void main(String[] args) throws IOException{
		n = readInt(); m = readInt(); p = new int[n+1]; a = new int[n+1];
		List<edge> e = new ArrayList();
		for(int i=1; i<=n; i++) {
			p[i] = i; a[i] = readInt();
		}
		for(int i=1; i<=m; i++) {
			e.add(new edge(readInt(), readInt(), readInt()));
		}
		Collections.sort(e);
		int ans = -1;
		for(int i=1, j=0; i<=n; i++) {
			for(; find(a[i]) != find(i); j++) {
				int u = e.get(j).u, v = e.get(j).v, w = e.get(j).w; 
				int fu = find(u), fv = find(v); 
				if(fu != fv) { p[fu] = fv; ans = w; }
			}
		}
		System.out.println(ans);
	}
	static int find(int d) {
		if(d != p[d]) p[d] = find(p[d]);
		return p[d];
	}
	static class edge implements Comparable<edge>{
		int u, v, w;
		edge(int u0, int v0, int w0) { u = u0; v = v0; w = w0; }
		public int compareTo(edge x) { return -Integer.compare(w, x.w); }
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