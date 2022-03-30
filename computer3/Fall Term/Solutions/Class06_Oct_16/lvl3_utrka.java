import java.util.*;
import java.io.*;
public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	//static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		HashMap<String, Integer> mp = new HashMap<String, Integer>();
		int n = readInt();
		for(int i=0; i<n; i++){
			String word = readLine();
			mp.put(word, mp.getOrDefault(word, 0)+1);
		}
		for(int i=0; i<n-1; i++){
			String word = readLine();
			mp.put(word, mp.get(word)-1);
		}
		for(String name: mp.keySet())
			if(mp.get(name) == 1) { System.out.println(name); break; }
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