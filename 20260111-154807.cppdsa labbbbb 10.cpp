#include <iostream>
using namespace std;


class SalaryManager {
private:
    int salaries[10];   
    int size;

public:
    
    SalaryManager() {
        size = 10;

       
        salaries[0] = 45000;
        salaries[1] = 32000;
        salaries[2] = 56000;
        salaries[3] = 28000;
        salaries[4] = 39000;
        salaries[5] = 61000;
        salaries[6] = 47000;
        salaries[7] = 30000;
        salaries[8] = 52000;
        salaries[9] = 35000;
    }

  
    void displaySalaries() {
        for (int i = 0; i < size; i++) {
            cout << salaries[i] << " ";
        }
        cout << endl;
    }


    void bubbleSort() {
        int temp;

        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (salaries[j] > salaries[j + 1]) {
                   
                    temp = salaries[j];
                    salaries[j] = salaries[j + 1];
                    salaries[j + 1] = temp;
                }
            }
        }
    }
};


int main() {
    SalaryManager payroll;

    cout << "Employee Salaries (Before Sorting):\n";
    payroll.displaySalaries();

    payroll.bubbleSort();

    cout << "\nEmployee Salaries (After Sorting in Ascending Order):\n";
    payroll.displaySalaries();

    return 0;
}
