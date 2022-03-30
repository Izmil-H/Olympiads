import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static int n, m, count=0; static boolean [][]conflict;
	public static void main(String[] args) throws IOException{
		n = readInt(); m = readInt(); conflict = new boolean[n+1][n+1];
		for(int i=1; i<=m; i++) {
			int x = readInt(), y = readInt();
			conflict[x][y] = conflict[y][x] = true;
		}
		List<Integer> comb = new ArrayList();
		getCombination(1, n, comb);
		System.out.println(count);
	}
	static void getCombination(int i, int n, List<Integer> comb) {
		if(i > n) {
			count++;
			return;
		}
		getCombination(i+1, n, comb); //don't choose i
		boolean can = true;
		for(int x : comb) {
			if(conflict[x][i]) can = false;
		}
		if(can) {
			comb.add(i); 
			getCombination(i+1, n, comb); 
			comb.remove(comb.size()-1);  //choose i
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