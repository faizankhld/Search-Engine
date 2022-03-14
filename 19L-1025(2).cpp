#include<iostream>
#include<fstream>
#include<list>
#include<string>
#include<vector>
using namespace std;
class graphnode
{
public:
	int startindex;       //edge infromation
	int endindex;
	int status;
	int id;
	int weight1;              // This will be the  weight required to  conect maindex id weight 
	string location;	         
	int mainindex;      // this will indicate the computer id of edge
	graphnode()
	{
		status = 0;
		id = 0;
		weight1 = 999999;
	}
	void add(int a, string b)  // function to add vertex
	{
		id = a;
		location = b;
	}
	bool operator >(graphnode & obj)          // greater or smaller operator according weight 
	{
		if (weight1 > obj.weight1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator <(graphnode & obj)
	{
		if (weight1 < obj.weight1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void adedege(int a, int b, int c)  //funtion to add edge infromation
	{
		startindex = a;
		endindex = b;
		weight1 = c;
	}
	void print2()
	{
		cout << "Computer Id :" << id << " Location " << location << " Weight " << weight1 << endl;
	}
	int getstatus()
	{
		return status;
	}
	void setstatus()
	{
		status = 1;
	}
	void printedege()
	{
		cout << "Id " << mainindex << " --Weight-- " << weight1 << " Id " << id << endl;
	}
};

class graph1
{
public:
	int totalver;
	list<graphnode> *abj;        // adjency list of vertex and edgeinformation 
public:
	graph1()
	{

	}
	graph1(int at)
	{
		totalver = at;
		abj = new list<graphnode>[totalver];
	}
	int gettotal()
	{
		return totalver;
	}
	void operator --()
	{
		--totalver;
	}
	void addver(string a)
	{
		int ct;
		int count;
		string aa;
		ifstream fin;
		fin.open(a);
		fin >> ct;
		for (int dd = 0; dd < ct; ++dd)                 // this function will add vertex information to list this will add vertex infrmation at head
		{
			fin >> count;
			fin >> aa;
			graphnode temp;
			temp.add(count, aa);			
			abj[dd].push_front(temp);
		}
		fin.close();
	}
	void grede(string c1)
	{
		int tt = 0;
		int a1 = 0;
		int b1 = 0;
		int d1 = 0;
		ifstream tin;
		tin.open(c1);
		tin >> tt;
		for (int ss = 0; ss < tt; ++ss)
		{
			tin >> a1;
			tin >> b1;
			tin >> d1;
			for (int se = 0; se < totalver; ++se)  //this function will add edge infromation at end of the list and mantain edge informaition related to vertex in each vertex  adjecny list
			{
				//if (abj[se].id == a1)
				//{
				//	abj[se].adedege(a1, b1, d1);
				//}
				graphnode temp;
				temp = abj[se].front();
				if (temp.id == a1)
				{
					graphnode tty;
					tty.adedege(a1, b1, d1);
					abj[se].push_back(tty);
				}
			}
		}
	}
};

class heap
{
	graphnode *tt;
	int capacity;
	int size2;
public:
	heap()
	{
		tt = nullptr;
		capacity = 0;
		size2 = 0;
	}
	heap(int a)
	{
	 capacity = a;
	 tt = new graphnode[capacity];		
	}
	void heapify1(int n, int i)
	{
		int smallest = i; // Initialize largest as root 
		int l = 2 * i + 1; // left = 2*i + 1 
		int r = 2 * i + 2; // right = 2*i + 2 

		if (l < n && tt[l] < tt[smallest])
		{
			smallest = l;
		}
		if (r < n && tt[r] < tt[smallest])
		{
			smallest = r;
		}
		if (smallest != i)
		{
			swap(tt[i], tt[smallest]);
			heapify1(n, smallest);
		}
	}
	void buildheap1()
	{
		int startIdx = (size2 / 2) - 1;
		for (int i = startIdx; i >= 0; i--)
		{
			heapify1(size2, i);
		}		
	}
	void inseterkey(graphnode key)
	{
		if (size2 != capacity)
		{
			tt[size2] = key;
			++size2;
		    buildheap1();
		}
	}
	void extractmin1()
	{
		tt[0] = tt[size2 - 1];
		--size2;
		buildheap1();
	}
	void decreasekey( int a, int newvalue)
	{
		tt[a].weight1 = newvalue;
		buildheap1();
	}
	~heap()
	{
		size2 = 0;
		capacity = 0;
		delete[]tt;
	}
};


void heapify(graph1 & empVector, int n, int i)
{
	int largest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 

	if (l < n && empVector.abj[l].front() < empVector.abj[largest].front())
	{
		largest = l;
	}
	if (r < n && empVector.abj[r].front() < empVector.abj[largest].front())
	{
		largest = r;
	}
	if (largest != i)
	{
		swap(empVector.abj[i], empVector.abj[largest]);
		//swap(empVector[i], empVector[largest]);
		heapify(empVector, n, largest);
	}
}
void buildheap(graph1 & empVector, int n)
{
	int startIdx = (n / 2) - 1;
	for (int i = startIdx; i >= 0; i--)
	{
		heapify(empVector, n, i);
	}
}
void extractmin(graph1 & bbj, int & n)
{
	bbj.abj[0] = bbj.abj[n - 1];
	--bbj.totalver;
	--n;
	buildheap(bbj, n);
}
void printpath(graph1 tbj, int & n1)
{
	vector<graphnode>ppp;
	vector<graphnode> taj;
	graph1 obj2;
	obj2 = tbj;

	graphnode rtr;
	int cot1 = obj2.totalver;
	obj2.abj[0].front().weight1 = 0;             // updating the weight of vertex to zero
	 
	//heap yy(obj2.abj,obj2.totalver);
	list<graphnode> ::iterator itr;
	int a65 = 0;
	for (itr = obj2.abj[0].begin(); itr != obj2.abj[0].end(); ++itr, ++a65)
	{
		if (a65 != 0)
	{
		graphnode temp;
		temp = *itr;
		int ed1 = temp.endindex;
		int w1 = temp.weight1;
		for (int ee = 1; ee < obj2.totalver; ++ee)
		{
			if (obj2.abj[ee].front().id == ed1)
			{
				obj2.abj[ee].front().weight1 = w1;

				if (obj2.abj[ee].front().id != temp.startindex)
				{
					obj2.abj[ee].front().mainindex = temp.startindex;                      // updating the weight of vertex edge information if weight is greter then edge weight then update otherwise do nothing
				}
				else
				{
					obj2.abj[ee].front().mainindex = temp.endindex;
				}
			}
		}
	}
	}
	int b65 = 0;
	for (int fr = 1; fr < obj2.totalver; ++fr)
	{
		list<graphnode>::iterator atr;
		for (atr = obj2.abj[fr].begin(); atr != obj2.abj[fr].end(); ++atr, ++b65)
		{
			if(b65 != 0)
		 {
			graphnode tp;
			tp = *atr;
			int g1 = tp.endindex;

			if (g1 == obj2.abj[0].front().id)
			{
				int w1 = tp.weight1;
				obj2.abj[fr].front().weight1 = w1;
				if (obj2.abj[fr].front().id != tp.startindex)
				{
					obj2.abj[fr].front().mainindex = tp.startindex;
				}
				else
				{
					obj2.abj[fr].front().mainindex = tp.endindex;
				}
			}
		 }
		}
	}
	buildheap(obj2, obj2.totalver);           // building the heap on vertex list
	//yy.buildheap1(obj2.abj, obj2.totalver);
	taj.push_back(obj2.abj[0].front());

	//for (int at = 0; at < obj.totalver; ++at)
	//{
	   // obj.abj[at].print2();

	//}
	//yy.extractmin1(obj2.abj, n1);
	extractmin(obj2, n1);           // extracting the minmmum from heap  

	while (n1 != 0)         // while min is not empty continue extracting minmum weight vertex 
	{
		int ggt = 0;
		list<graphnode> ::iterator itr1;
		for (itr1 = obj2.abj[0].begin(); itr1 != obj2.abj[0].end(); ++itr1, ++ggt)
		{
			if(ggt !=0)
		{			
			graphnode temp;
			temp = *itr1;
			int ed12 = temp.endindex;
			int w12 = temp.weight1;
			for (int ee = 1; ee < obj2.totalver; ++ee)
			{
				if (obj2.abj[ee].front().id == ed12)
				{
					if (obj2.abj[ee].front().weight1 > w12)
					{
						obj2.abj[ee].front().weight1 = w12;                                      // updating the weight of vertex of edge inforamtion 
						if (obj2.abj[ee].front().id != temp.startindex)
						{
							obj2.abj[ee].front().mainindex = temp.startindex;        /// storing in maindex the id of neigbour vertex shortest length computer
						}
						else
						{
							obj2.abj[ee].front().mainindex = temp.endindex;
						}
					}
				}
			}
		}
		}
		for (int fr1 = 1; fr1 < obj2.totalver; ++fr1)
		{
			int yty = 0;
			list<graphnode>::iterator atr3;
			for (atr3 = obj2.abj[fr1].begin(); atr3 != obj2.abj[fr1].end(); ++atr3,++yty)
			{
				if (yty != 0)
				{
					graphnode tp;
					tp = *atr3;
					int g1 = tp.endindex;
					if (g1 == obj2.abj[0].front().id)
					{
						int w1 = tp.weight1;
						if (obj2.abj[fr1].front().weight1 > w1)
						{
							obj2.abj[fr1].front().weight1 = w1;
							if (obj2.abj[fr1].front().id != tp.startindex)
							{
								obj2.abj[fr1].front().mainindex = tp.startindex;
							}
							else
							{
								obj2.abj[fr1].front().mainindex = tp.endindex;
							}
						}
					}
				}
			}
		}
		//cout << obj2.abj[0].id << endl;
		taj.push_back(obj2.abj[0].front());
		//for (int at2 = 0; at2 < obj2.totalver; ++at2)
		//{
		   // obj2.abj[at2].print2();

		//}
		/*buildheap(obj.abj, obj.totalver);*/
		//yy.extractmin1(obj2.abj, n1);
		extractmin(obj2, n1);      // extracting the minimum from heap after updating weight
	}
	for (auto i = taj.begin(); i != taj.end(); ++i)
	{
		graphnode op;
		op = *i;
		if (op.id != 1)
		{
			op.printedege();          // printing the starting and ending id and weight 
		}
	}
	int gg;
	cout << "Save Graph Press 1" << endl;
	cin >> gg;
	if (gg == 1)
	{
		ofstream fout;
		fout.open("new.txt");
		for (auto i = taj.begin(); i != taj.end(); ++i)         // if you want to save shortest connection path graph
		{
			graphnode op;
			op = *i;
			fout << op.id << " ";
			fout << op.mainindex << " ";
			fout << op.weight1 << endl;
		}
	}

}

int main()
{
	graph1 obj(7);
	int ft = 0;
	cout << "Press 1 to Input Graph" << endl;
	cout << "Press 2 to Print Graph" << endl; 
	//cout << "Press 3 to Save graph" << endl; This option is avaible in printhpath
	while (ft != -1)
	{
		cin >> ft;
		if (ft == 1)
		{
			string a = "vertex.txt";
			string b = "edge.txt";
			obj.addver(a);
			obj.grede(b);
		}
		if (ft == 2)
		{
			int f = 7;
			printpath(obj, f);
		}
	}
}