/*Median of Sorted Arrays
X
Algorithm .
1) Calculate the medians m1 and m2 of the input arrays ar1[] and ar2[] respectively.
2) If m1 and m2 both are equal then we are done. return m1 (or m2) .
3) If m1 is greater than m2, then median is present in one of the below two subarrays.
a) From first element of ar1 to m1 (ar1[0…|n/2|]) .
b) From m2 to last element of ar2 (ar2[|n/2|…n-1]) .
4) If m2 is greater than m1, then median is present in one
of the below two subarrays.
a) From m1 to last element of ar1 (ar1[|n/2|…n-1]) .
b) From first element of ar2 to m2 (ar2[0…|n/2|])
5) Repeat the above process until size of both the subarrays becomes 2.
6) If size of the two arrays is 2 then use below formula to get the median.
Median = (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1]))/2

Required Code is given below :
*/

#include<iostream>
using namespace std;


int median(int *arr1,int *arr2,int n){
	int lo1 = 0,hi1 = n-1;
	int lo2 = 0,hi2 = n-1;

	if(n == 1){
    	return (arr1[0] + arr2[0]) >> 1;
	}
	while(true){
    	int m1,m2,median1,median2;
    	median1 = arr1[(hi1 + lo1)>>1];
    	median2 = arr2[(hi2 + lo2)>>1];
	
    	m1 = (hi1 + lo1)>>1;
    	m2 = (hi2 + lo2)>>1;

    	if(hi1 - lo1 == 1){
        	return (max(arr1[lo1] , arr2[lo1]) +
        	min(arr1[hi1] , arr2[hi2])) / 2;
    	}

    	if(median1 == median2)
        	return median1;
    	if(m1 > m2){
        	hi1 = m1;
        	lo2 = m2;
    	}
    	else{
            hi2 = m2;
            lo1 = m1;
    	}
	}
	return 0;
}

int main(){
	int arr1[1000],arr2[1000];
	int n ;
	cin>>n;
	for(int i=0;i<n;i++){
    	cin>>arr1[i];
	}

	for(int i=0;i<n;i++){
    	cin>>arr2[i];
	}

	cout<<median(arr1,arr2,n)<<endl;
	return 0;
}

