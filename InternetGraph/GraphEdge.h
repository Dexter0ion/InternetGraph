#ifndef _GRAPHEDGE_H_
#define _GRAPHEDGE_H_

#include "GraphNode.h"


class GraphEdge {
    private:
        GraphNode N1;
        GraphNode N2;
        int weight;		//0不连通 >=1连通
        bool isConnect;

    public:
        GraphEdge() {
            GraphNode N1_ = GraphNode();
            N1 = N1_;
            GraphNode N2_ = GraphNode();
            N2 = N2_;
            weight = 0;
            isConnect = false;
        }
        GraphNode GetNode1() {
            return N1;
        }
        GraphNode GetNode2() {
            return N2;
        }
        GraphEdge(GraphNode N1_,GraphNode N2_,int weight_) {
            N1 = N1_;
            N2 = N2_;
            weight = weight_;
            isConnect = true;
        }
        bool setConnect(bool n) {
            isConnect=n;
        }

        bool getConnect() {
            return isConnect;
        }




};
#endif
