#include<iostream>
using namespace std;
class Line{
	public:
		char first_Vertex;
		char Second_Vertex;
		int waight;
		void Input(){
			cout<<"Enter First Vertex: ";
			cin>>first_Vertex;
			cout<<"Enter Second Vertex: ";
			cin>>Second_Vertex;
			cout<<"Enter weight of Edge: ";
			cin>>waight;
			cout<<endl;
		}
		void Display(){
			cout<<first_Vertex<<"-"<<Second_Vertex<<":"<<waight<<endl;
		}
};
void sort(Line *graph,int edges){
	Line temp;
	for(int i=0;i < edges ;i++){
		for(int j=0;j < edges-1;j++){
			if(graph[j].waight > graph[j+1].waight){
				temp=graph[j];
				graph[j]=graph[j+1];
				graph[j+1]=temp;	
			}
		}
	}
}
bool find(int value,Line *mst,int edges){
	int milgya=0;
	char sets_of_mst_vertices[edges];
	for(int i=0;i<edges;i=i+2){
		sets_of_mst_vertices[i]=mst[0].first_Vertex;
		sets_of_mst_vertices[i+1]=mst[0].Second_Vertex;
	}
	for(int i=0;i<edges;i++){
		if(value==sets_of_mst_vertices[i]){
		milgya=1;
		break;
		}
	}
	if(milgya==1){
		return true;
	}
	else{
		return false;
	}
}
void MST_kruskal_Algo(Line *graph,int nodes,int edges){
	int mst_value=0;
	Line *mst=new Line[edges];
	mst[0]=graph[0];
	int count=1;
	int i=1;
	while(true){
		if(!(find(graph[i].first_Vertex,mst,edges) && find(graph[i].Second_Vertex,mst,edges))){
			mst[count].first_Vertex=graph[i].first_Vertex;
			mst[count].Second_Vertex=graph[i].Second_Vertex;
			mst[count].waight=graph[i].waight;
			count++;
			i++;
		}
		else{
			i++;
		}
		if(i<edges){
			break;
		}	
	}
	Line *mst_Final=new Line[count];
	for(int i=0;i<count;i++){
		mst_Final[i].first_Vertex=mst[i].first_Vertex;
		mst_Final[i].Second_Vertex=mst[i].Second_Vertex;
		mst_Final[i].waight=mst[i].waight;
		
	}
	for(int i=0;i<count;i++){
		mst_Final[i].Display();
		mst_value+=mst_Final[i].waight;	
	}
	cout<<endl<<"Minnimum Spanning Tree waight is: "<<mst_value<<endl;
}
int main(){
	
//	ccout<<char(201);<<
//	ccout<<char(187);>>
	system("COLOR A");
	cout<<"\t\t\t\t Welcome To Minnimun Spanning Tree Program "<<endl<<endl;
	int edges=3,nodes=3;
	cout<<"Enter Number of Nodes: ";
	cin>>nodes;
	cout<<"Enter Number of Edges: ";
	cin>>edges;
	cout<<endl;
	system("cls");
	Line *graph=new Line[edges];
	for(int i=0;i< edges;i++){
			graph[i].Input();	
	}
	system("cls");		
	sort(graph,edges);	
	MST_kruskal_Algo(graph,nodes,edges);
	cout<<endl;
	system("Pause");
}
