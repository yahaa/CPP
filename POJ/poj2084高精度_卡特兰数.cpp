#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<fstream>
using namespace std;
string res[101];
string MINUS_INT(string str1, string str2);        //高精度减法
string MULTIPLY_INT(string str1, string str2);
string ADD_INT(string str1, string str2);      //高精度加法 
inline int compare(string str1, string str2){
	if (str1.size() > str2.size())return 1;
	else if (str1.size() < str2.size())return -1;
	else return str1.compare(str2);
}

string MINUS_INT(string str1, string str2){
	int sign = 1;
	string str;
	if (str2[0] == '-')str = ADD_INT(str, str2.erase(0, 1));
	else {
		int res = compare(str1, str2);
		if (res == 0)return "0";
		if (res < 0){
			sign = -1;
			string temp = str1;
			str1 = str2;
			str2 = temp;
		}
		string::size_type tempint;
		tempint = str1.size() - str2.size();
		for (int i = str2.size(); i >= 0; i--){
			if (str1[i + tempint] < str2[i]){
				str1[i + tempint - 1] = char(int(str1[i = tempint - 1]) - 1);
				str = char(str1[i + tempint] - str2[i] + 58) + str;
			}
			else str = char(str1[i + tempint] - str2[i] + 48) + str;
		}
		str.erase(0, str.find_first_not_of('0'));
		if (str.empty())str = "0";
		if ((sign == -1) && (str[0] != '0'))str = "-" + str;
		return str;
	}
}
string MULTIPLY_INT(string str1, string str2){               //高精度减法
	int sign = 1;
	string str;
	if (str1[0] == '-'){
		sign *= -1;
		str1 = str1.erase(0, 1);
	}
	if (str2[0] == '-'){
		sign *= -1;
		str2 = str2.erase(0, 1);
	}
	int i, j;
	string::size_type l1, l2;
	l1 = str1.size();
	l2 = str2.size();
	for (i = l2 - 1; i >= 0; i--){
		string tempstr;
		int int1 = 0, int2 = 0,  int3 = int(str2[i] - 48);
		if (int3 != 0){
			for (j = 1; j <= (int)(l2 - 1 - i); j++)tempstr = "0" + tempstr;
			for (j = l1 - 1; j >= 0; j--){
				int1 = (int3*(int(str1[j]) - 48) + int2) % 10;
				int2 = (int3*(int(str1[j]) - 48) + int2) / 10;
				tempstr = char(int1 + 48) + tempstr;
			}
			if (int2 != 0)tempstr = char(int2 + 48) + tempstr;
		}
		str = ADD_INT(str, tempstr);
	}
	str.erase(0, str.find_first_not_of('0'));
	if (str.empty())str = "0";
	if ((sign == -1) && (str[0] != '0'))str = "-" + str;
	return str;

}

string ADD_INT(string str1, string str2){        //       高精度加法
	int  sign = 1;     //sign位符号位
	string str; 
	if (str1[0] == '-'){
		if (str2[0] == '-'){
			sign = -1;
			str = ADD_INT(str.erase(0, 1), str2.erase(0, 1));
		}
		else   str = MINUS_INT(str2, str1.erase(0, 1));
	}
	else if (str[0] == '-')str = MINUS_INT(str1, str2.erase(0, 1));
	else {
		string::size_type  l1, l2;
		int i;
		l1 = str1.size();
		l2 = str2.size();
		if (l1 < l2){
			for (i = 1; i <= l1 - l2; i++)str1 = "0" + str1;
		}
		else {
			for (i = 1; i <= l1 - l2; i++)str2 = "0" + str2;
		}

		int int1 = 0, int2 = 0;
		for (i = str1.size() - 1; i >= 0; i--){
			int1 = (int(str1[i]) - 48 + int(str2[i]) - 48 + int2) % 10;
			int2 = (int(str1[i]) - 48 + int(str2[i]) - 48 + int2) / 10;
			str = char(int1 + 48) + str;
		}

		if (int2 != 0)str = char(int2 + 48) + str;
	}
	if ((sign == -1) && (str[0] != '0'))str = "-" + str;
	return str;
}
void gettalelin(){
	string temp, temp1;
	res[0] = "1";
	res[1] = "1";
	for (int i = 2; i < 101; i++){
		temp1 = "0";
		for (int j = 0; j < i; j++){
			temp = MULTIPLY_INT(res[j], res[i - 1 - j]);
			temp1 = ADD_INT(temp1, temp);
		}
		res[i] = temp1;
	}
		ofstream ans("d:\\tttttttt.txt"); 
		ans << "string res[101]={\n";
		for (int i = 0; i < 101; i++){
			if (i != 0)ans << ",";
			ans << "\"" << res[i] << "\"" << endl;
		}
		ans << "};";
	return;
}
int main(){
	char s[1000000];
	int n;
	cin >> n;
	gettalelin();
	return 0;
}





