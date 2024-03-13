# Apic
[c++ api with Pistache & Sqlite]

Installing Pistache#
git is needed to retrieve the sources. Compiling the sources will require CMake to generate build files and a recent compiler that supports C++17.

If you're on Ubuntu and want to skip the compilation process you can add the official PPA providing nightly builds:

# installation 
```
apt install build-essential
sudo apt-get install cmake
apt install libpistache-dev
cd /var/www/apic
git clone https://github.com/oktal/pistache.git
cd pistache
sudo apt-get install meson
meson build
ninja -C build
sudo ninja -C build install
ufw allow 9080
g++ -std=c++17 -o apic main.cpp -lpistache
```
