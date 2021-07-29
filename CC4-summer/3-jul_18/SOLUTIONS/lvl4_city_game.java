import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		for(int T = readInt(); T > 0; T --) {
			int R = readInt(), C = readInt(), hist[] = new int[C+1], ans = 0;
			for(int i=0; i<R; i++) {
				for(int j=0; j<C; j++) {
					if(readCharacter() == 'F') hist[j]++;
					else hist[j] = 0;
				}
				ans = Math.max(ans, getMaxRectFromHist(hist));
			}
			System.out.println(ans*3);
		}
	}
	static int getMaxRectFromHist(int hist[]) {
		Stack<Integer> stk = new Stack();  int area = 0;
		for(int i=0; i<hist.length; i++) {
			while(!stk.empty() && hist[stk.peek()] >= hist[i]) {
				int idx = stk.pop(), left = stk.empty()? -1 : stk.peek();
				area = Math.max(area, hist[idx] * (i - left - 1));
			}
			stk.push(i);
		}
		return area;
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