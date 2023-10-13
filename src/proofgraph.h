#ifndef PROOFGRAPH_H
#define PROOFGRPAH_H


#include <iostream>
#include <set>

//#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/variant/vector3.hpp"
#include "godot_cpp/classes/object.hpp"
#include "godot_cpp/classes/node3d.hpp"
#include "godot_cpp/templates/hash_map.hpp"
#include "godot_cpp/templates/hash_set.hpp"
#include "godot_cpp/classes/mesh_instance3d.hpp"
#include "godot_cpp/classes/scene_tree.hpp"



namespace godot{

class LogNode : public Node3D{
    GDCLASS(LogNode, Node3D)
    public:

        int nodeID;
        // Placeholder for 3D location info as I'm not sure how Godot handles it
        Vector3 location;
        // Placeholder for formula data
        int data;
        // Potentially split into seperate parent/child sets?
        HashSet<LogNode*> neighbors;

        LogNode();

        LogNode(int nodeID, Vector3 location, int data);

        void setNode(int nodeID, Vector3 location, int data);

        int getID();

        int getData();

        Vector3 getPosition();

    
    protected:
        static void _bind_methods();
};

class ProofGraph : public Node{
    GDCLASS(ProofGraph, Node)

    private:
        int nodeCount;
        HashMap<int, LogNode*> nodeMap;
    public:
        
        // Constructor, creates empty proof graph
        ProofGraph(); 
        ~ProofGraph();


        //void addNode(Vector3 location, int data);
        void addNode(LogNode* newNode);

        void addEdge(int start, int end);

        void removeNode(int deleteID);

        int getNodeCount();

        int getNodeData(int targetNodeID);

    protected:
        static void _bind_methods();

};

}

#endif