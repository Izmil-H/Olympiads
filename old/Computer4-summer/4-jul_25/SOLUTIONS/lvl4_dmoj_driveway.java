import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int T = readInt(), M = readInt(); 
		Deque<String> dq = new ArrayDeque();
		for(int i=0; i<T; i++) {
			String name = next(), ops = next();
			if(ops.equals("in")) dq.addLast(name);
			else {
				if(dq.isEmpty()) continue;
				if(name.equals(dq.peekLast())) dq.pollLast();
				else if(name.equals(dq.peekFirst()) && M > 0) { dq.pollFirst(); M--; }
			}
		}
		while(!dq.isEmpty()) System.out.println(dq.pollFirst());
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