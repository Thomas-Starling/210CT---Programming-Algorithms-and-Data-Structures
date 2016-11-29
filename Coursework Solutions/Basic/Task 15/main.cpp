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
                adjacencyMatrix[i][j] = 999;
            }
        }
    }

    void addWeight(int i, int j, int val)
    {
        adjacencyMatrix[i - 1][j - 1] = val;
        cout << "Weight " << val << " added to between node " << i << ", " << j << " Added!" << endl;
    }

    void findShortestPath(int s, int f)
    {
        int current = s - 1;
        bool visited[this->numOfVertex];
        int tentativeWeight[this->numOfVertex];

        for(int i = 0; i < numOfVertex; i++)
        {
            tentativeWeight[i] = 999;
        }
        tentativeWeight[current] = 0;

        while(current != f - 1)
        {
            cout << "->" << current + 1;
            for(int i = 0; i < numOfVertex; i++)
            {
                if(tentativeWeight[current] + adjacencyMatrix[current][i] < tentativeWeight[i])
                {
                    tentativeWeight[i] = tentativeWeight[current] + adjacencyMatrix[current][i];
                }
            }
            visited[current] = true;

            int min = 999;
            for(int i = 0; i < numOfVertex; i++)
            {
                if(!visited[i] && tentativeWeight[i] < min)
                {
                    current = i;
                    min = tentativeWeight[i];
                }
            }
        }
        cout << "->" << current + 1 << endl;
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

    cout << endl;
    g->findShortestPath(1, 4);

    delete g;
    return 0;
}
