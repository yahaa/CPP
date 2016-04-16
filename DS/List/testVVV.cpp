#include"seList.h"
#include"linkList.h"
#include"Node.h"
#include"Stack.h"
#include<queue>
//#include"linkList2.h"

using namespace std;

int  Ack(int m, int n){       //递归版本                 //第二次作业       第十题                     
	if (m == 0)return n + 1;
	else if (m != 0 && n == 0)return Ack(m - 1, 1);
	else if (n != 0 && m != 0)return Ack(m - 1, Ack(m, n - 1));
}     





//非递归版本
int Ackmans(int  m,int n)        //调用STL    中的   栈        #include<stack>    //第二次作业       第十题  
{                                
	stack<int>ans;                                      //一下都是模拟分段函数的过程             
	   ans.push(m);                                   //把m  放入栈顶
		while (!ans.empty()){
			m = ans.top();        //去当前栈顶进行操作
		                              //	cout << ans.size() << endl;        //用于跟踪栈的元素个数情况   
			ans.pop();                //把当前栈顶  删除
			if (m == 0){             //模拟分段函数的   第一个条件
				n = n + 1;
				if (ans.empty())break;     // 如果   栈为空   那么      终止while   
			}
			else   if (n == 0){               //模拟分段函数的第二个条件
					m -= 1;
					ans.push(m);              //把   m  -1  后  把m   再放入栈顶   
					n = 1;
				}
				else{                              //模拟分段函数的第三  个条件
					ans.push(m - 1);
					ans.push(m);
					n -= 1;
				}
		}
		return n;       //返回的即为答案    
}    



void testqq(int &sum){    //     sum 是引用形式      第四单元上机第八题
	int x;
	cin>>x;
	if(x==0)sum=0;
	else {
		testqq(sum);
		sum+=x;
	}
	cout<<sum<<endl;
	
}
 



// 修改为非递归版    第四单元上机第八题
void qq(){
	Stack<int> t2;
	int x;
	while(cin>>x){
	t2.push(x);
	}
	int sum=0;
	while(!t2.empty()){
		sum+=t2.Top();
		cout<<sum<<endl;
		t2.pop();
	}
}




//第四单元上机    第七题
void YHSJ() {          
	int n;
	queue<int> d;
	cin >> n;
	for (int i = 1; i <= n; i++){               //核心代码       
		int ele = 0;
		for (int j = 1; j <= i; j++){         //经过一次内循环就会得出  一行数
			if (d.empty())d.push(1);
			d.push(ele + d.front());
			ele = d.front();
			d.pop();
		}
		d.push(1);


		queue<int>temp = d;         //把每一行的结果用temp队列来保存  
		while (!temp.empty()){
			cout << temp.front() << " ";
			temp.pop();
		}
		cout << endl;
	}
}






