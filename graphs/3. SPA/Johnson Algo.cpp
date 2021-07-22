/**
*	JOHNSONS ALGORITHM
*/

https://www.geeksforgeeks.org/johnsons-algorithm/


The idea of Johnson’s algorithm is to re-weight all edges and make them all positive, 
then apply Dijkstra’s algorithm for every vertex.

One may think of a simple approach of finding the minimum weight edge 
and adding this weight to all edges. Unfortunately, this doesn’t work 
as there may be different number of edges in different paths 

 A new vertex is added to the graph and connected to all existing vertices. 
The shortest distance values from new vertex to all existing vertices are h[] values.

STEPS:
1. Let the given graph be G. Add a new vertex s to the graph, add edges from new vertex to all vertices of G.
2. Run Bellman-Ford algorithm on G’ with s as source. Let the distances calculated by Bellman-Ford be h[0], h[1], .. h[V-1]. 
3. Reweight the edges of original graph. For each edge (u, v), assign the new weight as “original weight + h[u] – h[v]”
4. Remove the added vertex s and run Dijkstra’s algorithm for every vertex
