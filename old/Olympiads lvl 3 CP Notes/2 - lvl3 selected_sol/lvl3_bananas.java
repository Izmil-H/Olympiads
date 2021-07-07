import java.util.*;
import java.io.*;
public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		for(String s=readLine(); !s.equals("X"); s=readLine()){
			if(isMonkeyWord(s)) System.out.println("YES");
			else System.out.println("NO");
		}
	}
	static boolean isMonkeyWord(String s){
		if(isAWord(s)) return true;
		else{
			for(int i=0; i<s.length(); i++){
				if(s.charAt(i) == 'N')
					if(isAWord(s.substring(0, i)) && isMonkeyWord(s.substring(i+1))) 
						return true;
			}
		}
		return false;
	}
	static boolean isAWord(String s){
		if(s.isEmpty()) return false;
		if(s.equals("A")) return true;
		else if(s.length()>=3 && s.charAt(0)=='B' && s.charAt(s.length()-1)=='S' 
					&& isMonkeyWord(s.substring(1, s.length()-1)))
				return true;
		return false;
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
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}