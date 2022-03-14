#include<iostream>
#include<string>

#include<fstream>
using namespace std;

template<typename T>
class List
{
	class Node
	{
	public:
		T data;
		Node *next;
		Node *pre;
	};
	Node *head;
	Node *tail;
	int size;
public:

	List()
	{
		head = new Node;
		tail = new Node;
		head->pre = nullptr;
		tail->next = nullptr;
		head->next = tail;
		tail->pre = head;
		size = 0;
	}

	void inserthead(T const element)
	{
		Node* temp = new Node;
		temp->data = element;
		if (head->next != nullptr)
		{
			Node*p = head->next;
			head->next = temp;
			temp->pre = head;
			p->pre = temp;
			temp->next = p;
			++size;
		}
	}
	void inserttail(T const element)
	{
		Node* temp = new Node;
		temp->data = element;
		if (head->next != nullptr)
		{
			Node *p = tail->pre;
			tail->pre = temp;
			p->next = temp;
			temp->pre = p;
			temp->next = tail;
		}
	}
	void print()
	{
		Node *p = head->next;
		Node *e = tail;
		while (p != tail)
		{
			cout << p->data;

			p = p->next;

		}
	}

	void DeleteAtStart()
	{
		if (head->next != tail)
		{
			Node *temp = head->next;
			Node *temp2 = temp->next;

			delete temp;
			temp2->pre = head;
			head->next = temp2;
			--size;
		}
	}
	void DeleteAtEnd()
	{
		Node *temp = tail->pre;
		Node*temp2 = temp->pre;
		temp2->next = tail;
		tail->pre = temp2;
		delete temp;
	}
	void reverse()
	{
		if (head->next != nullptr)
		{
			Node *temp = head->next;

			while (temp != nullptr)
			{
				Node *a = temp->pre;
				Node *b = temp->next;
				temp->next = a;
				temp->pre = b;
				temp = temp->pre;
			}

		}

	}
	int getsize1()
	{
		return size;
	}
	void insertbtw(T const v1, T const v2)
	{
		Node *temp = new Node;
		temp->data = v1;
		if (head->next != nullptr)
		{
			Node *p = head->next;

			while (p != tail)
			{
				if (p->data == v2)
				{

					Node * temppre = p->pre;
					temppre->next = temp;
					temp->next = p;
					temp->pre = temppre;
					p->pre = temp;


				}
				p = p->next;
			}



		}
	}
	void remove()
	{
		if (head->next != nullptr)
		{
			Node *temp = head->next;

			while (temp != tail)
			{
				Node *temp1 = head->next;
				int check = 0;
				Node *temp3;

				while (temp1 != tail)
				{

					if (temp->data == temp1->data)
					{
						temp3 = temp1;
						++check;
						if (check >= 2)
						{
							Node *t1 = temp3->pre;
							Node *t2 = temp3->next;
							t1->next = t2;
							t2->pre = t1;


						}

					}
					temp1 = temp1->next;

				}

				temp = temp->next;

			}
		}
	}
	class iterator
	{
		Node *current;

	public:
		iterator()
		{
			current = nullptr;
		}
		iterator(Node *n)
		{
			current = n;
		}
		iterator & operator++()
		{
			current = current->next;
			return *this;
		}
		iterator & operator--()
		{
			current = current->pre;
			return *this;
		}
		bool operator==(const iterator& rhs)const {

			if (current == rhs.current)
				return true;
			else return false;

		}
		bool operator!=(const iterator& rhs)const {

			if (current != rhs.current)
				return true;
			else return false;

		}

		T & operator *()
		{
			return current->data;
		}

		//void DeleteatHead()
		//{
		//	if (head->next != tail)
		//	{

		//		Iterator it(head->next)
		//		Delete(it);

		//	}
		//}
		//void DeleteatTail()
		//{
		//	if (head->next != tail) 
		//	{
		//		Iterator it(tail);
		//		Delete(--it);
		//	}
		//}

	};

