import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), m = readInt();
		long w[] = new long[m+1], seed = 131, sum = 0;
		w[0] = 1;
		for(int i=1; i<=m; i++) {
			w[i] = w[i-1] * seed;  sum += w[i];
		}
		int freq[] = new int[m+1], freq2[] = new int[n+1];
		long psa = 0, ans = 0;  Map<Long, Integer> map = new HashMap();
		map.put(0L, 1);
		for(int i=1; i<=n; i++) {
			int x = readInt();  freq[x]++;  freq2[freq[x]]++;
			psa += w[x];
			if(freq2[freq[x]] == m) {
				psa -= sum;
			}
			int t = map.getOrDefault(psa, 0);
			ans += t;  map.put(psa, t+1);
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