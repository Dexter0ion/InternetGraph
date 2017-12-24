#include "GraphNode.h"
#include "GraphEdge.h"
#include "GraphMatrix.h"

int main() {
    GraphMatrix M(4);
    M.InsertNode("Home","192.168.1.0/24");
    M.InsertNode("School","192.168.2.0/24");
    M.InsertNode("Store","192.168.3.0/24");
    M.InsertNode("Friend","192.168.4.0/24");
    M.DisplayNodeList();
    M.DisplayMatrix();
    cout<<"删除School"<<endl;
    M.DeleteNode("School");
    M.DisplayNodeList();
    M.DisplayMatrix();
    cout<<"建立连接条数：";
    int N;
    cin>>N;
    while(N) {
        M.SetConnect();
        N--;
    }
    M.DisplayMatrix();
    cout<<"删除连接条数：";
    cin>>N;
    while(N) {
        M.DeleteConnect();
        N--;
    }
    M.DisplayMatrix();
}

