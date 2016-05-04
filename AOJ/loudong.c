
#include <stdlib.h>
#include <stdio.h>

#define value1 0x44
#define value2 0x55

int main(int argc, char *argv[])
{
  char user_input[1000];
  int *secret;
  long int_input;
  int a, b, c, d; 
  secret = (int *) malloc(2*sizeof(int));

  secret[0] = value1; secret[1] = value2;

  printf("secret 的值在栈上的地址为 0x%8x (on stack)\n", &secret);
  printf("secret 的值在堆上的地址为 0x%8x (on heap)\n", secret);
  printf("secret[0] 的地址是 0x%8x (on heap)\n", &secret[0]);
  printf("secret[1] 的地址是 0x%8x (on heap)\n", &secret[1]);

  printf("输入一个整数：\n");
  scanf("%d", &int_input); 
  printf("输入一个字符串：\n");
  scanf("%s", user_input); 
  printf(user_input);  
  printf("\n");

  printf("secrets 原来的值: 0x%x -- 0x%x\n", value1, value2);
  printf("secrets 利用漏洞修改后值为:      0x%x -- 0x%x\n", secret[0], secret[1]);
  return 0;
}




//%016llx,%016llx,%016llx,%016llx,%016llx,%016llx,%016llx,%016llx
//%016llx,%016llx,%016llx,%016llx,%016llx,%016llx,%016llx,%016llx,%s
//%016llx,%016llx,%016llx,%016llx,%016llx,%016llx,%016llx,%016llx,%n
//%016llx,%016llx,%016llx,%016llx,%016llx,%016llx,%016llx,%.880u,%n