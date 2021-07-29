import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), q = readInt(), h[] = new int[n+2], maxV = (int)1e6 + 2;
		Stack<Integer> stk = new Stack();
		long [] ans = new long[maxV];
		h[0] = -1; stk.push(0);
		for(int i=1; i<=n+1; i++) {
			if(i <= n) h[i] = readInt();
			else h[i] = -1;
			while(h[stk.peek()] > h[i]) {
				int p = stk.pop(), lft = p - stk.peek(), rit = i - p;
				ans[h[p]] += (long)lft * rit;
			}
			stk.push(i);
		}
		for(int i=1; i<ans.length; i++) ans[i] += ans[i-1];
		while(q-- > 0) {
			int x = readInt(), y = readInt();
			System.out.println(ans[y] - ans[x-1]);
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