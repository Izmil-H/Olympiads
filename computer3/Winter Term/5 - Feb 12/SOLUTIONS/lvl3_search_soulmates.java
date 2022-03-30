import java.util.*;
import java.io.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException, InterruptedException {
		for(int T=readInt(); T>0; T--) {
			long a = readLong(), b =readLong();
			if(a == b) System.out.println(0);
			else {
				long cnt = 0, ans = Integer.MAX_VALUE;
				while(b > 1) {
					if(a > b) {
						if(a % 2 != 0) {
							a++; cnt++;
						}
						a/=2; cnt++;
					}else if(a < b) {
						ans = Math.min(ans,  cnt + b - a);
						if(b % 2 != 0) {
							b--; cnt++;
						}
						b/=2; cnt++;
					}else {
						ans = Math.min(ans, cnt);
						break;
					}
				}
				System.out.println(ans);
			}
		}
	}
	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong() throws IOException {
		return Long.parseLong(next());
	}
	static int readInt() throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}
	static char readCharacter() throws IOException {
		return next().charAt(0);
	}
	static String readLine() throws IOException {
		return br.readLine().trim();
	}
}