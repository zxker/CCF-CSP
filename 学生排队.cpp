#include<bits/stdc++.h>
using namespace std;
unordered_map<string,string>ans;//�洢��ֵ��
stringstream all;//���ո��ַ��ָ��ַ���
bool DFS(string key){//�ݹ鴦����
    string value;
    all>>value;//��ȡ��ǰ��ֵ
    if(value=="}")//��������
        return false;//����false����ʾ��ǰֵ�����Ѷ�ȡ���
    if(value=="{"){//��������
        if(key!="")//�����ǿ��ַ���
            ans[key]="{}";//�ü���Ӧ��ֵ��һ������
        while(DFS(key));//�ݹ鴦��ֵ����
    }else{
        string v=value.substr(1,value.rfind('"')-1);//��ȥ���˵������ַ���ʣ����������ַ���
        if(value.back()==':')//ĩβ��:�ַ�����ʾ���ַ����Ǽ�
            DFS((key=="")?v:(key+"."+v));//�ݹ鴦����ֵ
        else//���ַ�����ֵ
            ans[key]=v;//������ֵӳ������
    }
    return true;
}
int main(){
    int n,m;
    scanf("%d%d%*c",&n,&m);
    string s="";
    while(n--){//��n��JSON�ı���ȡ���ַ���s��
        string line;
        getline(cin,line);
        s+=line;
    }
    s=regex_replace(s,regex(" "),"");//ȥ��s�����еĿո��ַ�
    s=regex_replace(s,regex("\\\\\""),"\"");//������������\"�ַ�ת��Ϊ����"�ַ�
    s=regex_replace(s,regex("\\\\\\\\"),"\\");//������������\\�ַ�ת��Ϊ����\�ַ�
    s=regex_replace(s,regex(","),", ");//��ÿ��,�ַ������һ���ո��ַ�
    s=regex_replace(s,regex(":"),": ");//��ÿ��:�ַ������һ���ո��ַ�
    s=regex_replace(s,regex("\\{")," { ");//��ÿ��{�ַ����Ҿ���ӿո��ַ�
    s=regex_replace(s,regex("},?")," } ");//��ÿ��}�ַ����Ҿ���ӿո��ַ�
    all<<s;//���ַ���s����all�а��ո�ָ�
    DFS("");//�ݹ鴦��
    while(m--){//���в�ѯ
        cin>>s;
        if(ans.find(s)==ans.end())
            puts("NOTEXIST");
        else if(ans[s]=="{}")
            puts("OBJECT");
        else
            printf("STRING %s\n",ans[s].c_str());
    }
    return 0;
}

