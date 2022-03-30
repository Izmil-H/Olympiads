import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static int ans = Integer.MAX_VALUE, sour[], bit[];
	public static void main(String[] args) throws IOException{
		int n = readInt(); 
		sour = new int[n+1]; bit = new int[n+1];
		for(int i=1; i<=n; i++) {
			sour[i] = readInt(); bit[i] = readInt();
		}
		List<Integer> comb = new ArrayList();
		f(1, n, comb);
		System.out.println(ans);
	}
	static void f(int i, int n, List<Integer> comb) {
		if(i > n) {
			if(comb.isEmpty()) return;
			int totSour = 1, totBit = 0;
			for(int x : comb) {
				totSour *= sour[x]; totBit += bit[x];
			}
			ans = Math.min(ans, Math.abs(totSour - totBit));
			return;
		}
		f(i+1, n, comb); //don't choose i
		comb.add(i); f(i+1, n, comb); comb.remove(comb.size()-1);  //choose i
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