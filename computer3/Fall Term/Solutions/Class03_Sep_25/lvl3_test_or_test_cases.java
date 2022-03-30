import java.util.*;
public class Test {
	static int N, L;
	static ArrayList<String> [] letter = new ArrayList [26];
	static ArrayList<String> sol = new ArrayList<String>();
	public static void main(String [] args){
		Scanner in = new Scanner(System.in);
		N = in.nextInt(); L = in.nextInt();
		for(int i=0; i<N; i++){
			int m = in.nextInt();
			letter[i] = new ArrayList<String>();
			for(int j=0; j<m; j++)
				letter[i].add(in.next());
			if(i > 0) letter[i].add("");
		}
		fun(0, "");  
		Collections.sort(sol);
		for(String e: sol) System.out.println(e);
	}
	static void fun(int cur, String word){
		if(cur == N || word.length() == L) { sol.add(word); return; }
		for(String e: letter[cur]) 
			fun(cur+1, word+e);
	}
}