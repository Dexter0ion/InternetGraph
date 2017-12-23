#ifndef _GRAPHEDGE_H_
#define _GRAPHEDGE_H_

#include "GraphNode.h"

 
class GraphEdge{
	public:
		GraphEdge(){
			GraphNode N1_ = GraphNode();
			N1 = N1_;
			GraphNode N2_ = GraphNode();
			N2 = N2_;
			weight = 0;
			isConnect = false;
		}
		
		GraphEdge(GraphNode N1_,GraphNode N2_,int weight_){
			N1 = N1_;
			N2 = N2_;
			weight = weight_;
			isConnect = true;
		}
		
		bool getConnect(){
			return isConnect;
		}
		
		
	private:
		GraphNode N1;		
		GraphNode N2;
		int weight;		//0不连通 >=1连通
		bool isConnect; 

};
#endif
