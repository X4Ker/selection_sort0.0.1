#include <iostream>
#include <utility>
#include <string>
#include <sstream>

using namespace std;

void selectionSort(int *a, int n)
{
	int min;

	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		swap(a[min], a[i]);
	}
}

bool read_numbers(int *a, unsigned int n)
{
	string string;
	getline(cin, string);
	istringstream stream(string);
	bool success = true;
	for (int i = 0; i < n; ++i) {
		if (!(stream >> a[i])) {
			success = false;
			break;
		}
	}

	return success;
}

int main() {
	unsigned int n;
	int *a;
	cin >> n;
	cin.get();
	a = new int[n];
	if (read_numbers(a, n)) {
		selectionSort(a, n);
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
	}
	else {
		cout << "An error has occured while reading input data.";
	}
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return 0;
}
