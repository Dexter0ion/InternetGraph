#ifndef _GRAPHMATRIX_H_
#define _GRAPHMATRIX_H_

#include<iomanip>
#include "GraphNode.h"
#include "GraphEdge.h"
#include "vector"
using namespace std;

class GraphMatrix {//����
    public:
        GraphMatrix(int nodenum) {
            //��ʼ������
            NodeNum = nodenum;
            M.resize(NodeNum);
            for(int e=0; e<NodeNum; e++) {
                M[e].resize(NodeNum);
            }
            //�������ձ�

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

		void DeleteNode(string Name) {//ɾ���ڵ㺯��
            GraphNode node = SearchNodeName(Name);
			if(node.getNodeName()!="Empty") {
                cout<<"�ڵ���ҳɹ�!"<<endl;
				int idd=GetNodeId(Name);
				cout<<GetNodeId(node.getNodeName())<<endl;
                cout<<"ɾ���ڵ�..."<<endl;
				Nodes.erase(Nodes.begin()+idd);
				
			}
			else
			{
				cout<<"δ�ҵ��ýڵ�"<<endl;
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
            for(int i=0; i<Nodes.size(); i++) {				//�ع��õ�������
                if(Nodes[i].getNodeName()==name)
                    return Nodes[i];
            }

            if(!flag)
                return EmpeyNode;

        }

        int GetNodeId(string name) {
            bool flag=false;
            for(int i=0; i<Nodes.size(); i++) {				//�ع��õ�������
                if(Nodes[i].getNodeName()==name)
                    return i;
            }

            if(!flag)
                return -1;
        }
        void SetConnect() {
            string node1name,node2name;
            cout<<"��������..."<<endl;
            cout<<"������ʼ�ڵ����ƣ�";
            cin>>node1name;
            cout<<"�����յ�ڵ����ƣ�";
            cin>>node2name;

            GraphNode node1 = SearchNodeName(node1name);
            GraphNode node2 = SearchNodeName(node2name);

            if(node1.getNodeName()!="Empty"&&node2.getNodeName()!="Empty") {
                cout<<"�ڵ���ҳɹ�!"<<endl;
                cout<<"��������..."<<endl;

                //������
                GraphEdge Link = GraphEdge(node1,node2,1);
                //��������
                int node1ID = GetNodeId(node1name);
                int node2ID = GetNodeId(node2name);
                //cout<<"Node:"<<node1ID<<"&&Node:"<<node2ID<<endl;
                if(node2ID!=-1&&node1ID!=-1) {
                    M[node1ID][node2ID] = Link;
                    M[node2ID][node1ID] = Link;
                }

            }
        }
		
		 void DeleteConnect() {//ɾ���ߵĺ���
            string node1name,node2name;
            cout<<"ɾ������..."<<endl;
            cout<<"������ʼ�ڵ����ƣ�";
            cin>>node1name;
            cout<<"�����յ�ڵ����ƣ�";
            cin>>node2name;

            GraphNode node1 = SearchNodeName(node1name);
            GraphNode node2 = SearchNodeName(node2name);

            if(node1.getNodeName()!="Empty"&&node2.getNodeName()!="Empty") {
                cout<<"�ڵ���ҳɹ�!"<<endl;
                cout<<"ɾ������..."<<endl;

                //������
                GraphEdge Link = GraphEdge(node1,node2,0);
                //��������
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
        int NodeNum;					//�ڵ���
        vector<vector <GraphEdge> > M;	//vector��ά����
        vector<GraphNode> Nodes;		//�洢�ڵ�����
};
#endif

