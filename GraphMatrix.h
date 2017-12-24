#ifndef _GRAPHMATRIX_H_
#define _GRAPHMATRIX_H_

#include<iomanip>
#include "GraphNode.h"
#include "GraphEdge.h"
#include "vector"
using namespace std;

class GraphMatrix {//矩阵
    public:
        GraphMatrix(int nodenum) {
            //初始化矩阵
            NodeNum = nodenum;
            M.resize(NodeNum);
            for(int e=0; e<NodeNum; e++) {
                M[e].resize(NodeNum);
            }
            //矩阵填充空边

            for(int i=0; i<M.size(); i++)
                for(int j=0; j<M[i].size(); j++) {
                    GraphEdge EmptyEdge = GraphEdge();
                    M[i][j] = EmptyEdge;
                }
        }

        void InsertNode(string Name) {
            GraphNode node = GraphNode(Name);
            Nodes.push_back(node);
        }

		void DeleteNode(string Name) {//删除节点函数
            GraphNode node = SearchNodeName(Name);
			if(node.getNodeName()!="Empty") {
                cout<<"节点查找成功!"<<endl;
				int idd=GetNodeId(Name);
				cout<<GetNodeId(node.getNodeName())<<endl;
                cout<<"删除节点..."<<endl;
				Nodes.erase(Nodes.begin()+idd);
				
			}
			else
			{
				cout<<"未找到该节点"<<endl;
			}
        }
		
        void InsertNode(string Name,string IP) {
            GraphNode node = GraphNode(Name,IP);
            Nodes.push_back(node);
        }

        void DisplayNodeList() {
            for(int i=0; i<Nodes.size(); i++) {
                cout<<"Node "<<i<<"|";
                cout<<"Name:"<<Nodes[i].getNodeName()<<endl;
                cout<<"Ip Address:"<<Nodes[i].getIpAddress()<<endl<<endl;
            }
        }

        GraphNode SearchNodeName(string name) {
            GraphNode EmpeyNode = GraphNode("Empty");
            bool flag=false;
            for(int i=0; i<Nodes.size(); i++) {				//重构用迭代器？
                if(Nodes[i].getNodeName()==name)
                    return Nodes[i];
            }

            if(!flag)
                return EmpeyNode;

        }

        int GetNodeId(string name) {
            bool flag=false;
            for(int i=0; i<Nodes.size(); i++) {				//重构用迭代器？
                if(Nodes[i].getNodeName()==name)
                    return i;
            }

            if(!flag)
                return -1;
        }
        void SetConnect() {
            string node1name,node2name;
            cout<<"建立连接..."<<endl;
            cout<<"输入起始节点名称：";
            cin>>node1name;
            cout<<"输入终点节点名称：";
            cin>>node2name;

            GraphNode node1 = SearchNodeName(node1name);
            GraphNode node2 = SearchNodeName(node2name);

            if(node1.getNodeName()!="Empty"&&node2.getNodeName()!="Empty") {
                cout<<"节点查找成功!"<<endl;
                cout<<"建立连接..."<<endl;

                //建立边
                GraphEdge Link = GraphEdge(node1,node2,1);
                //关联矩阵
                int node1ID = GetNodeId(node1name);
                int node2ID = GetNodeId(node2name);
                //cout<<"Node:"<<node1ID<<"&&Node:"<<node2ID<<endl;
                if(node2ID!=-1&&node1ID!=-1) {
                    M[node1ID][node2ID] = Link;
                    M[node2ID][node1ID] = Link;
                }

            }
        }
		
		 void DeleteConnect() {//删除边的函数
            string node1name,node2name;
            cout<<"删除连接..."<<endl;
            cout<<"输入起始节点名称：";
            cin>>node1name;
            cout<<"输入终点节点名称：";
            cin>>node2name;

            GraphNode node1 = SearchNodeName(node1name);
            GraphNode node2 = SearchNodeName(node2name);

            if(node1.getNodeName()!="Empty"&&node2.getNodeName()!="Empty") {
                cout<<"节点查找成功!"<<endl;
                cout<<"删除连接..."<<endl;

                //建立边
                GraphEdge Link = GraphEdge(node1,node2,0);
                //关联矩阵
                int node1ID = GetNodeId(node1name);
                int node2ID = GetNodeId(node2name);
                //cout<<"Node:"<<node1ID<<"&&Node:"<<node2ID<<endl;
                if(node2ID!=-1&&node1ID!=-1) {
                    M[node1ID][node2ID] = Link;
                    M[node2ID][node1ID] = Link;
                }

            }
        }

		 
        void DisplayMatrix() {
            cout<<setw(4)<<" ";
            for(int k=0; k<Nodes.size(); k++)
                cout<<setw(4)<<"N"<<k;
            cout<<endl;
            for(int i=0; i<Nodes.size(); i++) {
				cout<<setw(4)<<"N"<<i;
                for(int j=0; j<Nodes.size(); j++) {
                    if(M[i][j].getConnect())
                        cout<<setw(4)<<"1";
                    else if(!M[i][j].getConnect())
                        cout<<setw(4)<<"0";
                    cout<<" ";
                }
                cout<<endl;
            }
        }
    private:
        int NodeNum;					//节点数
        vector<vector <GraphEdge> > M;	//vector二维数组
        vector<GraphNode> Nodes;		//存储节点数组
};
#endif

