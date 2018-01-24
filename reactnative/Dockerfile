FROM tiggilyboo/android
LABEL description="ReactNative"
MAINTAINER Simon Willshire <me@simonwillshire.com>

ENV \
  WATCHMAN_BRANCH="v4.9.0" \
  WATCHMAN_REPO="https://github.com/facebook/watchman.git" \
  BUILD_PACKAGES="apt-utils ca-certificates libssl-dev curl git autoconf automake make libtool python-setuptools python-dev pkg-config g++" \
  INSTALL_PACKAGES="inotify-tools"

RUN \
  apt-get update && \
  apt-get install --no-install-recommends -yq $BUILD_PACKAGES $INSTALL_PACKAGES && \
  git clone $WATCHMAN_REPO && \
  cd watchman && \
  git checkout $WATCHMAN_BRANCH && \
  ./autogen.sh && \
  ./configure && \
  make && \
  make install && \
  cd /src \
  npm install -g react-native-cli && \
  npm install -g create-react-native-app && \
  apt-get remove --allow-remove-essential --purge -y $BUILD_PACKAGES && \
  apt-get autoremove -yq && \
  rm -rf /var/lib/apt/lists && \
  rm -rf /var/cache/apt

VOLUME /src
WORKDIR /src
