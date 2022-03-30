import java.util.*;
import java.io.*;
import java.time.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		for(int T= readInt(); T>0; T--) {
			int n = readInt(), sum = 0; Set<Integer> vis=new HashSet();
			for(int i=0; i<n; i++) {
				sum += readInt();  vis.add(sum);
			}
			if(sum == 0) { System.out.println(0); continue; }
			int ans = Integer.MAX_VALUE;
			for(int len = n; len >= 1; len--) {
				if(sum % len != 0) continue;
				int val = sum / len; boolean flag = true;
				for(int x = val; x <= sum; x += val) {
					if(!vis.contains(x)) { flag =false; break; }
				}
				if(flag) {  ans = n-len; break; }
			}
			System.out.println(ans);
		}
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