#!/bin/bash
sudo docker run --privileged -v /dev/bus/usb:/dev/bus/usb -v $PWD/keymaps:/src/keyboards/planck/keymaps --rm -it tiggilyboo/qmk bash
