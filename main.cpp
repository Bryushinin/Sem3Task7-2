#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    ifstream src("in.txt");

    map<string, vector<string> > M;

    vector<string> A;

    int i,k,f;
    string s,d;


    vector<string>::iterator ai;

    getline(src, d);
    while(d!="textLines:")
    {
        getline(src,d);
        //cout<<d<<endl;
        if(d!="textLines:")
            {A.push_back(d);M[d].push_back(" ");}

    }
    i=0;
    f=1;
    while(f)
    {
        getline(src,d);
        ++i;
        k=d.find_first_of(':',0);
        s=d.substr(0,k);
        //cout<<s<<endl;



        if(d=="")
            f=0;
        else
        {
            d=d.substr(k+1,d.size());
            char t[]={(char)('0'+i),')',' '};
            //cout<<t<<endl;
            d.insert(0, t);
            //cout<<d<<endl;
            M[s].push_back(d);
        }
    }

    ofstream out("out.txt");
    for(ai=A.begin();ai!=A.end();++ai)
    {
        out<<*ai<<":";
        vector<string>::iterator it;
        for(it=M[*ai].begin();it!=M[*ai].end();++it)
            out<<*it<<endl;
    }


    src.close();
    out.close();


    return 0;
}
