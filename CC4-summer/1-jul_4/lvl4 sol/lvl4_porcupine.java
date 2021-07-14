import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), t = readInt(); long [] d2 = new long[t+2], d1 = new long[t+2], d0 = new long[t+2];
		for(int i=1; i<=n; i++) {
			int L = readInt(), R = readInt(); long a = readLong(), b = readLong(), c = readLong();
			long v2 = a, v1 = b - 2*a*L, v0 = a*L*L - b*L + c;
			d2[L] += v2;  d2[R+1] -= v2;
			d1[L] += v1;  d1[R+1] -= v1;
			d0[L] += v0;  d0[R+1] -= v0;
		}
		for(int i=1; i<=t; i++) {
			d2[i] += d2[i-1];
			d1[i] += d1[i-1];
			d0[i] += d0[i-1];
			System.out.print(d2[i]*i*i + d1[i]*i + d0[i] + " ");
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