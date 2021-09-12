import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static int ans;
	public static void main(String[] args) throws IOException{
		for(int T = readInt(), t=1; t<=T; t++) {
			System.out.print("Case #"+t+": ");
			int n = readInt(); ans = 0;
			node root = new node();
			for(int i=0; i<n; i++) {
				String s = readLine();
				insert(s, root);
			}
			System.out.println(ans);
		}
	}
	static void insert(String s, node root) {
		node cur = root;  int cnt = 0; boolean prefix = true;
		for(int i=0; i<s.length(); i++) {
			int c = s.charAt(i) - 'a';
			if(prefix) cnt++;
			if(cur.ch[c] == null) {
				cur.ch[c] = new node();
				prefix = false;
			}
			cur = cur.ch[c];
		}
		ans += cnt;
	}
	static class node {
		node ch[];
		node() { ch = new node[26]; }
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