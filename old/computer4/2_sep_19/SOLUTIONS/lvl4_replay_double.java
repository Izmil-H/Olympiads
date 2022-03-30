import java.util.*;
import java.io.*;
public class Main {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int a = 1;
		int b = 1;
		int M = Integer.parseInt(st.nextToken());
		int Q = Integer.parseInt(st.nextToken());
		StringBuilder S = new StringBuilder("011");
		while(true) {
			int c = (a+b)%M;
			a = b;
			b = c;
			if(a+b==1) {
				break;
			}
			S.append(c);
		}
		for(int i = 0; i<Q; i++) {
			Long N = Long.parseLong(br.readLine());
			System.out.println(S.charAt((int)(N%S.length())));
		}
	}
}