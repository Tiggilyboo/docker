FROM tiggilyboo/android
LABEL description="Flutter"
MAINTAINER Simon Willshire <me@simonwillshire.com>

ENV INSTALL_PACKAGES="curl git unzip ca-certificates openssl libssl1.1 lib32stdc++6" \
    FLUTTER_PATH="/usr/local" \
    FLUTTER_REPO="https://github.com/flutter/flutter.git" \
    FLUTTER_BRANCH="beta"
ENV PATH="$PATH:$FLUTTER_PATH/flutter/bin"

RUN \
  mkdir -p $FLUTTER_PATH && cd $FLUTTER_PATH && \
  apt-get -qq update -qq && \
  apt-get -y -qq --no-install-recommends install $INSTALL_PACKAGES && \
  ( sleep 8 && while [ 1 ]; do sleep 1; echo y; done ) | \
    android update sdk -u -a --filter "platform-tools" && \ 
  git clone -b $FLUTTER_BRANCH $FLUTTER_REPO && \
  flutter doctor && \
  apt-get autoremove -yq && \
  rm -rf /var/lib/apt/lists && \
  rm -rf /var/cache/apt && \
  rm -rf $ANDROID_HOME/temp/*

VOLUME /src
WORKDIR /src

CMD ["flutter"] 
