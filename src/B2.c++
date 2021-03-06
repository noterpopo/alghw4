#include<iostream>
#include<stdlib.h>
#include<windows.h>
#include<ctime>
#include<iomanip>
#include<cstring>
using namespace std;

//选择排序算法函数 
void chosse_sort(int array[],int size){
	int i,j;
	int min_index;
	int temp;
	for(i=0;i<size;i++){
		min_index=i;
		for(j=i+1;j<size;j++){
			if(array[j]<array[min_index]){
				min_index=j;
			}
			
		}
		if(min_index!=i){
			temp=array[i];
			array[i]=array[min_index];
			array[min_index]=temp;
		}
	}
} 
//冒泡排序算法函数 
void maopao_sort(int array[],int size){
	int i,j;
	for(i=0;i<size-1;i++){
		for(j=0;j<size-i-1;j++){
			if(array[j]>array[j+1]){
				int temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
		}
	}
} 
//插入排序排序算法函数 
void insert_sort(int array[],int size){
	for(int i=1;i<size;i++){
		int temp=array[i];
		int j;
		for(j=i-1;j>=0;j--){
			if(array[j]>temp){
				array[j+1]=array[j];
				j=j-1;
			}
			array[j+1]=temp;
		}
	}
} 
//快速排序算法函数 

 void fast_sort(int array[], int left, int right) {
    if (left < right) {
        int temp = array[left];
        int i = left;
        int j = right;
        while (i < j) {
            while (i < j && array[j] >= temp) {
                j--;
            }
            array[i] = array[j];
            while (i < j && array[i] <= temp) {
                i++;
            }
            array[j] = array[i];
        }
        array[i] = temp;
        fast_sort(array, left, i - 1);
        fast_sort(array, i + 1, right);
    }
}
//合并排序算法函数 
void hebing(int array[],int first,int p,int last)
{
    int *array1 = new int[p-first+1];
    int *array2 = new int[last-p+1];
    memcpy(array1,&array[first],sizeof(int)*(p-first+1));
    memcpy(array2,&array[p+1],sizeof(int)*(last - p));
    int size1 = p-first+1;
    int size2 = last - p;
    int i = 0,j = 0,k = 0;
    while(i<size1&&j<size2)
    {
        if(array1[i]<array2[j])
        {
            array[first+k] =array1[i];
            i++;
            k++;
        }
        else
        {
            array[first+k] = array2[j];
            j++;
            k++;
        }
    }

    while(i<size1)
       {
           array[first+k] =array1[i++];
           k++;
       }
    while(j<size2)
        {
            array[first+k] = array2[j++];
            k++;
        }
}


void  hebing_sort(int array[],int first,int last )
{
    if((last - first)>0)
    {
        int p = (first+last)/2;
        hebing_sort(array,first,p);
        hebing_sort(array,p+1,last);
        hebing(array,first,p,last);
    }
}

void display(int array[],int size)
{
    int i;
    for(i = 0;i<size;i++)
        cout<<array[i]<<" ";
        
		cout<<endl;
}
int main(){
	int n;
    int ***array,i,j,k;

    array = new int**[5];
   //设定组数 
    for(i = 0;i<5;i++)
        array[i] = new int*[20];
  //随机数必写函数 
    srand((unsigned)time(NULL));
   	cout<<"请输入规模N："<<endl;
   	cin>>n;
    //分配空间 
    for(j = 0;j<5;j++)
        for(k = 0;k<20;k++)
            array[j][k] = new int[n];

    //生成随机数 
    for(i = 0;i<20;i++)
        for(j = 0;j<n;j++)
            array[0][i][j] = rand();

    //拷贝数据
    for(k = 1;k<5;k++)
        for(i = 0;i<20;i++)
            for(j = 0;j<n;j++)
                array[k][i][j] = array[0][i][j];
            //快速排序
 		   cout<<"快速排序结果："<<endl;
           for(i = 0;i<20;i++)
               {
                    fast_sort(array[4][i],0,n-1);
                    cout<<i+1<<"组:"<<endl;
                    display(array[4][i],n);
               }


            cout<<"合并排序结果："<<endl;
 			for(i = 0;i<20;i++)
                {
                    hebing_sort(array[3][i],0,n-1);
                    cout<<i+1<<"组:"<<endl;
                    display(array[3][i],n);

                }


           cout<<"选择排序结果："<<endl;
           for(i = 0;i<20;i++)
                {
                    chosse_sort(array[2][i],n);
                    cout<<i+1<<"组:"<<endl;
                    display(array[2][i],n);

                }


           cout<<"插入排序结果："<<endl;
           for(i = 0;i<20;i++)
                {
                    insert_sort(array[1][i],n);
                    cout<<i+1<<"组:"<<endl;
                    display(array[1][i],n);

                }

            cout<<"冒泡排序结果："<<endl;
            for(i = 0;i<20;i++)
                {
                    maopao_sort(array[0][i],n);
                    cout<<i+1<<"组:"<<endl;
                    display(array[0][i],n);

                }
    int sw=1;
    
    cout<<"请选择测试排序时间或者退出程序：1.测试   0.退出"<<endl;
    cin>>sw;
    if(sw==0){
    	return 0;
	} 
    if(sw==1){
    
    	
    	while(1){
    		
	      cout<<"测试排序时间--请输入规模N:"<<endl;
            cin>>n;
            for(j = 0;j<5;j++)
                for(k = 0;k<20;k++)
                    array[j][k] = new int[n];


            for(i = 0;i<20;i++)
               for(j = 0;j<n;j++)
                    array[0][i][j] = rand();


            for(k = 1;k<5;k++)
                for(i = 0;i<20;i++)
                    for(j = 0;j<n;j++)
                        array[k][i][j] = array[0][i][j];

LARGE_INTEGER start,finsh,frequency;
QueryPerformanceFrequency(&frequency);
     
	   
		cout<<"快速排序算法20组数据所用的时间为(单位：ms):"<<endl;
        for(i = 0;i<20;i++)
            {
              QueryPerformanceCounter(&start);
              fast_sort(array[4][i],0,n-1);
              QueryPerformanceCounter(&finsh);
              cout<<(finsh.QuadPart - start.QuadPart)*1000.0/frequency.QuadPart<<" ";
            }
         cout<<endl;
   

		cout<<"合并排序20组数据所用的时间为(单位：ms):"<<endl;
  		for(i = 0;i<20;i++)
            {  
              QueryPerformanceCounter(&start);
              hebing_sort(array[3][i],0,n-1);
              QueryPerformanceCounter(&finsh);
              cout<<(finsh.QuadPart - start.QuadPart)*1000.0/frequency.QuadPart<<" ";                      
            }
         cout<<endl;  

		cout<<"插入排序算法20组数据所用的时间为(单位：ms):"<<endl;
		for(i = 0;i<20;i++)
           {               
              QueryPerformanceCounter(&start);
              insert_sort(array[1][i],n);
              QueryPerformanceCounter(&finsh);
              cout<<(finsh.QuadPart - start.QuadPart)*1000.0/frequency.QuadPart<<" ";                     
            }
          cout<<endl;

		cout<<"选择排序算法20组数据所用的时间为(单位：ms):"<<endl;
 		 for(i = 0;i<20;i++)
            {   
               QueryPerformanceCounter(&start);
               chosse_sort(array[2][i],n);
               QueryPerformanceCounter(&finsh);
               cout<<(finsh.QuadPart - start.QuadPart)*1000.0/frequency.QuadPart<<" ";
            }
           cout<<endl;

		cout<<"冒泡排序算法20组数据所用的时间为(单位：ms):"<<endl;
		for(i = 0;i<20;i++)
            {
               QueryPerformanceCounter(&start);
               maopao_sort(array[0][i],n);
               QueryPerformanceCounter(&finsh);
               cout<<(finsh.QuadPart - start.QuadPart)*1000.0/frequency.QuadPart<<" ";
            }
        cout<<endl;
		}
    	 
	}
      
	return 0;
}
