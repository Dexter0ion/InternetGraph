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
            cout<<"A ���Ĭ�Ͻڵ�"<<endl;
            cout<<"B �ֶ���ӽڵ�"<<endl;

            char choice;
            cin>>choice;

            if(choice=='A'||choice=='a') {
                M.InsertNode("Home","192.168.1.0/24");
                M.InsertNode("School","192.168.2.0/24");
                M.InsertNode("Store","192.168.3.0/24");
                M.InsertNode("Friend","192.168.4.0/24");
                M.InsertNode("Office","192.168.5.0/24");
                cout<<"�����ڵ���..."<<endl;
                cout<<"[PASS]��ӳɹ�"<<endl;
            }

            else if(choice=='B'||choice=='b') {
                string name,ip;
                cout<<"�ڵ����ƣ�";
                cin>>name;
                cout<<"�ڵ�IP��";
                cin>>ip;
                M.InsertNode(name,ip);
                cout<<"[PASS]��ӳɹ�"<<endl;
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
            cout<<"�����ɾ���ڵ����ƣ�"<<endl;
            string name;
            cin>>name;
            M.DeleteNode(name);
            cout<<"ɾ����..."<<endl;
            cout<<"[PASS]ɾ���ɹ�"<<endl;
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
            cout<<"��������������";
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
            cout<<"��������ʼ�����ƣ�";
            cin>>node1name;
            cout<<"�������յ����ƣ�";
            cin>>node2name;
            int node1ID = M.GetNodeId(node1name);
            int node2ID = M.GetNodeId(node2name);
            //cout<<"Node:"<<node1ID<<"&&Node:"<<node2ID<<endl;
            if(node2ID!=-1&&node1ID!=-1) {
                if(M.CheckWarshall(node1ID,node2ID))
                    cout<<"[�ɴ�]"<<node1name<<"&"<<node2name<<endl;
                else if(!M.CheckWarshall(node1ID,node2ID))
                    cout<<"[���ɴ�]"<<node1name<<"&"<<node2name<<endl;
            } else {
                cout<<"�������"<<endl;
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
            cout<<"	Internet����ͨ·����"<<endl;
            cout<<"[��һ��]�۲��� ���� ������ ������ ������"<<endl;
            cout<<"_________________�ڵ��б�_________________"<<endl;
            M.DisplayNodeList();
            cout<<"__________________________________________"<<endl;
            cout<<"	1 ��ӽڵ���Ϣ"<<endl;
            cout<<"	2 ɾ���ڵ���Ϣ"<<endl;
            cout<<"	3 ��ʾ�ڵ��б�"<<endl;
            cout<<"	4 ������������"<<endl;
            cout<<"	5 ɾ����������"<<endl;
            cout<<"	6 ��������ɴ���[Warshall]"<<endl;
            cout<<"	7 ������������·[Floyd]"<<endl;
            cout<<"	0 �˳�"<<endl;
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
