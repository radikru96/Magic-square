using namespace std;
#include <iostream>
#include <fstream>
#define SIZE 3
#define MAX 100

// #define THREAD_MAX 4

int arr [SIZE][SIZE] = {{9,8,7},{6,5,4},{3,2,1}};
ofstream fout;

bool test (const int arr[][SIZE])
{
	if ((arr[0][0]*arr[0][0])+(arr[0][1]*arr[0][1])+(arr[0][2]*arr[0][2])==
		(arr[1][0]*arr[1][0])+(arr[1][1]*arr[1][1])+(arr[1][2]*arr[1][2])==
		(arr[2][0]*arr[2][0])+(arr[2][1]*arr[2][1])+(arr[2][2]*arr[2][2])==
		(arr[0][0]*arr[0][0])+(arr[1][0]*arr[1][0])+(arr[2][0]*arr[2][0])==
		(arr[0][1]*arr[0][1])+(arr[1][1]*arr[1][1])+(arr[2][1]*arr[2][1])==
		(arr[0][2]*arr[0][2])+(arr[1][2]*arr[1][2])+(arr[2][2]*arr[2][2])==
		(arr[0][0]*arr[0][0])+(arr[1][1]*arr[1][1])+(arr[2][2]*arr[2][2])==
		(arr[0][2]*arr[0][2])+(arr[1][1]*arr[1][1])+(arr[2][0]*arr[2][0]))
		return true;
	return false;
}

void write (const int arr[][SIZE],ofstream &fout)
{
	do
	{
		fout.open("file.txt",ofstream::app);
	} while (!fout.is_open());
	fout << arr[0][0]<<"\t"<<arr[0][1]<<"\t"<<arr[0][2]<<"\n";
	fout << arr[1][0]<<"\t"<<arr[1][1]<<"\t"<<arr[1][2]<<"\n";
	fout << arr[2][0]<<"\t"<<arr[2][1]<<"\t"<<arr[2][2]<<"\n\n";
	cout << arr[0][0]<<"\t"<<arr[0][1]<<"\t"<<arr[0][2]<<"\n";
	cout << arr[1][0]<<"\t"<<arr[1][1]<<"\t"<<arr[1][2]<<"\n";
	cout << arr[2][0]<<"\t"<<arr[2][1]<<"\t"<<arr[2][2]<<"\n\n";
	fout.close();
}

int main() {
	while (arr[SIZE][SIZE]<MAX)
	{

		if (test(arr)) write(arr,fout);
		arr[0][0]++;
		if (arr[0][0]==MAX) {arr[0][0]=1; arr[0][1]++;}
		if (arr[0][1]==MAX) {arr[0][1]=1; arr[0][2]++;}
		if (arr[0][2]==MAX) {arr[0][2]=1; arr[1][0]++;}
		
		if (arr[1][0]==MAX) {arr[1][0]=1; arr[1][1]++;}
		if (arr[1][1]==MAX) {arr[1][1]=1; arr[1][2]++;}
		if (arr[1][2]==MAX) {arr[1][2]=1; arr[2][0]++;}
		
		if (arr[2][0]==MAX) {arr[2][0]=1; arr[2][1]++;}
		if (arr[2][1]==MAX) {arr[2][1]=1; arr[2][2]++;}
	}
	return 0;
}