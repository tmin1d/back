#include <stdio.h>

int add(int arr[], int x){
    if(arr[x-1] != x) arr[x-1] = x;
    return 0;
}
int remove_(int arr[], int x){
    if(arr[x-1] == x) arr[x-1] = 0;
    return 0;
}
int check(int arr[], int x){
    if(arr[x-1] == x){
        printf("1\n");
    }
    else{
        printf("0\n");
    }
    return 0;
}
int toggle(int arr[], int x){
    if(arr[x-1] != x){
        arr[x-1] = x;
    }
    else{
        arr[x-1] = 0;
    }
    return 0;
}
int all(int arr[]) {
    for (int i = 0; i < 20; i++) {
        arr[i] = i + 1;
    }
    return 0;
}

int empty(int arr[]) {
    for (int i = 0; i < 20; i++) {
        arr[i] = 0;
    }
    return 0;
}

int main(){
    int s[32];
    char f[8];
    int x;
    int m;
    
    scanf("%d", &m);
    
    for(int i =0; i<m; i++){
        scanf("%s %d", f, &x);
        if (strcmp(f, "add") == 0) add(s, x);
        if(f[0] == 'r') remove_(s, x);
        if(f[0] == 'c') check(s, x);
        if(f[0] == 't') toggle(s, x);
        if (strcmp(f, "all") == 0) all(s);
        if(f[0] == 'e') empty(s);
    }
}
