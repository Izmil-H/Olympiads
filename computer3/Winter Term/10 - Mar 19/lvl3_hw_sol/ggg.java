import java.util.*;
import java.io.*;
import java.time.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		int n = readInt(), maxV = (int)1e6, pos[] = new int[maxV+1];
		for(int i=1; i<=n; i++) pos[readInt()] = i;
		List<Integer> lis = new ArrayList();
		for(int m=readInt(); m>0; m--) {
			int x = pos[readInt()];
			if(x == 0) continue;
			if(lis.isEmpty() || x > lis.get(lis.size()-1)) lis.add(x);
			else {
				int p = Collections.binarySearch(lis, x);
				if(p < 0) lis.set(-p-1, x);
			}
		}
		System.out.println(lis.size());
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