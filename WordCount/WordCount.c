#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[]) {
    FILE* fp;

    if (argc == 3) {
        //��ȡ�ļ�������
        fp = fopen(argv[2], "r");
        //��ʧ�� 
        if (fp == NULL) {
            printf("�����޷���%s\n", argv[2]);
            exit(1);
        }
        //�Բ�������ƥ�� 
        if (0 == strcmp(argv[1], "-c")) {//ͳ���ַ��� 
            char ch;
            int number = 0;
            while ((ch = fgetc(fp)) != EOF) {

                if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)
                    || (ch >= 48 && ch <= 57) || (ch == 32) || (ch == 9) || (ch == 13)) {
                    number++;
                }
            }

            printf("�ַ�����%d\n", number);
        }

        else if (0 == strcmp(argv[1], "-w")) {//ͳ�Ƶ����� 
            int number = 0;
            int iflag = 0;
            char ch;
            while (feof(fp) == 0) {//����0��ʾ�ļ�δ����
                ch = fgetc(fp);//��ȡһ���ַ��󣬹��λ�û����һ���ֽڼ�����
                if (ch == 32) {
                    iflag = 0;
                }
                else if (iflag == 0) {//����ĳ�����ʵ�����ĸ 
                    iflag = 1;//��¼��־��˵����flag=1��ʱ���ַ�����i�������������ƶ� 
                    number++;
                }
            }
            printf("������Ϊ%d\n", number);
        }

        else {
            printf("��������");
        }
    }
    else {
        printf("���󣺲��������������������\n");
    }

}