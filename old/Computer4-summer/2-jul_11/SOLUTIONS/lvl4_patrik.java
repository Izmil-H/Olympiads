import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(); Stack<Integer> h = new Stack(), cnt = new Stack();
		long ans = 0;
		for(int i=1; i<=n; i++) {
			int x = readInt();
			while(!h.isEmpty() && h.peek() < x) {
				ans += cnt.peek(); h.pop(); cnt.pop();
			}
			if(h.isEmpty()) {
				h.push(x); cnt.push(1);
			}else {
				if(h.peek() == x) {
					int tmp = cnt.pop();
					ans += tmp + (h.size() > 1? 1:0);
					cnt.push(tmp + 1);
				}else {
					ans ++;
					h.push(x); cnt.push(1);
				}
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