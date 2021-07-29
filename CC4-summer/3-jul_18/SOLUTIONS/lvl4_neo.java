import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		int R = readInt(), C = readInt(), a[][] = new int[R][C];
		for(int i=0; i<R; i++)
			for(int j=0; j<C; j++)
				a[i][j] = readInt();
		int ans = 0, hist[] = new int[C];
		for(int i=0; i<R-1; i++) {
			for(int j=0; j<C-1; j++) {
				if(a[i][j] + a[i+1][j+1] <= a[i][j+1] + a[i+1][j]) hist[j]++;
				else hist[j] = 0;
			}
			ans = Math.max(ans, maxRectInHist(hist));
		}
		System.out.println(ans);
	}
	static int maxRectInHist(int h[]) {
		Stack<Integer> stk = new Stack(); int area = 0;
		for(int i=0; i<h.length; i++) {
			while(!stk.isEmpty() && h[i] <= h[stk.peek()]) {
				int idx = stk.pop(), rit = i, lft = stk.isEmpty()? -1:stk.peek();
				area = Math.max(area, (rit-lft) * (h[idx]+1));  // (rit-lft-1) * h[idx]
			}
			stk.push(i);
		}
		while(!stk.isEmpty()) {
			int idx = stk.pop(), rit = h.length, lft = stk.isEmpty()? -1:stk.peek();
			area = Math.max(area, (rit-lft) * (h[idx]+1));  // (rit-lft-1) * h[idx]
		}
		return area;
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