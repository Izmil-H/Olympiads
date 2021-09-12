import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static long [] hsh, pw, hsh2, pw2; static int mod=(int)1e9+7;
	public static void main(String[] args) throws IOException{
		String s = readLine(), t = readLine(); 
		int n = s.length(), m = t.length(), base = 131, base2=137, fs[] = new int[26], ft[] = new int[26];
		hsh = new long[m+1]; pw = new long[m+1]; hsh2 = new long[m+1]; pw2 = new long[m+1];
		for(int i=0; i<s.length(); i++) fs[s.charAt(i) - 'a']++;
		hsh[0] = 0; pw[0] = 1;  hsh2[0] =0; pw2[0] = 1;
		for(int i=1; i<=m; i++) {
			hsh[i] = (hsh[i-1]*base + t.charAt(i-1))%mod;
			pw[i] = pw[i-1]*base % mod;
			hsh2[i] = (hsh2[i-1]*base2 + t.charAt(i-1))%mod;
			pw2[i] = pw2[i-1] * base2 % mod;
		}
		Set<Long> set = new HashSet();
		for(int i=1; i<=m; i++) {
			ft[t.charAt(i-1) - 'a']++;
			if(i > n) ft[t.charAt(i-1-n) - 'a']--;
			if(Arrays.equals(fs, ft)) {
				//System.out.println(t.substring(i-n, i) + " " + getSubstringHash(i-n+1, i));
				set.add(getSubstringHash(i-n+1, i));
			}
		}
		System.out.println(set.size());
	}
	static long getSubstringHash(int L, int R) {
		long v1 = (hsh[R] - hsh[L-1] * pw[R-L+1] % mod + mod)%mod, v2 = (hsh2[R] - hsh2[L-1] * pw2[R-L+1] % mod + mod)%mod;
		return (v1 << 31) | v2;
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