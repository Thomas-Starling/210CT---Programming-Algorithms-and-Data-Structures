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
        this->numOfVertex = numOfVertex;    //Point to the instance in the class to set the number
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                adjacencyMatrix[i][j] = 0;  //Fill the array with 0's
            }
        }
    }

    void addVertex(int i)
    {
        numOfVertex = i;    //Change the number of vertices to i so now it will only print to that number
        
        for(int k = i; k <= numOfVertex + i; k++)
        {
            for(int j = 0; j < numOfVertex; j++)
            {
                adjacencyMatrix[k][j] = 0;  //Fill the new line with 0's
            }
        }
    }

    void addEdge(int i, int j)
    {
        adjacencyMatrix[i - 1][j - 1] = 1;  //Add an edge one way
        adjacencyMatrix[j - 1][i - 1] = 1;  //Add an edge the other way to make it undirected
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
        output.open ("depth.txt", fstream::out);    //Create the file
        
        bool visited[this->numOfVertex];    //Create sequence with the length of number of vertices
        for(int i = 0; i < numOfVertex; i++)
        {
            visited[i] = 0; //Fill viisted with 0's
        }
        
        v -= 1; //-1 since it's the way I have designed it
        
        stack<int> stack;
        visited[v] = 1; //True that the current paramenter is visited
        stack.push(v);  //Push the param to the stack

        while (!stack.empty())
        {
            v = stack.top();    //Get the top of the stack's element
            cout << v + 1 << " ";
            output << v + 1 << " "; //Write to the file
            stack.pop();    //Pop it off the stack
            
            for (int i = 0; i < numOfVertex; ++i)
            {
                if (!visited[i] && adjacencyMatrix[v][i] == 1)  //If its hasnt been visited and the row of the param and column of i is equal to 1
                {
                    visited[i] = 1; //Mark as visited
                    stack.push(i);  //Push to the stack
                }
            }
        }
        output.close(); //Close the file
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
