## Data Structure and Algorithms Problems

[![Build Status](https://travis-ci.org/wow2006/algorithms_and_data_structures.svg?branch=master)](https://travis-ci.org/wow2006/algorithms_and_data_structures)
[![Build status](https://ci.appveyor.com/api/projects/status/wcvou0ok66skv6ae?svg=true)](https://ci.appveyor.com/project/wow2006/algorithms-and-data-structures)

Install:
-------

For Windows
----------
I recommend [vcpkg](https://github.com/Microsoft/vcpkg)
```powershell
> .\vcpkg.exe install gtest:x64-windows
```

For Ubuntu
----------
```bash
> sudo apt-get install cmake
> sudo apt-get install libgtest-dev
> cd /usr/src/gtest
> sudo cmake CMakeLists.txt
> sudo make
> sudo cp *.a /usr/lib
> cd -
```

For Arc
-------
```bash
> sudo pacman -S gtest
```

For Fedora
----------
```bash
> sudo dnf install gtest
```

Run:
----
```
mkdir AlgorithmsAndDataStructures 
cd AlgorithmsAndDataStructures
git clone https://github.com/wow2006/algorithms_and_data_structures.git src
mkdir build/Release -p
cd build/Release
cmake -DCMAKE_BUILD_TYPE=Release ../src
cmake --build .
ctest
```

Problems:
--------

1. [Linked List](./LinkedList/README.md)
