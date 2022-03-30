import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), a[] = new int[n]; long ans =0;
		for(int i=0; i<n; i++) a[i] = readInt();
		Arrays.sort(a);
		for(int L = 0, R = n-1; L < n/2-1; L++, R--) {
			ans += a[R] * 2 - a[L] * 2;
		}
		if(n % 2 == 0) {
			ans += a[n/2] - a[n/2-1];
		}else {
			int x = a[n/2-1], y = a[n/2], z = a[n/2+1];
			ans += Math.max(2*z - x - y, z + y - x*2);
		}
		System.out.println(ans);
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