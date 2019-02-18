cd gtest-1.7.0
sudo mkdir /opt/gtest /opt/gtest/include /opt/gtest/lib
./configure --prefix=/opt/gtest
make
sudo cp -a include/gtest/ /opt/gtest/include
sudo cp -a lib/.libs/* /opt/gtest/lib
rm /opt/gtest/lib/libgtest.la
rm /opt/gtest/lib/libgtest_main.la
sudo cp -a lib/libgtest.la /opt/gtest/lib
sudo cp -a lib/libgtest_main.la /opt/gtest/lib
