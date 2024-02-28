# Apic
[c++ api with Pistache & Sqlite]

Installing Pistache#
git is needed to retrieve the sources. Compiling the sources will require CMake to generate build files and a recent compiler that supports C++17.

If you're on Ubuntu and want to skip the compilation process you can add the official PPA providing nightly builds:

sudo add-apt-repository ppa:pistache+team/unstable
sudo apt update
sudo apt install libpistache-dev
Otherwise, here's how to build and install the latest release:

git clone https://github.com/pistacheio/pistache.git
cd pistache
meson setup build
meson install -C build