int main(){
	//int  r[10] = { 1, 4, 4, 1, 6, 4, 5, 4, 6, 7 };
	cout << "ccccccccccccccccccccccccccccccccccccccccccccccccccc" << endl;
	cout<<"测试顺序表"<<endl;
	esqList<int> a;       
	cout << a << endl;      //在表的尾端加入    1----15    这一堆元素
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	a.push_back(6);
	a.push_back(7);
	a.push_back(8);
	a.push_back(9);
	a.push_back(10);
	a.push_back(11);
	a.push_back(12);
	a.push_back(13);
	a.push_back(14);
	a.push_back(15);
	cout << "the size of a is " << a.getLength() << endl;
    cout<<"未逆置前   -------->"<<endl;
	cout << a << endl;
	a.reverse();
	cout << "逆置后  -------->" << endl;
	cout << a << endl;
	//a.deleteDifferent();
	cout<<"删除指定区间的元素------->删除前如上"<<endl;
	a.deleteZoneElem(5, 14);
	cout<<"删除后----------->"<<endl;
	cout << a << endl;


    cout<<"对表排序--------> 排序前如上"<<endl;
	a.sortList();
	cout<<"排序后"<<endl;
	cout << a << endl;
	cout << "tttttttttt    测试重载=运算符    tttttttttttttttt" << endl;
	esqList<int >b = a;        //    a赋值   给    b
	b.addElem(2, 100);        //在b表中指定      下标添加指定元素
	cout << b;             
	b.push_back(1000);         //在b的尾端加入   那么一大堆东西    （测试稳定性用）
	b.push_back(1000);
	cout << "把表中重复出现的元素去掉 留下第一个   去掉前如下" << endl;
	cout << a << endl;
	cout << "去掉重复后如下-------->" << endl;
	a.deleteDifferent();
	cout << a << endl;
	cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
	cout << "测试-----------> b表" << endl;
	cout<<"输出b 的最大长度"<<endl;
	cout << b.getMaxLength() << endl;
	b.deleteDifferent();    //  去掉b 中重复出现的
	cout<<"b 去掉重复后"<<endl;
	cout << b << endl;

	cout << "before delete b" << endl;
	cout << b << endl;
	cout << "在b 中删除指定区间的元素" << endl;
	b.deleteZoneElem(-123, 122);        //第一种区间情况
	cout << "after delete b" << endl;
	cout << b << endl;

	cout << "the size of b is " << b.getLength() << endl;
	b.deleteZoneElem(0, 3);              //第二种区间情况
	cout << "5555555555555" << endl;
	cout << "测试删除指定区间功能完毕" << endl;
	cout<<"测试其他功能"<<endl;
	cout << b.findElem(100) << endl;
	cout << a.getLength() << endl;

    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
	cout << "以上是顺序表的各种测试------------->   下面是测试单链表" << endl << endl;
	linkList<int>v;
	/*v.insert(0, 5);
	v.insert(1, 5);
	v.insert(1, 5);
	v.insert(2,6);*/
	cout<<"在单链表的尾部假如一下一大堆东西"<<endl;
	v.push_back(4);      //在尾部添加
	v.push_back(5);
	v.push_back(6);
	v.push_back(1000);
	v.insert(1, 10000);    //在指定地方添加
	v.push_back(7);
	v.push_back(8);
	v.push_back(9);
	v.push_back(10);
	v.output(cout);         //输出    直接调用输出函数，，，，（当然你也可以重载   <<）
	cout << endl;
	cout << "the elem of 5 is " << v.getIndexElem(5) << endl;
	if (v.empty())cout << "v is empty" << endl;       //测试  empty
	else cout << "not empty" << endl;
	cout<<"测试单链表删除指定位置的元素"<<endl;
	v.erase(5);
	v.exchang(0, 1);      //交换任意位置的连个元素
	v.output(cout);
	linkList<int>g(v);    //测试单链表的拷贝构造函数
	cout << endl;
	g.exchang(1, 6);        //交换任意位置的连个元素
	g.output(cout);         
	cout << endl;
	cout<<" //测试单链表向链表的尾部添加元素"<<endl;
	linkList<int> f;         //测试单链表向链表的尾部添加元素
	f.push_back(1);
	f.push_back(2);
	f.push_back(3);
	f.push_back(4);
	f.push_back(5);
	f.push_back(6);
	f.push_back(7);
	f.push_back(8);
	//f.output(cout);
	linkList<int> ff;
	ff.push_back(1);
	ff.push_back(2);
	ff.push_back(3);
	ff.push_back(4);
	ff.push_back(5);
	ff.push_back(6);
	ff.push_back(7);
	ff.push_back(8);
	ff.output(cout);
	cout << endl;
	ff.reserse();
	ff.output(cout);
	cout << endl;
	cout << endl;
	ff.output(cout);
	cout << endl;

	cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
	cout << "111111111" << endl;
	cout<<"测试插入元素时就给链表排序"<<endl;     
	linkList<int> rr;            //插入时排序比较难     重载   +  并不是很难   
	rr.push_order(15);
	rr.push_order(1);
	rr.push_order(2);   
	rr.push_order(4);
	rr.push_order(5); 
	rr.push_order(1437);
	rr.push_order(-123);

	rr.push_order(7);
	rr.push_order(4);
	rr.push_order(7);
	rr.push_order(3);
	rr.push_order(6);
	/*ff.push_order(1);
	ff.push_order(7);
	
	ff.push_order(9);
	ff.push_order(4);
	ff.output(cout);*/
	rr.output(cout);
	//cout<<endl;

	cout << "测试上机第十题" << endl;
	cout<<endl;
	
	linkList<int> test1;
	test1.push_order(5);
	test1.push_order(2);
	test1.push_order(1);
	test1.push_order(7);
	test1.push_order(8);
	test1.push_order(30);
	test1.push_order(21);
	test1.push_order(56);
	test1.push_order(34);
	test1.push_order(10);
	test1.push_order(2);
	test1.push_order(8);
	test1.push_order(3);
	cout<<"test1 如下"<<endl;
	test1.output(cout);
	cout<<endl;
	
	linkList<int> test2;
	test2.push_order(4);
	test2.push_order(56);
	test2.push_order(76);
	test2.push_order(15);
	test2.push_order(9);
	test2.push_order(7);
	test2.push_order(56);
	test2.push_order(23);
	test2.push_order(11);
    test2.push_order(3);
	cout<<"test1 如下"<<endl;
	test2.output(cout);
	cout<<endl;
	cout<<"test1  +  test2"<<endl;
	(test1+test2).output(cout);
	cout<<endl;
	
    cout<<"测试第四单元上机------------------> <---------------"<<endl;	
	cout<<"测试 上机  第  4  题  Stack   "<<endl;
	
	Stack<int>stack1;
	stack1.push(4);
	//stack1.push(5);
	cout<<stack1.Top();
	
	
	
	cout<<"第四单元   上机第  7  题   "<<endl;
	YHSJ();
	
	/*//动态规划实现     
	    int qu[20][20];
		qu[0][0]=1;
		qu[0][1]=1;
		qu[1][0]=1
		for(int i=2;i<20;i++){
			qu[i][0]=1;
			for(int j=1;j<i;j++)qu[i][j]=qu[i-1][j]+qu[i-1][j-1];
			qu[i][i]=1;
		}
		for(int i=0;i<20;i++){
			for(int j=0;j<=i;j++){
				if(i==j)cout<<qu[i][j]<<endl;
				else cout<<qu[i][j];
			}
		}
	//queue<int>qu;
	//qu.
	*/
	cout<<"第四单元   上机第  8  题   "<<endl;
	int ggg=5;
	testqq(ggg);
	cout<<"改为非递归形式"<<endl;
	qq();
	
	return 0;
}
