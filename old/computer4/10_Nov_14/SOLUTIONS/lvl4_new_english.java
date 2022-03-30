import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), m = readInt(); 
		char s[] = new char[n];  boolean vis[] = new boolean[n];
		int freq[] = new int[26], st[] = new int[26]; List<E> lst = new ArrayList();
		for(int i=1; i<=m; i++) 
			lst.add(new E(readCharacter(), readInt(), readInt()));
		Collections.sort(lst);
		for(E e: lst) {
			int c = e.c - 'a';
			for(int i=st[c]; freq[c]<e.x && i<e.p; i++) {
				if(!vis[i]) { vis[i]=true; s[i] = e.c; freq[c]++; }
			}
			if(freq[c] != e.x) { System.out.println(-1); return; }
			st[c] = e.p; 
		}
		int min = n; char c = ' ';
		for(int i=0; i<26; i++) {
			if(st[i] < min) { min = st[i]; c = (char)(i+'a'); }
		}
		for(int i=0; i<n; i++) {
			if(!vis[i]) { 
				if(i < min) { System.out.println(-1); return; }
				vis[i] = true; s[i] = c;
			}
		}
		System.out.println(new String(s));
	}
	static class E implements Comparable<E>{
		char c; int x, p;
		E(char c0, int x0, int p0) { c = c0; x = x0; p = p0; }
		public int compareTo(E a) {
			return Integer.compare(p, a.p);
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