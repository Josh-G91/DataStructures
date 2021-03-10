#include <fstream>
#include <iostream>
#include <cstring>
#include "Graph.h"
#include "stack.h"
using namespace std;

Graph::Graph()
{
    nodes = new Vertex[SIZE];
    visited = new bool[SIZE];
    maxVertices = 0;
    for(int i=0; i<SIZE; i++)
        for(int j=0; j<SIZE; j++)
            AdjMatrix[i][j] = 0;
    
};

Graph::~Graph()
{
    delete [] nodes;
    delete [] visited;
    
}
void Graph::createGraph()
{
    
    ifstream inFile;
    
    inFile.open("GraphData.txt", ifstream::in);
    
    if(!inFile.is_open())
        cout << "Unable to open file GraphData.txt" << endl;
    
    else
        addVertandEdges(inFile, AdjMatrix);
    
    
    inFile.close();
    
}
void Graph::addVertandEdges(std::ifstream & inF, int AdjMatrix[SIZE][SIZE])
{
    
    
    int numEdges, adjVertex, vertIndex;
    
    inF >> maxVertices;
    while(!inF.eof())
    {
        
        inF >> vertIndex;
        nodes[vertIndex].index = vertIndex;
        assignCity(vertIndex);
        inF >> numEdges;
        for(int i = 0; i < numEdges; i++)
        {
            
            inF >> adjVertex;
            inF >> Distance;
            AdjMatrix[vertIndex][adjVertex] = Distance;
        }
    }
    
}

void Graph::assignCity(int nodeIndex)
{
    
    
    if(nodeIndex == 0)
        strcpy(nodes[0].cName, "Los Angeles");
    else if(nodeIndex == 1)
        strcpy(nodes[1].cName, "San Diego");
    else if(nodeIndex == 2)
        strcpy(nodes[2].cName, "Portland");
    else if(nodeIndex == 3)
        strcpy(nodes[3].cName, "Las Vegas");
    else if(nodeIndex == 4)
        strcpy(nodes[4].cName, "San Francisco");
    else if (nodeIndex == 5)
        strcpy(nodes[5].cName, "Seattle");
    else if (nodeIndex == 6)
        strcpy(nodes[6].cName, "Berkeley");
    else
        strcpy(nodes[7].cName, "Denver");
    
}
int Graph::getDistance(int current, int end)
{
    
    if(DirectFlight(end, current))
    {
        Distance = AdjMatrix[end][current];
        
    }
    else
    {
        Distance = AdjMatrix[current][end];
        
    }
    return Distance;
}

void Graph::SelectDepCity()
{
    
    int num = 0;
    int choice;
    int valueinGraph;
    
    for(int i=0; i<maxVertices; i++)
    {
        ++num;
        cout << num << "." << nodes[i].cName << endl;
    }
    cin >> choice;
    
    valueinGraph = choice - 1;
    
    SelectDestCity(valueinGraph);
    
};
void Graph::SelectDestCity(int depVert)
{
    Vertex *temp = new Vertex[SIZE];
    
    for(int i=0; i<maxVertices; i++)
        strcpy(temp[i].cName, nodes[i].cName);
    
    int choice;
    int destVert;
    int count = 1;
    cout << "Select Destination City: " << endl;
    
    for(int i=0; i<maxVertices; i++)
    {
        if (i == depVert)
            strcpy(temp[i].cName, " ");
        
        cout << count << "." << temp[i].cName << endl;
        count++;
    }
    
    cin >> choice;
    
    
    destVert = choice - 1;
    
    DepthFirstSearch(depVert, destVert);
    
    delete [] temp;
    
}
bool Graph::DirectFlight(int startV, int endV)
{
    
    if( AdjMatrix[startV][endV] > 0)
        return true;
    else
        return false;
    
}

void Graph::resetVisited()
{
    for(int i = 0; i < maxVertices; i++)
        visited[i] = false;
}

int Graph::getUnvisited(int current)
{
    int nextNode;
    
    for (nextNode = 0; nextNode < maxVertices; nextNode++)
    {
        if ( AdjMatrix[current][nextNode] > 0 && visited[nextNode] == false )
        {
            return nextNode;
            
        }
    }
    
    return -1;
}

void Graph::DepthFirstSearch(int startV, int endV)
{
    
    Stack stack;
    double totalDistance = 0;
    string path = "";
    bool morePaths = false;
    
    
    visited[startV] = true;
    stack.Push(startV);
    
    while (!stack.IsEmpty())
    {
        int current, nextNode;
        
        current = stack.Top();
        nextNode = getUnvisited(current);
        totalDistance += (double)getDistance(current, nextNode);
        
        if(nextNode != -1)
        {
            visited[nextNode] = true;
            stack.Push(nextNode);
            
            if(nextNode == endV)
            {
                path += "";
                
                if(path != "")
                {
                    morePaths = true;
                    cout << "Through connection between " << nodes[startV].cName << " and " << nodes[endV].cName << " via" << path << " " << totalDistance << " miles" <<  endl;
                }
                
            }
            else
            {
                path = path + " " + nodes[nextNode].cName;
            }
            
        }
        else
            stack.Pop();
    }
    resetVisited();
    
    if(DirectFlight(startV, endV) && !morePaths)
    {
        cout << "Direct Connection Between " << nodes[startV].cName << " and " << nodes[endV].cName << " "<< endl;
        cout << "No Through Connection Between " << nodes[startV].cName << " and " << nodes[endV].cName << " "<< endl;
        
    }
    
    else if (!DirectFlight(startV, endV) && !morePaths)
        cout << "No Direct or Through Connection between " << nodes[startV].cName << " and " << nodes[endV].cName << endl;
    
    path.clear();
}