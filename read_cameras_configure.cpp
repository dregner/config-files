

#include <iostream>
#include <libconfig.h++>
#include <iomanip>
#include <cstdlib>


using namespace libconfig;
using namespace std;

int main() {
    Config cfg;
    cout << "Hello, Lib Config!" << std::endl;
    try {
        cfg.readFile("/home/vant3d/read_files/cameras.cfg");
    }
    catch (const FileIOException &fioex) {
        cerr << "I/O error" << endl;
        return (EXIT_FAILURE);
    }
    catch (const ParseException &pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
                  << " - " << pex.getError() << std::endl;
        return (EXIT_FAILURE);
    }
    try {
        string name = cfg.lookup("group");
        cout << "String:" << name << endl;
    }
    catch (const SettingNotFoundException &nfex) {
        cerr << "No group" << endl;
    }
    const Setting &root = cfg.getRoot();

    try {
        const Setting &stereo = root["cameras"]["stereo"];
        int count = stereo.getLength();
        cout << "Stereo lenght: " << count << endl;
        cout << setw(30) << left << "NAME" << " "
             << setw(30) << left << "SHUTTER" << " "
             << setw(30) << left << "MODE" << " "
             << setw(30) << left << "IMG_FORMAT" << " "
             << setw(30) << left << "PX_WIDTH" << " "
             << "PX_ HEIGHT" << " " << endl;
        for (int i = 0; i < count; ++i) {
            const Setting &cam = stereo[i];

            string name, mode, img_format;
            int shutter, px_width, px_height;

            if (!(cam.lookupValue("name", name)
                  && cam.lookupValue("shutter", shutter)
                  && cam.lookupValue("mode", mode)
                  && cam.lookupValue("img_format", img_format)
                  && cam.lookupValue("width", px_width)
                  && cam.lookupValue("height", px_height)))
                continue;
            cout << setw(30) << left << name << " "
                 << setw(30) << left << shutter << " "
                 << setw(30) << left << mode << " "
                 << setw(30) << left << img_format << " "
                 << setw(30) << left << px_width << " "
                 << px_height
                 << endl;
        }
        cout << endl;

    }
    catch (const SettingNotFoundException &nfex) {
        cerr << "PROBLEM" << endl;
    }


    return 0;
}