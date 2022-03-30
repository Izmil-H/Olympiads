import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		for(int k=1; k<=2; k++) {
			int n = readInt(), p[] = new int[n+1];
			for(int i=1; i<=n; i++) p[i] = i;
			int cnt = 0;
			for(int i=1; i<=n; i++) {
				int x = readInt(), fi = find(i, p), fx = find(x, p);
				if(fi != fx) { cnt++; p[fx] = fi; }
			}
			System.out.print(n - cnt + " ");
		}
	}
	static int find(int d, int p[]) {
		if(d != p[d])  p[d] = find(p[d], p);
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