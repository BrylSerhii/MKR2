#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

/*Реалізуйте n-арне дерево для цілих чисел та функцію для генерування рандомного дерева з заданою кількістю вузлів.
Додатково імплементуйте функцію для прямого порядку обходу дерева. Вивести в консоль обхід згенерованого дерева*/

using namespace std;

class Node {
public:
    int data;
    vector<Node*> children;

    explicit Node(int value) : data(value) {}
};

class NTree {
public:
    Node* root;

    explicit NTree(int value) {
        root = new Node(value);
    }

    void addChild(Node* parent, int value) {
        Node* child = new Node(value);
        parent->children.push_back(child);
    }

    void preorderTraversal(Node* node) {
        if (!node) {
            return;
        }

        cout << node->data << " ";

        for (Node* child : node->children) {
            preorderTraversal(child);
        }
    }
};

NTree generateRandomTree(int numNodes) {
    srand(time(NULL));

    NTree tree(rand() % 100 + 1);

    vector<Node*> nodeQueue;
    nodeQueue.push_back(tree.root);

    while (nodeQueue.size() < numNodes) {
        Node* parent = nodeQueue.front();
        nodeQueue.erase(nodeQueue.begin());

        int numChildren = rand() % 4 + 1;

        for (int i = 0; i < numChildren; i++) {
            int value = rand() % 100 + 1;
            tree.addChild(parent, value);
            nodeQueue.push_back(parent->children.back());
        }
    }

    return tree;
}

int main() {
    int numNodes;
    cout << "Enter the number of nodes in the tree: ";
    cin >> numNodes;

    NTree tree = generateRandomTree(numNodes);

    cout << "Preorder Traversal: ";
    tree.preorderTraversal(tree.root);
    cout << endl;

    return 0;
}
