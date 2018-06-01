import java.util.*;

public class Graph{
	public static void main(String[] args){
		int matrix[][] = {{0,1,1,1,0,0,0,0,0},
  				  {0,0,0,0,1,0,0,0,0},
				  {0,0,0,0,1,0,1,0,0},
				  {0,0,0,0,0,1,0,0,0},
				  {0,0,0,0,0,0,0,1,0},
				  {0,0,0,0,0,0,0,0,0},
				  {0,0,0,0,0,0,0,0,1},
				  {0,0,0,0,0,0,0,0,0},
				  {0,0,0,0,0,0,0,0,0}};			  
		
		System.out.println("Graph");
		depthFirstTraverse(matrix, 9);
	}
	
	private static boolean visited(int []visitList, int node){
		boolean flag = false;
		for(int i=0; i<visitList.length; i++){
			if(visitList[i] == node){
				flag = true;
				break;
			}
		}
		return flag;
	}
	
	public static void depthFirstTraverse(int[][] matrix, int n){
		int []visitList = new int[n];
		Stack<Integer> stack = new Stack<Integer>();
		stack.push(0);
		int count = 0;
		try{
			while(true){
				int currentNode = stack.pop();
				visitList[count++] = currentNode;
				System.out.println(currentNode);
				for(int i=0; i<n; i++){
					if(!visited(visitList, i) && matrix[currentNode][i] == 1)
						stack.push(i);
				}
			}
		}
		catch(EmptyStackException ex){
			System.out.println("Done");
		}
	}
}
