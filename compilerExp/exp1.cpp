#include<bits/stdc++.h>
using namespace std;

/* 全局变量 */
char inBuffer[4096];    // 输入缓冲区
int line;               // 当前行数
int col;                // 当前列数
int preCol;             // 上一行列数
FILE* in;               // 输入流文件
FILE* out;              // 输出流文件

int state;              // 当前状态表示
char C;                 // 当前读入的字符
int iskey;              // 值为-1表示识别出的单词是用户自定义标识符，否则其值为关键字的记号
string token;           // 当前正在识别的单词字符串
char* lexemebegin;      // 指向输入缓冲区中当前单词的开始位置
char* forwardP;         // 向前指针

/* C语言关键字表 */
unordered_map<string, int> keyword = 
{
    /* 数据类型关键字 */
    {"char", 0},
    {"double", 1},
    {"enum", 2},
    {"float", 3},
    {"int", 4},
    {"long", 5},
    {"short", 6},
    {"signed", 7},
    {"struct", 8},
    {"union", 9},
    {"unsigned", 10},
    {"void", 11},
    {"bool", 12},       // C++中引入布尔类型

    /* 控制语句关键字 */
    /* A循环语句 */
    {"for", 13},
    {"do", 14},
    {"while", 15},
    {"break", 16},
    {"continue", 17},
    /* B条件语句 */
    {"if", 18},
    {"else", 19},
    {"goto", 20},
    /* C开关语句 */
    {"switch", 21},
    {"case", 22},
    {"default", 23},
    /* D返回语句 */
    {"return", 24},
    
    /* 存储类型关键字 */
    {"auto", 25},
    {"extern", 26},
    {"register", 27},
    {"static", 28},

    /* 其它关键字 */
    {"const", 29},
    {"sizeof", 30},
    {"typedef", 31},
    {"volatile", 32},

    /* 符号(与关键字一起编码) */
    /* 关系运算符 */
    {"<", 33},
    {"<=", 34},
    {">", 35},
    {">=", 36},
    {"!=", 37},
    {"==", 38},
    /* 赋值运算符 */
    {"=", 39},
    /* 算术运算符 */
    {"+", 40},
    {"-", 41},
    {"*", 42},
    {"/", 43},
    /* 注释处理 */
    {"/*", 44},
    {"*/", 45},
    /* 逻辑运算符 */
    {"&&", 46},
    {"&", 47},
    {"||", 48},
    {"|", 49},
    {"!", 50},
    /* 括号 */
    {"(", 51},
    {")", 52},
    {"[", 53},
    {"]", 54},
    {"{", 55},
    {"}", 56},
    /* 语句符号 */
    {",", 57},
    {";", 58},
    {":", 59},
    {"\'", 60},
    {"\"", 61},

    /* 输入输出 */
    {"get", 62},
    {"put", 63},

    /* 其它(与关键字一起编码) */
    {"num", 64},    // 常数
    {"cha", 65},    // 字符
    {"str", 66},    // 字符串
    {"boolean", 67},// 布尔
    {"array", 68},  // 数组
    {"func", 69},   // 函数
    {"id", 70}      // 用户自定义标识符
};

/* 用户自定义标识符表 */
unordered_map<string, int> table;
int table_size;         // 用户自定义标识符表的大小

/* 统计单词个数 */
unordered_map<string, int> statis;

/*
 * 每调用一次，根据向前指针forward的指示从输入缓冲区中读一个字符
 * 并把它放入变量C中，然后移动forward，使之指向下一个字符
 */
void get_char()
{
    C = *forwardP;
    if (C == '\n' || C == '\r')
    {
        line++;
        preCol = col;
        col = 0;
    }
    else
    {
        col++;
    }
    forwardP++;
}

/*
 * 每次调用时，检查C中的字符是否为空格
 * 若是，则反复调用get_char，直到C中进入一个非空字符为止
 */
void get_nbc()
{
    while (C == ' ' || C == '\t' || C == '\n' || C == '\r')
    {
        get_char();
    }
}

/*
 * 把C中的字符连接在token中的字符串后面
 */
void cat()
{
    token += C;
}

/*
 * 判断C中的字符是否为字母，若是则返回true，否则返回false
 */
bool letter()
{
    if (C >= 'A' && C <= 'Z' || C >= 'a' && C <= 'z')
    {
        return true;
    }
    return false;
}

/*
 * 判断C中的字符是否为数字，若是则返回true，否则返回false
 */
bool digit()
{
    if (C >= '0' && C <= '9')
    {
        return true;
    }
    return false;
}

