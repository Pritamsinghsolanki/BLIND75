/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution
{
public
    Node cloneGraph(Node node)
    {
        if (node == null)
            return null;
        Node[] visited = new Node[105];
        return solve(node, visited);
    }
public
    static Node solve(Node node, Node[] visited)
    {
        if (visited[node.val] != null)
        {
            return visited[node.val];
        }
        Node nodeClone = new Node(node.val);
        visited[node.val] = nodeClone;
        for (Node nbr : node.neighbors)
        {
            Node nbrClone = solve(nbr, visited);
            nodeClone.neighbors.add(nbrClone);
        }
        return nodeClone;
    }
}