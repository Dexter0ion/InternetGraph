#ifndef _SYSTEMCONTROL_H_
#define _SYSTEMCONTROL_H_

#include "GraphNode.h"
#include "GraphEdge.h"
#include "GraphMatrix.h"

class SystemControl {
    private:
        GraphMatrix M;
    public:
        SystemControl() {
            initMatrix();
        };
        void initMatrix() {
            GraphMatrix N(5);
            M=N;
        }
        void InsertNodeList() {
            cout<<"A 添加默认节点"<<endl;
            cout<<"B 手动添加节点"<<endl;

            char choice;
            cin>>choice;

            if(choice=='A'||choice=='a') {
                M.InsertNode("Home","192.168.1.0/24");
                M.InsertNode("School","192.168.2.0/24");
                M.InsertNode("Store","192.168.3.0/24");
                M.InsertNode("Friend","192.168.4.0/24");
                M.InsertNode("Office","192.168.5.0/24");
                cout<<"搜索节点中..."<<endl;
                cout<<"[PASS]添加成功"<<endl;
            }

            else if(choice=='B'||choice=='b') {
                string name,ip;
                cout<<"节点名称：";
                cin>>name;
                cout<<"节点IP：";
                cin>>ip;
                M.InsertNode(name,ip);
                cout<<"[PASS]添加成功"<<endl;
            } else {
            	system("cls");
                InsertNodeList();
            }
            M.DisplayNodeList();

            cout<<endl<<endl;
            system("PAUSE");
            system("cls");
        }

        void DisplayNodes() {
            cout<<endl<<endl;
            system("PAUSE");
            system("cls");
        }
        void DeleteNode() {
            cout<<"输入待删除节点名称："<<endl;
            string name;
            cin>>name;
            M.DeleteNode(name);
            cout<<"删除中..."<<endl;
            cout<<"[PASS]删除成功"<<endl;
            cout<<endl<<endl;
            system("PAUSE");
            system("cls");
        }

        void DeleteConnect() {
            M.DeleteConnect();
            cout<<endl<<endl;
            system("PAUSE");
            system("cls");
        }

        void SetConnect() {
            cout<<"建立连接条数：";
            int N;
            cin>>N;
            while(N) {
                M.SetConnect();
                N--;
            }
            cout<<endl<<endl;
            system("PAUSE");
            system("cls");
        }

        void CheckPath() {
            M.Warshall_beta();
            M.DisplayWarshallMatrix();

            string node1name,node2name;
            cout<<"请输入起始点名称：";
            cin>>node1name;
            cout<<"请输入终点名称：";
            cin>>node2name;
            int node1ID = M.GetNodeId(node1name);
            int node2ID = M.GetNodeId(node2name);
            //cout<<"Node:"<<node1ID<<"&&Node:"<<node2ID<<endl;
            if(node2ID!=-1&&node1ID!=-1) {
                if(M.CheckWarshall(node1ID,node2ID))
                    cout<<"[可达]"<<node1name<<"&"<<node2name<<endl;
                else if(!M.CheckWarshall(node1ID,node2ID))
                    cout<<"[不可达]"<<node1name<<"&"<<node2name<<endl;
            } else {
                cout<<"输入错误"<<endl;
            }
            cout<<endl<<endl;
            system("PAUSE");
            system("cls");

        }

        void CheckShortestPath() {
            M.DisplayMatrix();
            M.ShortestPath_Floyd();
            cout<<endl<<endl;
            system("PAUSE");
            system("cls");
        }
        void menu() {
            cout<<endl;
            cout<<"	Internet网络通路管理"<<endl;
            cout<<"[第一组]邵博超 王钢 王艳琴 周月星 朱利佳"<<endl;
            cout<<"_________________节点列表_________________"<<endl;
            M.DisplayNodeList();
            cout<<"__________________________________________"<<endl;
            cout<<"	1 添加节点信息"<<endl;
            cout<<"	2 删除节点信息"<<endl;
            cout<<"	3 显示节点列表"<<endl;
            cout<<"	4 建立网络连接"<<endl;
            cout<<"	5 删除网络连接"<<endl;
            cout<<"	6 检索网点可达性[Warshall]"<<endl;
            cout<<"	7 检索网点间最短路[Floyd]"<<endl;
            cout<<"	0 退出"<<endl;
            cout<<"__________________________________________"<<endl;
        }

        void Start() {

            menu();
            cout<<">>";
            int N;
            cin>>N;
            switch(N) {
                case 1: {
                    InsertNodeList();
                    Start();
                    break;
                }
                case 2: {
                    DeleteNode();
                    Start();
                    break;
                }
                case 3: {
                    DisplayNodes();
                    Start();
                    break;
                }



                case 4: {
                    SetConnect();
                    Start();
                    break;
                }

                case 5: {
                    DeleteConnect();
                    Start();
                    break;
                }

                case 6: {
                    CheckPath();
                    Start();
                    break;
                }

                case 7: {
                    CheckShortestPath();
                    Start();
                    break;
                }

                case 0:
                    break;
                default: {
                    Start();
                    break;
                }

            }
        }
};
#endif
