#include <cstdio>

#define MaxSize 100
#define M 200
#define N 200

typedef int ElemType;

typedef struct {  
    int r;  
    int c;  
    int value;
} TupNode;  
  
typedef struct{
  int rows;
  int cols;
  int nums;
  TupNode data[MaxSize];  
}TSMatrix;


void CreatMat(TSMatrix& t,ElemType* A,int rows,int cols)
{
    t.rows = rows; t.cols = cols; t.nums = 0;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
            if(A[i*cols+j] != 0)
            {
                t.data[t.nums].r = i;
                t.data[t.nums].c = j;
                t.data[t.nums].value = A[i*cols+j];
                t.nums++;
            }
    }
}
bool Value(TSMatrix& t,ElemType x,int i, int j)
{
    int k = 0,k1;
    if(i>=t.rows || j >= t.cols)
        return false;
    while(k < t.nums && i > t.data[k].r) k++;
    while(k < t.nums && i == t.data[k].r && j > t.data[k].c)  k++;
    if(t.data[k].r == i && t.data[k].c == j)
        t.data[k].value = x;
    else
    {
        for(k1 = t.nums-1; k1 >= k; k1--)
        {
            t.data[k1+1].r = t.data[k1].r;
            t.data[k1+1].c = t.data[k].c;
            t.data[k1+1].value = t.data[k1].value;
        }
        t.data[k].r = i; t.data[k].c = j;t.data[k].value =x;
        t.nums++;
    }
    return true;
}

bool Assign(TSMatrix& t,ElemType& x,int i, int j)
{
    int k =0;
    if(i >= t.rows || j >= t.cols)
        return false;
    while(k<t.nums && i>t.data[k].r) k++;
    while(k<t.nums && i==t.data[k].r && j >t.data[k].c)
        k++;
    if(t.data[k].r==i&&t.data[k].c==j)
        x=t.data[k].value;
    else
        x=0;
    return true;
}

void DispMat(TSMatrix& t)
{
    int k;
    if(t.nums <= 0)
        return;
    printf("\t%d\t%d\t%d\n",t.rows,t.cols,t.nums);
    printf("\t-------------------\n");
    for(k=0;k<t.nums;k++)
        printf("\t%d\t%d\t%d\n",t.data[k].r,t.data[k].c,t.data[k].value);
}

void TranTat(TSMatrix& t,TSMatrix& tb)
{
    int k,k1 = 0,v;
    tb.rows = t.cols; tb.cols=t.rows;tb.nums=t.nums;
    if(t.nums!=0)
    {
        for(v=0;v<t.cols;v++)
        {
            for(k=0;k<t.nums;k++)
                if(t.data[k].c==v)
                {
                    tb.data[k1].r=t.data[k].c;
                    tb.data[k1].c=t.data[k].r;
                    tb.data[k1].value = t.data[k].value;
                    k1++;
                }
        }
    }
}
