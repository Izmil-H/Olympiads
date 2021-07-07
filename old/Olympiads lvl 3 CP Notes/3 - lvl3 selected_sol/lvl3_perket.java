import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int sour[], bit[], ans = Integer.MAX_VALUE;
	public static void main(String[] args) throws IOException{
		int n = readInt(), id[]=new int[n]; sour = new int[n]; bit = new int[n];
		for(int i=0; i<n; i++) {
			sour[i] = readInt(); bit[i] = readInt(); id[i] = i;
		}
		List<Integer> res = new ArrayList();
		getCombination(0, id, res);
		System.out.println(ans);
	}
	static void getCombination(int idx, int a[], List<Integer> res) {
		if(idx == a.length) {
			if(res.isEmpty()) return;
			int totSour = 1, totBit = 0;
			for(int id: res) { totSour *= sour[id]; totBit += bit[id]; }
			ans = Math.min(ans, Math.abs(totBit - totSour));
			return;
		}
		getCombination(idx+1, a, res);  //not choose
		res.add(a[idx]); getCombination(idx+1, a, res); res.remove(res.size()-1);
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