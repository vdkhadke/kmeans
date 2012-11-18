

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string.h>
#include <stdlib.h>

using namespace std;

typedef std::vector<int> valuevector;
typedef std::map<int, valuevector > vmap;
typedef std::map<int, vector<int> >::const_iterator vmapIterator;
typedef vector<int>::const_iterator valuevectorIterator;


valuevector value;
vmap mymap;


int main(int argc, char ** argv)
{
    ifstream myfile;
    myfile.open("breast-cancer-wisconsin.data");
    string line;
    long key;
    int kvalue;
    char * cptr;
    long datakeys[700] = {0};
    //insert all the values in a map <int, vector>
    while (getline(myfile, line))
    {
      char *c;
      c = &line[0];
      cptr = strtok(c,",");

      key = (long)atoi(cptr);

      //cout<<key<<endl;

      while (cptr != NULL)
      {
    	//cout<< cptr <<endl;
		cptr = strtok(NULL, ",");
		if(cptr !=NULL)
		{
			int temp = atoi(cptr);
			value.push_back(temp);
		}//end if cptr null
      }//end while cptr null
      int a[10]= {0};
      if(mymap.count(key) > 0)
      {
    	//average the two value vectors
		//cout << "Key: " << iter->first << endl << "Values:";

		//cout << value.size();

		for (unsigned int i=0; i<value.size(); i++)
		{
		  a[i] = value[i];
		}
		value.clear();
		//Clear the value vector
    	vmapIterator iter = mymap.find(key);

    	int itr = 0;
		for (valuevectorIterator vec_iter = iter->second.begin(); vec_iter != iter->second.end(); vec_iter++)
		{
				a[itr] =  (*vec_iter + a[itr]) /2;
				itr++;
			//cout<<value.size()<<endl;
		}

		for (int i=0; i<(sizeof(a)/sizeof(int)); i++)
		{
			/*
			if (i==0)
			cout << key<<endl;
			cout<< a[i]<<" "<<endl;
			*/
			value.push_back(a[i]);
		}
      }// end if mymap count
      mymap[key] = value;
      value.clear();
    }//end while getline

/*****************To list the contents of map *************/


    int i = 0;
	 for (vmapIterator iter = mymap.begin(); iter != mymap.end(); iter++)
	 {
		 cout << "Key: " << iter->first << endl << "Values:";
		 datakeys[i++] = iter->first;
		 for (valuevectorIterator vec_iter = iter->second.begin(); vec_iter != iter->second.end(); vec_iter++)
		 {
			 //cout << " " << *vec_iter << " ";
			 //cout<<value.size()<<endl;
		 }
		 //cout<<endl;
	 }
	//cout<<mymap.size();
	 for(int i = 0; datakeys[i]>0; i++)
	 {
		 cout<<datakeys[i]<< endl;
	 }
	cout << "enter the number of clusters" <<endl;
	cin >> kvalue;

//Select random k values as clusters
	for(int i =0; i < kvalue; i++)
	{
		srand(time(NULL));
		int i=0;
		while(i<5)
		{
		        cout<<rand() % mymap.size()<<endl;
		        i++;
		}


	}

	// Done with inserting in map;
}//End main
