#include <iostream>
#include <libraw/libraw.h>
#include <cmath>
#include <string>

using namespace std;

string calculateShutterSpeed(double shutter) {
    if (shutter < 0)
        return "Unknown";
    else if (shutter < 1)
        return "1/" + to_string((int)round(pow(shutter, -1.0))) + "\"";
    else
        return to_string(static_cast<int>(shutter)) + "\"";
    return "";
}

int main(int argc, char* argv[]) {
    
    string filePath = argv[1];
    cout << "Attempting to open: " << filePath << endl;

    LibRaw processor;

    int openResult = processor.open_file(filePath.c_str());
    if (openResult != LIBRAW_SUCCESS) {
        cerr << "Error opening file: " << libraw_strerror(openResult) << endl;
        return 1;
    }

    string dimensions = to_string(processor.imgdata.sizes.width) + "*" + to_string(processor.imgdata.sizes.height) + " px";
    string camera_model_name = processor.imgdata.idata.make + string(" ") + processor.imgdata.idata.model;
    
    cout << "File opened successfully!" << endl;
    cout << "Image Dimensions: " << dimensions << endl;

    cout << "Shot on: " << camera_model_name << endl;
    cout << "ISO: " << processor.imgdata.other.iso_speed << endl;
    cout << "Shutter Speed: " << calculateShutterSpeed(processor.imgdata.other.shutter) << endl;
    cout << "Aperture: " << "f" << processor.imgdata.other.aperture << endl;
    cout << "Focal Length: " << processor.imgdata.other.focal_len << " mm" << endl;
    cout << "Lens: " << processor.imgdata.lens.Lens << endl;

    processor.recycle(); 

    return 0;
}