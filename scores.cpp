#include <iostream>
using namespace std;

const int MAX = 10;
float findAverageScore(int scores[], int n)
{
	float avg = 0;
	float max = 0;
	float min = 10;
	float sum = 0; 

	for (int i = 0; i < n; i++)
	{
		if (scores[i] < min)
		{
			min = scores[i];
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (scores[i] > max)
		{
			max = scores[i];
		}
	}

	for (int i = 0; i < n; i++)
	{
		sum += scores[i];
	}

	sum = sum - (min + max);
	avg = sum / (n - 2);

	return avg; 
}

int main()
{
	int scores[MAX]; 
	float avg1 = 0;
	float avg2 = 0; 
	float avg3 = 0;
	int cont1;
	int cont2;
	int cont3;
	int n;

	cout << "Number of Judges: ";
	cin >> n; 

	cout << endl << "There are " << n << " judges." << endl;
	//----------------------------------------
	
	cout << "Enter your contestant #: ";
	cin >> cont1; 

	cout << "Enter your contestant # scores: ";

	for (int i = 0; i < n; i++)
	{
		cin >> scores[i];
	}

	avg1 = findAverageScore(scores, n);

	cout << "\nContestant " << cont1 << endl
		<< "Average: " << avg1 << endl;

	//----------------------------------------

	cout << "\nEnter your contestant #: ";
	cin >> cont2;

	cout << "Enter your contestant # scores: ";
	for (int i = 0; i < n; i++)
	{
		cin >> scores[i];
	}

	avg2 = findAverageScore(scores, n);
	
	cout << "\nContestant " << cont2 << endl
		<< "Average: " << avg2 << endl;

	//----------------------------------------

	cout << "\nEnter your contestant #: ";
	cin >> cont3;  

	cout << "Enter your contestant # scores: ";
	for (int i = 0; i < n; i++)
	{
		cin >> scores[i];
	}

	avg3 = findAverageScore(scores, n);

	cout << "\nContestant " << cont3 << endl
		<< "Average: " << avg3 << endl;
	//----------------------------------------


	if ((avg1 > avg2) && (avg1 > avg3))
	{
		cout << "Contestant " << cont1 << " had the highest score.";
	}
	else if ((avg2 > avg1) && (avg2 > avg3))
	{
		cout << "Contestant " << cont2 << " had the highest score.";
	}
	else if ((avg3 > avg1) && (avg3 > avg2))
	{
		cout << "Contestant " << cont3 << " had the highest score.";
	}

	cout << endl; 

	return 0; 

}
