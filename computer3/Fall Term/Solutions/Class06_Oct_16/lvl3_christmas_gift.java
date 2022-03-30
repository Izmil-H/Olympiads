import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static int n, budget, p[], s[], ans=0;
	public static void main(String[] args) throws IOException{
		n = readInt(); budget = readInt();
		p = new int[n]; s = new int[n];
		for(int i=0; i<n; i++) {
			p[i] = readInt(); s[i] = readInt();
		}
		for(int i=0; i<n; i++) {
			p[i] /= 2;
			update();
			p[i] *= 2;
		}
		System.out.println(ans);
	}
	static void update() {
		int cost[] = new int[n];
		for(int i=0; i<n; i++) {
			cost[i] = p[i] + s[i];
		}
		Arrays.sort(cost);
		int count = 0, total = budget;
		for(int i=0; i<n; i++) {
			if(total >= cost[i]) {
				count++; total -= cost[i];
			}else break;
		}
		ans = Math.max(ans, count);
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