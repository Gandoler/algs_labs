#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>


using namespace std;
#define RESET   "\033[0m"
#define RED     "\033[31m"     
#define GREEN   "\033[32m" 


class Lab_2_tasks {
private:
	stack<char> check_math_input;
	string str;
	



	
	~Lab_2_tasks() {
		while (!check_math_input.empty()) {
			check_math_input.pop();
		}

	}

	unsigned long long factorial(int n) {
		if (n == 0 || n == 1) {
			return 1;
		}
		return n * factorial(n - 1);


	}

	double calculate_an(int n) {
		if (n == 0)
			return 1; 
		else
			return static_cast<double>((factorial(n)) / pow(2,n)); 
	}
public:
	Lab_2_tasks() {
		
	}

	void Num_1() {
		while (true) {
			check_math_input = stack<char>(); // Очистка стека перед каждой новой проверкой
			cout << "Enter the string (enter space to exit):\n ";
			getline(cin, str);

			if (str == " ") // Если пользователь ввел пробел, завершаем проверку
				break;

			for (char ch : str) {
				if (ch == '(' || ch == '[' || ch == '{') {
					check_math_input.push(ch);
				}
				else if (ch == ')' || ch == ']' || ch == '}') {
					if (check_math_input.empty()) {
						cerr << RED << "ERROR MISSING OPEN POINT\n\n\n" << RESET;
						return;
					}

					char previous = check_math_input.top();
					check_math_input.pop();
					if ((ch == ')' && previous != '(') ||
						(ch == ']' && previous != '[') ||
						(ch == '}' && previous != '{')) {
						cerr << RED << "ERROR DIFFERENT TYPE POINT\n\n\n" << RESET;
						return;
					}
				}
			}

			if (!check_math_input.empty()) {
				cerr << RED << "ERROR MISSING CLOSE POINT--" << check_math_input.top() << RESET;
				return;
			}

			cout << GREEN << "ALL GOOD)))" << RESET << endl;
		}
	}
	double Num_2() {
		printf("Введите n:\n");
		int n = 0;
		do {
			cin >> n;
		} while (n < 0 or n>100);
		return calculate_an(n);
	}


	
};


struct Edge {
    int src, dest, weight;
};

class Graph {
private:
    int V;
    vector<vector<int>> adjMatrix;

    int find(vector<int>& parent, int i) {
        if (parent[i] == -1)
            return i;
        return find(parent, parent[i]);
    }

    void Union(vector<int>& parent, int x, int y) {
        int xset = find(parent, x);
        int yset = find(parent, y);
        parent[xset] = yset;
    }

    int minKey(vector<int>& key, vector<bool>& inMST) {
        int min = INT_MAX;
        int min_index = -1;
        for (int v = 0; v < V; ++v) {
            if (!inMST[v] && key[v] < min) {
                min = key[v];
                min_index = v;
            }
        }
        return min_index;
    }

    void printMST(vector<Edge>& result) {
        cout << "Edge \tWeight\n";
        for (Edge& edge : result)
            cout << edge.src << " - " << edge.dest << " \t" << edge.weight << endl;
    }
public:
    Graph(int V) {
        this->V = V;
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    void addEdge(int src, int dest, int weight) {
        adjMatrix[src][dest] = weight;
        adjMatrix[dest][src] = weight; 
    }

    void printGraph() {
        cout << "Graph:" << endl;
        cout << "   ";
        for (int i = 0; i < V; ++i)
            cout << i << " ";
        cout << endl;
        for (int i = 0; i < V; ++i) {
            cout << i << "  ";
            for (int j = 0; j < V; ++j)
                cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }

    void KruskalMST() {
        vector<Edge> result;
        vector<Edge> edges;
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (adjMatrix[i][j] != 0) {
                    edges.push_back({ i, j, adjMatrix[i][j] });
                }
            }
        }
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.weight < b.weight;
            });
        vector<int> parent(V, -1);
        for (Edge& edge : edges) {
            int x = find(parent, edge.src);
            int y = find(parent, edge.dest);
            if (x != y) {
                result.push_back(edge);
                Union(parent, x, y);
            }
        }
        cout << "Minimum Spanning Tree (Kruskal's Algorithm):" << endl;
        printMST(result);
    }

    void PrimMST() {
        vector<bool> inMST(V, false);
        vector<int> key(V, INT_MAX);
        vector<int> parent(V, -1);
        key[0] = 0;
        for (int count = 0; count < V - 1; ++count) {
            int u = minKey(key, inMST);
            inMST[u] = true;
            for (int v = 0; v < V; ++v) {
                if (adjMatrix[u][v] != 0 && !inMST[v] && adjMatrix[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = adjMatrix[u][v];
                }
            }
        }
        vector<Edge> result;
        for (int i = 1; i < V; ++i) {
            result.push_back({ parent[i], i, adjMatrix[i][parent[i]] });
        }
        cout << "Minimum Spanning Tree (Prim's Algorithm):" << endl;
        printMST(result);
    }

    void Num_3(Graph graph) {
        graph.addEdge(0, 1, 2);
        graph.addEdge(0, 5, 10);
        graph.addEdge(0, 4, 3);
        graph.addEdge(1, 2, 1);
        graph.addEdge(1, 6, 35);
        graph.addEdge(2, 3, 17);
        graph.addEdge(3, 6, 13);
        graph.addEdge(4, 5, 11);
        graph.addEdge(4, 7, 20);
        graph.addEdge(5, 6, 15);
        graph.addEdge(5, 7, 12);
        graph.addEdge(6, 7, 10);
        graph.printGraph();

        cout << endl;
        graph.KruskalMST();

        cout << endl;
        graph.PrimMST();
    }
};

void Num_3_4() {
    int V = 8;  // Number of vertices
    Graph graph(V);
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 5, 10);
    graph.addEdge(0, 4, 3);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 6, 35);
    graph.addEdge(2, 3, 17);
    graph.addEdge(3, 6, 13);
    graph.addEdge(4, 5, 11);
    graph.addEdge(4, 7, 20);
    graph.addEdge(5, 6, 15);
    graph.addEdge(5, 7, 12);
    graph.addEdge(6, 7, 10);
    graph.printGraph();

    cout << endl;
    graph.KruskalMST();

    cout << endl;
    graph.PrimMST();
}
int main(){
	system("chcp 1251");
	system("cls");
	Lab_2_tasks *laba = new Lab_2_tasks();
	/*(a+{b-c})*[d*(e-f)+g]*/
	/*(a+b*(c-d)*/
	/*(a+b)*{c-[d+e)}*/
	/*(a+b)*(c- d}]*/

	//laba->Num_1();
	//cout<< laba->Num_2()
    
    Num_3_4();
    
	
	
	return 0;
}