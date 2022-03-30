import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{	
		int n = readInt(), k = readInt(), b[] = new int[n], ans = 0, mx = 0;
		for(int i=0; i<n; i++) {
			b[i] = readInt();  mx = Math.max(mx, b[i]);
		}
		for(int x=1; x<=mx; x++) {
			int count = 0; List<Integer> rem = new ArrayList<>();
			for(int i=0; i<n; i++) {
				count += b[i] / x;  rem.add(b[i] % x);
			}
			if(count < k/2) break;
			if(count >= k) ans = Math.max(ans, k/2 * x);
			else {
				int sum = (count - k/2) * x;
				Collections.sort(rem, Collections.reverseOrder());
				for(int i=0; i<k - count && i < rem.size(); i++)
					sum += rem.get(i);
				ans = Math.max(ans, sum);
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