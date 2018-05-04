#include <iostream>
using namespace std;

#define pixel 3byte
class Bitmap {
public:
    Bitmap(size_t w, size_t h)
    : width(w), height(h) {
        pixelArray = (int**)malloc(height);
        for (int i=0; i<height; i++)
            pixelArray[i] = new int[width];
    }
    void print() {
        for (int i=0;i<height;i++) {
            for (int j=0;j<width;j++) {
                cout << "[ ]";
            }
            cout << endl;
        }
    }
private:
    size_t width,height;
    int **pixelArray;
};

class Widget {
public:
    Widget(size_t w, size_t h)
    : pb(new Bitmap(w,h))
    {

    }
    Widget& operator=(const Widget& w) {
        if (this == &w)
            return *this;
    
        delete pb;
        pb = nullptr;
        pb = new Bitmap(*w.pb);
        return *this;
    }
    Bitmap& getBitmap() {
        return *pb;
    }
private:
    Bitmap* pb;
};

int main()
{
    Widget w(3,4);
    w.getBitmap().print();
    w = w;
    w.getBitmap().print();
}