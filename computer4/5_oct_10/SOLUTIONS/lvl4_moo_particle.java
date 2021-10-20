import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt();  List<pair> a = new ArrayList();
		for(int i=0; i<n; i++) a.add(new pair(readInt(), readInt()));
		Collections.sort(a, Collections.reverseOrder());
		Stack<Integer> stk = new Stack();
		for(pair e : a) {
			if(stk.empty() || stk.peek() < e.y) stk.push(e.y);
			else {
				int y = stk.pop();
				while(!stk.empty() && stk.peek() >= e.y) stk.pop();
				stk.push(y);
			}
		}
		System.out.println(stk.size());
	}
	static class pair implements Comparable<pair>{
		int x, y;
		pair(int x0, int y0) { x = x0; y = y0; }
		public int compareTo(pair a) {
			if(x != a.x) return Integer.compare(x, a.x);
			return Integer.compare(y, a.y);
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