/*
 * 判断C中的字符是否为八进制数字，若是则返回true，否则返回false
 */
bool digit_oct()
{
    if (C >= '0' && C <= '7')
    {
        return true;
    }
    return false;
}

/*
 * 判断C中的字符是否为十六进制数字，若是则返回true，否则返回false
 */
bool digit_hex()
{
    if (C >= '0' && C <= '9' || C >= 'A' && C <= 'F' || C >= 'a' && C <= 'f')
    {
        return true;
    }
    return false;
}

/*
 * 向前指针forward后退一个字符
 */
void retract()
{
    if (C == '\n' || C == '\r')
    {
        line--;
        col = preCol;
    }
    else
    {
        col--;
    }
    forwardP--;
}

/*
 * 根据token中的单词查关键字表
 * 若token中的单词是关键字，则返回该关键字的记号
 * 否则，返回值-1
 */
int reserve()
{
    if (keyword.count(token))
    {
        return keyword[token];
    }
    return -1;
}

/*
 * 将token中的字符串转换成整数
 */
int SToI(string s)
{
    int num = 0;
    for (char& c : s)
    {
        num = num * 10 + c - '0';
    }
    return num;
}

/*
 * 将token中的字符串转换成浮点数
 */
float SToF(string s)
{
    float num = 0;          // 整数部分
    int exp = 0;            // 指数部分
    int index;              // 索引
    bool positive;          // 是否为正数
    if (s[0] == '-')        // 整数部分为负数
    {
        index = 1;
        positive = false;
    }
    else                    // 整数部分为正数
    {
        index = 0;
        positive = true;
    }
    for (; s[index] != 'e' && s[index] != 'E'; index++) // 读取整数部分
    {
        num = num * 10 + s[index] - '0';
    }
    if (positive == false)  // 若整数部分为负数则取负
    {
        num = -num;
    }
    if (s[index + 1] == '-')// 指数部分为负数 
    {
        index = index + 2;
        positive = false;
    }
    else                    // 指数部分为正数
    {
        index = index + 1;
        positive = true;
    }
    for (; index < s.size(); index++)  // 读取指数部分
    {
        exp = exp * 10 + s[index] - '0';
    }
    if (positive == false)  // 若指数部分为负数则除以10的exp次方
    {
        while (exp--)
        {
            num /= 10;
        }
    }
    else                    // 若指数部分为正数则乘以10的exp次方
    {
        while (exp--)
        {
            num *= 10;
        }
    }
    return num;
}

/*
 * 将识别出来的用户自定义标识符(即token中的单词)插入符号表
 * 返回该单词在符号表中的位置指针
 */
int table_insert()
{
    if (table.count(token))
    {
        return table[token];
    }
    else
    {
        table[token] = table_size;
        table_size++;
        return table_size - 1;
    }
}

/*
 * 对发现的错误进行相应的处理
 */
void error()
{
    printf("line %d: col %d: error!\n", line, col);
    fprintf(out, "line %d: col %d: error!\n", line, col);
}

/*
 * 将识别出来的单词的记号返回给调用程序
 */
