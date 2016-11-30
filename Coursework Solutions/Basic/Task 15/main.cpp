#include <iostream>
#include <array>
#include <vector>

using namespace std;

class Dijkstra
{
private:
    int numOfVertex;
    int adjacencyMatrix[4][4];
public:
    Dijkstra(int numOfVertex)
    {
        this->numOfVertex = numOfVertex;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                adjacencyMatrix[i][j] = 999;    //Fill the matrix with inf or 999
            }
        }
    }

    void addWeight(int i, int j, int val)
    {
        adjacencyMatrix[i - 1][j - 1] = val;    //Add the weight between the edges i and j
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
        int current = s - 1;
        bool visited[this->numOfVertex];
        int tentativeWeight[this->numOfVertex];

        for(int i = 0; i < numOfVertex; i++)    //Fill the weights array with inf
        {
            tentativeWeight[i] = 999;
        }
        tentativeWeight[current] = 0;   //Mark the current index in the weight array with 0

        while(current != f - 1) //While current isn't equal to the param
        {
            cout << "->" << current + 1;    //Print the connections
            for(int i = 0; i < numOfVertex; i++)
            {
                if(tentativeWeight[current] + adjacencyMatrix[current][i] < tentativeWeight[i]) //If the index in the weight sequence + the adjacencyMatrix row of current with i as column is less than the weight sequence at index i
                {
                    tentativeWeight[i] = tentativeWeight[current] + adjacencyMatrix[current][i];    //Take that addition and place it into the array
                }
            }
            visited[current] = true;    //Mark as visited

            int min = 999;  //Set min to inf
            for(int i = 0; i < numOfVertex; i++)
            {
                if(!visited[i] && tentativeWeight[i] < min) //If not visited and the weight sequence at index i is less than min
                {
                    current = i;    //Current now become i
                    min = tentativeWeight[i];   //Min becomes the index of i in the weight array
                }
            }
        }
        cout << "->" << current + 1 << endl;    //Print the last computed edge
    }

    ~Dijkstra()
    {
        std::cout << "Destructor" << std::endl;
    }
};

int main()
{
    Dijkstra *g = new Dijkstra(4);

    /*                                                      */
    /*             ***********       ***********            */
    /*             *         *       *         *            */
    /*             *         *       *         *            */
    /*             *     1   ZZZZZZZZZ    2    *            */
    /*             *         *       *         *            */
    /*             *         *       *         *            */
    /*             *****Z*****      ZZ****Z*****            */
    /*                  Z        ZZZ      Z                 */
    /*                  Z      ZZ         Z                 */
    /*             *****Z****ZZ      *****Z*****            */
    /*             *         *       *         *            */
    /*             *         *       *         *            */
    /*             *    3    ZZZZZZZZZ    4    *            */
    /*             *         *       *         *            */
    /*             *         *       *         *            */
    /*             ***********       ***********            */
    /*                                                      */
    
    g->addWeight(1, 2, 7);  //Change to 8 for a different and chanage again to 7 for another order
    g->addWeight(1, 3, 5);
    g->addWeight(2, 4, 5);
    g->addWeight(2, 3, 4);
    g->addWeight(3, 4, 2);

    g->printGraph();
    
    g->findShortestPath(1, 4);

    delete g;
    return 0;
}
