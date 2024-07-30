//without memoisation, recursively computes optimal value
//without memoisation, recursively finds optimal set

#include <stdio.h>
#define N 6

//start-time,finish-time,value.
int jobs[][3] = {
    {0, 0, 0},   // Dummy job
    {1, 2, 100},
    {2, 5, 200},
    {3, 6, 300},
    {4, 8, 400},
    {5, 9, 500},
    {6, 10, 100}
};

int max(int a, int b){
    return (a>b) ? a : b;
}

int p(int j){
    int count = 0;
    for (int i = 1 ; i <= N ; i++){
        if (jobs[j][0]>=jobs[i][1]){
            count++;
        }
    }
    return count;
}

int compute_opt(int j){
    if (j==0)
        return 0;
    else{
        return max(jobs[j][2] + compute_opt(p(j)), compute_opt(j-1));
    }
}

void find_solution(int j){
    if (j>0){
        if (jobs[j][2] + compute_opt(p(j)) >= compute_opt(j-1)){
            printf("%d  ",j);
            find_solution(p(j));
        }
        else
            find_solution(j-1);
    }
}

int main(){
    printf("Optimal solution : %d\n",compute_opt(6));
    printf("Optimal Set : ");
    find_solution(6);
    printf("\n");
    return 0;
}