import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		for(int t = readInt(); t > 0; t--) {
			int C = readInt(), R = readInt(); char [][] g = new char[R][C];
			pair st = new pair(0, 0), ed = new pair(0, 0);
			for(int i=0; i<R; i++) {
				g[i] = readLine().toCharArray();
				for(int j=0; j<C; j++) {
					if(g[i][j] == 'C') st = new pair(i, j);
					if(g[i][j] == 'W') ed = new pair(i, j);
				}
			}
			Queue<pair> q = new LinkedList<>();  
			boolean[][] vis=new boolean[R][C]; 
			int [][] dis = new int[R][C], dir = {{-1,0}, {1, 0}, {0, -1}, {0, 1}};
			q.add(st); vis[st.r][st.c]=true; 
			while(!q.isEmpty()) {
				int r = q.peek().r, c = q.peek().c; q.poll();
				for(int k=0; k<4; k++) {
					int nr = r + dir[k][0], nc = c + dir[k][1];
					if(nr < 0 || nr >= R || nc <0 || nc >= C || vis[nr][nc] || g[nr][nc] =='X') continue;
					q.add(new pair(nr, nc)); vis[nr][nc]=true; 
					dis[nr][nc] = dis[r][c] + 1;
				}
			}
			if(vis[ed.r][ed.c] && dis[ed.r][ed.c] < 60) System.out.println(dis[ed.r][ed.c]);
			else System.out.println("#notworth");
		}
	}
	static class pair {
		int r, c;
		pair(int r0, int c0) { r=r0; c=c0; }
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