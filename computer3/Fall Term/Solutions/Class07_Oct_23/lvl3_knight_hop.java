import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int sx = readInt(), sy = readInt(), tx = readInt(), ty = readInt();
		Queue<pair> q = new LinkedList<>();
		boolean vis[][] = new boolean[9][9]; int dis[][] = new int[9][9];
		int d[][] = {{2, 1}, {2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
		q.add(new pair(sx, sy)); vis[sx][sy]=true; dis[sx][sy]=0;
		while(!q.isEmpty()) {
			int x = q.peek().x, y = q.peek().y; q.poll();
			for(int k=0; k<8; k++) {
				int nx = x + d[k][0], ny = y + d[k][1];
				if(nx < 1 || nx > 8 || ny < 1 || ny > 8 || vis[nx][ny]) continue;
				q.add(new pair(nx, ny)); vis[nx][ny]=true;
				dis[nx][ny] = dis[x][y] + 1;
			}
		}
		System.out.println(dis[tx][ty]);
	}
	static class pair {
		int x, y;
		pair(int x0, int y0) { x = x0; y = y0; }
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