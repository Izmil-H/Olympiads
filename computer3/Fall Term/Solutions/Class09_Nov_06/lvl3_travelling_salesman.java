import java.util.*;
public class graph3p1 {
	public static void main(String [] args){
		Scanner in = new Scanner(System.in);
		int N = in.nextInt(), M = in.nextInt();
		ArrayList [] graph = new ArrayList [N+1];
		for(int i=0; i<=N; i++)
			graph[i] = new ArrayList<>();
		for(int i=0; i<M; i++){
			int u=in.nextInt(), v=in.nextInt();
			graph[u].add(v); graph[v].add(u);
		}
		Queue<Integer> Q = new LinkedList<>();
		int [] time = new int [N+1];
		boolean [] vis = new boolean [N+1];
		int C = in.nextInt(), ans = 0;
		for(int i=0; i<C; i++){
			int u = in.nextInt();
			Q.add(u); vis[u]=true; time[u]=0;
		}
		while(!Q.isEmpty()){
			int u = Q.poll();
			for(int v: (ArrayList<Integer>) graph[u]){
				if(!vis[v]){
					Q.add(v); vis[v]=true; 
					time[v]=time[u]+1;
					ans = Math.max(ans, time[v]);
				}
			}
		}
		System.out.println(ans);
	}
}