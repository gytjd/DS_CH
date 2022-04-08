//
//  3.c
//  KNU C
//
//  Created by hwang hyosung on 2022/04/08.
//

#include "3.h"

int sumAry1D_fl(int pa[],int n)
{
    int i;
    int sum=0;
    for(i=0;i<n;i++)
    {
        sum+=pa[i];
    }
    
    return sum;
}

int sumAry1D_f2(int *pa,int n)
{
    int i;
    int sum=0;
    for(i=0;i<n;i++)
    {
        sum+=pa[i];
    }
    
    return sum;
}

int sumAry1D_f3(int pa[6],int n)
{
    int i;
    int sum=0;
    for(i=0;i<n;i++)
    {
        sum+=pa[i];
    }
    
    return sum;

}
int main()
{
    int ary1D[]={1,2,3,4,5,6};
    
    printf("sumAry1D_fl() %d\n",sumAry1D_fl(ary1D,6));
    printf("sumAry1D_f2() %d\n",sumAry1D_f2(ary1D,6));
    printf("sumAry1D_f3() %d\n",sumAry1D_f3(ary1D,6));
    
    
    return 0;
}
