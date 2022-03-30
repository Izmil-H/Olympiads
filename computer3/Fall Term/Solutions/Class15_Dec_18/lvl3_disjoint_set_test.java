import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), m = readInt(), p[] = new int[n+1];
		List<Integer> ans = new ArrayList();
		for(int i=1; i<=n; i++) p[i] = i; //create set
		for(int i=1; i<=m; i++) {
			int x = readInt(), y = readInt();
			int fx = find(x, p), fy = find(y, p);
			if(fx != fy) { p[fx] = fy; ans.add(i); }
		}
		if(ans.size() != n-1) System.out.println("Disconnected Graph");
		else for(int x: ans) System.out.println(x);
	}
	static int find(int d, int p[]) {
		if(d != p[d]) p[d] = find(p[d], p);
		return p[d];
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