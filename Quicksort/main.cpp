#include <bits/stdc++.h>

using namespace std;

double A[1000008];

void QuickSort(int Left, int Right)
{
	int i, j;
	double x;
	i = Left; j = Right;
	x = A[(Left+Right)/2];
	do
	{
		while (A[i] < x) i++;
		while (A[j] > x) j--;
		if (i <= j)
		{
			swap(A[i], A[j]);
			i++; j--;
		}
	} while (i <= j);
	if (Left < j) QuickSort(Left, j);
	if (i < Right) QuickSort(i, Right);
}
void Check(int n);
int main(){
    int dem=1;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ofstream out;
    out.open("time.txt");
    while(dem<=10){
        freopen(("inp" + to_string(dem) + ".txt").c_str(),"r",stdin);
        freopen(("outp" + to_string(dem) + ".txt").c_str(),"w",stdout);
    int n;
    cin>>n;
    //float *a = new float[n+5];
    for(int i=1; i<=n; i++){
        cin>>A[i];
    }
    clock_t Start = clock();
    QuickSort(1,n);
    clock_t End = clock();

    out <<"test "<<dem<<": "<< (double)(End - Start) / CLOCKS_PER_SEC << "s\n";
    for(int i=1; i<=n; i++) cout<< setprecision(13)<<A[i]<<" ";
    //Check(n);
    dem++;

    fclose(stdout);
    }
    out.close();
    return 0;
}
void Check(int n){
    for(int i=1; i<=n-1; i++)
    {
        if(A[i] > A[i+1]) {cout<<"fail\n"; return;}
    }
    cout<<"true\n";
}
