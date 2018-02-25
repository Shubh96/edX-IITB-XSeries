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

int cyclicRightShift(int num){
	int temp, shifted;
	
	shifted= num%10;
	num/=10;
	temp = num;
	
	while(temp){
		shifted = shifted*10;
		temp/= 10;
	}
	
	shifted += num;
	
	return shifted; 
}

void solutionRPM(long long int rpm, int &years, long long int &finalRPM){
	
	long long int rpmSum, rpmProd, rpmShift, rpmMax = rpm*8;
	cout<<"MAX RPM = "<<rpmMax<<endl;
	cout<<"RPM\tYears\tSSD\tSSD*323\tShift\tNext RPM"<<endl;
	
	while(years<10 && rpm<rpmMax){
		years+=1;
		cout<<rpm<<"\t"<<years;
		
		rpmSum = digiSum(rpm);
		rpmProd = rpmSum*323;
		rpmShift = cyclicRightShift(rpm);
		
		cout<<"\t"<<rpmSum<<"\t"<<rpmProd<<"\t"<<rpmShift;
		
		rpm = rpmProd + rpmShift%100;
		
		cout<<"\t"<<rpm<<endl;
	}
}

int main(){
	
	int years=0;
	long long int RPM;
	long long int finalRPM = 0;
	
	cin>>RPM;
	
	solutionRPM(RPM, years, finalRPM);
	
	return 0;
}
