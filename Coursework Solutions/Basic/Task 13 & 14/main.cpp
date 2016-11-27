#include <iostream>
#include <array>
#include <fstream>
#include <stack>
#include <queue>

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

    void Depth(int v)
    {
        ofstream output;
        output.open ("depth.txt", fstream::out);
        
        bool visited[this->numOfVertex];
        for(int i = 0; i < numOfVertex; i++)
        {
            visited[i] = 0;
        }
        
        v -= 1;
        
        stack<int> stack;
        visited[v] = 1;
        stack.push(v);

        while (!stack.empty())
        {
            v = stack.top();
            cout << v + 1 << " ";
            output << v + 1 << " ";
            stack.pop();
            
            for (int i = 0; i < numOfVertex; ++i)
            {
                if (!visited[i] && adjacencyMatrix[v][i] == 1)
                {
                    visited[i] = 1;
                    stack.push(i);
                }
            }
        }
        output.close();
        cout << endl;
    }
    
    void Breadth(int v)
    {
        ofstream output;
        output.open ("breadth.txt", fstream::out);
        
        bool visited[this->numOfVertex];
        for(int i = 0; i < numOfVertex; i++)
        {
            visited[i] = 0;
        }
        
        v -= 1;
        
        queue<int> queue;
        visited[v] = true;
        queue.push(v);
        
        while(!queue.empty())
        {
            v = queue.front();
            cout << v + 1 << " ";
            output << v + 1 << " ";
            queue.pop();

            for(int i = 0; i < numOfVertex; i++)
            {
                if(!visited[i] && adjacencyMatrix[v][i] == 1)
                {
                    visited[i] = 1;
                    queue.push(i);
                }
            }
        }
        output.close();
        cout << endl;
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
    g->addEdge(2, 4);
    g->addEdge(2, 3);
    g->printGraph();

    cout << endl;

    g->addVertex(6);
    g->addEdge(4, 5);
    g->addEdge(5, 1);
    g->addEdge(1, 6);
    g->printGraph();
    
    g->printGraph();

    g->printConnections();
    
    g->Depth(6);
    g->Breadth(3);

    delete g;
    return 0;
}
