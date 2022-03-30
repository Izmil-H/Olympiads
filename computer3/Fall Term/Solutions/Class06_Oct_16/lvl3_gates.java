import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int G = readInt(), P = readInt(); 
		TreeSet<Integer> gate = new TreeSet();
		for(int i=1; i<=G; i++) gate.add(i);
		for(int i=1; i<=P; i++) {
			int x = readInt();
			Integer dock = gate.floor(x);
			if(dock != null) {
				gate.remove(dock);
			}else {
				System.out.println(i-1);
				return;
			}
		}
		System.out.println(P);
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