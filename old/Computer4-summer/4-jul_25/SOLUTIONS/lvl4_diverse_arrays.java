import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), k = readInt(), maxv = (int)1e6, a[] = new int[n], freq[] = new int[maxv+1];
		for(int i=0; i<n; i++) a[i] = readInt();
		int distinct = 0; long ans = 0;
		for(int L=0, R=0; R<n; R++) {
			if(++freq[a[R]] == 1) distinct++;
			while(distinct >= k) {
				ans += n - R;
				if(--freq[a[L]] == 0) distinct--;
				L++;
			}
		}
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