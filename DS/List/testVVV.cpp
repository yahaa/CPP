#include"seList.h"
#include"linkList.h"
#include"Node.h"
#include"Stack.h"
#include<queue>
//#include"linkList2.h"

using namespace std;

int  Ack(int m, int n){       //�ݹ�汾                 //�ڶ�����ҵ       ��ʮ��                     
	if (m == 0)return n + 1;
	else if (m != 0 && n == 0)return Ack(m - 1, 1);
	else if (n != 0 && m != 0)return Ack(m - 1, Ack(m, n - 1));
}     





//�ǵݹ�汾
int Ackmans(int  m,int n)        //����STL    �е�   ջ        #include<stack>    //�ڶ�����ҵ       ��ʮ��  
{                                
	stack<int>ans;                                      //һ�¶���ģ��ֶκ����Ĺ���             
	   ans.push(m);                                   //��m  ����ջ��
		while (!ans.empty()){
			m = ans.top();        //ȥ��ǰջ�����в���
		                              //	cout << ans.size() << endl;        //���ڸ���ջ��Ԫ�ظ������   
			ans.pop();                //�ѵ�ǰջ��  ɾ��
			if (m == 0){             //ģ��ֶκ�����   ��һ������
				n = n + 1;
				if (ans.empty())break;     // ���   ջΪ��   ��ô      ��ֹwhile   
			}
			else   if (n == 0){               //ģ��ֶκ����ĵڶ�������
					m -= 1;
					ans.push(m);              //��   m  -1  ��  ��m   �ٷ���ջ��   
					n = 1;
				}
				else{                              //ģ��ֶκ����ĵ���  ������
					ans.push(m - 1);
					ans.push(m);
					n -= 1;
				}
		}
		return n;       //���صļ�Ϊ��    
}    



void testqq(int &sum){    //     sum ��������ʽ      ���ĵ�Ԫ�ϻ��ڰ���
	int x;
	cin>>x;
	if(x==0)sum=0;
	else {
		testqq(sum);
		sum+=x;
	}
	cout<<sum<<endl;
	
}
 



// �޸�Ϊ�ǵݹ��    ���ĵ�Ԫ�ϻ��ڰ���
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




