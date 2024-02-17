#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// QUICKSORT
// Time complexity: O(n log n)
// Space complexity:  O(1)
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

// MERGESORT
// Time complexity: O(n log n)
// Space complexity:  O(n)
const int MAX_SIZE = 100;
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[MAX_SIZE], R[MAX_SIZE];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        // Same as (left+right)/2, but avoids overflow for large left and right
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

/*
MERGESORT CASE USES:
- Large datasets (millions>)
- Partialy sorted data
- Memory it's not a concern
- Perserving order of equal elements !?

QUICKSORT CASE USES:
- Faster for small datsets (thousands>)
- Simpler implementation
- Cache locality (potential performance gains)
*/

// BFS (Va por niveles)
// Time complexity: O(V + E) *V = vertices & E = edges
// Space complexity:  O(V)
void BFS(int start, vector<bool> &visited, const vector<vector<int>> &graph)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        // Process the current node
        // Ej. print ...

        for (int neighbor : graph[current])
        {
            if (!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

// DFS Recursive
// Time complexity: O(V + E) *V = vertices & E = edges
// Space complexity:  O(H) *H = max depth
void DFS(const vector<vector<int>> &graph, int node, vector<bool> &visited)
{
    visited[node] = true;

    // Process the current node
    // Ej. print ...

    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
        {
            DFS(graph, neighbor, visited);
        }
    }
}

// DFS iterative
// Time complexity: O(V + E) *V = vertices & E = edges
// Space complexity:  O(H) *H = max depth
void DFS(const vector<vector<int>> &graph, int node)
{
    stack<int> s;
    s.push(node);
    vector<bool> visited(graph.size(), false);

    while (!s.empty())
    {
        int node = s.top();
        s.pop();

        if (!visited[node])
        {
            visited[node] = true;

            // Process the current node
            // Ej. print ...

            for (int neighbor : graph[node])
            {
                if (!visited[neighbor])
                {
                    s.push(neighbor);
                }
            }
        }
    }
}

/*
DFS recursive USE CASE:
- Easier to implement
- No aditional data structure

* For small graphs

DFS iterative USE CASE:
- More efficient
- More scalable (large graphs)
- Easier to debug
- Lower memory usage

* For larger graphs
* Performance-critical apps
* Memory limited
*/

/*
DFS USE CASE:
- Detecting cyles
- Finding longest path
- Topological sorting

BFS USE CASE:
- Finding the shortest path
- Searching for specific nodes at certain depth
- Can efficiently determine if all nodes are reachable from a starting point
- Identify separate connected components within the graph.
*/

// BINARY SEARCH TREE(BST) || Extra: AVL & RED-BLACK Tree
// Balanced tree:
// Time complexity: O(log n)
// Space complexity:  O(n)

// Unbalanced tree:
// Time complexity: O(n)
// Space complexity:  O(n)
struct Node
{
    int value;
    Node *left;
    Node *right;

    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value)
    {
        root = insert(root, value);
    }

    bool search(int value)
    {
        return search(root, value);
    }

    void inorderTraversal()
    {
        inorderTraversal(root);
    }

private:
    Node *root;

    Node *insert(Node *node, int value)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }

        if (value < node->value)
        {
            node->left = insert(node->left, value);
        }
        else
        {
            node->right = insert(node->right, value);
        }

        return node;
    }

    bool search(Node *node, int value)
    {
        if (node == nullptr)
        {
            return false;
        }

        if (value == node->value)
        {
            return true;
        }
        else if (value < node->value)
        {
            return search(node->left, value);
        }
        else
        {
            return search(node->right, value);
        }
    }

    void inorderTraversal(Node *node)
    {
        if (node == nullptr)
            return;

        inorderTraversal(node->left);
        inorderTraversal(node->right);
    }
};

// ARRAY
int numbers[5];
string names[3] = {"Alice", "Bob", "Charlie"};

for (int i = 0; i < 5; ++i)
{
    cout << numbers[i] << " ";
}

// Or using iterators:
for (auto it = names.begin(); it != names.end(); ++it)
{
    std::cout << *it << " ";
}

// Row:3 & Col:2
int matrix[3][2] = {{1, 2}, {3, 4}, {5, 6}};

// VECTOR
vector<int> numbers;       // Empty vector
vector<int> values(10, 0); // 10 members with value 0
vector<string> names = {"Alice", "Bob", "Charlie"};

for (auto it = numbers.begin(); it != numbers.end(); ++it)
{
    cout << *it << " ";
}

for (int num : numbers)
{
    cout << num << " ";
}

numbers.push_back(10);                    // Add an element to the end
names.insert(names.begin() + 1, "Emily"); // Insert an element at position 1
numbers.erase(numbers.begin() + 2);       // Remove element at position 2

//TREE
/*
Types of trees:
- Binary Tree: Each node has two childs (left & right)
- Bianry Search Tree (BST): Same than previous, but the value of left leaf is lower than the parent, and the right one is greater than the parent 
- AVL Tree: BST that is self-balancing, and mantains a specific height.
- Red-Black Tree: BST that  uses color coding to enforce balance properties.
- N-ary Tree: Each node have more than two child nodes
*/

//GRAPHS
