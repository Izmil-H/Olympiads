import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), m = readInt(), a[] = new int[n+1];
		long bit[] = new long[n+1], freq[] = new long[(int)1e5+1];
		for(int i=1; i<=n; i++) {
			a[i] = readInt(); 
			update(bit, i, a[i]); update(freq, a[i], 1);
		}
		for(int i=1; i<=m; i++) {
			char op = readCharacter();
			if(op == 'C') {
				int x = readInt(), v = readInt();
				update(bit, x, -a[x]+v);  update(freq, a[x], -1);  update(freq, v, 1);
				a[x] = v;
			}else if(op == 'S') {
				int l = readInt(), r = readInt();
				System.out.println(query(bit, r) - query(bit, l-1));
			}else {
				int v = readInt();
				System.out.println(query(freq, v));
			}
		}
	}
	static void update(long [] bit, int idx, int val) {
		for(int i=idx; i<bit.length; i+= i&-i) 
			bit[i] += val;
	}
	static long query(long [] bit, int idx) {
		long sum = 0;
		for(int i=idx; i>0; i-=i&-i)
			sum += bit[i];
		return sum;
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