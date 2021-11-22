import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{	
		int n = readInt();
		String [] sen = readLine().split("[.?!]");
		for(String s : sen) {
			String words[] = s.split(" "); int cnt = 0;
			for(String word : words) {
				if(isName(word)) cnt++;
			}
			System.out.println(cnt);
		}
	}
	static boolean isName(String word) {
		if(word.length() == 0) return false;
		if(!Character.isUpperCase(word.charAt(0))) return false;
		for(int i=1; i<word.length(); i++) {
			if(!Character.isLowerCase(word.charAt(i))) return false;
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