#include <cstdio>
#include <cstring>
int n;
class BigInt              //长整型 类，实现高精度大数据运算  
{public:
	int data[60];
	BigInt& operator = (const BigInt &ob)         //重载    =
	{
		memcpy(data, ob.data, sizeof(data));
		return *this;
	}
	BigInt& operator  += (const BigInt &ob)       //重载    +=
	{
		if (data[0] < ob.data[0]) data[0] = ob.data[0];         //data[0]用于记录数据的长度       操作从下标1  开始操作
		for (int i = 1; i <= data[0]; ++i)
		{
			data[i] += ob.data[i];            
			if (data[i] >= 10)
			{
				data[i] -= 10;                      //两长数对应为之和  不会超过  20   
				data[i + 1] ++;                   //高位进位
			}
		}
		if (data[data[0] + 1] != 0) data[0] ++;          //判断进行操作后的 最高位是不是有效位   是有效位的话    data[0]++ 即相当于  有效位+1
		return *this;
	}
	void setDigit(int n)        //重置数据   
	{
		memset(data, 0, sizeof(data));
		data[0] = 1;
		data[1] = n;
	}
	BigInt operator * (const BigInt &ob)      //重载     *       
	{
		BigInt pro;
		pro.setDigit(0);
		pro.data[0] = data[0] + ob.data[0] - 1;
		for (int i = 1; i <= data[0]; ++i)
		for (int j = 1; j <= ob.data[0]; ++j)
			pro.data[i + j - 1] += data[i] * ob.data[j];             //采用先加
		for (int i = 1; i <= pro.data[0]; ++i)                    //后进位，的思想
		{
			pro.data[i + 1] += pro.data[i] / 10;
			pro.data[i] %= 10;
		}
		while (pro.data[pro.data[0]] >= 10)      //对最高位进行操作   
		{
			pro.data[pro.data[0] + 1] += pro.data[pro.data[0]] / 10; 
			pro.data[pro.data[0]] %= 10;
			pro.data[0] ++;
		}
		return pro;
	}
	void print()              //输出   
	{
		for (int i = data[0]; i > 0; --i)
			printf("%d", data[i]);
	}
} f[105];
void calc()
{
	f[0].setDigit(1);
	f[1].setDigit(1);
	for (int i = 2; i <= 100; ++i)
	{
		f[i].setDigit(0);
		for (int j = 0; j < i; ++j)
			f[i] += f[j] * f[i - j - 1];
	}
}
int main()
{
	calc();
	while (scanf("%d", &n) && n != -1)
	{
		f[n].print();
		printf("\n");
	}
}






#include <stdio.h>
char list[100][100] = { "1", "2", "5", "14", "42", "132", "429", "1430", "4862", "16796", "58786", "208012", "742900", 
"2674440", "9694845", "35357670", "129644790", "477638700", "1767263190", "6564120420", "24466267020", 
"91482563640", "343059613650", "1289904147324", "4861946401452", "18367353072152", "69533550916004", 
"263747951750360", "1002242216651368", "3814986502092304", "14544636039226909", "55534064877048198", 
"212336130412243110", "812944042149730764", "3116285494907301262", "11959798385860453492", "45950804324621742364", 
"176733862787006701400", "680425371729975800390", "2622127042276492108820", "10113918591637898134020", 
"39044429911904443959240", "150853479205085351660700", "583300119592996693088040", "2257117854077248073253720", 
"8740328711533173390046320", "33868773757191046886429490", "131327898242169365477991900", "509552245179617138054608572", 
"1978261657756160653623774456", "7684785670514316385230816156", "29869166945772625950142417512", "116157871455782434250553845880",
"451959718027953471447609509424", "1759414616608818870992479875972", "6852456927844873497549658464312", "26700952856774851904245220912664",
"104088460289122304033498318812080", "405944995127576985730643443367112", 
"1583850964596120042686772779038896", "6182127958584855650487080847216336", 
"24139737743045626825711458546273312", "94295850558771979787935384946380125", 
"368479169875816659479009042713546950", "1440418573150919668872489894243865350", 
"5632681584560312734993915705849145100", "22033725021956517463358552614056949950",
"86218923998960285726185640663701108500", "337485502510215975556783793455058624700", 
"1321422108420282270489942177190229544600", "5175569924646105559418940193995065716350", 
"20276890389709399862928998568254641025700", "79463489365077377841208237632349268884500", 
"311496878311103321137536291518809134027240", "1221395654430378811828760722007962130791020", 
"4790408930363303911328386208394864461024520", "18793142726809884575211361279087545193250040", 
"73745243611532458459690151854647329239335600", "289450081175264899454283846029490767264392230", 
"1136359577947336271931632877004667456667613940", "4462290049988320482463241297506133183499654740",
"17526585015616776834735140517915655636396234280", "68854441132780194707888052034668647142985206100", 
"270557451039395118028642463289168566420671280440", "1063353702922273835973036658043476458723103404520", 
"4180080073556524734514695828170907458428751314320", "16435314834665426797069144960762886143367590394940", 
"64633260585762914370496637486146181462681535261000", "254224158304000796523953440778841647086547372026600", 
"1000134600800354781929399250536541864362461089950800", "3935312233584004685417853572763349509774031680023800", 
"15487357822491889407128326963778343232013931127835600", "60960876535340415751462563580829648891969728907438000",
"239993345518077005168915776623476723006280827488229600", "944973797977428207852605870454939596837230758234904050", 
"3721443204405954385563870541379246659709506697378694300", "14657929356129575437016877846657032761712954950899755100", 
"57743358069601357782187700608042856334020731624756611000", "227508830794229349661819540395688853956041682601541047340", 
"896519947090131496687170070074100632420837521538745909320" };
int main(void)
{
	int k;
	while (scanf("%ld", &k) == 1 && k + 1)
		printf("%s\n", list[k - 1]);
	return 0;
}