import java.util.*;
import java.io.*;
public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		long a = readLong(), b = readLong(); int k = readInt();
		List<Long> factor = new ArrayList();
		long g = GCD(a, b), root=(long)Math.sqrt(g);
		for(long i=1; i<root; i++)
			if(g % i == 0) { factor.add(i);  factor.add(g/i); }
		if(root*root == g) factor.add(root);
		Collections.sort(factor, Collections.reverseOrder());
		if(k>factor.size()) System.out.println(-1);
		else System.out.println(factor.get(k-1));
	}
	static long GCD(long x, long y) {
		if(y == 0) return x;
		return GCD(y, x%y);
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