#include <iostream>
#include <array>
#include <stack>
#include <queue>

using namespace std;

class Dijkstra
{
private:
    int numOfVertex;
    int adjacencyMatrix[5][5];
public:
    Dijkstra(int numOfVertex)
    {
        this->numOfVertex = numOfVertex;
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                adjacencyMatrix[i][j] = -1;
            }
        }
    }
    
    void addWeight(int i, int j, int val)
    {
        adjacencyMatrix[i - 1][j - 1] = val;
        adjacencyMatrix[j - 1][i - 1] = val;
        cout << "Weight " << val << " added to between node " << i << ", " << j << " Added!" << endl;
    }
    
    void printGraph()
    {
        cout << endl << "Printing Graph...." << endl;

        for(int i = 0; i < numOfVertex; i++)
        {
            for(int j = 0; j < numOfVertex; j++)
            {
                cout << adjacencyMatrix[i][j] << " " ;
            }
            cout << endl;
        }
    }
    
    void findShortestPath(int s, int f)
    {
        int current = s;
        int visited[this->numOfVertex];
        visited[current] = true;
        
        while(current != f)
        {
            for(int i = 0; i < numOfVertex; i++)
            {
                if(!visited[i] && (adjacencyMatrix[current][i] > 0))
                {
                    
                }
            }
        }
    }
    
    ~Dijkstra()
    {
        std::cout << "Destructor" << std::endl;
    }
};

int main()
{
    Dijkstra *g = new Dijkstra(5);
    
    g->addWeight(1, 2, 3);
    g->addWeight(2, 4, 2);
    g->addWeight(2, 3, 5);
    g->addWeight(4, 5, 1);
    g->addWeight(5, 7, 3);
    
    g->printGraph();
    g->findShortestPath(1, 6);
    
    delete g;
    return 0;
}
