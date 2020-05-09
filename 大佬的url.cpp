#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    scanf("%d%d%*c",&n,&m);
    string p,r;
    vector<pair<string,regex>>rules;//�洢URL����ӳ��Ϊ������->�����������ʽ
    vector<pair<regex,string>>trans={
        {regex("<int>"),"([0-9]+)"},{regex("<str>"),"([^/]+)"},{regex("<path>"),"(.+)"}
    };
    while(n--){
        cin>>p>>r;
        for(auto&i:trans)
            p=regex_replace(p,i.first,i.second);//������ת��Ϊ��Ӧ��������ʽ
        rules.push_back({r,regex(p)});//������˳��ѹ��rules��
    }
    smatch result;
    while(m--){
        cin>>p;
        for(auto i:rules)//��ÿ��������һ����ƥ��
            if(regex_match(p,result,i.second)){//ƥ��ɹ�
                printf("%s",i.first.c_str());//���������
                for(auto i=1;i<=result.size();++i){//����ÿһ��ƥ�䵽��Ԫ��
                    p=result.str(i).c_str();
                    while(p[0]=='0')//ȥ��ǰ��0
                        p.erase(0,1);
                    printf(" %s",p.c_str());//���
                }
                puts("");//����
                goto loop;//ƥ��ɹ���ֱ��ƥ����һ��URL��ַ
            }
        puts("404");//û��ƥ�䵽�κ�һ���������404
        loop:;
    }
    return 0;
}

