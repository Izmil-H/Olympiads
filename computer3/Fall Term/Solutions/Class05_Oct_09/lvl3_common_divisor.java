import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{	
		long a = readLong(), b = readLong(); int k = readInt();
		long g = gcd(a, b);
		List<Long> factor = new ArrayList();
		for(long i=1; i*i <= g; i++) {
			if(g % i == 0) {
				factor.add((long)i);
				if(g/i != i) factor.add(g/i);
			}
		}
		Collections.sort(factor, Collections.reverseOrder());
		if(k > factor.size()) System.out.println(-1);
		else System.out.println(factor.get(k-1));
	}
	static long gcd(long x, long y) {
		return y==0? x: gcd(y, x%y);
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