//���ĵ�Ԫ�ϻ�    ������
void YHSJ() {          
	int n;
	queue<int> d;
	cin >> n;
	for (int i = 1; i <= n; i++){               //���Ĵ���       
		int ele = 0;
		for (int j = 1; j <= i; j++){         //����һ����ѭ���ͻ�ó�  һ����
			if (d.empty())d.push(1);
			d.push(ele + d.front());
			ele = d.front();
			d.pop();
		}
		d.push(1);


		queue<int>temp = d;         //��ÿһ�еĽ����temp����������  
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
	cout<<"����˳���"<<endl;
	esqList<int> a;       
	cout << a << endl;      //�ڱ��β�˼���    1----15    ��һ��Ԫ��
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
    cout<<"δ����ǰ   -------->"<<endl;
	cout << a << endl;
	a.reverse();
	cout << "���ú�  -------->" << endl;
	cout << a << endl;
	//a.deleteDifferent();
	cout<<"ɾ��ָ�������Ԫ��------->ɾ��ǰ����"<<endl;
	a.deleteZoneElem(5, 14);
	cout<<"ɾ����----------->"<<endl;
	cout << a << endl;


    cout<<"�Ա�����--------> ����ǰ����"<<endl;
	a.sortList();
	cout<<"�����"<<endl;
	cout << a << endl;
	cout << "tttttttttt    ��������=�����    tttttttttttttttt" << endl;
	esqList<int >b = a;        //    a��ֵ   ��    b
	b.addElem(2, 100);        //��b����ָ��      �±����ָ��Ԫ��
	cout << b;             
	b.push_back(1000);         //��b��β�˼���   ��ôһ��Ѷ���    �������ȶ����ã�
	b.push_back(1000);
	cout << "�ѱ����ظ����ֵ�Ԫ��ȥ�� ���µ�һ��   ȥ��ǰ����" << endl;
	cout << a << endl;
	cout << "ȥ���ظ�������-------->" << endl;
	a.deleteDifferent();
	cout << a << endl;
	cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
	cout << "����-----------> b��" << endl;
	cout<<"���b ����󳤶�"<<endl;
	cout << b.getMaxLength() << endl;
	b.deleteDifferent();    //  ȥ��b ���ظ����ֵ�
	cout<<"b ȥ���ظ���"<<endl;
	cout << b << endl;

	cout << "before delete b" << endl;
	cout << b << endl;
	cout << "��b ��ɾ��ָ�������Ԫ��" << endl;
	b.deleteZoneElem(-123, 122);        //��һ���������
	cout << "after delete b" << endl;
	cout << b << endl;

	cout << "the size of b is " << b.getLength() << endl;
	b.deleteZoneElem(0, 3);              //�ڶ����������
	cout << "5555555555555" << endl;
	cout << "����ɾ��ָ�����书�����" << endl;
	cout<<"������������"<<endl;
	cout << b.findElem(100) << endl;
	cout << a.getLength() << endl;

    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
	cout << "������˳���ĸ��ֲ���------------->   �����ǲ��Ե�����" << endl << endl;
	linkList<int>v;
	/*v.insert(0, 5);
	v.insert(1, 5);
	v.insert(1, 5);
	v.insert(2,6);*/
	cout<<"�ڵ������β������һ��һ��Ѷ���"<<endl;
	v.push_back(4);      //��β�����
	v.push_back(5);
	v.push_back(6);
	v.push_back(1000);
	v.insert(1, 10000);    //��ָ���ط����
	v.push_back(7);
	v.push_back(8);
	v.push_back(9);
	v.push_back(10);
	v.output(cout);         //���    ֱ�ӵ����������������������Ȼ��Ҳ��������   <<��
	cout << endl;
	cout << "the elem of 5 is " << v.getIndexElem(5) << endl;
	if (v.empty())cout << "v is empty" << endl;       //����  empty
	else cout << "not empty" << endl;
	cout<<"���Ե�����ɾ��ָ��λ�õ�Ԫ��"<<endl;
	v.erase(5);
	v.exchang(0, 1);      //��������λ�õ�����Ԫ��
	v.output(cout);
	linkList<int>g(v);    //���Ե�����Ŀ������캯��
	cout << endl;
	g.exchang(1, 6);        //��������λ�õ�����Ԫ��
	g.output(cout);         
	cout << endl;
	cout<<" //���Ե������������β�����Ԫ��"<<endl;
	linkList<int> f;         //���Ե������������β�����Ԫ��
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
	cout<<"���Բ���Ԫ��ʱ�͸���������"<<endl;     
	linkList<int> rr;            //����ʱ����Ƚ���     ����   +  �����Ǻ���   
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

	cout << "�����ϻ���ʮ��" << endl;
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
	cout<<"test1 ����"<<endl;
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
	cout<<"test1 ����"<<endl;
	test2.output(cout);
	cout<<endl;
	cout<<"test1  +  test2"<<endl;
	(test1+test2).output(cout);
	cout<<endl;
	
    cout<<"���Ե��ĵ�Ԫ�ϻ�------------------> <---------------"<<endl;	
	cout<<"���� �ϻ�  ��  4  ��  Stack   "<<endl;
	
	Stack<int>stack1;
	stack1.push(4);
	//stack1.push(5);
	cout<<stack1.Top();
	
	
	
	cout<<"���ĵ�Ԫ   �ϻ���  7  ��   "<<endl;
	YHSJ();
	
	/*//��̬�滮ʵ��     
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
	cout<<"���ĵ�Ԫ   �ϻ���  8  ��   "<<endl;
	int ggg=5;
	testqq(ggg);
	cout<<"��Ϊ�ǵݹ���ʽ"<<endl;
	qq();
	
	return 0;
}
