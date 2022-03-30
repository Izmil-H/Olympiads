import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int op = readInt(), n = readInt(), bit[][] = new int[n+1][n+1];
		while(true) {
			op = readInt();
			if(op == 3) break;
			if(op == 1) {
				int r = readInt()+1, c = readInt()+1, v = readInt();
				update(bit, r, c, v);
			}else {
				int l = readInt(), b = readInt(), r = readInt() + 1, t = readInt() + 1;
				System.out.println( query(bit, r, t) - query(bit, r, b) - query(bit, l, t) + query(bit, l, b) );
			}
		}
	}
	static void update(int [][] bit, int r, int c, int val) {
		for(int i=r; i<bit.length; i+=i&-i)
			for(int j=c; j<bit.length; j+= j&-j)
				bit[i][j] += val;
	}
	static long query(int [][] bit, int r, int c) {
		int sum = 0;
		for(int i=r; i>0; i-=i&-i)
			for(int j=c; j>0; j-=j&-j)
				sum += bit[i][j];
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