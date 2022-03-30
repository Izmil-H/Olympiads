import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		int n = readInt(); long prod[] = new long[n+1], mi = (long)n*n, mx=0;
		for(int i=2; i<=n; i++) {
			System.out.println("? 1 " + i);
			System.out.flush();
			prod[i] = readLong();
			mi = Math.min(mi, prod[i]);
			mx = Math.max(mx, prod[i]);
		}
		int a[] = new int[n+1];
		if(mi == 2) {
			if(mx == n) a[1] = 1;
			else a[1] = 2;
		}else {
			a[1] = (int)mi;
		}
		for(int i=2; i<=n; i++) a[i] = (int)(prod[i] / a[1]);
		System.out.print("!");
		for(int i=1; i<=n; i++) {
			System.out.print(" " + a[i]);
		}
		System.out.println();
	}
	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}

	static long readLong() throws IOException {
		return Long.parseLong(next());
	}

	static int readInt() throws IOException {
		return Integer.parseInt(next());
	}

	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static char readCharacter() throws IOException {
		return next().charAt(0);
	}

	static String readLine() throws IOException {
		return br.readLine().trim();
	}
}