import java.util.*;
import java.io.*;

public class dmoj_vudu{
	static long [] bit; static long out = 0;
	static long freqTo(int ind) {
		ind++; long sum = 0;
		while(ind > 0) {
			sum += bit[ind]; ind -= ind & -ind;
		}
		return sum;
	}
	static void update(int ind) {
		ind++;
		while(ind < bit.length) {
			bit[ind] ++; ind += ind & -ind;
		}
	}
	static int lower_bound(long a[], int lo, int hi, long key){
		int len = hi - lo;
		while( len > 0 ){
			int half = len/2, mid = lo + half;
			if(a[mid] < key) { lo = mid+1; len = len - half - 1; }
			else len = half;
		}
		return lo;
	}
	public static void main(String[]args) throws NumberFormatException, IOException{
		BufferedReader bf = new BufferedReader (new InputStreamReader (System.in));
		Integer N = Integer.parseInt(bf.readLine());
		long [] ai = new long [N]; bit = new long [N + 1]; long [] rep = new long [N];
		StringTokenizer st = new StringTokenizer(bf.readLine());
		for(int i = 0; i < N; i++) ai[i] = Integer.parseInt(st.nextToken());
		Integer P = Integer.parseInt(bf.readLine());
		// minus P 
		for(int i = 0; i < N; i++) { ai[i] -= P;}
		// prefix sum array
		rep[0] = ai[0];
		for(int i = 1; i < N; i++) { ai[i] += ai[i - 1]; rep[i] = ai[i];}	
		// ranking 
		Arrays.sort(rep); 		
		// inversion
		for(int i = 0; i < N; i++) {
			int rank = lower_bound(rep, 0, rep.length, ai[i]);
			out += freqTo(rank); update(rank); if(ai[i]>=0) out++;
		}
		// output
		System.out.println(out);
	}
}