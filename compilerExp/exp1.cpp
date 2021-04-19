#include<bits/stdc++.h>
using namespace std;

/* 全局变量 */
char inBuffer[4096];    // 输入缓冲区
int state;              // 当前状态表示
char C;                 // 当前读入的字符
int iskey;              // 值为-1表示识别出的单词是用户自定义标识符，否则其值为关键字的记号
string token;           // 当前正在识别的单词字符串
char* lexemebegin;      // 指向输入缓冲区中当前单词的开始位置
char* forwardP;         // 向前指针


/*
 * 每调用一次，根据向前指针forward的指示从输入缓冲区中读一个字符
 * 并把它放入变量C中，然后移动forward，使之指向下一个字符
 */
void get_char()
{
    C = *forwardP;
    forwardP++;
}

/*
 * 每次调用时，检查C中的字符是否为空格
 * 若是，则反复调用get_char，直到C中进入一个非空字符为止
 */
void get_nbc()
{
    
}

/*
 * 把C中的字符连接在token中的字符串后面
 */
void cat()
{

}

/*
 * 判断C中的字符是否为字母，若是则返回true，否则返回false
 */
bool letter()
{
    return false;
}

/*
 * 判断C中的字符是否为数字，若是则返回true，否则返回false
 */
bool digit()
{
    return false;
}

/*
 * 向前指针forward后退一个字符
 */
void retract()
{

}

/*
 * 根据token中的单词查关键字表
 * 若token中的单词是关键字，则返回该关键字的记号
 * 否则，返回值-1
 */
int reverse()
{ 
    return 0;
}

/*
 * 将token中的字符串转换成整数
 */
void SToI()
{

}

/*
 * 将token中的字符串转换成浮点数
 */
void SToF()
{

}

/*
 * 将识别出来的用户自定义标识符(即token中的单词)插入符号表
 * 返回该单词在符号表中的位置指针
 */
int table_insert()
{
    return 0;
}

/*
 * 对发现的错误进行相应的处理
 */
void error()
{

}

/*
 * 将识别出来的单词的记号返回给调用程序
 */
// void return()
// {

// }

/*
 * 词法分析程序的主体部分
 */ 
void scanner()
{
    state = 0;
    do
    {
        switch (state)
        {
            case 0:
                token = "";
                get_char();
                get_nbc();
                if (C == '\n')
                {
                    cout << endl;
                }
                else
                {
                    cout << C;
                }
                switch (C)
                {
                    case 0:
                        /* code */
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    } while (C != EOF);
}

int main()
{
    FILE* in = fopen("in.txt", "r");
    char ch;
    int size;
    while ((ch = fgetc(in)) != EOF)
    {
        inBuffer[size++] = ch;
    }
    inBuffer[size] = EOF;
    forwardP = inBuffer;
    scanner();
    fclose(in);
    return 0;
}