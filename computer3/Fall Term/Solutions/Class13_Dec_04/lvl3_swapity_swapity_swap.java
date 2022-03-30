import java.util.*;

import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), m = readInt(), k = readInt(), a[] = new int[n+1], nxt[] = new int[n+1];
		for(int i=1; i<=n; i++) a[i] = i;
		for(int i=1; i<=m; i++) {
			int x = readInt(), y = readInt();
			for(int l=x, r=y; l<r; l++, r--) {
				int tmp = a[l]; a[l]=a[r]; a[r]=tmp;
			}
		}
		for(int i=1; i<=n; i++) nxt[a[i]] = i;
		boolean vis[] = new boolean[n+1];
		int ans[] = new int[n+1];
		for(int i=1; i<=n; i++) {
			if(vis[i]) continue;
			List<Integer> cycle = new ArrayList();
			cycle.add(i); vis[i] = true;
			for(int u=nxt[i]; u!=i; u=nxt[u]) {
				cycle.add(u); vis[u] = true;
			}
			int rem = k % cycle.size();
			for(int j=0; j<cycle.size(); j++) {
				int pos = (j + rem)%cycle.size();
				ans[cycle.get(pos)] = cycle.get(j);
			}
		}
		for(int i=1; i<=n; i++) System.out.println(ans[i]);
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