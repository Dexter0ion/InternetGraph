#ifndef _GRAPHMATRIX_H_
#define _GRAPHMATRIX_H_

#include<iomanip>
#include "GraphNode.h"
#include "GraphEdge.h"
#include "vector"
using namespace std;

class GraphMatrix {
    public:
        GraphMatrix(int nodenum) {
            //初始化矩阵
            NodeNum = nodenum;
            M.resize(NodeNum);
            for(int i=0; i<NodeNum; i++) {
                M[i].resize(NodeNum);
            }
            //矩阵填充空边

            for(int i=0; i<M.size(); i++)
                for(int j=0; j<M[i].size(); j++) {
                    GraphEdge EmptyEdge = GraphEdge();
                    M[i][j] = EmptyEdge;
                }

            //初始化矩阵

            Path.resize(NodeNum);
            for(int i=0; i<NodeNum; i++) {
                Path[i].resize(NodeNum);
            }


            Dis.resize(NodeNum);
            for(int i=0; i<NodeNum; i++) {
                Dis[i].resize(NodeNum);
            }
        }

        void InsertNode(string Name) {
            GraphNode node = GraphNode(Name);
            Nodes.push_back(node);
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
            cout<<"输入节点1名称：";
            cin>>node1name;
            cout<<"输入节点2名称：";
            cin>>node2name;

            GraphNode node1 = SearchNodeName(node1name);
            GraphNode node2 = SearchNodeName(node2name);

            if(node1.getNodeName()!="Empty"&&node2.getNodeName()!="Empty") {
                cout<<"节点查找成功!"<<endl;
                cout<<"建立连接..."<<endl;

                //建立边
                GraphEdge Link = GraphEdge(node1,node2,1);
                Link.SetWeight(1);
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
            for(int k=0; k<M.size(); k++)
                cout<<setw(4)<<"N"<<k;
            cout<<endl;
            for(int i=0; i<M.size(); i++) {
                cout<<setw(4)<<"N"<<i;
                for(int j=0; j<M[i].size(); j++) {


                    if(M[i][j].getConnect())
                        cout<<setw(4)<<"1";
                    else if(!M[i][j].getConnect())
                        cout<<setw(4)<<"0";
                    cout<<" ";
                }
                cout<<endl;
            }
        }


        //最短路
        //floyd
        void ShortestPath_Floyd() {
            //DistancMatrix路径长度
            int INF = 32767;

            //初始化
            for(int i=0; i<NodeNum; i++) {
                for(int j=0; j<NodeNum; j++) {
                    if(i==j)
                        Dis[i][j]=0;
                    else
                        Dis[i][j] = INF;
                    Path[i][j] = -1;


                }
            }
            //设置DIS
            for(int i=0; i<NodeNum; i++) {
                for(int j=0; j<NodeNum; j++) {
                    if(M[i][j].GetWeight()!=0) {
                        Dis[i][j] = M[i][j].GetWeight();
                        //cout<<i<<"to"<<j<<":"<<Dis[i][j]<<endl;

                    }
                }
            }

            //关键代码
            for(int k=0; k<NodeNum; k++)
                for(int i=0; i<NodeNum; i++)
                    for(int j=0; j<NodeNum; j++) {

                        if(Dis[i][k]+Dis[k][j]<Dis[i][j]) {
                            Dis[i][j] = Dis[i][k]+Dis[k][j];
                            //cout<<"Dis"<<i<<k<<"="<<Dis[i][k]<<endl;
                            //cout<<"Dis"<<k<<j<<"="<<Dis[k][j]<<endl;
                            //cout<<"Dis"<<i<<j<<"="<<Dis[i][j]<<endl;
                            //cout<<"YES"<<endl;
                            Path[i][j] = k;
                        }
                    }
            //输出最短路
            for(int i=0; i<NodeNum; i++)
                for(int j=0; j<NodeNum; j++) {
                    if(i!=j) {

                        //输出最短路径
                        if(Dis[i][j]!=INF) {
                            cout<<"从"<<Nodes[i].getNodeName()<<"到"<<Nodes[j].getNodeName();
                            cout<<"最短路径长度为:"<<Dis[i][j]<<endl;
                            cout<< "从"<<Nodes[i].getNodeName()<<"到"<<Nodes[j].getNodeName()<<"最短路径";
                            cout<<Nodes[i].getNodeName();
                            prn_pass(i,j);
                            cout<<"-->"<<Nodes[j].getNodeName()<<endl;
                        } else if(Dis[i][j]==INF) {
                            //cout<<Nodes[i].getNodeName()<<"与"<<Nodes[j].getNodeName()<<"不可达"<<endl;
                        }
                    }
                }

        }


        void  prn_pass(int j , int k) {
            if (Path[j][k]!=-1) {
                prn_pass(j,Path[j][k]);
                cout<<"-->"<<Path[j][k];
                prn_pass(Path[j][k],k);
            }
        }

    private:



        int NodeNum;					//节点数
        vector<vector <GraphEdge> > M;	//vector二维数组
        vector<GraphNode> Nodes;		//存储节点数组
        vector<vector <int> >Path;
        vector<vector <int> >Dis;

};
#endif
