
import java.util.ArrayList;

/**
 *
 * @author Milan
 */
class Graph {

    final private int numberOfNode;
    private int[][] graph;
    private int[] parent;
    boolean[] visited;

    Graph(int[][] matrix) {
        graph = matrix;
        numberOfNode = graph.length;
        parent = new int[numberOfNode];
        visited = new boolean[numberOfNode];
    }

    public int mstPrimes(int sorce) {
        int Cost = 0, CurrentNode = sorce, ParentNode = Integer.MAX_VALUE;
        ArrayList<Integer> ConsideredEdge = new ArrayList<>();
        visited[sorce] = true;
        for (int count = 0; count < numberOfNode; count++) {

            for (int i = 0; i < numberOfNode; i++) {
                int var = graph[CurrentNode][i];
                ConsideredEdge.add(i + (count * numberOfNode), var);
            }

            int[] NodeWithMinimumCost = minWithIndex(ConsideredEdge);
            Cost += NodeWithMinimumCost[0];
            parent[CurrentNode] = ParentNode;
            CurrentNode = NodeWithMinimumCost[1];
            ParentNode = NodeWithMinimumCost[2];
            visited[CurrentNode] = true;
        }

        return Cost;
    }

    public void printMST() {
        System.out.print("MST: \nNode --> Reach From Node(Parent Node)\n");
        for (int i = 0; i < numberOfNode; i++) {
            System.out.printf("%d --> %d\n", i, parent[i]);
        }
    }

    private int[] minWithIndex(ArrayList<Integer> AL) {
        int[] Answer = new int[3];
        Answer[0] = Integer.MAX_VALUE;
        boolean flag = false;
        for (int i = 0; i < AL.size(); i++) {
            if (AL.get(i) != 0 && !visited[i % numberOfNode] && Answer[0] > AL.get(i)) {
                Answer[0] = AL.get(i);
                Answer[1] = i % numberOfNode;
                Answer[2] = i / numberOfNode;
                flag = true;
            }
        }

        if (flag) {
            return Answer;
        } else {
            Answer[0] = 0;
            return Answer;
        }
    }
}

public class Prims {

    public static void main(String[] args) {

        int graph[][] = new int[][]{
            {0, 10, 9, 4, 2},
            {10, 0, 20, 3, Integer.MAX_VALUE},
            {9, 20, 0, Integer.MAX_VALUE, 5},
            {4, 3, Integer.MAX_VALUE, 0, Integer.MAX_VALUE},
            {2, Integer.MAX_VALUE, 5, Integer.MAX_VALUE, 0}
        };

        /*FOR ANALYSIS:*/ long startTime = System.currentTimeMillis();

        Graph G1 = new Graph(graph);
        int Cost = G1.mstPrimes(0);

        /*FOR ANALYSIS:*/ long endTime = System.currentTimeMillis();

        System.out.printf("cost %d\n", Cost);
        G1.printMST();
        /*FOR ANALYSIS:*/ long executionTime = endTime - startTime;

        /*FOR ANALYSIS:*/ System.out.println("Total Execution Time: " + executionTime + " ms");
    }
}
