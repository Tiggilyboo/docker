FROM tiggilyboo/go
MAINTAINER Simon Willshire <me@simonwillshire.com>
LABEL description="Golang Qt"

ENV DEBIAN_FRONTEND=noninteractive \
    INSTALL_PACKAGES="curl git ca-certificates libcurl4-openssl-dev fakeroot libssl1.1" \
    BUILD_PACKAGES="software-properties-common apt-utils \
    libgl1-mesa-dev fontconfig libfontconfig1-dev unzip bison build-essential gperf \
    flex ruby python libasound2-dev libbz2-dev libcap-dev \
    libcups2-dev libdrm-dev libegl1-mesa-dev libgcrypt11-dev libnss3-dev libpci-dev \
    libpulse-dev libudev-dev libxtst-dev gyp ninja-build libssl-dev libxcursor-dev \
    libxcomposite-dev libxdamage-dev libxrandr-dev libxss-dev \
    libsrtp0-dev libwebp-dev libjsoncpp-dev libopus-dev libavutil-dev libavformat-dev \
    libavcodec-dev libevent-dev libxslt1-dev" \
    QT=qt-unified-linux-x64-online.run \
    QT_QPA_PLATFORM=minimal \
    QT_DIR=/opt/Qt \
    QT_DOCKER=true \
    QT_REPO=github.com/therecipe/qt

RUN \
  apt-get update -qq && \
  apt-get install -yq --no-install-recommends $INSTALL_PACKAGES $BUILD_PACKAGES && \
  go get -v $QT_REPO/cmd/... && \
  curl -sL --retry 10 --retry-delay 10 -o /tmp/$QT https://download.qt.io/official_releases/online_installers/$QT && \
  chmod +x /tmp/$QT && \
  /tmp/$QT --script $GOPATH/src/$QT_REPO/internal/ci/iscript.qs && \
  $GOPATH/bin/qtsetup prep linux && \
  $GOPATH/bin/qtsetup check linux && \
  $GOPATH/bin/qtsetup generate linux && \
  $GOPATH/bin/qtsetup install linux && \
  apt-get remove -yq --allow-remove-essential --purge $BUILD_PACKAGES && \
  apt-get autoremove -yq && \
  rm -f /tmp/$QT && \
  rm -rf $GOPATH/src/golang.org/ && \
  rm -rf $GOPATH/src/github.com/Sirupsen/ && \
  rm -rf $GOPATH/pkg/linux_amd64/golang.org/ && \
  rm -rf $GOPATH/pkg/linux_amd64/github.com/Sirupsen/ && \
  rm -rf /var/lib/apt/lists && \
  rm -rf /var/cache/apt

CMD ["/bin/bash"]