void return_mark(string name, int mark, string attribute)
{
    printf("<%8s, %4d, %4s>\n", name.c_str(), mark, attribute.c_str());
    fprintf(out, "<%8s, %4d, %4s>\n", name.c_str(), mark, attribute.c_str());
}

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
                if (letter() || C == '_')   // 关键字或自定义标识符
                {
                    state = 1;
                }
                else if (C == '0')      // 八进制或0或十六进制常数
                {
                    state = 5;
                }
                else if (digit())   // 非0十进制常数
                {
                    state = 4;
                }
                else
                {
                    switch (C)
                    {
                        case '<':   // '<'状态
                            state = 9;
                            break;
                        case '>':   // '>'状态
                            state = 10;
                            break;
                        case '!':   // '!'状态
                            state = 11;
                            break;
                        case '=':   // '='状态
                            state = 12;
                            break;
                        case '/':   // '/'状态
                            state = 13;
                            break;
                        case '&':   // '&'状态
                            state = 15;
                            break;
                        case '|':   // '|'状态
                            state = 16;
                            break;
                        case '\'':  // '\''状态
                            state = 17;
                            return_mark("\'", keyword["\'"], "-");
                            break;
                        case '\"':  // '\"'状态
                            state = 18;
                            return_mark("\"", keyword["\""], "-");
                            break;
                        case '+':   // 返回'+'
                            state = 0;
                            return_mark("+", keyword["+"], "-");
                            break;
                        case '-':   // 返回'-'
                            state = 0;
                            return_mark("-", keyword["-"], "-");
                            break;
                        case '*':   // 返回'*'
                            state = 0;
                            return_mark("*", keyword["*"], "-");
                            break;
                        case '(':   // 返回'('
                            state = 0;
                            return_mark("(", keyword["("], "-");
                            break;
                        case ')':   // 返回')'
                            state = 0;
                            return_mark(")", keyword[")"], "-");
                            break;
                        case '[':   // 返回'['
                            state = 0;
                            return_mark("[", keyword["["], "-");
                            break;
                        case ']':   // 返回']'
                            state = 0;
                            return_mark("]", keyword["]"], "-");
                            break;
                        case '{':   // 返回'{'
                            state = 0;
                            return_mark("{", keyword["{"], "-");
                            break;
                        case '}':   // 返回'}'
                            state = 0;
                            return_mark("}", keyword["}"], "-");
                            break;
                        case ',':   // 返回','
                            state = 0;
                            return_mark(",", keyword[","], "-");
                            break;
                        case ';':   // 返回';'
                            state = 0;
                            return_mark(";", keyword[";"], "-");
                            break;
                        case ':':   // 返回':'
                            state = 0;
                            return_mark(":", keyword[":"], "-");
                            break;
                        default:    // error状态
                            state = 19;
                            break;
                    }
                }
                break;
            case 1:     // 关键字或自定义标识符状态
                cat();
                get_char();
                if (letter() || digit() || C == '_')
                {
                    state = 1;
                }
                else
                {
                    retract();
                    state = 0;
                    iskey = reserve();  // 查关键字表
                    if (iskey != -1)    // 识别出的是关键字
                    {
                        return_mark(token, iskey, "-");
                        statis[token]++;    // 统计单词个数
                    }
                    else                // 识别出的是自定义标识符
                    {
                        if (token == "false" || token == "true")
                        {
                            return_mark(token, keyword["boolean"], "-");
                        }
                        else
                        {
                            int identry = table_insert();   // 返回标识符在符号表的入口指针
                            return_mark(token, keyword["id"], to_string(identry));
                            statis[token]++;    // 统计单词个数
                            get_char();     // 读一个字符判断是否为数组或函数
                            if (C == '[')   // 数组状态
                            {
                                state = 2;
                            }
                            else if (C == '(')  // 函数状态
                            {
                                state = 3;
                            }
                            else            // 非数组或函数
                            {
                                retract();
                            }
                        }
                    }
                }
                break;
            case 2:     // 数组状态
                cat();
                get_char();
                if (C != ']')
                {
                    state = 2;
                }
                else
                {
                    cat();
                    return_mark(token, keyword["array"], "-");
                    state = 0;
                }
                break;
            case 3:     // 函数状态
                cat();
                get_char();
                if (C != ')')
                {
                    state = 3;
                }
                else
                {
                    cat();
                    return_mark(token, keyword["func"], "-");
                    state = 0;
                }
                break;
            case 4:     // 十进制常数状态
                cat();
                get_char();
                if (digit())    // 十进制常数状态
                {
                    state = 4;
                }
                else if (C == 'E' || C == 'e')  // 指数状态
                {
                    state = 8;
                }
                else
                {
                    retract();
                    state = 0;
                    return_mark(token, keyword["num"], "dec");
                }
                break;
            case 5:
                cat();
                get_char();
                if (digit_oct())    // 八进制常数
                {
                    state = 6;
                }
                else if (C == 'X' || C == 'x')  // 十六进制常数
                {
                    state = 7;
                }
                else                // 十进制常数0
                {
                    retract();
                    state = 0;
                    return_mark(token, keyword["num"], "dec");
                }
                break;
            case 6:     // 八进制常数状态
                cat();
                get_char();
                if (digit_oct())
                {
                    state = 6;
                }
                else
                {
                    retract();
                    state = 0;
                    return_mark(token, keyword["num"], "oct");
                }
                break;
            case 7:     // 十六进制常数状态
                cat();
                get_char();
                if (digit_hex())
                {
                    state = 7;
                }
                else
                {
                    retract();
                    state = 0;
                    return_mark(token, keyword["num"], "hex");
                }
                break;
            case 8:     // 指数形式的浮点数状态
                cat();
                get_char();
                if (digit())
                {
                    state = 8;
                }
                else
                {
                    retract();
                    state = 0;
                    return_mark(token, keyword["num"], "exp_float");
                }
                break;
            case 9:     // '<'状态
                cat();
                get_char();
                if (C == '=')   // <=
                {
                    cat();
                    state = 0;
                    return_mark(token, keyword["<="], "-");
                }
                else            // <
                {
                    retract;
                    state = 0;
                    return_mark(token, keyword["<"], "-");
                }
                break;
            case 10:     // '>'状态
                cat();
                get_char();
                if (C == '=')   // >=
                {
                    cat();
                    state = 0;
                    return_mark(token, keyword[">="], "-");
                }
                else            // >
                {
                    retract;
                    state = 0;
                    return_mark(token, keyword[">"], "-");
                }
                break;
            case 11:     // '!'状态
                cat();
                get_char();
                if (C == '=')   // !=
                {
                    cat();
                    state = 0;
                    return_mark(token, keyword["!="], "-");
                }
                else            // !
                {
                    retract;
                    state = 0;
                    return_mark(token, keyword["!"], "-");
                }
                break;
            case 12:     // '='状态
                cat();
                get_char();
                if (C == '=')   // ==
                {
                    cat();
                    state = 0;
                    return_mark(token, keyword["=="], "-");
                }
                else            // =
                {
                    retract;
                    state = 0;
                    return_mark(token, keyword["="], "-");
                }
                break;
            case 13:     // '/'状态
                cat();
                get_char();
                if (C == '*')   // /* 注释开始
                {
                    cat();
                    state = 14;
                    return_mark(token, keyword["/*"], "-");
                    token = "";
                }
                else            // <
                {
                    retract();
                    state = 0;
                    return_mark(token, keyword["/"], "-");
                }
                break;
            case 14:    // 注释状态
                get_char();
                if (C != '*')       // 注释未结束
                {
                    state = 14;
                }
                else
                {
                    cat();
                    get_char();
                    if (C != '/')   // 注释未结束
                    {
                        retract();
                        state = 14;
                        token = "";
                    }
                    else            // */ 注释结束
                    {
                        cat();
                        state = 0;
                        return_mark(token, keyword["*/"], "-");
                    }
                }
                break;
            case 15:     // '&'状态
                cat();
                get_char();
                if (C == '&')   // &&
                {
                    cat();
                    state = 0;
                    return_mark(token, keyword["&&"], "-");
                }
                else            // &
                {
                    retract;
                    state = 0;
                    return_mark(token, keyword["&"], "-");
                }
                break;
            case 16:     // '|'状态
                cat();
                get_char();
                if (C == '|')   // ||
                {
                    cat();
                    state = 0;
                    return_mark(token, keyword["||"], "-");
                }
                else            // |
                {
                    retract;
                    state = 0;
                    return_mark(token, keyword["|"], "-");
                }
                break;
            case 17:     // '\''状态
                cat();
                get_char();
                if (C != '\'')   // 读入字符
                {
                    state = 17;
                }
                else
                {
                    cat();
                    return_mark(token, keyword["cha"], "-");
                    return_mark("\'", keyword["\'"], "-");
                    state = 0;
                }
                break;
            case 18:     // '\"'状态
                cat();
                get_char();
                if (C != '\"')  // 读入字符串
                {
                    state = 18;
                }
                else
                {
                    cat();
                    return_mark(token, keyword["str"], "-");
                    return_mark("\"", keyword["\""], "-");
                    state = 0;
                }
                break;
            case 19:    // error状态
                error();
                state = 0;
                break;
            default:
                break;
        }
    } while (C != EOF);
}

/*
 * 初始化
 */
void init()
{
    forwardP = inBuffer;
    line = 1;
    col = 0;
}

/*
 * 主函数
 */
int main()
{
    /* 将源程序读入缓存区 */
    in = fopen("in.txt", "r");
    out = fopen("out.txt", "w");
    char ch;
    int size;   // 字符总数
    while ((ch = fgetc(in)) != EOF)
    {
        inBuffer[size++] = ch;
    }
    inBuffer[size] = EOF;

    /* 输出源程序 */
    cout << "---------------program---------------" << endl;
    cout << inBuffer << endl;
    cout << "-------------------------------------" << endl;

    /* 词法分析 */
    init();
    scanner();

    /* 输出统计信息 */
    cout << "---------------statis----------------" << endl;
    cout << "characters: " << size << endl;
    cout << "     lines: " << line << endl;
    for (auto& t : statis)
    {
        printf("%10s: %d\n", t.first.c_str(), t.second);
    }
    cout << "-------------------------------------" << endl;

    fclose(in);
    fclose(out);
    return 0;
}