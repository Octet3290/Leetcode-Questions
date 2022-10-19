/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

OJ’s undirected graph serialization:Nodes are labeled uniquely.We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.As an example, consider the serialized graph {0,1,2#1,2#2,2}. The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2. Second node is labeled as 1. Connect node 1 to node 2. Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
*/


//code

public class Solution {
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        if (node == null)
            return null;
        // assumption : this is a undirected connected graph
        LinkedList<UndirectedGraphNode> q = new LinkedList<UndirectedGraphNode>();
        //map contains only copied nodes
        HashMap<Integer, UndirectedGraphNode> map = new HashMap<Integer, UndirectedGraphNode>();
        q.add(node);// in q original nodes
        map.put(node.label, new UndirectedGraphNode(node.label));
        while (q.size() > 0){
            UndirectedGraphNode now = q.pollFirst();
            UndirectedGraphNode copied = map.get(now.label);
            copied.neighbors = new ArrayList<UndirectedGraphNode>();
            for (UndirectedGraphNode n:now.neighbors){
                if (!map.containsKey(n.label)){
                    q.add(n);
                    map.put(n.label, new UndirectedGraphNode(n.label));
                }
                copied.neighbors.add(map.get(n.label));
            }
        }//while
        return map.get(node.label);
    }
}
