import java.util.*;
import java.io.*;
public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		int N = readInt(), K = readInt(); long psa[] = new long[2*N + 1];
		for(int i=1; i<=N; i++) {
			psa[i] = readLong(); psa[i+N] = psa[i];
		}
		Deque<Long> mi = new ArrayDeque();  long ans = Long.MIN_VALUE;
		mi.addLast(0L);
		for(int L=0, R=1; R<=2*N; R++) {
			psa[R] += psa[R-1];
			while(!mi.isEmpty() && mi.getLast() > psa[R]) mi.removeLast();
			mi.addLast(psa[R]);
			while(L < R - K) {
				if(mi.getFirst() == psa[L]) mi.removeFirst();
				L++;
			}
			ans = Math.max(ans, psa[R] - mi.getFirst());
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