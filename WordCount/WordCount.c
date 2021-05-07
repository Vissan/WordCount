#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[]) {
    FILE* fp;

    if (argc == 3) {
        //读取文件的内容
        fp = fopen(argv[2], "r");
        //打开失败 
        if (fp == NULL) {
            printf("错误：无法打开%s\n", argv[2]);
            exit(1);
        }
        //对参数进行匹配 
        if (0 == strcmp(argv[1], "-c")) {//统计字符数 
            char ch;
            int number = 0;
            while ((ch = fgetc(fp)) != EOF) {

                if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)
                    || (ch >= 48 && ch <= 57) || (ch == 32) || (ch == 9) || (ch == 13)) {
                    number++;
                }
            }

            printf("字符数：%d\n", number);
        }

        else if (0 == strcmp(argv[1], "-w")) {//统计单词数 
            int number = 0;
            int iflag = 0;
            char ch;
            while (feof(fp) == 0) {//等于0表示文件未结束
                ch = fgetc(fp);//读取一个字符后，光标位置会后移一个字节继续读
                if (ch == 32) {
                    iflag = 0;
                }
                else if (iflag == 0) {//遇到某个单词的首字母 
                    iflag = 1;//记录标志，说明在flag=1的时候，字符随着i的增大在往后移动 
                    number++;
                }
            }
            printf("单词数为%d\n", number);
        }

        else {
            printf("参数错误！");
        }
    }
    else {
        printf("错误：参数输入错误，请重新输入\n");
    }

}