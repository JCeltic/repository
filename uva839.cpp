#include <iostream>
//递归输入
bool solve(int& w)
{
    using namespace std;
    bool b1=true,b2=true;//b1,b2作为创建子树是否成功的标志
    int w1,d1,w2,d2,ww;
    cin>>w1>>d1>>w2>>d2;
    if(!w1) b1=solve(w1);
    if(!w2) b2=solve(w2);
    ww=w1+w2;
    return b1&&b2&&(w1*d1==w2*d2);
}
int main(int argc, char const *argv[])
{
    using namespace std;
    int T,W;
    std::cin>>T;
    while (T--)
    {
        /* code */
        if(solve(W)) cout<<"YES";else cout<<"NO";
        if(T) cout<<"\n"; 
    }
    return 0;
}
