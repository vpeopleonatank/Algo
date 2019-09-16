#include <stdio.h>
#include <algorithm>
using namespace std;

int n, k, m;
int a[1230997];

void bsearch(int k){
    int ll=1, rr=n, i;
    for (i=ll; i<=rr; i++)
    if (a[i]>=k) { printf("%d\n", a[i]); return; }
    printf("Not found\n");
}

int main(){
    int i;
    scanf("%d", &n);
    for (i=1; i<=n; i++) scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    scanf("%d", &m);
    for (i=1; i<=m; i++){
        scanf("%d", &k);
        bsearch(k);
    }
}