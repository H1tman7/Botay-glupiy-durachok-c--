#include <iostream>
#include <cmath>
int main(){
    float a,b,c,ans1,ans2;std::cin>>a>>b>>c;if(a==0.0){if(c!=0)std::cout<<"x="<<-b/c<<'\n';else std::cout<<"x="<<0.0<<'\n';return 0;}float D=b*b-4*a*c;if(D<0.0)std::cout<<"no roots\n";else if(D==0.0)std::cout<<"x="<<-b/(2*a);else{ans1=((-b)+sqrt(D))/(2*a);ans2=((-b)-sqrt(D))/(2*a);std::cout<<"x1="<<(ans1==-0.0?0.0:ans1)<<'\n';std::cout<<"x2="<<(ans2==-0.0?0.0:ans2)<<'\n';}return 0;
}