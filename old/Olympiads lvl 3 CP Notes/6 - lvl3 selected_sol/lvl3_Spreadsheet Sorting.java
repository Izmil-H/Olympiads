import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int R = readInt(), C = readInt(), a[][] = new int[R][C]; Integer id[] = new Integer[R];
		for(int i=0; i<R; i++) {
			id[i] = i;
			for(int j=0; j<C; j++) a[i][j] = readInt();
		}
		for(int i=0, n=readInt(); i < n; i++) {
			int col = readInt() - 1;
			Arrays.sort(id, new Comparator<Integer>() {
				public int compare(Integer x, Integer y) {
					return Integer.compare(a[x][col], a[y][col]);
				}
			});
		}
		for(int i=0; i<R; i++) {
			for(int j=0; j<C; j++) {
				System.out.print(a[id[i]][j] + " ");
			}
			System.out.println();
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
