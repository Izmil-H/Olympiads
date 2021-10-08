import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), q = readInt(), LOG = 31 - Integer.numberOfLeadingZeros(n); //LOG = (int)(Math.log(n) / Math.log(2));
		int [][] max = new int[LOG+1][n+1], min = new int[LOG+1][n+1];
		for(int i=1; i<=n; i++) {
			min[0][i] = max[0][i] = readInt(); 
		}
		for(int i=1; i<=LOG; i++) {
			for(int j = 1; j + (1<<i) - 1 <= n; j++) {
				max[i][j] = Math.max(max[i-1][j], max[i-1][j+(1<<(i-1))]);
				min[i][j] = Math.min(min[i-1][j], min[i-1][j+(1<<(i-1))]);
			}
		}
		for(int i=1; i<=q; i++) {
			int x = readInt(), y = readInt(), k = 31 - Integer.numberOfLeadingZeros(y-x+1);
			int mm = Math.max(max[k][x], max[k][y-(1<<k)+1]),  mi = Math.min(min[k][x], min[k][y-(1<<k)+1]); 
			System.out.println(mm - mi);
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