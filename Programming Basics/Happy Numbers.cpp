#include<iostream>

using namespace std;

int digiSum(int num){
	int exp, sum=0;
	
	while(num){
		exp = num%10;
		sum += exp*exp;
		num /= 10;
	}
	
	return sum;
}

int main(){
	
	int num, digitSum, cycle_no = 0, finalNumber=0;
	
	cin>>num;
	
	while(cycle_no!=10)
	{
		digitSum = digiSum(num);
		cout<<"Cycle Number, digitSum: "<<cycle_no+1<<"\t"<<digitSum<<endl;
		cycle_no += 1;
		
		finalNumber = digitSum;
		
		if(digitSum == 1)
			break;
		else
			num = digitSum;
	}
	
	cout<<"Final Number: "<<finalNumber<<endl;
	cout<<"Cycle Count: "<<cycle_no;
	return 0;
}
