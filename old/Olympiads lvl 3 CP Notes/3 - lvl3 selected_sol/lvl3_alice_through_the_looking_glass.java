import java.util.*;
public class Test {
	public static void main(String [] args){
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int i=0; i<T; i++){
			int m = in.nextInt(), x = in.nextInt(), y = in.nextInt();
			if(solve(m, x, y)) System.out.println("crystal");
			else System.out.println("empty");
		}
	}
	static boolean solve(int m, int x, int y){
		if(m == 1){
			if((y==0 && x>=1 && x<=3) || (x==2 && y==1)) return true;
			else return false;
		}
		int s = (int)Math.pow(5, m-1), bx = x/s, by = y/s;
		if((by==0 && bx>=1 && bx<=3) || (bx==2 && by==1)) return true;
		else if((by==1 && (bx==1 || bx==3)) || (by==2 && bx==2))
			return solve(m-1, x % s, y % s);
		else return false;
	}
}