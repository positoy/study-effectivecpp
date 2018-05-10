#include <iostream>
#include <memory>
#include <cstring>
using namespace std;

struct _fonthandle {
    char *fontname;
    int fontsize;
};

typedef struct _fonthandle* FontHandle;

FontHandle getFont() {
    FontHandle fh = new struct _fonthandle;
    fh->fontname = new char[10];
    strcpy(fh->fontname, "Calibri");
    fh->fontsize = 10;
    return fh;
}

void releaseFont(FontHandle fh) {
    free(fh->fontname);
}

void increaseFontSize(FontHandle fh, size_t sizeDelta = 0) {
    if (sizeDelta == 0)
        fh->fontsize++;
    else
        fh->fontsize += sizeDelta;
}

class Font {
public:
    Font(FontHandle fh) : fonthandle(fh) {}
    FontHandle get() const { return fonthandle; }
    operator FontHandle() const { return fonthandle; }
private:
    FontHandle fonthandle;
};

int main()
{
    // explicitly getting resource
    Font myFont(getFont());
    cout << myFont.get()->fontname << '/' << myFont.get()->fontsize << endl;

    std::shared_ptr<struct _fonthandle> rcspFont(getFont());
    cout << rcspFont.get()->fontname << '/' << rcspFont.get()->fontsize << endl;
    cout << rcspFont->fontname << '/' << rcspFont->fontsize << endl;

    // implicitly getting resource
    increaseFontSize(myFont);
    cout << myFont.get()->fontname << '/' << myFont.get()->fontsize << endl;
    increaseFontSize(myFont, 2);
    cout << myFont.get()->fontname << '/' << myFont.get()->fontsize << endl;
}
