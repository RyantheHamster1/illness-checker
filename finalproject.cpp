#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
using namespace std;

/**/
int covid_count;
int cold_count;
int flu_count;
int other_count;

/*Function to easily display the symptoms board.*/
void displayBoard(){
	cout<<"Guide:   *Common      + Sometimes/Rarely      - No"<<endl;
	cout<<"---------------------------------------------------"<<endl;
	cout<<"Symptoms            |  COVID-19  |  Cold  |  Flu  |"<<endl;
	cout<<"---------------------------------------------------"<<endl;
	cout<<"Fever               |     *      |    +   |   *   |"<<endl;
	cout<<"Cough               |     *      |    +   |   *   |"<<endl;
	cout<<"Shortness of Breath |     *      |    -   |   -   |"<<endl;
	cout<<"Runny Nose          |     +      |    *   |   +   |"<<endl;
	cout<<"Headaches           |     +      |    +   |   *   |"<<endl;
	cout<<"Sneezing            |     -      |    *   |   -   |"<<endl;
	cout<<"Fatigue             |     +      |    +   |   *   |"<<endl;
	cout<<"---------------------------------------------------"<<endl;
}

/*Using 0 and 1 to show whether or not the symtpom is present or absent. (1 = present, 0 = absent"*/
class Sickness {
	public:
		int fever;
		int cough;
		int breath;
		int nose;
		int head;
		int sneeze;
		int fatigue;
};

class Covid: public Sickness {
	public:
		const static int fever = 1;
		const static int cough = 1;
		const static int breath = 1;
		const static int sneeze = 0;
};

class Cold: public Sickness {
	public:
		const static int nose = 1;
		const static int sneeze = 1;
		const static int breath = 0;
};

class Flu: public Sickness {
	public:
		const static int fever = 1;
		const static int cough = 1;
		const static int head = 1;
		const static int fatigue = 1;
		const static int breath = 0;
};

Covid covid;
Cold cold;
Flu flu;

int main(void) {
	cout<<"Welcome to Symptoms Checker\n"<<endl;
	displayBoard();
	int patient_count;
	cout<<"Enter the number of patients: "<<endl;
	cin>> patient_count;
	cout<<"Please wait."<<endl;
	cout<<"------------------------------------"<<endl;
	srand (time(NULL));
	for (int i = 1; i <= patient_count; ++i){

		Sickness patient;
		patient.fever = rand() % 2;
		patient.cough = rand() % 2;
		patient.breath = rand() % 2;
		patient.nose = rand() % 2;
		patient.head = rand() % 2;
		patient.sneeze = rand() % 2;
		patient.fatigue = rand() % 2;
		if (patient.fever == covid.fever && patient.cough == covid.cough && patient.breath == covid.breath && patient.sneeze == covid.sneeze){
			covid_count += 1;
		}
		else if (patient.nose == cold.nose && patient.sneeze == cold.sneeze && patient.breath == cold.breath){
			cold_count += 1;
		}
		else if (patient.fever == flu.fever && patient.cough == flu.cough && patient.head == flu.head && patient.fatigue == flu.fatigue && patient.breath == flu.breath){
			flu_count += 1;
		}
		else {
			other_count += 1;
		}
	}
	cout<<covid_count<<" patients have symptoms of COVID-19.\n"<<cold_count<<" patients have symptoms of the cold.\n"<<flu_count<<" patients have symptoms of the flu.\n"<<other_count<<" patients may have other illnesses."<<""<<endl;
	cout<<"------------------------------------"<<endl;
	int covid_perc = covid_count*100/patient_count;
	int cold_perc = cold_count*100 / patient_count;
	int flu_perc = flu_count*100 / patient_count;
	int other_perc = other_count*100 /patient_count;
	cout<<"Percentages of each illness:\n"<<endl;
	cout<<"COVID-19: ["<<covid_perc<<"]";
	for (int i = 1; i <= covid_perc; ++i){
		cout<<"+";
	}
	cout<<"\nCold: ["<<cold_perc<<"]";
	for (int i = 1; i <= cold_perc; ++i){
		cout<<"+";
	}
	cout<<"\nFlu: ["<<flu_perc<<"]";
	for (int i = 1; i <= flu_perc; ++i){
		cout<<"+";
	}	
	cout<<"\nOther Illnesses: ["<<other_perc<<"]";
	for (int i = 1; i <= other_perc; ++i){
		cout<<"+";
	}	
	return 0;
}








