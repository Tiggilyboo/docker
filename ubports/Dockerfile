FROM ubuntu:18.04 
MAINTAINER Simon Willshire <me@simonwillshire.com>
LABEL description="Halium UBPorts for Sony Xperia X Performance"

ENV DEBIAN_FRONTEND=noninteractive \
    INSTALL_PACKAGES="curl git ca-certificates openssl libssl1.1 g++ gcc libc6-dev make pkg-config git gnupg flex bison gperf build-essential zip bzr curl libc6-dev libncurses5-dev:i386 x11proto-core-dev libx11-dev:i386 libreadline6-dev:i386 libgl1-mesa-glx:i386 libgl1-mesa-dev g++-multilib mingw-w64-i686-dev tofrodos python-markdown libxml2-utils xsltproc zlib1g-dev:i386 schedtool liblz4-tool bc lzop wget libssl-dev imagemagick repo" \
    PROJECT_ROOT="/ssd/Halium-7.1" \
    DEVICE=suzu \
    BREAKFAST_DEVICE=aosp_f5121-userdebug \
    HALIUM_VER=halium-7.1 

RUN \
  export LC_ALL=C && \
  dpkg --add-architecture i386 && \
  apt-get -qq update -qq && \
  apt-get -y --no-install-recommends install $INSTALL_PACKAGES && \
  apt-get autoremove -yq && \
  rm -rf /var/lib/apt/lists && \
  rm -rf /var/cache/apt && \
  mkdir -p $PROJECT_ROOT && cd $PROJECT_ROOT 

#RUN \
#  repo init -u https://github.com/Halium/android -b $HALIUM_VER --depth=1 && \ 
#  repo sync && \
#  ./halium/devices/setup $DEVICE && \ 
#  repo sync --force-sync && \
#  source build/envsetup.sh && \
#  breakfast $BREAKFAST_DEVICE

CMD ["/bin/bash"]
