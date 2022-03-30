import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{	
		int n = readInt(); long a[] = new long[n+1];
		print(1, 2);
		long d = readLong();  //[ a[1]+a[2], a[1] - a[2], a[3] .... ]
		print(1, 2);
		long s = readLong();  //[ 2*a[1], 2*a[2], a[3] .... ]
		a[2] = s/2;  a[1] = a[2] + d;
		long cur = 2*a[1];
		for(int i=3; i<=n; i++) {
			print(1, i);  
			d = readLong();
			a[i] = cur - d;
			cur += a[i];
		}
		System.out.print("!");
		for(int i=1; i<=n; i++) System.out.print(" " + a[i]);
		System.out.println();
	}
	static void print(int i, int j) {
		System.out.println("? " + i + " " + j);
		System.out.flush();
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