# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/ubuntu-rbe-200x/RBE200x/Lab1/build/_deps/picotool-src"
  "/home/ubuntu-rbe-200x/RBE200x/Lab1/build/_deps/picotool-build"
  "/home/ubuntu-rbe-200x/RBE200x/Lab1/build/_deps"
  "/home/ubuntu-rbe-200x/RBE200x/Lab1/build/picotool/tmp"
  "/home/ubuntu-rbe-200x/RBE200x/Lab1/build/picotool/src/picotoolBuild-stamp"
  "/home/ubuntu-rbe-200x/RBE200x/Lab1/build/picotool/src"
  "/home/ubuntu-rbe-200x/RBE200x/Lab1/build/picotool/src/picotoolBuild-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/ubuntu-rbe-200x/RBE200x/Lab1/build/picotool/src/picotoolBuild-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/ubuntu-rbe-200x/RBE200x/Lab1/build/picotool/src/picotoolBuild-stamp${cfgdir}") # cfgdir has leading slash
endif()
