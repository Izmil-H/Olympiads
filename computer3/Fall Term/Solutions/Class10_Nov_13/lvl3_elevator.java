import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int N = readInt(), T = readInt(), M = readInt(), t[] = new int[M], s[] = new int[M], d[] = new int[M];
		for(int i=0; i<M; i++) {
			t[i] = readInt(); s[i] = readInt(); d[i] = readInt();
		}
		int floor = 0, time = 0, passengers = M, ans = 0; boolean up = true;
		int inElevator [] = new int[M]; boolean done[] = new boolean [M];
		Arrays.fill(inElevator, -1);
		while(passengers > 0) {
			for(int i=0; i<M; i++) {
				if(done[i]) continue;
				if(floor == s[i] && time >= t[i] && inElevator[i] == -1) {
					inElevator[i] = time; ans += time - t[i];  //add waiting time
				}else if(floor == d[i] && inElevator[i] != -1) {
					ans += time - inElevator[i];  //add travel time
					passengers--;  done[i] = true;
				}
			}
			if(floor == 0) up = true;
			if(floor == N) up = false;
			if(up) floor++;
			else floor--;
			time += T;
		}
		System.out.println(ans);
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