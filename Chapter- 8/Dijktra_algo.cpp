#include <iostream>
#include <vector>

#define INT_MAX 10000000

using namespace std;

void Dijkstras_Algo();

int main() {
  Dijkstras_Algo();
  return 0;
}

class Node;
class Edge;

void Dijkstra();
vector<Node*>* Adjacent_RemainingNodes(Node* node);
Node* extract_Smallest(vector<Node*>& nodes);
int Distance(Node* node1, Node* node2);
bool contains(vector<Node*>& nodes, Node* node);
void Print_ShortestRouteTo(Node* destination);

vector<Node*> nodes;
vector<Edge*> edges;

class Node {
   public:
  Node(char id)
    : id(id), previous(NULL), distance_FromStart(INT_MAX) {
    nodes.push_back(this);
  }

   public:
  char id;
  Node* previous;
  int distance_FromStart;
};

class Edge {
   public:
  Edge(Node* node1, Node* node2, int distance)
    : node1(node1), node2(node2), distance(distance) {
    edges.push_back(this);
  }
  bool Connects(Node* node1, Node* node2) {
    return (
      (node1 == this->node1 &&
       node2 == this->node2) ||
      (node1 == this->node2 &&
       node2 == this->node1));
  }

   public:
  Node* node1;
  Node* node2;
  int distance;
};

void Dijkstras_Algo() {
  Node* A = new Node('A');
  Node* B = new Node('B');
  Node* C = new Node('C');
  Node* D = new Node('D');
  Node* E = new Node('E');



  Edge* e1 = new Edge(A, B, 10);
  Edge* e2 = new Edge(A, C, 3);
  Edge* e3 = new Edge(B, C, 1);
  Edge* e4 = new Edge(B, D, 2);
  Edge* e5 = new Edge(C, B, 4);
  Edge* e6 = new Edge(C, D, 8);
  Edge* e7 = new Edge(C, E, 2);
  Edge* e8 = new Edge(D, E, 7);
  Edge* e9 = new Edge(E, D, 9);

  A->distance_FromStart = 0;
  Dijkstra();
  Print_ShortestRouteTo(E);
}

void Dijkstra() {
  while (nodes.size() > 0) {
    Node* smallest = extract_Smallest(nodes);
    vector<Node*>* Adjacent_Nodes =
      Adjacent_RemainingNodes(smallest);

    const int size = Adjacent_Nodes->size();
    for (int i = 0; i < size; ++i) {
      Node* adjacent = Adjacent_Nodes->at(i);
      int distance = Distance(smallest, adjacent) +
               smallest->distance_FromStart;

      if (distance < adjacent->distance_FromStart) {
        adjacent->distance_FromStart = distance;
        adjacent->previous = smallest;
      }
    }
    delete Adjacent_Nodes;
  }
}

Node* extract_Smallest(vector<Node*>& nodes) {
  int size = nodes.size();
  if (size == 0) return NULL;
  int smallestPosition = 0;
  Node* smallest = nodes.at(0);
  for (int i = 1; i < size; ++i) {
    Node* current = nodes.at(i);
    if (current->distance_FromStart <
      smallest->distance_FromStart) {
      smallest = current;
      smallestPosition = i;
    }
  }
  nodes.erase(nodes.begin() + smallestPosition);
  return smallest;
}

vector<Node*>* Adjacent_RemainingNodes(Node* node) {
  vector<Node*>* Adjacent_Nodes = new vector<Node*>();
  const int size = edges.size();
  for (int i = 0; i < size; ++i) {
    Edge* edge = edges.at(i);
    Node* adjacent = NULL;
    if (edge->node1 == node) {
      adjacent = edge->node2;
    } else if (edge->node2 == node) {
      adjacent = edge->node1;
    }
    if (adjacent && contains(nodes, adjacent)) {
      Adjacent_Nodes->push_back(adjacent);
    }
  }
  return Adjacent_Nodes;
}

int Distance(Node* node1, Node* node2) {
  const int size = edges.size();
  for (int i = 0; i < size; ++i) {
    Edge* edge = edges.at(i);
    if (edge->Connects(node1, node2)) {
      return edge->distance;
    }
  }
  return -1;
}

bool contains(vector<Node*>& nodes, Node* node) {
  const int size = nodes.size();
  for (int i = 0; i < size; ++i) {
    if (node == nodes.at(i)) {
      return true;
    }
  }
  return false;
}

void Print_ShortestRouteTo(Node* destination) {
  Node* previous = destination;
  cout << "DISTANCE from Start: "
     << destination->distance_FromStart << endl;
  while (previous) {
    cout << previous->id << " ";
    previous = previous->previous;
  }
  cout << endl;
}

vector<Edge*>* Adjacent_Edges(vector<Edge*>& Edges, Node* node);
void Remove_Edge(vector<Edge*>& Edges, Edge* edge);

vector<Edge*>* Adjacent_Edges(vector<Edge*>& edges, Node* node) {
  vector<Edge*>* Adjacent_Edges = new vector<Edge*>();

  const int size = edges.size();
  for (int i = 0; i < size; ++i) {
    Edge* edge = edges.at(i);
    if (edge->node1 == node) {
      cout << "ADJACENT: " << edge->node2->id << endl;
      Adjacent_Edges->push_back(edge);
    } else if (edge->node2 == node) {
      cout << "ADJACENT: " << edge->node1->id << endl;
      Adjacent_Edges->push_back(edge);
    }
  }
  return Adjacent_Edges;
}

void Remove_Edge(vector<Edge*>& edges, Edge* edge) {
  vector<Edge*>::iterator it;
  for (it = edges.begin(); it < edges.end(); ++it) {
    if (*it == edge) {
      edges.erase(it);
      return;
    }
  }
}
