#include <iostream>
#include <iostream>
#include <list>
#include <cstring>
#include <fstream>
#include <string>
#include <sstream>
#include <bitset>
#include <queue>
#include <stack>
#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
#include <cmath>
#include <iostream>
#include <cstring>
#include <climits>

//const int DADANUMBER = data[0][1];
using namespace std;
string InPutFile2;
class MST {

	string InPutFile;
	vector<vector<int> > data;
	vector<vector<int> > dataWeight;
	vector<vector<int> > pathWeight;
	vector<vector<int> > MinpathWeight;
	vector<vector<int> > PomoikaSet;
	vector<vector<int> > UltimatePath;
	vector<int> Pointset;
	vector<int> Weightset;
	int PointNumber = 0;
	int NumberOfEdges = 0;

	public:
		void ReadTheInput();
		void CalculateWeight();
		void AddEdges();

};

void MST::ReadTheInput() {
	
	
	string line,word;
	ifstream myfile(InPutFile2.c_str());
	while(getline(myfile, line)) {
		vector<int> lineData;
		stringstream lineStream(line);
		int value;
		lineData.push_back(PointNumber);
		PointNumber++;
		while (lineStream >> value)
		{
			
			lineData.push_back(value);
			
		}
		
		data.push_back(lineData);
	}


}

void MST::CalculateWeight() {
	int i, j;
	int xvertexstart;
	int xvertexfinish;
	int yvertexstart;
	int yvertexfinish;
	int edge;
	////cout << "check" << endl;

	for (i = 1; i < data[0][1]+1; i++) {
		
		for (j = 1; j < data[0][1]+1; j++) {
			vector<int> lineedge;
			xvertexstart = data[i][1];
			yvertexstart = data[i][2];

			xvertexfinish = data[j][1];
			yvertexfinish = data[j][2];

			edge = sqrt(((xvertexstart - xvertexfinish) * (xvertexstart - xvertexfinish)) + 
							((yvertexstart - yvertexfinish) * (yvertexstart - yvertexfinish)));
			Weightset.push_back(edge);

		}
		dataWeight.push_back(Weightset);
		Weightset.clear();
		//Weightset.clear();
	}
	


}

void MST::AddEdges(){
	

	int TotalDistance = 0;
	int edge;
	int visit[10];
	for (int i = 0; i < data[0][1]; i++) {
		visit[i] = false;
	}

	edge = 0;

	visit[0] = true;

	int x;
	int y;
	cout << "Point(x,y)"  << "   Distance" << endl;
	int x;
	int y;
	cout << "Point(x,y)"  << "   Distance" << endl;
	
	while (edge < data[0][1]-1) {
		int min = INT_MAX;
		x = 0;
		y = 0;
		for (int i = 0; i < data[0][1]; i++) {
			if (visit[i]) {
				for (int j = 0; j < data[0][1]; j++) {
					if (!visit[j] && dataWeight[i][j]) { // not in selected and there is an edge
						if (min > dataWeight[i][j]) {
							min = dataWeight[i][j];
							x = i;
							y = j;
						}

					}
				}
			}
		}

		
		TotalDistance = TotalDistance + dataWeight[x][y];
		cout <<"("<< data[x+1][1] <<","<< data[x+1][2] << ")"<< " ---> " <<"("<< data[y+1][1] <<","<< data[y+1][2] <<")" << " :					" << dataWeight[x][y];
		cout << endl;
		visit[y] = true;
		edge++;
	}
	cout << "Total Distance : " << TotalDistance << endl;
	return;
}




	

int main()
{
	string inputstring;
	cout << "Please enter the filename" << endl;
	getline(cin, InPutFile2);

	MST One;

	One.ReadTheInput();
	One.CalculateWeight();
	One.AddEdges();
}

