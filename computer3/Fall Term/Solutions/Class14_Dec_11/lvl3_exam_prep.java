import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{	
		int n = readInt(), q = readInt(), p[] = new int[n+1], sz[] = new int[n+1]; long val[] = new long[n+1];
		for(int i=1; i<=n; i++) { //make n disjoint sets
			p[i] = i;  sz[i] = 1;  val[i] = readLong();
		}
		for(int i=1; i<=q; i++) {
			int op = readInt();
			if(op == 1) {
				int a = readInt(), b = readInt();
				int fa = find_set(p, a), fb = find_set(p, b);
				if(fa != fb) { p[fa] = fb; sz[fb] += sz[fa]; val[fb] += val[fa]; }
			}else if(op == 2) {
				int fa = find_set(p, readInt());
				System.out.println(sz[fa]);
			}else {
				int fa = find_set(p, readInt());
				System.out.println(val[fa]);
			}
		}
	}
	static int find_set(int p[], int d) {
		if(d != p[d]) p[d] = find_set(p, p[d]);
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