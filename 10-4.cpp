﻿#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Subscriber {
private:
    string name;
    int numChannels;
    string* channelList = new string[10];
    int size;

public:
    Subscriber() {};
    Subscriber(string name) {
        this->name = name;
        size = 10;
        channelList = new string[10];
    }

    ~Subscriber() {
        delete[] channelList;
    };

    Subscriber operator =(const Subscriber& oldObj) {
        name = oldObj.name;
        numChannels = oldObj.numChannels;
        size = oldObj.size;
        channelList = new string[size];

        for (int i = 0; i < numChannels; i++)
            *(channelList + i) = *(oldObj.channelList + i);

    }

    void handleInput() {
        string input, input_name;
        cout << "Enter name=> ";
        cin >> input_name;
        this->name = input_name;

        numChannels = 0;
        while (true) {
            cout << "Enter the subscribed channel (-q to end)=> ";
            cin >> input;
            if (input == "-q") {
                break;
            }
            numChannels++;

            if (numChannels > size) {
                string* temp = new string[size + 10];

                for (int i = 0; i < size; i++) {
                    *(temp + i) = *(channelList + i);
                }
                size += 10;
                delete[] channelList;
                channelList = temp;

            }
            *(channelList + numChannels - 1) = input;
        }
    }

    void reset() {
        numChannels = 0;
        delete[] channelList;
        channelList = new string[10];
    }

    void display() const {
        cout << endl << "[*] Info of " << name << endl;
        cout << "Name: " << name << endl;
        cout << "Total subscribed: " << numChannels << endl;
        cout << "List of channels:" << endl;
        for (int i = 0; i < numChannels; i++) {
            cout << i + 1 << ". " << *(channelList + i) << endl;
        }
    }
};


int main() {
    Subscriber sub1, sub2;

    sub1.handleInput();
    sub1.display();

    cout << endl << "[*] Subscriber 2 (copy from Subscriber 1):";
    sub2 = sub1;
    sub1.display();

    cout << endl << "[*] Reset subscriber 2:";
    sub2.reset();
    sub2.handleInput();
    sub2.display();

    system("pause");
    return 0;
}