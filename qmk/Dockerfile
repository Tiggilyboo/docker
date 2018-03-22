FROM tiggilyboo/base
MAINTAINER Simon Willshire <me@simonwillshire.com>
LABEL description="Quantum Mechanical Keyboard Firmware"

ENV INSTALL_PACKAGES="build-essential curl ca-certificates gcc unzip wget zip gcc-avr binutils-avr avr-libc dfu-programmer dfu-util gcc-arm-none-eabi binutils-arm-none-eabi libnewlib-arm-none-eabi git" \ 
    GIT_REPO="https://github.com/qmk/qmk_firmware" \
    KEYBOARD=planck \
    REVISION=rev5 \
    KEYMAP=tiggilyboo \
    TARGET=dfu 

WORKDIR /src

RUN \
  mkdir -p /src && cd /src && \
  apt-get -qq update -qq && \
  apt-get -y -qq --no-install-recommends install $INSTALL_PACKAGES && \
  apt-get autoremove -yq && \
  rm -rf /var/lib/apt/lists && \
  rm -rf /var/cache/apt && \
  git clone --recurse-submodules $GIT_REPO /src && \ 
  make clean

VOLUME /src/keyboards/planck/keymaps

CMD ["/bin/bash"]
