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
//	int j = 0, k = -1;      // f函数    其中f[i]=k      k  保存的是下标      
//	next[0] = -1;       //初始化的时候   之所以给    f[0]=-1   
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
//	int j = 0, k = -1;               // f函数    其中f[i]=k      k  保存的是下标      
//	next[0] = -1;                       //初始化的时候   之所以给    f[0]=-1   
//	while (j<pat.size() - 1){
//		if (k == -1 || pat[k] == pat[j]){
//			next[++j] = ++k;
//		}
//		else k = next[k];
//	}
//}
////next数组
//int KMP_Find(const string &ob, const string &pat, int p = 0){
//	int *next = new int[pat.size()];
//	getNext(pat, next);
//	for (int i = 0; i < pat.size(); i++)cout << i << " " << next[i] << endl;
//	int i = p, j = 0;
//	while (i < ob.size() && j < pat.size() && pat.size() - j <= ob.size() - i){
//		if (pat[j] == ob[i]){       //如果等      i   和   j   都同步增加
//			i++;     //这里输出的是每次匹配成功的  下标
//			j++;
//		}
//		else {        //不等的话     i   暂时不用增        
//			j =next[j];           //失效函数保存的是匹配失效时  下一个 比较的是 
//			                                 //f[j]   的值   （排除   j  =-1的情况）
//			if (j == -1)j++, i++;    //如果   j==-1, 这个情况是特别的 
//		}          //   也就相当于  模式串串的第一个字符  都没有匹配
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
//		if (ans < 0)cout << "未能匹配" << endl;
//		else cout << "匹配位置为  " << ans << endl;
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
////	int j = 0, k = -1;               // f函数    其中f[i]=k      k  保存的是下标      
////	next[0] = -1;                       //初始化的时候   之所以给    f[0]=-1   
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
////		if (pat[j] == ob[i]){       //如果等      i   和   j   都同步增加
////			i++;     //这里输出的是每次匹配成功的  下标
////			j++;
////		}
////		else {        //不等的话     i   暂时不用增        
////			j = next[j];           //失效函数保存的是匹配失效时  下一个 比较的是 
////			//f[j]   的值   （排除   j  =-1的情况）
////			if (j == -1)j++, i++;    //如果   j==-1, 这个情况是特别的 
////		}          //   也就相当于  模式串串的第一个字符  都没有匹配
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