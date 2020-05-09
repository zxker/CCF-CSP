#include<bits/stdc++.h>
using namespace std;
struct IP{//IP��ַ��
    string ip="";//IP��ַ32λ�Ķ������ַ���
    int length=-1;//IP��ַ��ǰ׺����
};
IP stringToIp(string&input){//�������IP��ַת��Ϊ32λ������IP��ַ�������ǰ׺����
    IP ip;
    string s="";
    vector<int>pow2={1,2,4,8,16,32,64,128};//2��0~7����
    for(int i=0;i<=input.size();++i)//���������IP��ַ
        if(i==input.size()||!isdigit(input[i])){//�����ַ���ĩβ��ǰ�ַ����������ַ�
            int k=stoi(s);//���ַ���sת��Ϊ����
            for(int ii=7;ii>=0;--ii)//�����ǰ�����Ķ����Ʊ�ʾ
                if(k>=pow2[ii]){
                    ip.ip+="1";
                    k-=pow2[ii];
                }else
                    ip.ip+="0";
            s="";
            if(input[i]=='/'){//������/�ַ��������������ʹ�����ǰ׺����
                ip.length=stoi(input.substr(i+1));
                break;
            }
        }else
            s+=input[i];
    if(ip.length==-1)//�����IP��ַ�в�����ǰ׺����
        ip.length=ip.ip.size();//ǰ׺���ȼ�Ϊ2�����ַ�������
    while(ip.ip.size()<32)//IP��ַС��32λ����ĩβ��0
        ip.ip+="0";
    return ip;
}
bool isChildCollection(IP&a,IP&b){//�ж�IP��ַb�ǲ���IP��ַa��ƥ�伯���Ӽ�
    if(a.length>b.length)
        return false;
    for(int i=0;i<a.length;++i)
        if(a.ip[i]!=b.ip[i])
            return false;
    return true;
}
void Merge1(list<IP>&ipAddress){//��һ���ϲ����Ƴ�ƥ�伯��ǰһIP��ַ�Ӽ���IP��ַ
    auto i=ipAddress.begin(),j=ipAddress.begin();
    for(++j;j!=ipAddress.end();){
        if(isChildCollection(*i,*j)){
            j=ipAddress.erase(j);
        }else{
            ++i;
            ++j;
        }
    }
}
bool unionCollection(IP&a,IP&b){//�ж�IP��ַa��b��ƥ�伯�Ĳ����Ƿ����a'��ƥ�伯
    if(a.length!=b.length)
        return false;
    for(int i=0;i<a.length-1;++i)
        if(a.ip[i]!=b.ip[i])
            return false;
    return a.ip[a.length-1]!=b.ip[a.length-1];
}
void Merge2(list<IP>&ipAddress){//�ڶ����ϲ���ͬ���ϲ�
    auto i=ipAddress.begin(),j=ipAddress.begin();
    for(++j;j!=ipAddress.end();){
        if(unionCollection(*i,*j)){
            j=ipAddress.erase(j);
            --(*i).length;
            if(i!=ipAddress.begin()){
                --i;
                --j;
            }
        }else{
            ++i;
            ++j;
        }
    }
}
int main(){
    int N;
    cin>>N;
    list<IP>ipAddress;
    while(N--){
        string input;
        cin>>input;
        ipAddress.push_back(stringToIp(input));
    }
    ipAddress.sort([](const IP&a,const IP&b){
        if(a.ip!=b.ip)
            return a.ip<b.ip;
        return a.length<b.length;
    });
    Merge1(ipAddress);//��һ���ϲ�
    Merge2(ipAddress);//�ڶ����ϲ�
    for(auto i:ipAddress){//���IP��ַ
        for(int j=0;j<4;++j){//���ÿ8λ2�����ַ�����������������
            int k=0;
            for(int ii=0;ii<8;++ii)
                k=k*2+(i.ip[ii+j*8]-'0');
            printf("%d%s",k,j<3?".":"/");
        }
        printf("%d\n",i.length);//���ǰ׺����
    }
    return 0;
}
