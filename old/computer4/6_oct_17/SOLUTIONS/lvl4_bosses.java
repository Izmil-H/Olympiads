import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		//30% partial point sol (will TLE)
		int N = readInt(), H = readInt(), P = readInt(), a[] = new int[N]; long sum = 0;
		for(int i=0; i<N; i++) {
			a[i] = readInt(); sum += a[i];
		}
		Arrays.sort(a);
		long ans = (long)sum*P;
		for(int i=0; i<N; i++) {
			sum -= a[i];
			long time = (long)a[i]*H;
			time += (sum - (long)(N-i-1)*a[i])*P;
			ans = Math.min(ans, time);
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