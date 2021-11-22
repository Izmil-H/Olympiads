import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), m = readInt(), t = readInt();
		List<pair> a = new ArrayList<>();
		for(int i=0; i<n; i++) {
			a.add(new pair(readInt(), readInt()));
		}
		Collections.sort(a);
		PriorityQueue<Integer> q = new PriorityQueue<>();
		int ans = 0, sum = 0;
		for(pair e : a) {
			if(e.p * 2 + t > m) break;
			sum += e.c; q.add(e.c);
			int lmt = (m - e.p*2)/t;
			while(q.size() > lmt) {
				sum -= q.poll();
			}
			ans = Math.max(ans, sum);
		}
		System.out.println(ans);
	}
	static class pair implements Comparable<pair>{
		int p, c;
		pair(int p0, int c0) { p = p0; c = c0; }
		public int compareTo(pair x) { return Integer.compare(p, x.p); }
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