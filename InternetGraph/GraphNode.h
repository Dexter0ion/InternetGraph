#ifndef _GRAPHNODE_H_
#define _GRAPHNODE_H_

#include <iostream>
#include <string>

using namespace std;
class GraphNode {
    private:
        string NodeName;
        string IpAddress;
    public:
        GraphNode() {
            NodeName = "NULL";
            IpAddress = "127.0.0.1";	//±æµÿµÿ÷∑
        }

        GraphNode(string Name) {
            NodeName = Name;
            IpAddress = "127.0.0.1";
        }

        GraphNode(string Name,string IP) {
            NodeName = Name;
            IpAddress = IP;
        }

        GraphNode& operator=(const GraphNode &node) {
            NodeName = node.NodeName;
            IpAddress = node.IpAddress;
            return *this;
        }

        void setNodeName(string Name) {
            NodeName = Name;
        }

        string getNodeName() {
            return NodeName;
        }

        void setIpAddress(string IP) {
            IpAddress = IP;
        }

        string getIpAddress() {
            return IpAddress;
        }
};

#endif

