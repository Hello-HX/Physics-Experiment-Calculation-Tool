/*本程序对原始数据实现以下功能：*/
// 一: 求原始数据的平均值
// 二：求原始数据的A类不确定度
// 三：根据自己输入的仪器允许误差，实现对B类不确定度的求解
// 四：自行对数据有效数字进行舍取，从而求出合成不确定度和相对不确定度
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;
int main()
{
    int i, n;                                 // n为原始数据个数
    double average, data[100] = {0}, sum = 0; // 定义sum存放原始数据之和
    double sum1 = 0, A;                       // sum1为求A类不确定度时用到的中间变量，A存放A类不确定度的计算结果
    double derta, B;                          // derta为实验仪器允许的最大误差，B存放B类不确定度的计算结果
    double U, R;                              // U存放合成不确定度，R存放相对不确定度

    puts("欢迎来到我的大学物理实验小工具！\n")
        printf("请输入数据个数:"); // 输入数据个数提示
    scanf("%d", &n);
    while (1)
    {
        // 求原始数据的算术平均值
        printf("请输入原始数据:"); // 输入提示
        for (i = 1; i <= n; i++)
        {
            scanf("%lf", &data[i]);
            sum += data[i];
        }
        printf("\n");
        average = sum / n;
        printf("所求数据平均值为:%f\n\n", average);

        printf("\n");
        // 求A类不确定度
        for (i = 1; i <= n; i++)
        {
            sum1 += pow(data[i] - average, 2);
        }
        A = sqrt(sum1 / ((double)n * ((double)n - 1)));
        printf("A类不确定度为:%lf\n\n", A);

        printf("\n");
        // 求B类仪器误差不确定度
        printf("请输入实验仪器误差:\n");
        printf("\t直尺0.2\n");
        printf("\t游标卡尺: 50=0.02mm 20=0.05mm 10=0.01mm\n");
        printf("\t螺旋：0-100=0.004mm 100-150=0.005mm\n");
        printf("\t天平：最小分度一半0.1\n");
        printf("\t显微镜：0.005mm\n");
        printf("\t数字类：仪器最小读数\n");
        printf("\t计时类：0.3s\n");
        printf("\t分光计：最小分度\n");
        printf("\t温度计：0.1g\n");
        printf("\t万用表不用\n");
        scanf("%lf", &derta);
        B = derta / sqrt(3);
        printf("B类仪器误差不确定度为:%f\n\n", B);

        printf("\n");
        // 求合成不确定度
        puts("保留位数，分度值下一位，不估读外\n");
        puts("四舍六入五左右\n");
        puts("五右边非0，就进\n");
        puts("否则看左，奇入偶舍\n");
        printf("请分别输入A类和B类不确定度:");
        scanf("%lf%lf", &A, &B);
        U = sqrt(pow(A, 2) + pow(B, 2));
        printf("合成不确定度为:%lf\n\n", U);

        printf("\n");
        // 求相对不确定度
        R = U / average;
        printf("相对不确定度为:%f\n\n", R);

        printf("/n");
        printf("继续或者退出q？\n");
        char q;
        scanf("%c", &q);
        if (q == 'q')
            return 0;
        system("cls");
    }
    return 0;
}
