import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		int n = readInt(), m = readInt(); long k = readLong();
		long minK = n, maxK = (long)(1+m)*m/2 + (long)(n-m)*m;
		if(k < minK || k > maxK) { System.out.println(-1); return; }
		List<Integer> ans = new ArrayList(); Deque<Integer> q = new LinkedList();
		k -= n;  q.add(1); ans.add(1);
		int last = 1;
		while(k > 0) {
			if(k >= q.size()) {
				last++;
				if(last <= m) {
					k-= q.size();  ans.add(last);  q.add(last);
				}else {
					k-= q.size()-1; 
					int x = q.pollFirst();
					ans.add(x); q.add(x); 
				}
			}else {
				ArrayList<Integer> tmp = new ArrayList<>(q);
				int pos = (int)(q.size() - k -1); last = tmp.get(pos);
				ans.add(last); k = 0;
			}
		}
		while(ans.size() < n) ans.add(last);
		for(int x : ans) System.out.print(x + " ");
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