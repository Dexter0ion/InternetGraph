#ifndef _GRAPHEDGE_H_
#define _GRAPHEDGE_H_
#include "GraphNode.h"
class GraphEdge {
    private:
        GraphNode N1;//l俩点
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

        GraphEdge(GraphNode N1_,GraphNode N2_,int weight_) {
            N1 = N1_;
            N2 = N2_;
            weight = weight_;
            if(weight_)
                isConnect = true;
            else
                isConnect = false;
        }

        bool getConnect() {
            return isConnect;
        }
};
#endif

