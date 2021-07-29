import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), h[] = new int[n]; Stack<Integer> stk = new Stack();
		for(int i=0; i<n; i++) {
			h[i] = readInt();
		}
		for(int i=0; i<n; i++) {
			while(!stk.empty() && h[i] >= h[stk.peek()]) {
				stk.pop();
			}
			if(stk.empty()) System.out.print(i + " ");
			else System.out.print(i - stk.peek() + " ");
			stk.push(i);
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