import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		long n = readLong(), cnt[] = new long[19];
		cnt[1] = 9;
		for(int i=3; i<cnt.length; i+=2) {
			cnt[i] = 100*cnt[i-2];
		}
		int digits = String.valueOf(n).length();  long ans = 0;
		if(digits % 2 != 0) {
			long pre = 0;
			for(int i=1; i<digits; i++) pre = pre*10 + 9;
			ans += n - pre;
		}
		for(int i=digits-1; i>=0; i--) ans += cnt[i];
		System.out.println(ans);
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