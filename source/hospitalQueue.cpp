#include <iostream>

using namespace std;

const int MAX_QUEUE = 5;
const int MAX_SPECIALIZATION = 100;

struct Patient {
  string name;
  short int status;

  Patient(){};
  Patient(string name, short int status) {
    this->name = name;
    this->status = status;
  };
};

struct HospitalQueue {
  Patient patients[MAX_QUEUE];
  int len;
  int spec;

  HospitalQueue() {
    this->len = 0;
    this->spec = -1;
  };

  HospitalQueue(int spec) { this->spec = spec; };

  bool addEnd(const Patient &p) {
    if (this->len == MAX_QUEUE) return false;

    this->patients[this->len].name = p.name;
    this->patients[this->len].status = p.status;
    this->len++;

    return true;
  }

  bool addFront(Patient &p) {
    if (this->len == MAX_QUEUE) return false;

    for (int i = this->len - 1; i >= 0; i--)
      this->patients[i + 1] = this->patients[i];

    this->patients[0].name = p.name;
    this->patients[0].status = p.status;
    this->len++;

    return true;
  }

  bool removeFront() {
    if (this->len == 0) return false;

    cout << patients[0].name << " Please go with Dr.\n";
    for (int i = 1; i < this->len; i++)
      this->patients[i - 1] = this->patients[i];

    this->len--;
    return true;
  }

  void print() {
    if (this->len == 0) return;

    for (int i = 0; i < this->len; i++) {
      string *name = &this->patients[i].name;
      string status = patients[i].status == 0 ? "regular" : "urgent";

      cout << "Name: " << *name << "\t";
      cout << "Status: " << status << "\n";
    }
  }
};

struct HospitalSystem {
  HospitalQueue queues[MAX_SPECIALIZATION];

  HospitalSystem() {
    for (int i = 0; i < MAX_SPECIALIZATION; i++) queues[i] = HospitalQueue(i);
  }

  short int menu() {
    short int choice = -1;

    while (choice == -1) {
      cout << "1) Add patient.\n";
      cout << "2) Print all patients.\n";
      cout << "3) Get next patient.\n";
      cout << "4) Exit.\n";
      cout << "Enter one option: ";

      cin >> choice;

      if (!(choice >= 1 && choice <= 3)) {
        cout << "\n\nInvalid choice, try again.\n\n";
        choice = -1;
      }

      if (cin.fail()) {
        cin.clear();
        cin.ignore();
        choice = -1;
      }
    }
    return choice;
  }

  void run() {
    while (true) {
      short int choice = menu();
      // cout << choice;
      if (choice == 1)
        addPatient();
      else if (choice == 2)
        printAllPatients();
      else if (choice == 3)
        getNextPatient();
      else
        break;
    }
  }

  bool addPatient() {
    Patient p;
    short int spec;

    cout << "\nEnter specialization: ";
    cin >> spec;

    cout << "\nEnter name: ";
    cin >> p.name;

    cout << "\nEnter status, 0 for regular 1 for urgent: ";
    cin >> p.status;

    bool status;
    if (p.status == 0)
      status = this->queues[spec].addEnd(p);
    else
      status = this->queues[spec].addFront(p);

    if (status == false) {
      cout << "\nSorry we can't add more patients for this specialization.\n";
      return false;
    }

    return true;
  }

  void printAllPatients() {
    cout << "\n All Patients \n";
    for (int i = 0; i < MAX_SPECIALIZATION; i++) queues[i].print();
  }

  void getNextPatient() {
    int spec;

    cout << "Enter specialization: ";
    cin >> spec;

    queues[spec].removeFront();
  }
};

int main() {
  HospitalSystem hospital = HospitalSystem();
  hospital.run();

  return 0;
}