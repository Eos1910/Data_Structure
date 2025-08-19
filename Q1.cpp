#include <iostream>
#include <stack>
using namespace std;

int main() {
    //Input elements 85, 75, 95, 80
    int a[] = {85, 75, 95, 80}, n = 4;
    //Create original stack (st)
    stack<int> st;

    //Push the elements into the stack
    cout << "(1) push the elements ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << ",";
        st.push(a[i]);
    }

    cout << " onto the stack st." << endl;
    cout << "(2) the process of sorting elements of stack st is:" << endl;

    //Create a temporary extra stack (tmpst)
    stack<int> tmpst;

    while (!st.empty()) {
        //Obtain the top element from the st and assign to tmp
        int tmp = st.top();
        //Pop out the element from the st
        st.pop();
        cout << "\tst: pop out " << tmp << "=>" << endl;

        //If stack tmpst is not empty
        while (!tmpst.empty()) {
            cout << "\t\ttmpst: get the top element " << tmpst.top() << endl;

            //Making sure to push tmpst top element until tmpst top element becomes smaller than tmp.
            if (tmpst.top() > tmp) {
                cout << "\t\t\tSince " << tmpst.top() << " > " << tmp << " tmpst: pop out " << tmpst.top() << endl;
                cout << "\t\t\tst: push " << tmpst.top() << endl;

                //Push the element from tmpst onto st
                st.push(tmpst.top());
                //Pop out tmpst element
                tmpst.pop();
            }
            else
            {
                cout << "\t\t\tSince " << tmpst.top() << " < " << tmp << ", exit the loop" << endl;
                break;
            }
        }

        cout << "\t\ttmpst: push " << tmp << endl;
        //If stack tmpst is empty, push tmp onto tmpst
        tmpst.push(tmp);
        cout << endl;
    }

    //If tmpst is not empty
    while (!tmpst.empty()) {
        //Push remaining elements from tmpst to the st
        st.push(tmpst.top());
        //Pop the top element from tmpst
        tmpst.pop();
    }

    cout << "(3) the sorting of stack st ends." << endl;
    cout << "(4) the popping sequence of st is: ";

    while (!st.empty()) {
        //Print out the sorted numbers on screen
        cout << st.top() << " ";
        //Pop out the top element of st
        st.pop();
    }

    cout << endl;

    return 0;
}

