import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int n, lmt; static List<String> list[];
	public static void main(String[] args) throws IOException{
		n = readInt(); lmt = readInt();
		list = new ArrayList[n];
		for(int i=0; i<n; i++) {
			list[i] = new ArrayList();
			int m = readInt();
			if(i > 0) list[i].add("");
			for(int j=0; j<m; j++) list[i].add(next());
		}
		List<String> res = new ArrayList();
		fun(0, "", res);
		Collections.sort(res);
		for(String x: res) System.out.println(x);
	}
	static void fun(int idx, String word, List<String> res) {
		if(idx == n || word.length() == lmt) {
			res.add(word); return;
		}
		for(String x: list[idx])
			fun(idx+1, word + x, res);
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