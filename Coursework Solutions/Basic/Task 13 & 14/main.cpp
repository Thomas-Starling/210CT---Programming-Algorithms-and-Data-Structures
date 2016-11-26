#include <iostream>
#include <array>
#include <fstream>

using namespace std;

class Graph
{
private:
    int numOfVertex;
    bool adjacencyMatrix[10][10];
public:
    Graph(int numOfVertex)
    {
        this->numOfVertex = numOfVertex;
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                adjacencyMatrix[i][j] = 0;
            }
        }
    }

    void addVertex(int i)
    {
        numOfVertex = i;
        
        for(int k = i; k <= numOfVertex + i; k++)
        {
            for(int j = 0; j < numOfVertex; j++)
            {
                adjacencyMatrix[k][j] = 0;
            }
        }
    }

    void addEdge(int i, int j)
    {
        adjacencyMatrix[i - 1][j - 1] = 1;
        adjacencyMatrix[j - 1][i - 1] = 1;
        cout << "Edge " << i << " to " << j << " Added!" << endl;
    }

    void printGraph()
    {
        cout << endl << "Printing Graph...." << endl << "  ";
        for(int k = 0; k < numOfVertex; k++)
        {
            cout << k + 1 << " ";
        }
        cout << endl;

        for(int i = 0; i < numOfVertex; i++)
        {
            cout << i + 1 << "|";
            for(int j = 0; j < numOfVertex; j++)
            {
                cout << adjacencyMatrix[i][j] << " " ;
            }
            cout << endl;
        }
    }

    void printConnections()
    {
        cout << endl;
        for(int i = 0; i < numOfVertex; i++)
        {
            for(int j = 0; j < numOfVertex; j++)
            {
                if(adjacencyMatrix[i][j] == 1)
                {
                    cout << "Vertex " << i + 1 << " is connnected to vertex " << j + 1 << endl;
                }
            }
        }
        cout << endl;
    }

    void Breadth()
    {
        ofstream output;
        output.open ("breadth.txt");
        output << "";
        output.close();
    }

    void Depth()
    {
        ofstream output;
        output.open ("depth.txt");
        output << "";
        output.close();
    }

    ~Graph()
    {
        std::cout << "Destructor" << std::endl;
    }
};

int main()
{
    Graph *g = new Graph(5);

    g->addEdge(1, 2);
    g->addEdge(2, 3);
    g->addEdge(4, 1);
    g->addEdge(5, 2);
    g->printGraph();

    cout << endl;

    g->addVertex(6);
    g->addEdge(6, 4);
    g->printGraph();

    cout << endl;

    g->addVertex(7);
    g->addEdge(7, 3);
    g->printGraph();

    g->printConnections();

    delete g;
    return 0;
}
