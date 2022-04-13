#include <iostream>
#include <string>
using namespace std; 
int KMP(string t, string p)
{
    int m,n,i,j,f=0;
    m = t.length();
    n = p.length(); 
    if (n == 0)
    {
        cout<<"The pattern occurs with shift 0";
        return 0;
    } 
    if (m < n)
    {
        cout<<"Pattern not found";
        return 0;
    }
    int next[n+1]; 
    for (i=0;i<n+1;i++)
        next[i]=0;
    for (i=1;i<n;i++)
    {
        j=next[i+1]; 
        while (j > 0 && p[j]!=p[i])
            j=next[j];
        if (j>0 || p[j]==p[i])
            next[i+1]=j+1;
    } 
    for (i=0,j=0;i<m;i++)
    {
        if (t[i]==p[j])
        {
            if (++j == n)
            {
                f=1;
                return i-j+2;
            }
        }
        else if (j > 0)
        {
            j=next[j];
            i--;    
        }
    }
    if(f!=1)
        cout<<"Pattern not found";
    return 0;
}
int main()
{    
    int i,n,m,c=0,f,s=0,d,k,nf=0,pos=0;
    cin>>n;
    cin>>m;
    f=n-m;
    string t[n],p[m];
    for(i=0;i<n;i++)
    
    {
        cin>>t[i];
    for(i=0;i<m;i++)
        cin>>p[i];
    while(s!=m-1)
    {
        d=0;
        for(i=c;i<=f;i++)
        {
            if(d==0)
            {
                d=KMP(t[i],p[s]);
                k=i;
            }
            else
                break;
        }
        if(d!=0)
        {
            if(c==0)
                pos=k;
            c=k+1;
            f=c;
            s++;            
        }
        else
        {
            nf=1;
            break;
        }
    }
    if(nf==1)
        cout<<0<<endl;
    else
    {
        pos=pos*10+d-1;
        cout<<pos<<endl;
    }
    return 0;
}