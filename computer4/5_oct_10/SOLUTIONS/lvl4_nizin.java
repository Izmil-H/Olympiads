import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{	
		int n = readInt(); Deque<Long> q = new ArrayDeque();
		for(int i=0; i<n; i++) q.add(readLong());
		int ans = 0;
		while(q.size() > 1) {
			if(q.peekFirst().equals(q.peekLast())) {
				q.pollFirst(); q.pollLast();
			}else if(q.peekFirst() < q.peekLast()) {
				long x = q.pollFirst(), y = q.pollFirst();
				q.addFirst(x+y); ans++;
			}else {
				long x = q.pollLast(), y = q.pollLast();
				q.addLast(x+y); ans++;
			}
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