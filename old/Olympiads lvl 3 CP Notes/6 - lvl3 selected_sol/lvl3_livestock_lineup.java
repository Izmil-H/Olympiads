import java.util.*;
public class homework {
	public static void main(String [] args) {
		Scanner in = new Scanner(System.in);
		String a[] = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
		Arrays.sort(a);
		int n = in.nextInt(); in.nextLine();
		String p[] = new String[n], q[] = new String[n];
		for(int i=0; i<n; i++) {
			String s[] = in.nextLine().split(" ");
			p[i] = s[0]; q[i] = s[5];
		}
		do {
			boolean flag = true;
			for(int i=0; i<n; i++) {
				if(Math.abs(getIndex(a, p[i]) - getIndex(a, q[i])) != 1) { flag = false; break; } 
			}
			if(flag) {
				for(int i=0; i<a.length; i++) System.out.println(a[i]);
				break;
			}
		}while(next_permutation(a));
	}
	static int getIndex(String a[], String name) {
		for(int i=0; i<a.length; i++)
			if(a[i].equals(name)) return i;
		return 0;
	}
	static boolean next_permutation(String a[]) {
		if(a.length <= 1) return false;
		int p = a.length - 2;
		while(p>=0 && a[p].compareTo(a[p+1]) >= 0 ) p--;
		if(p < 0) return false;
		int q = a.length - 1;
		while(a[q].compareTo(a[p])<=0) q--;
		String tmp = a[p]; a[p] = a[q]; a[q] = tmp;
		for(int l=p+1, r = a.length-1; l<r; l++, r--) {
			tmp = a[l]; a[l] = a[r]; a[r] = tmp;
		}
		return true;
	}
}