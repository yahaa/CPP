//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<string>
//#include<Windows.h>
//#include<vector>
//using namespace std;
//struct T{
//	int i, j;
//};
//
//int sut = 0, fat = 0;
//void getNext(const string&pat, int *next){    
//	int j = 0, k = -1;      // f����    ����f[i]=k      k  ��������±�      
//	next[0] = -1;       //��ʼ����ʱ��   ֮���Ը�    f[0]=-1   
//	while (j<pat.size() - 1){      
//		if (k == -1 || (pat[k] == pat[j] && pat[j] != pat[j + 1])){
//			next[++j] = ++k;
//		}
//		else k = next[k];
//	}
//}
//
//
//void getNext(const string &pat, int *next){
//	int j = 0, k = -1;               // f����    ����f[i]=k      k  ��������±�      
//	next[0] = -1;                       //��ʼ����ʱ��   ֮���Ը�    f[0]=-1   
//	while (j<pat.size() - 1){
//		if (k == -1 || pat[k] == pat[j]){
//			next[++j] = ++k;
//		}
//		else k = next[k];
//	}
//}
////next����
//int KMP_Find(const string &ob, const string &pat, int p = 0){
//	int *next = new int[pat.size()];
//	getNext(pat, next);
//	for (int i = 0; i < pat.size(); i++)cout << i << " " << next[i] << endl;
//	int i = p, j = 0;
//	while (i < ob.size() && j < pat.size() && pat.size() - j <= ob.size() - i){
//		if (pat[j] == ob[i]){       //�����      i   ��   j   ��ͬ������
//			i++;     //�����������ÿ��ƥ��ɹ���  �±�
//			j++;
//		}
//		else {        //���ȵĻ�     i   ��ʱ������        
//			j =next[j];           //ʧЧ�����������ƥ��ʧЧʱ  ��һ�� �Ƚϵ��� 
//			                                 //f[j]   ��ֵ   ���ų�   j  =-1�������
//			if (j == -1)j++, i++;    //���   j==-1, ���������ر�� 
//		}          //   Ҳ���൱��  ģʽ�����ĵ�һ���ַ�  ��û��ƥ��
//	}
//	delete[]next;
//	if (j < pat.size())return -1;
//	else return i - j;
//}
//int main(){
//	string s;
//	string t;
//	cin >> s;
//	while (1){
//		cin >>t;
//		sut = 0;
//		fat = 0;
//		int ans = KMP_Find(s, t, 0);
//		if (ans < 0)cout << "δ��ƥ��" << endl;
//		else cout << "ƥ��λ��Ϊ  " << ans << endl;
//	
//
//		
//	}
//}
//
//
////#include<iostream>
////#include<cstdio>
////#include<cstring>
////#include<string>
////#include<vector>
////using namespace std;
////void getNext(const string &pat, int *next){
////	int j = 0, k = -1;               // f����    ����f[i]=k      k  ��������±�      
////	next[0] = -1;                       //��ʼ����ʱ��   ֮���Ը�    f[0]=-1   
////	while (j<pat.size() - 1){
////		if (k == -1 || (pat[k] == pat[j] && pat[j] != pat[j + 1])){
////			next[++j] = ++k;
////		}
////		else k = next[k];
////	}
////}
////int KMP_Find(const string &ob, const string &pat, int p = 0){
////	int *next = new int[pat.size()];
////	getNext(pat, next);
////	int i = p, j = 0;
////	while (i < ob.size() && j < pat.size() && pat.size() - j <= ob.size() - i){
////		if (pat[j] == ob[i]){       //�����      i   ��   j   ��ͬ������
////			i++;     //�����������ÿ��ƥ��ɹ���  �±�
////			j++;
////		}
////		else {        //���ȵĻ�     i   ��ʱ������        
////			j = next[j];           //ʧЧ�����������ƥ��ʧЧʱ  ��һ�� �Ƚϵ��� 
////			//f[j]   ��ֵ   ���ų�   j  =-1�������
////			if (j == -1)j++, i++;    //���   j==-1, ���������ر�� 
////		}          //   Ҳ���൱��  ģʽ�����ĵ�һ���ַ�  ��û��ƥ��
////	}
////	delete[]next;
////	if (j < pat.size())return -1;
////	else return i - j;
////}
////int main(){
////	string s, t, b;
////	int ans;
////	while (cin >> s >> t){
////		getchar();
////		ans = 0;
////		for (int i = 1; i < t.size(); i++){
////			b = t.substr(0, i);
////			if (KMP_Find(s, b, 0) >= 0)ans++;
////			else break;
////		}
////		printf("%d\n", ans);
////	}
////}