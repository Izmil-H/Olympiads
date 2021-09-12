import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		int n = readInt(); List<pt> p = new ArrayList();
		for(int i=0; i<n; i++) p.add(new pt(readInt(), readInt()));
		Collections.sort(p);
		int st[] = new int[n+1], tp = -1;
		st[++tp] = Integer.MIN_VALUE;
		for(int i=n-1; i>=0; i--) {
			pt t = p.get(i);
			if(t.y > st[tp]) { st[++tp] = t.y; }
			else {
				int tmp = st[tp--];
				while(t.y <= st[tp]) tp--;
				st[++tp] = tmp;
			}
		}
		System.out.println(tp);
	}
	static class pt implements Comparable<pt> {
		int x, y;
		pt(int x0, int y0) { x = x0; y = y0;}
		public int compareTo(pt a) { 
			if(x != a.x) return Integer.compare(x, a.x);
			return Integer.compare(y, a.y);
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