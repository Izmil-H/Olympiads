import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), f[] = new int[n], w[] = new int[n], id[] = new int[n];
		int tot = 0, ans = Integer.MAX_VALUE;
		for(int i=0; i<n; i++) {
			f[i] = readInt(); w[i] = readInt(); 
			tot += w[i]; id[i] = i;
		}
		do {
			int cur = 101, stress = tot, tmp = 0;
			for(int i=0; i<n; i++) {
				int k = id[i];
				tmp += (Math.abs(cur - f[k]) + 1)*stress;
				cur = f[k]; stress -= w[k];
			}
			ans = Math.min(ans,  tmp);
		}while(next_permutation(id));
		System.out.println(ans);
	}
	static boolean next_permutation(int a[]) {
		if(a.length <= 1) return false;
		int p = a.length - 2, q = a.length - 1;
		while(p >= 0 && a[p] >= a[p+1]) p--;
		if(p < 0) return false; 
		while(a[q] <= a[p]) q--;
		int tmp = a[p]; a[p] = a[q]; a[q] = tmp;
		for(int l=p+1, r= a.length-1; l<r; l++, r--) {
			tmp = a[l]; a[l] = a[r]; a[r] = tmp;
		}
		return true;
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