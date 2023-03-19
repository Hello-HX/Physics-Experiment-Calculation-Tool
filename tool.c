/*本程序对原始数据实现以下功能：*/
// 一: 求原始数据的平均值
// 二：求原始数据的A类不确定度
// 三：根据自己输入的仪器允许误差，实现对B类不确定度的求解
// 四：自行对数据有效数字进行舍取，从而求出合成不确定度和相对不确定度
//ctrl + z to ese
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int i, n;                                 // n为原始数据个数
    double average, data[100] = {0}, sum = 0; // 定义sum存放原始数据之和
    double sum1 = 0, A;                       // sum1为求A类不确定度时用到的中间变量，A存放A类不确定度的计算结果
    double derta, B;                          // derta为实验仪器允许的最大误差，B存放B类不确定度的计算结果
    double U, R;                              // U存放合成不确定度，R存放相对不确定度

    while (1)
    {   
        sum = 0;
        sum1 = 0;
        printf("\033[31m");
        printf("<><><><><><><><><><><><><><><><><><><><><><>\n");
        puts("@CHX->欢迎来到我的大学物理实验小工具！");
        printf("\033[m");
        
        printf("|step1--\033[33m请输入数据个数:\033[m"); // 输入数据个数提示
        scanf("%d", &n);
        
        // 求原始数据的算术平均值
        printf("|step2--\033[33m请输入原始数据:\033[m"); // 输入提示
        for (i = 1; i <= n; i++)
        {
            scanf("%lf", &data[i]);
            sum += data[i];
        }

        printf("|step3--\033[33m请输入零点读数：\033[m");
        double d = 0;
        scanf("%lf",&d);
        average = sum / n - d;
        printf("\033[31m");
        printf("  <>@CHX>>>>所求数据平均值为:%f\n", average);

        // 求A类不确定度
        for (i = 1; i <= n; i++)
        {
            sum1 += pow(data[i] - average, 2);
        }
        A = sqrt(sum1 / ((double)n * ((double)n - 1)));
        printf("  <>@CHX>>>>A类不确定度为:%lf\n", A);
        printf("\033[m");

        // 求B类仪器误差不确定度
        printf("|step4--\033[33m请输入实验仪器误差:\033[m\n");
        printf("  |直尺0.5\n");
        printf("  |游标卡尺: 50=0.02mm 20=0.05mm 10=0.01mm\n");
        printf("  |螺旋：0-100=0.004mm 100-150=0.005mm\n");
        printf("  |天平：最小分度一半0.1\n");
        printf("  |显微镜：0.005mm\n");
        printf("  |数字类：仪器最小读数\n");
        printf("  |计时类：0.3s\n");
        printf("  |分光计：最小分度\n");
        printf("  |温度计：0.1g\n");
        printf("  |万用表不用\n");
        printf("  |拉力计：0.005kg\n");
        printf("  |电阻箱子：读数×等级3+最小刻度×3\n");
        printf("  \033[33m||请输入->\033[m");
        scanf("%lf", &derta);
        B = derta / sqrt(3);
        printf("\033[31m");
        printf("  @CHX>>>>B类仪器误差不确定度为:%f\n", B);
         printf("\033[m");

        // 求合成不确定度
        printf("|step5--\033[33m请分别输入A类和B类不确定度:\033[m\n");
        puts("  |保留位数，分度值下一位，不估读外");
        puts("  |四舍六入五左右");
        puts("  |五右边非0，就进");
        puts("  |否则看左，奇入偶舍");
        printf("  |看有效位\n");
        printf("  \033[33m||请输入->\033[m");
        scanf("%lf%lf", &A, &B);
        U = sqrt(pow(A, 2) + pow(B, 2));
        printf("\033[31m");
        printf("  <>@CHX>>>>合成不确定度为:%lf\n", U);
         printf("\033[m");


        // 求相对不确定度
        R = U / average;
        printf("\033[31m");
        printf("  <>@CHX>>>>相对不确定度为:%f\n", R);
         printf("\033[m");
        

        //数据整合
        printf("|step6--\033[33m数据整合情况如下：\033[m\n");
        printf("\033[31m");
        printf("  <>@CHX>>>>所求数据平均值为:%f\n", average);
        printf("  <>@CHX>>>>A类不确定度为:%lf\n", A);
        printf("  <>@CHX>>>>B类仪器误差不确定度为:%f\n", B);
        printf("  <>@CHX>>>>合成不确定度为:%lf\n", U);
        printf("  <>@CHX>>>>相对不确定度为:%f\n", R);
         printf("\033[m");

        printf("\n\n");
    }
    return 0;
}
