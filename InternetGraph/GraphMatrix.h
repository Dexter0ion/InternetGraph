#ifndef _GRAPHMATRIX_H_
#define _GRAPHMATRIX_H_

#include<iomanip>
#include "GraphNode.h"
#include "GraphEdge.h"
#include "vector"
using namespace std;

class GraphMatrix {
    public:
        GraphMatrix() {
            int nodenum=5;
            //��ʼ������
            NodeNum = nodenum;
            M.resize(NodeNum);
            for(int i=0; i<NodeNum; i++) {
                M[i].resize(NodeNum);
            }
            //�������ձ�

            for(int i=0; i<M.size(); i++)
                for(int j=0; j<M[i].size(); j++) {
                    GraphEdge EmptyEdge = GraphEdge();
                    M[i][j] = EmptyEdge;
                }

            //��ʼ��floyd·������
            Path.resize(NodeNum);
            for(int i=0; i<NodeNum; i++) {
                Path[i].resize(NodeNum);
            }

            //��ʼ��floyd�������
            Dis.resize(NodeNum);
            for(int i=0; i<NodeNum; i++) {
                Dis[i].resize(NodeNum);
            }

            WarshallM.resize(NodeNum);
            for(int i=0; i<NodeNum; i++) {
                WarshallM[i].resize(NodeNum);
            }
        }
        GraphMatrix(int nodenum) {
            //��ʼ������
            NodeNum = nodenum;
            M.resize(NodeNum);
            for(int i=0; i<NodeNum; i++) {
                M[i].resize(NodeNum);
            }
            //�������ձ�

            for(int i=0; i<M.size(); i++)
                for(int j=0; j<M[i].size(); j++) {
                    GraphEdge EmptyEdge = GraphEdge();
                    M[i][j] = EmptyEdge;
                }

            //��ʼ��floyd·������
            Path.resize(NodeNum);
            for(int i=0; i<NodeNum; i++) {
                Path[i].resize(NodeNum);
            }

            //��ʼ��floyd�������
            Dis.resize(NodeNum);
            for(int i=0; i<NodeNum; i++) {
                Dis[i].resize(NodeNum);
            }

            WarshallM.resize(NodeNum);
            for(int i=0; i<NodeNum; i++) {
                WarshallM[i].resize(NodeNum);
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

        void DeleteNode(string Name) {//ɾ���ڵ㺯��
            GraphNode node = SearchNodeName(Name);
            if(node.getNodeName()!="Empty") {
                cout<<"�ڵ���ҳɹ�!"<<endl;
                int idd=GetNodeId(Name);
                cout<<GetNodeId(node.getNodeName())<<endl;
                cout<<"ɾ���ڵ�..."<<endl;
                Nodes.erase(Nodes.begin()+idd);

            } else {
                cout<<"δ�ҵ��ýڵ�"<<endl;
            }
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
            cout<<"����ڵ�1���ƣ�";
            cin>>node1name;
            cout<<"����ڵ�2���ƣ�";
            cin>>node2name;

            GraphNode node1 = SearchNodeName(node1name);
            GraphNode node2 = SearchNodeName(node2name);

            if(node1.getNodeName()!="Empty"&&node2.getNodeName()!="Empty") {
                cout<<"�ڵ���ҳɹ�!"<<endl;
                cout<<"��������..."<<endl;

                //������
                GraphEdge Link = GraphEdge(node1,node2,1);
                Link.SetWeight(1);
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


        //���·
        //floyd
        void ShortestPath_Floyd() {
            //DistancMatrix·������
            int INF = 32767;

            //��ʼ��
            for(int i=0; i<NodeNum; i++) {
                for(int j=0; j<NodeNum; j++) {
                    if(i==j)
                        Dis[i][j]=0;
                    else
                        Dis[i][j] = INF;
                    Path[i][j] = -1;


                }
            }
            //����DIS
            for(int i=0; i<NodeNum; i++) {
                for(int j=0; j<NodeNum; j++) {
                    if(M[i][j].GetWeight()!=0) {
                        Dis[i][j] = M[i][j].GetWeight();
                        //cout<<i<<"to"<<j<<":"<<Dis[i][j]<<endl;

                    }
                }
            }

            //�ؼ�����
            for(int k=0; k<NodeNum; k++)
                for(int i=0; i<NodeNum; i++)
                    for(int j=0; j<NodeNum; j++) {

                        if(Dis[i][k]+Dis[k][j]<Dis[i][j]) {
                            Dis[i][j] = Dis[i][k]+Dis[k][j];
                            Path[i][j] = k;
                        }
                    }
            //������·
            for(int i=0; i<NodeNum; i++)
                for(int j=0; j<NodeNum; j++) {
                    if(i!=j) {

                        //������·��
                        if(Dis[i][j]!=INF) {
                            cout<<"��"<<Nodes[i].getNodeName()<<"��"<<Nodes[j].getNodeName();
                            cout<<"���·������Ϊ:"<<Dis[i][j]<<endl;
                            cout<< "��"<<Nodes[i].getNodeName()<<"��"<<Nodes[j].getNodeName()<<"���·��";
                            cout<<Nodes[i].getNodeName();
                            prn_pass(i,j);
                            cout<<"-->"<<Nodes[j].getNodeName()<<endl;
                        } else if(Dis[i][j]==INF) {
                            //cout<<Nodes[i].getNodeName()<<"��"<<Nodes[j].getNodeName()<<"���ɴ�"<<endl;
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

        void DisplayWarshallMatrix() {
            cout<<setw(4)<<" ";
            for(int k=0; k<WarshallM.size(); k++)
                cout<<setw(4)<<"N"<<k;
            cout<<endl;
            for(int i=0; i<WarshallM.size(); i++) {
                cout<<setw(4)<<"N"<<i;
                for(int j=0; j<M[i].size(); j++) {


                    if(WarshallM[i][j]==1)
                        cout<<setw(4)<<"1";
                    else if(WarshallM[i][j]==0)
                        cout<<setw(4)<<"0";
                    cout<<" ";
                }
                cout<<endl;
            }
        }

        void Warshall_beta() {
            int M0[M.size()][M.size()],M1[M.size()][M.size()];
            for(int i=0; i<M.size(); i++) {
                for(int j=0; j<M[i].size(); j++) {
                    if(M[i][j].getConnect())
                        M0[i][j]=1;
                    else if(!M[i][j].getConnect())
                        M0[i][j]=0;
                }
            }
            for(int k=0; k<M.size(); k++) {
                for(int i=0; i<M.size(); i++) {
                    for(int j=0; j<M.size(); j++) {
                        if(M0[i][k]==1&&M0[k][j]==1)
                            M1[i][j]=1;
                        else
                            M1[i][j]=0;
                        if(M1[i][j]+M0[i][j]>=1)
                            M1[i][j]=1;
                        M0[i][j] = M1[i][j];
                    }
                }
            }

            //set WarshallM
            for(int i=0; i<M.size(); i++) {
                for(int j=0; j<M.size(); j++) {
                    WarshallM[i][j] = M1[i][j];
                }
            };

}

bool CheckWarshall(int x,int y) {
    if(WarshallM[x][y]==1)
        return true;
    else if(WarshallM[x][y]==0)
        return false;
}
private:



int NodeNum;					//�ڵ���
vector<vector <GraphEdge> > M;	//vector��ά����
vector<GraphNode> Nodes;		//�洢�ڵ�����
vector<vector <int> >WarshallM;	//Warshall����洢�ɴ���
vector<vector <int> >Path;
vector<vector <int> >Dis;

};
#endif
