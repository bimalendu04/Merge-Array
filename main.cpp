#include <iostream>
#include<string>
#include <cstdlib>
#include <sstream>

using namespace std;
int NtS ( string myS );
int getx(int x,string st);


int main()
{
    int n,m,i,j,k;
int l1 = 0;
int l2=0;

   cout<<"Enter the elements of first array"<<endl;
  string r;
   getline(cin,r);

   cout<<"Enter the elements of second array"<<endl;

   string s;
   getline(cin,s);

   for (int z = 0; z < r.length(); z++) {
    if (r[z] == ' ') {
        l1++;
    }
}
n=l1+1;
cout<<n<<endl;

for (int z = 0; z < s.length(); z++) {
    if (s[z] == ' ') {
        l2++;
    }
}
m=l2+1;
cout<<m<<endl;

    int *a = new int[n];
   int *b = new int[m];
   int *c = new int[n+m];

for(i=0;i<n;i++)
   {
       a[i]=getx(i,r);
}

for(i=0;i<m;i++)
   {
       b[i]=getx(i,s);
}



    cout<<"You entered the arrays : "<<endl;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(i=0;i<m;i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]<a[j])
            {
                a[i]=a[i]+a[j];
                a[j]=a[i]-a[j];
                a[i]=a[i]-a[j];
            }
        }
    }

    for(i=0;i<m;i++)
    {
        for(j=i+1;j<m;j++)
        {
            if(b[i]<b[j])
            {
                b[i]=b[i]+b[j];
                b[j]=b[i]-b[j];
                b[i]=b[i]-b[j];
            }
        }
    }

    cout<<endl;
    cout<<endl;
    cout<<"Sorted Arrays are:"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(i=0;i<m;i++)
    {
        cout<<b[i]<<" ";
    }

    i=0;
    j=0;
    for(k=0;k<(m+n);k++)
    {
        if((i!=n) && (j!=m))
        {
            if(a[i]>b[j])
            {
                c[k]=a[i];
                i++;
            }
            else if(a[i]==b[j])
            {
                c[k]=a[i];
                i++;
            }
            else
            {
                c[k]=b[j];
                j++;
            }
        }
        else
        {
            if(i==n)
            {
                c[k]=b[j];
                j++;
            }
            else
            {
                c[k]=a[i];
                i++;
            }
        }
    }

    cout<<endl;
    cout<<endl;
    cout<<"Sorted and merged : "<<endl;
    for(k=0;k<(m+n);k++)
    {
        cout<<c[k]<<" ";
    }
    delete [] a;
    delete [] b;
    delete [] c;
    return 0;



}

int NtS ( string myS )
{
    istringstream buffer(myS);
    int value=0;
    buffer >> value;

    return value;

}


int getx(int x,string st)
{
    int nr=0;
    string ret="";
    for(int i=0;i<st.size();++i)
        {
            if(st[i]==' '){
                ++nr;
                continue;
                }
            if(nr==x)
                ret = ret + st[i];
        }

    return NtS(ret);
}

