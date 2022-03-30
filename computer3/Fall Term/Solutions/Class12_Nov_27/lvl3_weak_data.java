import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{	
		long K = readLong(), lmt = (long)1e6; Map<Long, Long> map = new HashMap();
		if(K==0) { System.out.println(1 + "\n" + 1); return; }
		for(long i = 0; i<=lmt; i++) map.put(i*(i+1)/2, i);
		for(long i=1; i<=lmt; i++) {
			long rem = K - i*(i+1)/2;
			if(!map.containsKey(rem)) continue;
			long m = i, n = map.get(rem);
			if(n > 0) {
				if(m + 1 + n > lmt) continue;
				System.out.println(m+1+n);
				for(int k=0; k<m; k++) System.out.print(0 + " ");
				System.out.print(1 + " ");
				for(int k=0; k<n-1; k++) System.out.print(0 + " ");
				System.out.println(0);
			}else {
				System.out.println(m);
				for(int k=0; k<m-1; k++) System.out.print(0 + " ");
				System.out.println(0);
			}
			return;
		}
		System.out.println(-1);
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