	iterator begin()
	{

		iterator itr(head->next);
		return itr;
	}
	iterator end()
	{
		iterator itr(tail);
		return itr;
	}
	//void forward()
	//{
	//	iterator itr;
	//	for (itr = begin(); itr != end(); ++itr)
	//	{
	//		std::cout << *(itr) << endl;
	//	}
	//}
	//void reversep()
	//{
	//	iterator itr;
	//	for (itr = --end(); itr != --begin(); --itr)
	//	{
	//		std::cout << *(itr) << endl;
	//	}

	//}






	~List()
	{

		while (head->next != tail)
		{

			DeleteAtStart();

		}
	}

};
class Doc_info
{
	string Doc_id;
	int frequency;
	int times;

public:

	Doc_info()
	{
		Doc_id = '\0';
		frequency = 0;
		times = 0;
	}
	void add(string a, int b)
	{
                                                                   // function to add data in class doc_info
		Doc_id = a;
		frequency = b;
		
	}
	string get_id()
	{
		return Doc_id;
	}
	int get_frequency()
	{
		return frequency;
	}
	void setfre(int yi)
	{
		frequency = yi;
	}
	void print()
	{
		cout << "Doc_id " << Doc_id << endl;                       // Print Only Doc_id
	}
	Doc_info(Doc_info & obj)
	{
		string a = obj.get_id();
		Doc_id = a;
		int b = obj.get_frequency();                                // copy constructor
		frequency = b;
		int bb = obj.times;
		times = bb;
	}
	int gettime()
	{
		return times;
	}
	void settimes()
	{
		++times;
		
	}
	void tm(int g)
	{
		times = g;
	}
	void ad(string hg, int lo)
	{
		frequency = lo;
		Doc_id = hg;                             // same as above

	}

	~Doc_info()
	{

	}

};
class Term_info
{
	string keyword;
	List<Doc_info> abj;

public:
	Term_info()
	{
		keyword = '\0';
	}
	string getword()
	{
		return keyword;
	}
	void inst(string a)
	{
		keyword = a;
	}
	void instfrequency(string b, int c)
	{
		Doc_info obj1;
		obj1.add(b, c);                                   //function to add doc_info data in linked list
		abj.inserthead(obj1);

	}
	Term_info(Term_info & obj)
	{
		string ty = obj.getword();
		keyword = ty;
		List<Doc_info> ::iterator atr;                               // copy constructor deep copy
		for (atr = obj.abj.begin(); atr != obj.abj.end(); ++atr)
		{
			Doc_info oj = *atr;
			abj.inserthead(oj);
		}

	}
	Term_info & operator = (Term_info & obj)
	{
		string ty = obj.getword();
		keyword = ty;
		List<Doc_info> ::iterator atr;
		for (atr = obj.abj.begin(); atr != obj.abj.end(); ++atr)
		{
			Doc_info oj = *atr;
			abj.inserthead(oj);
		}
		return *this;

	}
	void print()
	{
		List<Doc_info>::iterator itr;
		cout << keyword << endl;
		for (itr = abj.begin(); itr != abj.end(); ++itr)       // function will print key word and its doc_info data in linked list using iterotr
		{

			Doc_info obj1;
			obj1 = *itr;
			obj1.print();
		}
	}

