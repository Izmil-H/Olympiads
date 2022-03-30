import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{	
		int n = readInt(); char[] dir = new char[n+1]; int [] x = new int[n+1], y = new int[n+1];
		for(int i=1; i<=n; i++) {
			dir[i] = readCharacter(); x[i] = readInt(); y[i] = readInt();
		}
		List<inter> lst = new ArrayList();
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				if(dir[i] == dir[j]) continue;
				int ex = x[i], ey = y[i], nx = x[i], ny = y[i];
				if(dir[i] == 'E') { nx = x[j]; ny = y[j]; }
				else { ex = x[j]; ey = y[j]; }
				if(ex < nx && ny < ey) lst.add(new inter(nx, ey, i, j));
			}
		}
		Collections.sort(lst);
		boolean [] stop = new boolean[n+1]; int [] ans = new int[n+1];
		for(inter e : lst) {
			if(stop[e.a] || stop[e.b]) continue;
			int ta = e.x - x[e.a] + e.y - y[e.a], tb = e.x - x[e.b] + e.y - y[e.b];
			if(ta < tb) { stop[e.b] = true; ans[e.b] = tb; }
			else if(ta > tb) { stop[e.a] = true; ans[e.a] = ta; }
		}
		for(int i=1; i<=n; i++)
			System.out.println(stop[i]? ans[i] : "Infinity");
	}
	static class inter implements Comparable<inter> {
		int x, y, a, b;
		inter(int x0, int y0, int a0, int b0) { x = x0; y = y0; a = a0; b = b0; }
		public int compareTo(inter p) {
			if(x != p.x) return Integer.compare(x,  p.x);
			return Integer.compare(y, p.y);
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