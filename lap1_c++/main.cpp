#include <iostream>
using namespace std;

class Complex {
private:
    int real, imag;

public:
    int getReal() {
        return real;
    }

    int getImag() {
        return imag;
    }

    void setReal(int r) {
        real = r;
    }

    void setImag(int i) {
        imag = i;
    }

    void print() {
        if (real == 0 && imag == 0) {
            cout << "0";
        } else if (imag == 0) {
            cout << real;
        } else if (imag > 0) {
            cout << real << " + " << imag << "i";
        } else {
            cout << real << " - " << -imag << "i";
        }
    }

    Complex add(Complex b) {
        Complex x;
        int newReal = real + b.getReal();
        int newImag = imag + b.getImag();
        x.setImag(newImag);
        x.setReal(newReal);
        return x;
    }

    friend Complex sub(Complex c, Complex x);
};

Complex sub(Complex c, Complex x) {
    Complex res;
    res.imag = c.imag - x.imag;
    res.real = c.real - x.real;
    return res;
}

void printStandAlone(Complex c) {
    cout << c.getReal();
    if (c.getImag() > 0) {
        cout << " + " << c.getImag() << "i";
    } else if (c.getImag() < 0) {
        cout << " - " << -c.getImag() << "i";
    }
}
Complex addStandAlone(Complex c,Complex y){
      Complex res;
      res.setImag(y.getImag()+c.getImag());
      res.setReal(y.getReal()+c.getReal());
      return res;
}
Complex subStandAlone(Complex c,Complex y){
      Complex res;
      res.setImag(c.getImag()-y.getImag());
      res.setReal(c.getReal()-y.getReal());
      return res;
    }

int main() {
    Complex c1, c2, result;
    c1.setReal(3);
    c1.setImag(2);
    c2.setReal(3);
    c2.setImag(2);

    Complex y = c1.add(c2);
    y.print();

    cout << endl;

    printStandAlone(c1);

    cout << endl;

    result = c1.add(c2);
    result.print();

    cout << endl;

    result = sub(c1, c2);
    result.print();

    return 0;
}
