import java.util.*;
import java.io.*;
import java.time.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		char [] line = readLine().toCharArray();
		for(int i=0; i < line.length; ) {
			String s = "", op = "", turn = "";
			while( Character.isAlphabetic(line[i]) ) {
				s += line[i];
				i++;
			}
			op = (line[i]=='+'? "tighten" : "loosen");
			i++;
			while( i < line.length && Character.isDigit(line[i]) ) {
				turn += line[i];
				i++;
			}
			System.out.println(s + " " + op + " " + turn);
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