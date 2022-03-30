import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static int N, M, C, t[];
	public static void main(String[] args) throws IOException{	
		N=readInt(); M=readInt(); C = readInt(); t=new int[N];
		for(int i=0; i<N; i++) t[i] = readInt();
		Arrays.sort(t);
		int lo = 0, hi = t[N-1], ans = 0;
		while(lo <= hi) {
			int mid = (lo + hi)/2;
			if(check(mid)) { ans = mid; hi = mid - 1; }
			else lo = mid + 1;
		}
		System.out.println(ans);
	}
	static boolean check(int lmt) {
		int bus = 1, last = 0;
		for(int i=1; i<N; i++) {
			if(i - last >= C || t[i] - t[last] > lmt) {
				bus++; last = i;
			}
		}
		return bus <= M;
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