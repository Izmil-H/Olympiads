import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static int n, q; static char g[][]; static boolean vis[][];
	public static void main(String[] args) throws IOException{	
		n = readInt(); q = readInt();  g = new char[n][n];
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				g[i][j] = readCharacter();
		for(int i=0; i<q; i++) {
			String word = readLine(); boolean found = false;
			vis = new boolean[n][n];
			outside:
			for(int r=0; r<n; r++) {
				for(int c = 0; c<n; c++) {
					if(g[r][c] == word.charAt(0)) found = fun(r, c, 1, word);
					if(found) break outside;
				}
			}
			System.out.println(found? "good puzzle!" : "bad puzzle!");
		}
	}
	static boolean fun(int r, int c, int idx, String word) {
		if(idx >= word.length()) return true;
		vis[r][c] = true;
		for(int dr=-1; dr<=1; dr++) {
			for(int dc=-1; dc<=1; dc++) {
				int nr = r + dr, nc = c + dc;  //(r-1, c-1) (r-1, c) (r-1, c+1) .... 
				if(nr < 0 || nr >= n || nc < 0 || nc>=n || vis[nr][nc] || g[nr][nc] != word.charAt(idx)) continue;
				if(fun(nr, nc, idx+1, word)) return true;
			}
		}
		vis[r][c] = false; return false;
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