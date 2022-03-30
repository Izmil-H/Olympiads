import java.io.*;
import java.util.*;

public class P2 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static PrintWriter pr = new PrintWriter(System.out);
	static String readLine() throws IOException {
		return br.readLine();
	}
	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(readLine());
		return st.nextToken();
	}
	static int readInt() throws IOException {
		return Integer.parseInt(next());
	}
	static long readLong() throws IOException {
		return Long.parseLong(next());
	}
	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}
	static char readChar() throws IOException {
		return next().charAt(0);
	}
	static class Pair implements Comparable<Pair> {
		int f, s;
		Pair(int f, int s) {
			this.f = f; this.s = s;
		}
		public int compareTo(Pair other) {
			if (this.f != other.f) return this.f - other.f;
			return this.s - other.s;
		}
	}
	final static int inf = (int)1e9;
	static boolean walk(int dr, int dc) {
		return Math.abs(dr) + Math.abs(dc) == 1;
	}
	static boolean jump(int dr, int dc) {
		return Math.abs(dr) + Math.abs(dc) == 3 && dr != 0 && dc != 0;
	}
	static void solve() throws IOException {
		int H = readInt(), W = readInt(), sr = readInt(), sc = readInt(), er = readInt(), ec = readInt();
		char g[][] = new char[H + 1][W + 1];
		for (int i = 1; i <= H; ++i) {
			String s = readLine();
			for (int j = 1; j <= W; ++j)
				g[i][j] = s.charAt(j - 1);
		}
		int dis[][] = new int[H + 1][W + 1];
		for (int i = 1; i <= H; ++i)
			for (int j = 1; j <= W; ++j)
				dis[i][j] = inf;
		Queue<Pair> q = new ArrayDeque();
		dis[sr][sc] = 0;
		q.add(new Pair(sr, sc));
		while (!q.isEmpty()) {
			Pair p = q.poll();
			int r = p.f, c = p.s;
			for (int dr = -2; dr <= 2; ++dr) {
				for (int dc = -2; dc <= 2; ++dc) {
					if (walk(dr, dc) || jump(dr, dc)) {
						int rr = r + dr, cc = c + dc;
						if (1 <= rr && rr <= H && 1 <= cc && cc <= W && g[rr][cc] != '#' && dis[rr][cc] == inf) {
							dis[rr][cc] = dis[r][c] + 1;
							q.add(new Pair(rr, cc));
						}
					}
				}
			}
		}
		if (dis[er][ec] == inf) pr.println(-1);
		else pr.println(dis[er][ec]);
	}
	public static void main(String[] args) throws IOException {
		solve();
		//for (int t = readInt(); t > 0; --t) solve();
		pr.close();
	}
}