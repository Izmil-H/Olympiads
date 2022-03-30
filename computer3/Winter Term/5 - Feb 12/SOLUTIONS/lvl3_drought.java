import java.util.*;
import java.io.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException, InterruptedException {
		for(int T = readInt(); T > 0; T--) {
			int N = readInt(); long a[] = new long[N+1], sum = 0;
			for(int i=1; i<=N; i++) {
				a[i] = readLong();  sum = a[i] - sum;
			}
			if(N % 2 == 0) {
				if(sum != 0) { System.out.println(-1); continue; }
				long x = (long)1e18; sum = 0;
				for(int i=1; i<=N; i++) {
					sum = a[i] - sum;
					if(i % 2 != 0) x = Math.min(x, sum);
				}
				if(x < 0) { System.out.println(-1); continue; }
				long ans = 0; boolean flag = true;
				for(int i=1; i<=N; i++) {
					if(a[i] < x) flag = false;
					ans += a[i] - x;
				}
				System.out.println(flag? ans : -1);
			}else {
				if(sum < 0) { System.out.println(-1); continue; }
				long x = sum, ans = 0;  boolean flag =true;
				for(int i=1; i<=N; i++) {
					if(a[i] < x) flag = false;
					ans += a[i] - x;
				}
				System.out.println(flag? ans : -1);
			}
		}
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