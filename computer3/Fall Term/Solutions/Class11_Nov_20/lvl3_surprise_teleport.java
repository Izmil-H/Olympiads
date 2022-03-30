import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int R = readInt(), C = readInt(); char g[][] = new char [R][C];
		int sr = readInt(), sc = readInt(), tr = readInt(), tc = readInt();
		for(int i=0; i<R; i++) g[i] = readLine().toCharArray();
		Queue<E> q = new LinkedList(); 
		boolean [][] vis = new boolean[R][C];
		int dis[][] = new int [R][C], dir[][] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
		q.add(new E(sr, sc)); vis[sr][sc] = true; 
		while(!q.isEmpty()) {
			E e = q.poll();
			for(int k=0; k<4; k++) {
				int nr = e.r + dir[k][0], nc = e.c + dir[k][1];
				if(nr >= 0 && nr < R && nc >= 0 && nc < C && g[nr][nc] != 'X' && !vis[nr][nc]) {
					q.add(new E(nr, nc)); vis[nr][nc] = true; 
					dis[nr][nc] = dis[e.r][e.c]+ 1; 
				}
			}
		}
		int T = readInt(), min = dis[tr][tc];
		for(int i=0; i<T; i++) {
			int r = readInt(), c = readInt();
			if(vis[r][c]) min = Math.min(min, dis[r][c]);
		}
		System.out.println(dis[tr][tc] - min);
	}
	static class E {
		int r, c;
		E(int r0, int c0) { r = r0; c = c0;}
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