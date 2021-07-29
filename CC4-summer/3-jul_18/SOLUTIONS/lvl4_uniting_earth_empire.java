import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(); Stack<hill> stk = new Stack(); long ans = 0;
		for(int i=1; i<=n; i++) {
			long h = readLong();
			while(!stk.isEmpty() && stk.peek().h < h) {
				ans += stk.peek().cnt; stk.pop();
			}
			if(!stk.isEmpty() && stk.peek().h == h) {
				ans += stk.peek().cnt;
				stk.peek().cnt++;
				if(stk.size() > 1) ans ++;
			}else {
				if(!stk.isEmpty()) ans ++;
				stk.push(new hill(h, 1));
			}
		}
		System.out.println(ans);
	}
	static class hill {
		long h, cnt;
		hill(long h0, long c0) { h = h0; cnt = c0; }
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