import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static int n, m; static List<pair> p = new ArrayList();
	public static void main(String[] args) throws IOException {
		n = readInt(); m = readInt();
		for(int i=0; i<m; i++) p.add(new pair(readLong(), readLong()));
		Collections.sort(p);
		long lo = 1, hi = (long)1e18, ans = 0;
		while(lo <= hi) {
			long mid = (lo + hi)/2;
			if(check(mid)) { ans = mid; lo = mid + 1; }
			else hi = mid - 1;
		}
		System.out.println(ans);
	}
	static boolean check(long d) {
		long last = Long.MIN_VALUE, cnt = 0;
		for(pair e: p) {
			last = Math.max(last, e.l);
			while(last <= e.r) {
				cnt++; last += d;
			}
			if(cnt >= n) return true;
		}
		return false;
	}
	static class pair implements Comparable<pair>{
		long l, r;
		pair(long l0, long r0) { l = l0; r = r0; }
		public int compareTo(pair x) { return Long.compare(l, x.l); }
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