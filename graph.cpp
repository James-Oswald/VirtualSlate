#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>


class Node{
    public:
        int nodeID;
        // Placeholder for 3D location info as I'm not sure how Godot handles it
        std::tuple <double, double, double> location;
        // Placeholder for formula data
        int data;
        // Potentially split into seperate parent/child sets?
        std::set<Node*> neighbors;

        Node(){
            nodeID = 0;
            location = std::make_tuple(0,0,0);
            data = 0; 
        }
        Node(int nodeID, const std::tuple<double, double, double>& location, int data){
            this->nodeID = nodeID;
            this->location = location;
            this->data = data;
        }
};

class ProofGraph{
    private:
        int nodeCount;
        std::map<int, Node> nodeMap;
    public:

        // Constructor, creates empty proof graph
        ProofGraph(){
            nodeCount = 0;
            std::map<int, Node> nodeMap;
        }

        std::string getNodeRepresentation() {
            std::string result = "";
            for (auto& tempNode : nodeMap){
                result += std::to_string(tempNode.second.nodeID) + ": ";
                for(auto& i : tempNode.second.neighbors){
                    result += std::to_string(i->nodeID) + " ";
                }
                result += "\n";
            }
            return result;            
        }

        void displayNodeList(){
            std::cout << getNodeRepresentation();
        }

        void addNode(const std::tuple<double, double, double>& location, int data){
            Node temp = Node(this->nodeCount, location, data);
            nodeMap[nodeCount] = temp;
            nodeCount++;
        }

        // Needs better check for node validity
        void addEdge(int start, int end){
            if(nodeMap.find(start) == nodeMap.end() || nodeMap.find(end) == nodeMap.end()){
                std::cout << "Nodes not found\n ";
            }
            else{
                nodeMap[start].neighbors.insert(&(nodeMap[end]));
                nodeMap[end].neighbors.insert(&(nodeMap[start]));
            }
        }

        // Needs checks for node validity
        void removeNode(int deleteID){
            Node* temp = &nodeMap[deleteID];
            if(nodeMap.find(deleteID) != nodeMap.end()) {
                for(auto& i : temp->neighbors){
                    i->neighbors.erase(temp);
                }
                nodeMap.erase(deleteID);
            }
        }
        //Needed for testing
        int getSize() {
            return nodeCount;
        }
        //Needed for testing
        std::map<int, Node> getNodeMap() {
            return nodeMap;
        }

};

/*
int main(){
    ProofGraph graph = ProofGraph();
    graph.addNode(std::make_tuple(0,0,0), 0);
    graph.addNode(std::make_tuple(0,1,1), 1);
    graph.addNode(std::make_tuple(0,1,1), 2);
    graph.addNode(std::make_tuple(2,1,1), 3);
    graph.displayNodeList();
    std::cout << "--------\n";
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(2,3);
    graph.addEdge(3,0);
    //graph.addEdge(0,5);
    graph.displayNodeList();
    std::cout << "--------\n";
    graph.removeNode(0);
    graph.displayNodeList();
    std::cout << "--------\n";
}
*/
