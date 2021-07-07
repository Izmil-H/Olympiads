import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), len = readInt(), s = readInt();
		List<pair> list = new ArrayList();
		for(int i=1; i<=n; i++) {
			int x = readInt(), y = readInt(), v = readInt();
			list.add(new pair(x, v)); list.add(new pair(y+1, -v));
		}
		Collections.sort(list);
		int sum = 0, interval = 0;
		for(int i=0; i<list.size() - 1; i++) {
			sum += list.get(i).val;
			if(sum >= s) interval += list.get(i+1).pos - list.get(i).pos;
		}
		System.out.println(len - interval);
	}
	static class pair implements Comparable<pair>{
		int pos, val;
		pair(int p, int v){ pos = p; val = v; }
		public int compareTo(pair x) { return Integer.compare(pos, x.pos); }
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