#ifndef Graph_h
#define Graph_h
#include <fstream>
const int SIZE = 10;
struct Vertex
{
    int index;
    char cName[80];
    
};

class Graph
{
    
private:
    Vertex* nodes;
    bool *visited;
    int AdjMatrix[SIZE][SIZE];
    int Distance, maxVertices;
    
public:
    Graph();
    ~Graph();
    void createGraph();
    void addVertandEdges(std::ifstream&, int AdjMatrix[SIZE][SIZE]);
    void assignCity(int);
    void SelectDepCity();
    void SelectDestCity(int);
    void addConnection(int);
    void resetVisited();
    bool DirectFlight(int, int);
    void DepthFirstSearch(int, int);
    int getUnvisited(int);
    int getDistance(int, int);
    
};

#endif /* Graph_h */
