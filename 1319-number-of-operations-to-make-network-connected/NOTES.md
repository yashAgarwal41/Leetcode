* m->no of edges(cables), n->no of nodes(computers)..
* to connect all computers in a network, [min no of cables = no of computers - 1]
*  so first find no of components in the network(i.e, no of disconnected graphs)..
*  To calculate **no of components = how many times 'dfs' function get called from the main function**
* then min no of cables extract will be needed to connect those disconnected networks..
* ans = NumberOfComponents - 1;