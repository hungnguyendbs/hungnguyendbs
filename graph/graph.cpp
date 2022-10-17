// vo huong
#include<iostream>
#include<fstream>
#include<conio.h>
#include<vector>
using namespace std;

typedef struct Diem
{
    int canh;
    int dinh;
}diem;

class Graph
{
    private:
        diem data;
        int size;
        vector< vector<int> > x;
    public:
        Graph();
        Graph(int,int,int);
        void InputGraph(const char*,Graph&);
        void ds_Ke(Graph);
        void ds_Canh(Graph);
        void displayGraph(Graph);
        int getDinh(Graph);
        int getCanh(Graph);
        int Bac(int,Graph);
        void DinhKe(int,Graph);
        int getSize()
        {
            return size;
        }
};

Graph::Graph()
{
    
    this->data.canh=0;
    this->data.dinh=0;
    this->size=1;
    vector< vector<int> > grap(0, vector<int>(0,0));
    x=grap;
    
}
Graph::Graph(int d, int c, int s)
{
    data.dinh=d;
    data.canh=c;
    size=s;
    vector< vector<int> > grap(size, vector<int>(size,0));
    this->x=grap;
}

void Graph::InputGraph(const char* in,Graph &graph)
{
    fstream filename;
    filename.open(in);
    filename>>graph.size;
     int a=graph.size;
    graph.x.resize(a);
    for(int i=0;i<a;i++)
    {
        graph.x[i].resize(a);
        for(int j=0;j<a;j++)
        {
            int c=0;
           filename>>c;
           graph.x[i][j]=c;
           if(c==1) graph.data.canh++;
        }
    }
    graph.data.canh=graph.data.canh/2;
}

void Graph::ds_Ke(Graph graph)
{
    for(int i=0;i<graph.size;i++)
    {
        cout<<i<<"| ";
        for(int j=0;j<graph.size;j++)
        {
            if(graph.x[i][j]==1)
            {
                cout<<j<<" ";
            }
        }
        cout<<endl;
    }
}

void Graph::ds_Canh(Graph garph)
{
    for(int i=0;i<garph.size;i++)
    {
        for(int j=0;j<garph.size;j++)
        {
            if(garph.x[i][j]==1) 
            {
                cout<<i<<"-->"<<j<<endl;
                garph.x[j][i]=0;
            }
        }
    }
}

void Graph::displayGraph(Graph grap)
{
    cout<<"    ";
    for(int i=0;i<grap.size;i++) cout<<i<<" ";
    cout<<endl<<"    ";
    for(int i=0;i<grap.size;i++) cout<<"_ ";
    cout<<endl;
    for(int i=0;i<grap.size;i++)
    {
        cout<<i<<" | ";
        for(int j=0;j<grap.size;j++)
        {
            cout<<grap.x[i][j]<<" ";
        }
        cout<<endl;
    }
}

int Graph::getCanh(Graph gr)
{
    return gr.data.canh;
}
int Graph::getDinh(Graph gr)
{
    data.dinh =gr.size;
    return gr.data.dinh;
}

int Graph::Bac(int dinh_x, Graph gr)
{
    int bac=0;
    for(int i=0;i<gr.size;i++)
    {
        if(i==dinh_x)
        {
            for(int j=0;j<gr.size;j++)
            {
                if(gr.x[i][j]==1) bac++;
            }

            break;
        }
        
    }
    return bac;
}

void Graph::DinhKe(int dinh_ke, Graph gr)
{
     for(int i=0;i<gr.size;i++)
    {
        if(i==dinh_ke)
        {
            for(int j=0;j<gr.size;j++)
            {
                if(gr.x[i][j]==1)
                {
                    cout<<j<<" ";
                }
            }

            break;
        }
        
    }
}
int main()
{
    



    Graph graph;


    bool check =true;
    while (check)
    {
          system("cls");
                cout << "                        GRAPH\n";
		        cout << " ________________________MENU__________________________\n";
		        cout << "|   1. Doc du lieu tu file.                            |\n";
		        cout << "|   2. Xuat du lieu tu file.                           |\n";
		        cout << "|   3. Xuat danh sach ke.                              |\n";
		        cout << "|   4. Xuat danh sach canh.                            |\n";
		        cout << "|   5. Xuat so dinh, so canh cua do thi.               |\n";
	        	cout << "|   6. Tim bac cua dinh.                               |\n";
	        	cout << "|   7. Tim dinh ke                                     |\n";
	        	cout << "|   0. Thoat                                           |\n";
                cout << "|______________________________________________________|\n";
		        cout << "Nhap tuy chon: ";
                int key; cin>>key;

                  switch (key)
        {
            case 1:
            {
               graph.InputGraph("output1_1.txt",graph);
               cout<<"doc du lieu thanh cong";
                getch();
                 break;
            }
            case 2:
            {
                system("cls");
                cout<<"Ma tran ke doc tu file ("<<graph.getSize()<<"*"<<graph.getSize()<<")"<<endl;
                graph.displayGraph(graph);
                getch();
                break;
            }
            case 3:
            {
                system("cls");
                cout<<"----------------Danh sach ke-----------------"<<endl;
                graph.ds_Ke(graph);
              
                 getch();
                 break;
            }
            case 4:
            {
                 system("cls");
                 cout<<"----------------Danh sach canh-----------------"<<endl;
                graph.ds_Canh(graph);
              
                 getch();
                 break;

            }
            case 5:
            {
                cout<<endl<<"so dinh cua do thi la: "<<graph.getDinh(graph)<<endl<<"so canh cua do thi la: "<<graph.getCanh(graph);
                getch();
                break;
                
            }

            case 6:
            {
                cout<<endl;
                int bac=0;
                cout<<"Nhap dinh muon tim bac: "; cin>>bac;
                cout<<"bac cua dinh "<<bac<<" la: "<<graph.Bac(bac,graph);
                getch();
                break;
            }
            case 7:
            {
                int dinhke=0;
                cout<<"Nhap dinh : "; cin>>dinhke;
                cout<<"Dinh ke voi dinh "<<dinhke<<" la: "; graph.DinhKe(dinhke,graph);
                getch();
                break;

            }
            case 0:
            {
                check=false;
                break;
            }
        }

           
        }
}
