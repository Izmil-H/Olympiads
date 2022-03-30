import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static int M, N, a[][]; static long [][] bit;
	public static void main(String[] args) throws IOException{
		M = readInt(); N = readInt(); a = new int[M+1][N+1]; bit = new long[M+1][N+1];
		while(true) {
			int op = readInt();
			if(op == 0) break;
			if(op == 1) {
				int r = readInt(), c = readInt(), v = readInt();
				if( (r+c) % 2 != 0 ) {
					update(r, c, -a[r][c] - v); a[r][c] = -v;
				}else {
					update(r, c, -a[r][c] + v); a[r][c] = v;
				}
			}else {
				int r1 = readInt(), c1 = readInt(), r2 = readInt(), c2 = readInt();
				long sum = query(r2, c2) - query(r1-1, c2) - query(r2, c1-1) + query(r1-1, c1-1);
				if((r1+c1) %2 != 0) System.out.println(-sum);
				else System.out.println(sum);
			}
		}
	}
	static void update(int r, int c, int val) {
		for(int i=r; i<bit.length; i+=i&-i)
			for(int j=c; j<bit[i].length; j+=j&-j)
				bit[i][j] += val;
	}
	static long query(int r, int c) {
		long ret = 0;
		for(int i=r; i>0; i-=i&-i)
			for(int j=c; j>0; j-=j&-j)
				ret += bit[i][j];
		return ret;
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