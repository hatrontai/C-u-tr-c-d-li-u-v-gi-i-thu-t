#include <bits/stdc++.h>
using namespace std;
double A[1000008], TempArray[1000008];
void Merge( int Left, int Mid, int Right)
{
    int d=Left, c1=Left, c2=Mid+1;
	for(; (c1 <= Mid) && (c2 <= Right); d++ )
	{
		if (A[c1] < A[c2])
			TempArray[d] = A[c1++];
		else
			TempArray[d] = A[c2++];
	}
	for( ; c1 <= Mid; c1++, d++ ) TempArray[d] = A[c1];
	for( ; c2 <= Right; c2++, d++ ) TempArray[d] = A[c2];
	for (d=Left; d<=Right; d++)
		A[d] = TempArray[d];
}
void MergeSort(int Left, int Right)
{
	int Mid;
	if (Left < Right)
	{
		Mid = (Left + Right)/2;
		MergeSort(Left, Mid);
		MergeSort(Mid+1, Right);
		Merge(Left, Mid, Right);
	}
}
void Check(int n){
    for(int i=1; i<=n-1; i++)
    {
        if(A[i]>A[i+1]) {
            cout<<"fail";
            return;
        }
    }
    cout << "true\n";
}

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
    MergeSort(1,n);
    clock_t End = clock();
    out <<"Test "<<dem<<": "<< (double)(End - Start) / CLOCKS_PER_SEC << "s\n";
    for(int i=1; i<=n; i++) cout<<setprecision(13)<<A[i]<<" ";
    //Check(n);
    dem++;
    }
    out.close();

    return 0;
}
