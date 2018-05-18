/*
Algorithm for main function--
START
	s1-Read a string store in str.
	s2-call findrank function to calculate rank store in rank.
	s3-display rank.
END

Algorithm for findrank function--
START
	s1-calculate the lenght of the string passed.
	s2-call the factorial function to calculate the total number of words that can be formed by the letters of input string and store it in mul.
	s3-run a for loop from i=0 to i<len
	s4-	perform mul=mul/(len-i)
	s5-	call the count in right function to calculate the number of letters smaller than i and store it in count.
	s6-	calculate rank as rank=count*mul.
	s7-return rank.
END

Algorithm for countinright function--
START
	s1-run a for loop from j=i+1 to j=len-1 where i+1 is passed by findrank function stored as low and len-1 stored as high.
	s2-	check whether str[i]is less than str[low]
	s3-		if yes increment the value of count.
	s4-return count.
END
*/
#include<stdio.h>
#include<string.h>

int factorial(int n)								//calculating factorial (total number of rearrangements).
{
	if(n<=1)
		return 1;
	else
		return n*factorial(n-1);
}

int countinright(char str[],int low,int high)				      //counting the letters which are smaller than letter at str[i] in the right side of str 
{
	
	int j,count=0;
	for(j=low+1;j<=high;j++)
		if(str[j]<str[low])
			count++;
	return count;
}

int findrank(char str[])							
{
	int i,rank=1,mul,len;
	long int counter;
	len=strlen(str);
	mul=factorial(len);
	
	for(i=0;i<len;i++)
	{
		mul=mul/(len-i);						//permutation changes for every letter in a string.
		counter=countinright(str,i,len-1);				//calling of count in right function to get the number of smaller letters.
		rank+=counter*mul;						//Adding up every word formed before the input word.
	}
	return rank;
}


int main()
{
	char str[100];
	int rank;
	printf("\n Enter a string (all uppercase letters or all lowercase letters) : ");
	scanf("%s",&str);
	rank=findrank(str);
	printf("\n The rank is : %d",rank);
	return 0;
}	
			
