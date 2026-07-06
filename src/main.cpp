#include <iostream>
#include <libraw/libraw.h>

using namespace std;

int main(int argc, char* argv[]) {
    
    string filePath = argv[1];
    cout << "Attempting to open: " << filePath << endl;

    LibRaw processor;

    int openResult = processor.open_file(filePath.c_str());
    if (openResult != LIBRAW_SUCCESS) {
        cerr << "Error opening file: " << libraw_strerror(openResult) << endl;
        return 1;
    }

    cout << "File opened successfully!" << endl;
    cout << "Image width: " << processor.imgdata.sizes.width << endl;
    cout << "Camera manufacturer: " << processor.imgdata.idata.make << endl;
    cout << "Camera model: " << processor.imgdata.idata.model << endl;

    processor.recycle(); 

    return 0;
}