	bool checklist(string hh)
	{
		List<Doc_info>::iterator itr;
		int point = 0;
		for (itr = abj.begin(); itr != abj.end(); ++itr)
		{
			Doc_info obj1;
			obj1 = *itr;                   // function will be use to check duplicate if data is already entered then return true so new duplicate data will be not be enter else return false
			if (hh == obj1.get_id())
			{

				point = point + 1;
			}

		}
		if (point == 1)
		{
			return true;
		}
		if (point == 0)
		{
			return false;
		}
	}
	string geti(int ll)
	{
		if (ll == abj.getsize1())
		{
			string as = "ab";
			return as;
		}                                   // This Function will be use to acess linked list all  data id  one by one according to size and no 
		if (ll < abj.getsize1())
		{
			List<Doc_info>::iterator itr;
			int xx = 0;
			for (itr = abj.begin(); itr != abj.end(); ++itr)
			{

				Doc_info obj1;
				obj1 = *itr;
				if (xx == ll)
				{
					string ht;
					ht = obj1.get_id();
					return ht;
				}
				++xx;
			}

		}
	}
	int getfre(int pp)
	{
		if (pp == abj.getsize1())
		{
			return 0;
		}
		if (pp < abj.getsize1())
		{
			List<Doc_info>::iterator itr;
			int xx = 0;
			for (itr = abj.begin(); itr != abj.end(); ++itr)
			{

				Doc_info obj1;
				obj1 = *itr;
				if (xx == pp)
				{                                     // This function will be use to acess frequency of of every linked list doc id 
					int ht;
					ht = obj1.get_frequency();
					return ht;
				}
				++xx;
			}

		}

	}
	~Term_info()
	{

	}

};
class search_engine
{
	Term_info * indexlist;
	int array_size;
	int array_max;
public:
	search_engine()
	{
		array_max = 200;                        //default constutor wiill make array of size 200
		indexlist = new Term_info[array_max];
		array_size = 0;
	}
	void add(string ac, int nsize)
	{
		char filename[30];
		int index = 0;                                       // This function will add data in index and will mke linked list
		int co = 0;

		int b = 0;
		int c = 0;



		for (int a = 0; a < nsize; ++a)
		{
			b = a;
			filename[co] = ac[a];                //this is first token of file name until first space space occur or equal to string size

			c = b + 1;

			if ((ac[c] == ' ') || (c == nsize))
			{
				filename[++co] = '\0';

				string cn = filename;              

				ifstream fin;
				fin.open(cn);          // This will open file accoding to name
				string read;
				getline(fin, read); // this will read the whole file with space at one time
				/*cout << read << endl;*/
				fin.close(); // this will close file
				++a;
				co = 0;
				char token[30];   // declare to store first token of file data
				int cf = 0;
				int ff = 0;
				int siz = read.length();  // storing the size of file 
				for (int dd = 0; dd < siz; ++dd)
				{
					token[cf] = read[dd];   // it will make token and store until first space occur or until null occur
					ff = dd + 1;

					if ((read[ff] == ' ') || (read[ff] == '\0'))
					{
						token[++cf] = '\0';
						int yy = 0;
						string gg = token;                   // storing first token in string
						int sit = gg.length();
						int occur = 0;

						string hh;
						fin.open(cn);          // again opening file to check occuren of token in whole file how many time it occur in file
						while (!fin.eof())
						{
							fin >> hh;
							if (hh == gg)
							{
								++occur; // counter to count occurence of token
							}

						}
						fin.close();

						if (array_size == array_max)            // reallocting array with double size if previous size is full 
						{

							Term_info*tmp = new Term_info[array_max];
							for (int ww = 0; ww < array_size; ++ww)
							{
								tmp[ww] = indexlist[ww];            // storing first in temporary array

							}
							delete[]indexlist;


							array_max = array_max + array_max;    // doubling the size

							indexlist = new Term_info[array_max];   // allocating size according to new one

							for (int dd = 0; dd < array_size; ++dd)
							{

								indexlist[dd] = tmp[dd];
							}

							delete[]tmp; // dealloctig the temporay array
						}

						int check = 0;   //this check point will be use to check word exist in index list or not

						for (int ww = 0; ww < array_size; ++ww)
						{

							if (indexlist[ww].getword() == gg)   // if word alreading exist in index 
							{

								bool qw = indexlist[ww].checklist(cn);  // funtion to check duplicate 
								if (qw == false)
								{
									indexlist[ww].instfrequency(cn, occur);   // if no duplicate then enter data in linked list
								}
								check = 1;
							}
						}
						if (check == 0)  // if word not exist in index 
						{
							if (array_size < array_max)
							{                                    
								
								indexlist[array_size].inst(gg);           // entering keyword
								indexlist[array_size].instfrequency(cn, occur); // entering data in linked list
								++array_size; 
							}
						}
						cf = 0;   // this for token 
						++dd; // increment to skip space
						if (dd == siz)
						{
							--dd;
						}
					}
					else
					{
						++cf; // this is for token if no space occur or word is not completed then increment to store token 
					}
				}
			}
			else
			{
				++co; // this for storing file name if word is not completed then increment
			}
		}
	}
	void search(string oo)
	{

		int arsize = 50;
		Term_info *tp = new Term_info[arsize];
		int arra = 0;
		int sizh = oo.length(); // calculting the size of query string
		char tokn[30];
		int uu = 0;
		for (int cv = 0; cv < sizh; ++cv)
		{
			tokn[uu] = oo[cv];     // tokenizing 
			int hh = cv + 1;
			if ((oo[hh] == ' ') || (hh == sizh))    // if word completed token is formed 
			{
				tokn[++uu] = '\0';
				string jj = tokn;

				for (int se = 0; se < array_size; ++se)
				{
					if (arra == arsize)                    // reallocating size if array is full
					{
						Term_info *lt = new Term_info[array_size];
						for (int sw = 0; sw < arra; ++sw)
						{
							lt[sw] = tp[sw];
						}
						delete[]tp;
						arsize = arsize + arsize;
						tp = new Term_info[arsize];
						for (int ww = 0; ww < arra; ++ww)
						{
							tp[ww] = lt[ww];
						}
						delete[]lt;
					}
					if (indexlist[se].getword() == jj)          // if word match the index then story in temp array
					{
						tp[arra] = indexlist[se];
						++arra;

					}

				}
				++cv; // this is for to skip space 
				uu = 0;
			}

			else
			{
				++uu;     // this is for token if word is not completed
			}
			//for (int sr = 0; sr < arra; ++sr)
			//{
			//	tp[sr]->print();
			//}
		}
		int dx = 0;
		
		int lp = 50;
		Doc_info *rte;
		rte = new Doc_info[lp];                   //making temporay array of doc_info 
		/*rte = new Doc_info*[lp];*/

		//Doc_info kj[50];


		/*rte[1]->ad(hq,4);*/
		//kj[0].add(hq, 4);
		//kj[0].print();
		//Doc_info obj;
		//obj.add(hq, 5);
		//obj.print();


		for (int cc = 0; cc < arra; ++cc)
		{

			for (int vv = 0; vv > -1; ++vv)
			{

				if (dx == lp)                  // reallocting array to  if array is full 
				{
					lp = lp + lp;
					Doc_info *tap = new Doc_info[dx];
					for (int a = 0; a < dx; ++a)
					{
						tap[a] = rte[a];
					}
					delete[]rte;
					rte = new Doc_info[lp];
					for (int ss = 0; ss < dx; ++ss)
					{
						rte[ss] = tap[ss];

					}
					delete[]tap;
				}

				string jj = tp[cc].geti(vv);    // storing the linked list  data of matched query word in temp _doc info array storing doc id and frequecncy

				int k1 = tp[cc].getfre(vv);

				if ((jj != "ab") && (k1 != 0))    // ab and 0 equal to means linked list data is ended 
				{


					
					rte[dx].add(jj, k1);         // storing data in doc_info array
					++dx;

				}
				else
				{

					vv = -100;
				}
			}

		}
		//for (int as = 0; as < dx; ++as)
		//{
		//	rte[as].print();
		//}
		//
		//for (int fg = 0; fg < dx; ++fg)
		//{
		//	for (int jh = 1 + fg; jh < dx; ++jh)
		//	{
		//		if (rte[fg].get_frequency() < rte[jh].get_frequency())
		//		{
		//			Doc_info temp;
		//			temp.add(rte[fg].get_id(), rte[fg].get_frequency());
		//			rte[fg].add(rte[jh].get_id(), rte[jh].get_frequency());					
		//			rte[jh].add(temp.get_id(), temp.get_frequency());
		//		}
		//	}		
		//}
		for (int hy = 0; hy < dx; ++hy)
		{
			if (rte[hy].get_frequency() != 0)                    
			{
				for (int yu = 0; yu < dx; ++yu)
				{
					if (rte[yu].get_frequency() != 0)
					{
						if (hy != yu) //            this function will store data if doc 1 have two or query words then it will plus all the words frequncy exist in his doc
						{
							if (rte[hy].get_id() == rte[yu].get_id())
							{
								int hu = rte[hy].get_frequency() + rte[yu].get_frequency();
								rte[hy].setfre(hu);
								rte[hy].settimes();
								rte[yu].setfre(0);
							}
						}
					}
				}
			}
		}

		for (int fg = 0; fg < dx; ++fg)
		{

			for (int jh = 1 + fg; jh < dx; ++jh)                       //This function is similar to array sorting in descending order this sort docinfo data according no of query words doc having more query word will be ranked first
			{
				if (rte[fg].gettime() < rte[jh].gettime())        
				{
					Doc_info temp;
					temp.add(rte[fg].get_id(), rte[fg].get_frequency());
					temp.tm(rte[fg].gettime());
					rte[fg].add(rte[jh].get_id(), rte[jh].get_frequency());
					rte[fg].tm(rte[jh].gettime());
					rte[jh].add(temp.get_id(), temp.get_frequency());
					rte[jh].tm(temp.gettime());
				}
			}
		}

		for (int fg = 0; fg < dx; ++fg)
		{

			for (int jh = 1 + fg; jh < dx; ++jh)   // this function will rank according to frequcny  after ranking according to query words
			{
				if (rte[fg].gettime() == rte[jh].gettime()) 
				{

					if (rte[fg].get_frequency() < rte[jh].get_frequency())  
					{
						Doc_info temp;
						temp.add(rte[fg].get_id(), rte[fg].get_frequency());
						rte[fg].add(rte[jh].get_id(), rte[jh].get_frequency());
						rte[jh].add(temp.get_id(), temp.get_frequency());
					}
				}
			}
		}

		for (int fg = 0; fg < dx; ++fg)
		{

			for (int jh = 1 + fg; jh < dx; ++jh)
			{                                                //This will sort data if two doc have same frequcny and same no of query words then it will ranks according alphabatical order
				if (rte[fg].gettime() == rte[jh].gettime())
				{

					if (rte[fg].get_frequency() == rte[jh].get_frequency())
					{
						if (rte[fg].get_id() > rte[jh].get_id())
						{
							Doc_info temp;
						temp.add(rte[fg].get_id(), rte[fg].get_frequency());
						rte[fg].add(rte[jh].get_id(), rte[jh].get_frequency());
						rte[jh].add(temp.get_id(), temp.get_frequency());
					    }
					}
				}
			}
		}

		for (int ft = 0; ft < dx; ++ft)
		{
			if (rte[ft].get_frequency() != 0)
			{
				rte[ft].print();                 // This will print the final result stored in temporay array of doc_info 
			}
		}
		delete[]rte;
	}
	void prit()
	{
		for (int xx = 0; xx < array_size; ++xx)
		{
			indexlist[xx].print();
			

		}
	}

	~search_engine()
	{
		                              // destructor all dynamicillay index will be deallocatted
		delete[]indexlist;
		indexlist = nullptr;
	}

};
int main()
{


	string ab = "Doc1.txt Doc2.txt Doc3.txt Doc4.txt Doc5.txt";   // stored defult stored  file name 
	string lk = "Doc1.txt";
	search_engine *abj = new search_engine;
	abj->add(ab, 44);             // adding file data making index and linked list
	/*abj->prit();*/

	int po = 0;
	while (po != 3)
	{
		cout << "Press 1 to Search  " << endl;
		cout << "Press 2 To Add Doc " << endl;
		cout << "Press 3 To Exit " << endl;
		cin >> po;

		if (po == 1)
		{


			string str;
			cout << "Please enter your query: " << endl;   // User will input query words
			cin.ignore();
			getline(cin, str);

			abj->search(str);

		}
		if (po == 2)
		{
			string li;
			cout << "Enter Your File Name" << endl;
			cin >> li;             // user will enter filename to add to index if any new he wants
			int st = li.length();
			abj->add(li, st);
		}
	}
	delete abj;

	system("pause");
}