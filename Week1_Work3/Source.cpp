#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
    char c[1001], d[1001], print[1001];
    int a, b, more, checkcase;
    scanf("%s", c);
    scanf("%s", d);
    for (int i = 0;i <= 1001;i++) //check จำนวน input c
    {
        if (c[i] == '\0') {
            a = i;
            break;
        }

    }
    for (int i = 0;i <= 1001;i++) //check จำนวน input d
    {
        if (d[i] == '\0') {
            b = i;
            break;
        }

    }
    printf("input c (a) : %d\n", a);
    printf("input d (b) : %d\n", b);
    if (a > b) more = a;
    else more = b;
    printf("%0*s\n", a, c);
    printf("%0*s\n", a, d);
    if (a > b) {   //หลัก a มากกว่า b ผลลัพธ์รวมจะไม่ติดลบ
        for (int i = 1;i <= a;i++) {
            //printf("Last Character - %d\n",c[a-i]-d[b-i]);
            if (b - i < 0) {
                print[a - i] = c[a - i];//printf("%c\n",c[a-i]);
            }
            else if ((c[a - i] >= '0' && c[a - i] <= '9') && (d[b - i] >= '0' && d[b - i] <= '9')) //คู่นั้นเป็นตัวเลข
            {
                if (c[a - i] - d[b - i] >= 0)
                {
                    print[a - i] = c[a - i] - d[b - i] + '0';//printf("%c",c[a-i]-d[b-i]+'0');//คู่นั้น c >= d
                }
                else //การยืมตัวข้างหน้า
                {
                    print[a - i] = (c[a - i] - d[b - i]) + '9' + 1;//printf("%c",(c[a-i]-d[b-i])+'9'+1);
                    for (int k = 1;i + k <= a;k++) // 100-1 = 99
                    {
                        if (c[a - i - k] == '0') c[a - i - k] = '9';
                        else
                        {
                            c[a - i - k] -= 1;
                            //printf("%c\n",c[a-i-k]);
                            break;
                        }
                    }
                }

            }
            else {
                printf("ERROR !");
                return(0);
            }

        }
        checkcase = 1;
    }
    else if (a < b) {
        for (int i = 1;i <= b;i++) {
            //printf("Last Character - %d\n",c[a-i]-d[b-i]);
            if (a - i < 0)
            {
                print[b - i] = d[b - i]; //ถ้า a-i มันหมดแล้ว
                //printf(" *%c* ",d[b-i]);
            }
            else if ((c[a - i] >= '0' && c[a - i] <= '9') && (d[b - i] >= '0' && d[b - i] <= '9')) //คู่นั้นเป็นตัวเลข
            {
                if (d[b - i] - c[a - i] >= 0)
                {
                    print[b - i] = d[b - i] - c[a - i] + '0';//printf("%c",c[a-i]-d[b-i]+'0');//คู่นั้น c >= d
                }
                else //การยืมตัวข้างหน้า
                {
                    print[b - i] = (d[b - i] - c[a - i]) + '9' + 1;//printf("%c",(c[a-i]-d[b-i])+'9'+1);
                    for (int k = 1;i + k <= b;k++) // 100-1 = 99
                    {
                        if (d[b - i - k] == '0')
                        {
                            d[b - i - k] = '9';
                        }
                        else if (d[b - i - k] > '0')
                        {
                            d[b - i - k] = d[b - i - k] - 1;
                            break;
                        }
                    }
                }

            }
            else {
                printf("ERROR !");
                return(0);
            }
        }
        checkcase = 2;
    }
    else
    {
        if (c[0] >= d[0])  //ค่าตัวแรกมากกว่าจะเป็น + แน่ๆ
        {
            for (int i = 1;i <= a;i++)
            {
                //printf("Last Character - %d\n",c[a-i]-d[b-i]);
                if ((c[a - i] >= '0' && c[a - i] <= '9') && (d[b - i] >= '0' && d[b - i] <= '9')) //คู่นั้นเป็นตัวเลข
                {
                    if (c[a - i] - d[b - i] >= 0)
                    {
                        print[a - i] = c[a - i] - d[b - i] + '0';//printf("%c",c[a-i]-d[b-i]+'0');//คู่นั้น c >= d
                    }
                    else //การยืมตัวข้างหน้า
                    {
                        print[a - i] = (c[a - i] - d[b - i]) + '9' + 1;//printf("%c",(c[a-i]-d[b-i])+'9'+1);
                        for (int k = 1;i + k <= a;k++) // 100-1 = 99
                        {

                            if (c[a - i - k] == '0')
                            {
                                c[a - i - k] = '9';
                            }
                            else
                            {
                                c[a - i - k] -= 1;
                                break;
                            }
                        }
                    }

                }
                else
                {
                    printf("ERROR !");
                    return(0);
                }

            }
            checkcase = 1;
        }
        else
        {
            for (int i = 1;i <= b;i++) {
                //printf("Last Character - %d\n",c[a-i]-d[b-i]);
                if (a - i < 0) print[b - i] = d[b - i]; //ถ้า a-i มันหมดแล้ว
                //printf(" *%c* ",d[b-i]);
                if ((c[a - i] >= '0' && c[a - i] <= '9') && (d[b - i] >= '0' && d[b - i] <= '9')) //คู่นั้นเป็นตัวเลข
                {
                    if (d[b - i] - c[a - i] >= 0)
                    {
                        print[b - i] = d[b - i] - c[a - i] + '0';//printf("%c",c[a-i]-d[b-i]+'0');//คู่นั้น c >= d
                    }
                    else //การยืมตัวข้างหน้า
                    {
                        print[b - i] = (d[b - i] - c[a - i]) + '9' + 1;//printf("%c",(c[a-i]-d[b-i])+'9'+1);
                        for (int k = 1;i + k <= a;k++) // 100-1 = 99
                        {
                            if (d[b - i - k] == '0') d[b - i - k] = '9';
                            else
                            {
                                d[b - i - k] -= 1;
                                break;

                            }
                        }
                    }

                }
                else {
                    printf("ERROR !");
                    return(0);
                }
            }
            checkcase = 2;
        }
    }

    if (checkcase == 1) for (int k = 0;k < more;k++) printf("%c", print[k]); //แสดงผลลัพธ์
    else if (checkcase == 2) {
        printf("-");
        for (int k = 0;k < more;k++) printf("%c", print[k]); //แสดงผลลัพธ์
    }

    /*char a[3],b[3],c[3];
    scanf("%s",a);
    scanf("%s",b);
    c[2]= a[2]-b[2];
    printf("%c",c[2]+'0');*/

}
