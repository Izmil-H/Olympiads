import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static long [] hash, p; static int mod = (int)1e9+7;
	public static void main(String[] args) throws IOException{
		String s = " " + readLine();
		int k = readInt(), n = s.length()-1, base = 131;
		hash = new long[n+1]; p = new long[n+1];
		p[0] = 1;
		for(int i=1; i<=n; i++) {
			hash[i] = (hash[i-1] * base + s.charAt(i))%mod;
			p[i] = p[i-1] * base % mod; 
		}
		int pos = 1;
		for(int i=2; i+k-1<=n; i++) {
			char c = s.charAt(i);
			if(c < s.charAt(pos)) pos = i;
			else if(c == s.charAt(pos)) {
				int lo = 0, hi = k-1, q = 0;
				while(lo <= hi) {
					int mid = (lo + hi)/2;
					if(subhash(pos, pos+mid) == subhash(i, i+mid)) {
						lo = mid + 1;
					}else { 
						q = mid; hi = mid - 1;
					}
				}
				if(s.charAt(pos+q) > s.charAt(i+q)) pos = i;
			}
		}
		System.out.println(s.substring(pos, pos+k));
	}
	static long subhash(int l, int r) {
		return (hash[r] - hash[l-1]*p[r-l+1]%mod + mod)%mod;
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