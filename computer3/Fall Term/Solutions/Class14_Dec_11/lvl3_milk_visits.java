import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{	
		int n = readInt(), m = readInt(), p[] = new int[n];
		for(int i=0; i<n; i++) { //make n disjoint sets
			p[i] = i;
		}
		char s [] = readLine().toCharArray();
		for(int i=1; i<n; i++) {
			int u = readInt() - 1, v= readInt() - 1;
			if(s[u] == s[v]) p[find_set(p, u)] = find_set(p, v);
		}
		for(int i=1; i<=m; i++) {
			int u = readInt()-1, v=readInt()-1; 
			char type = readCharacter();
			if(s[u] != type && s[v]!=type && find_set(p, u) == find_set(p, v)) System.out.print(0);
			else System.out.print(1);
		}
		System.out.println();
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