#include <iostream>
#include <filesystem>
#include <map>

//1. Prepare your IDE to work with the C++20 standard (or newer). (In VS - right click the project name in solution explorer
//properties -> general -> ISO Standard (/std:c••20))
//2. Create your own namespace to replace std::filesystem (something shorter to write).
namespace fs = std::filesystem; // Task #2

int main() {
    fs::path path("E:\\Documents\\cpp_projects\\polsl-aei-cp4-ang\\2d98c560-gr12-repo\\lab3\\filesystem\\main.cpp"); // Task #3

    // Display information about the path (dæs it exist. name. root path. relative path, parent path, file name, its stem and
    // extension).
    std::cout << "exists: " << fs::exists(path) << '\n';
    std::cout << "name: " << path.root_name() << '\n';
    std::cout << "root path: " << path.root_path() << '\n';
    std::cout << "relative Path: " << path.relative_path() << '\n';
    std::cout << "Parent Path: " << path.parent_path() << '\n';;
    std::cout << "file name: " << path.filename() << '\n';
    std::cout << "stem: " << path.stem() << '\n';
    std::cout << "extension: " << path.extension() << '\n';

    std::cout << "=============" << '\n';

    //4. Modify the code so it reads the current directory, without the need to copy-paste it. What is the difference?
    fs::path currentPath = fs::current_path();
    std::cout << "currentPath: " << currentPath << '\n';

    std::cout << "=============" << '\n';

    //5. Modify the code again so the path object holding the current path includes the file name you are working on.
    fs::path mainCppPath = currentPath.parent_path() / "main.cpp";
    std::cout << "mainCppPath: " << mainCppPath << '\n';

    std::cout << "=============" << '\n';

    //6. Extract the folder which has provided to you to the directory from task 3, display information the filesystem/
    //subdirl/shrek.txt file (file_size.)
    fs::path shrekPath = currentPath.parent_path() / "subdir1/shrek.txt";
    std::cout << "info about " << shrekPath << '\n';
    std::cout << "exists: " << fs::exists(shrekPath) << '\n';
    std::cout << "name: " << shrekPath.root_name() << '\n';
    std::cout << "root path: " << shrekPath.root_path() << '\n';
    std::cout << "relative Path: " << shrekPath.relative_path() << '\n';
    std::cout << "parent Path: " << shrekPath.parent_path() << '\n';
    std::cout << "file name: " << shrekPath.filename() << '\n';
    std::cout << "stem: " << shrekPath.stem() << '\n';
    std::cout << "extension: " << shrekPath.extension()<< '\n';
    std::cout << "file size: " << file_size(shrekPath) << '\n';

    //7. Copy the shrek.txt file to a new file and call it shrek2.txt. (Note: file_copy only works if the destination file does not exist, so
    //        running the same code twice without deleting shrek2.txt in the meantime will not work).
    //- optional: modify your code so it checks whether the destination file exists. If it dcE•s, ask the user if they want to overwrite the
    //        file and continue if they do.
    fs::path t7 = fs::current_path().parent_path() / "subdir1/shrek.txt";
    //fs::copy( t7,  t7.parent_path() / "shrek2.txt", fs::copy_options::update_existing);

    //todo
    std::cout << "=============" << '\n';
    std::cout << "currentPath: " << currentPath << '\n';

    //8. Check whether the filesystem/subdir2 is empty (is_empty) and if it is a directory (is_directory).
  //  fs::path newPath = currentPath.parent_path() / "subdir2";
    std::cout << "empty: " << is_empty(fs::current_path().parent_path() / "subdir2")  << '\n';
    std::cout << "directory: " << is_directory(fs::current_path().parent_path() / "subdir2") << '\n';


    std::cout << "=============" << '\n';
    std::cout << "currentPath: " << currentPath << '\n';

    //9. Display all names (without the path and without the extension) Of files which have the •.rtf• extension (in the /filesystem
    //        directory).
    //10. •Rename them all so they do not lose the extension and are named like this: filetrtf. file2.rtf. file3.rtf etc.
    int it = 1;
    for (auto &dir: fs::recursive_directory_iterator{currentPath.parent_path()}) {

        if (dir.path().extension() == ".rtf") {

            std::string name = "file" + std::to_string(it) + ".rtf";

            std::cout << dir.path().stem() << '\n';
            fs::rename(dir.path(), dir.path().parent_path() /= name);
            it++;
        }
    }

    std::cout << "=============" << '\n';
    std::cout << "currentPath: " << currentPath << '\n';

    //11.Find the file which takes up the most memory.
    fs::path maxPath;
    int maxSize;
    for (auto &dir: fs::recursive_directory_iterator{currentPath.parent_path()}) {
        if (!dir.is_directory() && dir.file_size() > maxSize) {
            maxPath = dir.path();
            maxSize = dir.file_size();
        }
    }
    std::cout << maxPath.filename() << " | " << maxSize << '\n';

    std::cout << "=============" << '\n';
    std::cout << "currentPath: " << currentPath << '\n';

    //12.Sort all Of the files with ".rtf" extension (in the 'filesystem directory) in the incrementing order, print the results in the console.
    auto fileIterator = fs::recursive_directory_iterator(currentPath.parent_path());

    std::map<int, std::string> map;

    for (auto &dir: fs::recursive_directory_iterator{currentPath.parent_path()}) {

        if (!dir.is_directory() && dir.path().extension() == ".rtf") {
            map.insert(std::pair<int, std::string>(dir.file_size(), dir.path().filename()));
        }
    }
    for (auto &element: map) {
        std::cout << element.second << " | " << element.first << '\n';
    }


    std::cout << "=============" << '\n';
    std::cout << "currentPath: " << currentPath << '\n';

    // 13
    fs::path toJpg = currentPath.parent_path() / "subdir3/ilovejpg";
    fs::path toPng = currentPath.parent_path() / "subdir3/ilovepng";

    for (auto& dirr : fs::directory_iterator{currentPath.parent_path() / "subdir3"}) {

        if (dirr.path().extension() == ".jpg") {
            fs::rename (dirr.path(), toJpg / dirr.path().filename());
        }

        if (dirr.path().extension() == ".png") {
            fs::rename (dirr.path(), toPng / dirr.path().filename());
        }
    }



    return 0;
}





