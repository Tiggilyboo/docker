#!/bin/bash
cat rootfs.tar.xz | sudo docker import - tiggilyboo/base
sudo docker push tiggilyboo/base 
